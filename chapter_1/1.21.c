#include <stdio.h>

#define TAB '\t'
#define INPUT_SIZE 10000
#define TAB_WIDTH 8

int main() {
  char input[INPUT_SIZE];
  int c;
  int linepos = 0;
  int nb = 0;
  int i = 0;
  while (i < INPUT_SIZE-1 && (c=getchar()) != EOF) {
    if (c == ' ') {
      nb = 1;
      while ((c = getchar()) == ' ') {
	nb++;
      }
      int spaces_next_tab = TAB_WIDTH - (linepos % TAB_WIDTH);
      if (nb < spaces_next_tab) {
	for (int j = 0; j < nb; j++){
	  input[i++] = ' ';
	  linepos++;
	}   
      } else {
	while (nb >= spaces_next_tab) {
	  input[i++] = TAB;
	  linepos += spaces_next_tab;
	  nb = nb - spaces_next_tab;
	  spaces_next_tab = TAB_WIDTH;
	}
	while (nb > 0) {
	  input[i++] = ' ';
	  linepos++;
	  nb--;
	}
      }
      if (c != EOF && i < INPUT_SIZE -1) {
	input[i++] = c;
	if (c == '\n') {
          nb = 0;
	  linepos = 0;
        } else if (c == TAB) {
	  nb = 0;
	  linepos += TAB_WIDTH;
	} else {
	  linepos++;
	}
      }
      nb = 0;
    } else if (c == '\n') {
      nb = 0;
      linepos = 0;
      input[i++] = '\n';
    } else if (c == TAB) {
      nb = 0;
      linepos += TAB_WIDTH;
      input[i++] = TAB;
    } else {
      nb = 0;
      input[i++] = c;
      linepos++;
    }
  }
  input[i] = '\0';
  printf("\n");
  printf("%s\n", input);
  return 0;
}

