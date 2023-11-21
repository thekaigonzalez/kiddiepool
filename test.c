#include "pool.h"

#include <stdio.h>

main(void) {
  Block* __main = block_init();

  char* ptr = alloc(__main, 11);
  
  ptr[0] = 'h';
  ptr[1] = 'e';
  ptr[2] = 'l';
  ptr[3] = 'l';
  ptr[4] = 'o';
  ptr[5] = ' ';
  ptr[6] = 'w';
  ptr[7] = 'o';
  ptr[8] = 'r';
  ptr[9] = 'l';
  ptr[10] = 'd';

  printf("%s\n", ptr);

  pfree(__main);
}