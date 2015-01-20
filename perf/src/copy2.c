/* gcc -O2 copy2 copy2.c */ 

/* move n*i out of the 2nd loop */
void copy2(int n, int *a, int *b){
   int i = 0, j = 0;
   int k = 0;	
   for (i=0; i<n; ++i) {
      k = n*i;
      for (j=0; j<n; ++j)
	 a[k+j] = b[j]; 
   }
}

int main(){
  int n = 1000;
  int a[n*n];
  int b[n];
  int i = 0;
  for (i=0; i<n; ++i){
     b[i] = i;
  }
  copy2(n, a, b);
		
  return 0;
}
