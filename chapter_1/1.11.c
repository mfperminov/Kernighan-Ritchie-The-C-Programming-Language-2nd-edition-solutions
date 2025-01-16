#include <stdio.h>
/* Input for testing:							 */
/* Edge cases: single word; only whitespaces; only tabulation symbols, only newlines; */
/* Also word with apostrophe will be counted as one: We're learning c language */

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  return 0;
}
  
