#include <stdio.h>

float jtt = 0.29;
float utt = 32.86;

float thbtojpy(float a) {
  return a / jtt;
}

float thbtousd(float a) {
  return a / utt;
}

int main() {
  float amount = 5000;
  printf("%.2f %.2f", thbtousd(amount), thbtojpy(amount));
}