#include <stdio.h>

#define MAXLINE 100
#define BUFFER_SIZE 1000

void reverse(char s[]);
int get_line(char s[], int lim);
void copy(char to[], char from[], int pos);

int main() {
  int len, pos;
  len = pos = 0;
  char line[MAXLINE];
  char printbuf[BUFFER_SIZE];
  while((len = get_line(line, MAXLINE)) > 0 && (len + pos) < (BUFFER_SIZE-1)) {
    reverse(line);
    copy(printbuf, line, pos);
    pos += len;
  }
  printbuf[pos] = '\0';
  printf("%s\n", printbuf);
  return 0;
}

void reverse(char s[]) {
  int i = 0;
  while (s[i] != '\0')
    i++;
  int mid = i / 2;
  for(int j = 0; j < mid; i--, j++) {
    char temp = s[i-1];
    s[i-1] = s[j];
    s[j] = temp;
  }
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
