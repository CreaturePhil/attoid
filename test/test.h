#ifndef _TEST_H_
#define _TEST_H_

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"
#define ANSI_BOLD_START   "\e[1m"
#define ANSI_BOLD_END     "\e[0m"
#define NUM_TEST_DASHES   50

int num_tests_pass = 0;
int num_tests_fail = 0;

#define EXPECT(a, b)                                                        \
  if ((a) == (b)) {                                                         \
    printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET ": %-20s L=%d\n",       \
        __FUNCTION__, __LINE__);                                            \
    num_tests_pass++;                                                       \
  } else {                                                                  \
    printf(ANSI_COLOR_RED "FAIL " ANSI_COLOR_RESET ": %s L=%d\n",           \
        __FUNCTION__, __LINE__);                                            \
    num_tests_fail++;                                                       \
  }

#define END_TESTS()                                                               \
  int test_dashes;                                                                \
  printf(num_tests_fail == 0 ? ANSI_COLOR_GREEN : ANSI_COLOR_RED);                \
  for (test_dashes = 0; test_dashes < NUM_TEST_DASHES; test_dashes++) {           \
    printf("=");                                                                  \
  }                                                                               \
  printf("\nTestsuite summary\n");                                                \
  for (test_dashes = 0; test_dashes < NUM_TEST_DASHES; test_dashes++) {           \
    printf("=");                                                                  \
  }                                                                               \
  printf(num_tests_fail == 0 ? ANSI_COLOR_GREEN : ANSI_COLOR_RED);                \
  printf("\n");                                                                   \
  printf(ANSI_BOLD_START "# TOTAL:" ANSI_BOLD_END "%9d\n",                        \
      num_tests_pass + num_tests_fail);                                           \
  printf(ANSI_COLOR_GREEN "# PASS:" ANSI_COLOR_RESET "%10d\n", num_tests_pass);   \
  printf(ANSI_COLOR_RED "# FAIL:" ANSI_COLOR_RESET "%10d\n", num_tests_fail);     \

#endif
