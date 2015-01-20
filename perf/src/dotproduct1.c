/* aliasing example */
/* gcc -O2 -o dotprod1 dotprod1.c */

/* dot_prod_1(a, b, n, r)
 * assume a[n] and b[n]; compute sum a[i]*b[i] and deposit result in r
 *
 */
void dot_prod_1 (double* a, double* b, long n, double* r) {
  int i;
  *r = 0.0;
  for (i = 0; i < n; i++)
    *r += a[i]*b[i];
}

int main () {

  int n = 10000000;
  double a[n], b[n];
  double r = 0.0;
  int i = 0;
  for (i=0; i<n; ++i){
    a[i] = i;
    b[i] = i;
  }	

  dot_prod_1(a, b, n, &r);	
  
  //printf("dot_prod_1 = %f\n", r);

  return 0;
}
