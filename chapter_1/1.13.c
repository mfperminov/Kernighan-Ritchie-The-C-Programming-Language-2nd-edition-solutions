#include <stdio.h>

#define MAX_WORD_L 12
#define MAX_LINE_W 80
#define YES 1
#define NO 0

void horizontal_histogram(int wordsl[]);
void vertical_histogram(int wordsl[]);

int main() {
  int i, curl, c;
  int wordsl[MAX_WORD_L + 1];
  for (i = 1; i <= MAX_WORD_L; i++) {
    wordsl[i] = 0;
  }
  curl = 0;
  while ((c=getchar()) != EOF) {
    if (c == ' ' || c== '\n' || c=='\t') {
      if (curl > 0) {
	wordsl[curl]++;
	curl = 0;
      }
    } else {
      curl++;
    }
  }
  if (curl > 0) {
    wordsl[curl]++;
  }
  printf("\n");
  horizontal_histogram(wordsl);
  printf("\n");
  vertical_histogram(wordsl);
  return 0;
}

void horizontal_histogram(int wordsl[]) {
  for (int i = 1; i<=MAX_WORD_L; i++) {
    printf("%2d|", i);
    for (int j=0; j < wordsl[i]; j++) {
      putchar('#');
    }
    printf("\n");
  }
}

void vertical_histogram(int wordsl[]){
  int i;
  for (i=1; i<=MAX_WORD_L; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  for (i=1; i<=MAX_WORD_L; i++) {
    printf("___");
  }
  printf("\n");
  int maxl = YES;
  for (i=1; i<=MAX_LINE_W && maxl; i++) {
    maxl = NO;
    for (int j = 1; j <=MAX_WORD_L; j++) {
      if (wordsl[j] < i) {
	printf("   ");
      } else {
	maxl = YES;
	printf(" # ");
      }
    }
    printf("\n");
  }
}
  
