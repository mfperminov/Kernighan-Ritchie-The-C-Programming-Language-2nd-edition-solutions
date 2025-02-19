/*
  Exercise 1-17. Write a program to print all input lines that are longer than 80 characters
*/
#include <stdio.h>

#define MAXLINE 1000
#define PRINT_THRESHOLD 80

int get_line(char line[], int maxline);
void copy(char to[], char from[], int posfrom);

int main() {
  int len;
  char line[MAXLINE];
  char printbuf[MAXLINE * 10];
  int pos = 0;
  while ((len = get_line(line, MAXLINE)) > 0 && pos < MAXLINE * 10) {
    if (len > PRINT_THRESHOLD && (len + pos) < (MAXLINE * 10-1)) {
      copy(printbuf, line, pos);
      pos += len;
    }
  }
  printbuf[pos] = '\0';
  printf("%s", printbuf);
  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for(i = 0; i < lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[], int posfrom) {
  int i = posfrom;
  int j = 0;

  while ((to[i] = from[j]) != '\0') {
    ++i;
    ++j;
  }
}
