/*
 * Calculate the square root using Newton method
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
  float	      n = 0;
  float		old_root = 1;
  float		new_root = 0;
  float		delta = 0.0001;
  printf("Enter a number:");
  scanf("%f", &n);
  if (n < 0) {
    printf("invalid input.\n");
    exit(0);
  }
  float		d = 1.0;
  while (d > delta) {
    new_root = (n / old_root + old_root) / 2.0;
    d = fabs(new_root - old_root);
    old_root = new_root;
  }
  
  printf("Square root of %f = %f\n", n, new_root);
  
  return 0;
}
