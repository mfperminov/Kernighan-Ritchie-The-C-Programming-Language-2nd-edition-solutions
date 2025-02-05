#include <stdio.h>

#define ASCII_SYM_COUNT 128
#define NORM_CONSTANT 32
#define YES 1
#define NO 0

void horizontal_histogram(int wordsl[]);
void vertical_histogram(int wordsl[]);

int main() {
  int c = 0;
  int i = 0;
  int symbols[ASCII_SYM_COUNT];
  for (i = 0; i< ASCII_SYM_COUNT; i++) {
    symbols[i] = 0;
  }
  int max = 0;
  while ((c=getchar()) != EOF) {
    if (c >= 0 && c < ASCII_SYM_COUNT) {
      if (++symbols[c] > max) {
	max = symbols[c];
      }
    }
  }
  if (max < 1) return 0;
  int norm = 0;
  for (i = 0; i < ASCII_SYM_COUNT; i++) {
    norm = symbols[i]*NORM_CONSTANT / max;
    if (symbols[i] > 0 && norm == 0) {
      symbols[i] = 1;
    } else {
      symbols[i] = norm;
    }
  }
  printf("\n");
  horizontal_histogram(symbols);
  printf("\n");
  vertical_histogram(symbols);
  return 0;
}

void horizontal_histogram(int symbols[]) {
  for (int i = 0; i<ASCII_SYM_COUNT; i++) {
    if (symbols[i] == 0) continue;
    printf("%2c|", i);
    for (int j=0; j < symbols[i]; j++) {
      putchar('#');
    }
    printf("\n");
  }
}

void vertical_histogram(int symbols[]){
  int i;
  for (i=0; i<ASCII_SYM_COUNT; i++) {
    if (symbols[i] == 0) continue;
    printf("%2c ", i);
  }
  printf("\n");
  for (i=0; i<ASCII_SYM_COUNT; i++) {
    if (symbols[i] == 0) continue;
    printf(" --");
  }
  printf("\n");
  int has_more_lines = YES;
  for (i=0; i<NORM_CONSTANT && has_more_lines; i++) {
    has_more_lines = NO;
    for (int j = 0; j < ASCII_SYM_COUNT; j++) {
      if (symbols[j]==0) continue;
      if (symbols[j] > i) {
	printf(" # ");
	has_more_lines = YES;
      } else {
	printf("   ");
      }
    }
    printf("\n");
  }
}
  
