#ifndef   POOL_H
#define  POOL_H

#include <stdlib.h>

#define INCREMENT 1024 // to define block size increment

typedef struct _Block {
  void** list;
  int size;
  int cap;
} Block;

Block* block_init();
void *alloc(Block* block, size_t size);

void pfree(Block* block);

#endif // POOL_H