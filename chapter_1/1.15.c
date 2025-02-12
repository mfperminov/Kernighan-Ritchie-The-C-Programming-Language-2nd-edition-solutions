/*
  1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion
*/
#include <stdio.h>

float celsius(float fahr);

int main() {
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahrenheit Celsius\n");
  while (fahr <= upper) {
    printf("%7.0f %10.1f\n", fahr, celsius(fahr));
    fahr += step;
  }
  return 0;
}

float celsius(float fahr) {
  return (5.0/9.0) * (fahr-32.0);
}
