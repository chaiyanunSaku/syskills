#include <stdio.h>

int main() {
  char s[10] = "abcde";
  char* cptr;

  cptr = s;
  while (*ctpr != '\0') {
    cptr++;
  }

  cptr--; // move back 1 step because it was '\0'

  while (cptr >= s) {
    printf("%c", *cptr);
    cptr--;
  }
  printf("\n");
  return 0;
}
