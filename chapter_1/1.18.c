/*
  Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
*/
#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int trimcopy(char to[], char from[], int posfrom);

int main() {
  int len, trimlen;
  char line[MAXLINE];
  char printbuf[MAXLINE * 10];
  int pos = 0;
  while ((len = get_line(line, MAXLINE)) > 0 && (pos+len) < (MAXLINE * 10-1)) {
    trimlen = trimcopy(printbuf, line, pos);
    if (trimlen > 0) {
      pos += trimlen;
      printbuf[pos++] = '\n';
    }
  }
  printbuf[pos] = '\0';
  printf("\n");
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

int trimcopy(char to[], char from[], int posfrom) {
  int i = 0;
  int lastchpos = -1;

  while (from[i] != '\0' && from [i] != '\n') {
    if (from[i] != ' ' && from[i] != '\t') lastchpos = i;
    ++i;
  }
  if (lastchpos == -1) return 0;
  for (i = 0; i <= lastchpos; ++i) {
    to[posfrom++] = from[i];
  }
  return lastchpos+1;
}
