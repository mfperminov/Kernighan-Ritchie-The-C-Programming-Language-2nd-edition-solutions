#include <stdio.h>

int main() {
  float celsius, fahr;
  int lower, upper, step;

  lower = -270;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("Celcius Fahrenheit\n");
  while (celsius <= upper) {
    fahr = celsius * 9 / 5 + 32;
    printf("%7.0f %10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
