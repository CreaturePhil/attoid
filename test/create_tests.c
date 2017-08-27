#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOID_LEN 5
#define BUF_LEN  128

int main(int argc, char *argv[])
{
  FILE *cmd, *fin, *fout;
  char result[1024];
  int c, index;
  char *v;
  char buf[BUF_LEN];

  if (argc != 2) {
    printf("Must have a file argument.\n");
    return 0;
  }

  snprintf(buf, BUF_LEN, "grep %s -e \"void \\w*()$\"", argv[1]);

  cmd = popen(buf, "r");
  if (cmd == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }

  fin = fopen(argv[1], "r");
  fout = fopen("tests_main.c", "w");

  while ((c = fgetc(fin)) != EOF) {
    fputc(c, fout);
  }

  fprintf(fout, "\nint main(void) {\n");

  while (fgets(result, sizeof(result), cmd)) {
    v = strchr(result, '\n');
    index = v - result;
    result[index] = '\0';
    if (v == NULL) break;
    fprintf(fout, "\t%s;\n", result + VOID_LEN);
  }

  fprintf(fout, "\n\tEND_TESTS();\n\treturn 0;\n}");

  pclose(cmd);
  fclose(fin);
  fclose(fout);

  return 0;
}
