#include "pool.h"

Block *
block_init ()
{
  Block *block = (Block *)malloc (sizeof (Block));

  if (block)
    {
      block->size = 0;
      block->cap = INCREMENT;
      block->list = malloc (sizeof (void *) * block->cap);

      if (!block->list)
        {
          free (block);

          return NULL;
        }
    }
  return block;
}

void *
alloc (Block *block, size_t size)
{
  if (block && size < block->cap) {
    void* ptr = calloc (size, sizeof(void*));

    if (block->size == block->cap) {
      block->cap += INCREMENT;
      block->list = realloc (block->list, sizeof (void *) * block->cap);
    }
    block->list[block->size] = ptr;
    block->size++;


    return ptr;
  }
  return NULL;
}

void
pfree (Block *block)
{
  if (block) {
    for (int i = 0; i < block->size; i++) {
      free (block->list[i]);
    }
  }

  free (block->list);
  free (block);
}
