#include <stdio.h>

#define TAB '\t'
#define INPUT_SIZE 10000
#define TAB_WIDTH 8

int detab(char input[], int i, int pos);

int main() {
  char input[INPUT_SIZE];
  int c;
  int line_pos = 0;
  int i = 0;
  while (i < INPUT_SIZE-1 && (c=getchar()) != EOF) {
    if (c == TAB) {
      int blanks = detab(input, i, line_pos);
      i += blanks;
      line_pos += blanks;
    } else if (c == '\n') {
      line_pos = 0;
      input[i++] = c;
    } else {
      input[i++] = c;
      line_pos++;
    }
  }
  input[i] = '\0';
  printf("\n");
  printf("%s\n", input);
  return 0;
}

int detab(char input[], int i, int pos) {
  int blanks = TAB_WIDTH - (pos % TAB_WIDTH);
  for (int j = 0; (j < blanks) && (i+j < INPUT_SIZE-1); ++j) 
    input[i+j]=' ';
  return blanks;
}
