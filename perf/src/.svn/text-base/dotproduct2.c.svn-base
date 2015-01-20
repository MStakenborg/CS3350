/* aliasing example */
/* gcc -O2 -o dotprod2 dotprod2.c  */

/* avoid repeated memory references by creating local variables */
void dot_prod_2 (double* a, double* b, long n, double* r) {
  int i;
  double sum = 0.0;
  for (i = 0; i < n; i++)
    sum += a[i]*b[i];
  *r = sum;
}

int main () {
  int n=10000000;
  double a[n], b[n];
  double r = 0.0;
  int i = 0;
  for (i=0; i<n; ++i){
    a[i] = i;
    b[i] = i;
  }	

  dot_prod_2(a, b, n, &r);
  
  //printf("dot_prod_2 = %f\n", r);

  return 0;
}
