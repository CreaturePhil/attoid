#include <attoid.h>
#include <stdio.h>
#include <string.h>
#include "test.h"

#define URL_LEN 64
static char url[URL_LEN] = "_~0123456789"
                      "abcdefghijklmnopqrstuvwxyz"
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void test_url()
{
  int i, j;
  char id[ATTOID_DEFAULT_SIZE];

  for (i = 0; i < 10; i++) {
    attoid(id);
    EXPECT(strlen(id), 22);
    for (j = 0; j < strlen(id); j++) {
      EXPECT(strchr(url, id[j]) != NULL, 1);
    }
  }
}
