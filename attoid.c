#include <stdio.h>
#include <sodium.h>
#include "attoid.h"

static char url[] = "_~0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void attoid(char *id)
{
  int i;
  randombytes_buf(id, ATTOID_DEFAULT_SIZE);
  for (i = 0; i < ATTOID_DEFAULT_SIZE; i++) {
    id[i] = url[id[i] & 63];
  }
}
