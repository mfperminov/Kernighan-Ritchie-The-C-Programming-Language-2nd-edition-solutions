/*
  Exercise 1-16. Revise the main routine of the longest line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text
*/

#include <stdio.h>
#define MAXLINE 1000

int readline(char line[], int maxline);
void copy(char to[], char from[], int maxline);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = readline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line, MAXLINE);
    }
  if (max > 0) {
    printf("length of max string is %d\n", max);
    printf("first %d symbols of the longest string: %s\n", MAXLINE-1, longest);
  }
  return 0;
}

int readline(char s[], int lim) {
  int c, i;
  for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  if (i == (lim -1) && c !=EOF && c !='\n') {
    for (; (c=getchar()) != EOF && c!='\n'; ++i)
      ;
  }
  return i;
}

void copy(char to[], char from[], int maxline) {
  int i;

  for(i=0; i < maxline-1 && from[i]!='\0'; ++i) {
    to[i] = from[i];    
  }
  to[i] = '\0';
}
  
