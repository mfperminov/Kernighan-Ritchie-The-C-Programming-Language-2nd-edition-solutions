#include <stdio.h>

int main() {
  int c;
  int wscnt = 0;
  while((c = getchar()) != EOF) {
    if (c != ' ') {
      if (wscnt > 0) {
	putchar(' ');
	wscnt = 0;
      }
      putchar(c);
    } else {
      wscnt++;
    }
  }    
  return 0;
}
