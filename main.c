#include <stdio.h>
#include <attoid.h>

int main(void)
{
  char id[ATTOID_DEFAULT_SIZE];

  attoid(id);

  printf("%s\n", id);

  return 0;
}
