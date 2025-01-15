#include <stdio.h>

int main() {
  int c, ns, nt, nl;
  ns = nt = nl = 0;
  while ((c=getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ') {
      ++ns;
    }
    if (c == '\t') {
      ++nt;
    }
  }
  printf("\nlines=%d, spaces=%d, tabs=%d\n",nl, ns, nt);
  return 0;
}
