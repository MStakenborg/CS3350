/* gcc -O2 copy1 copy1.c */ 

void copy1(int n, int *a, int *b){
   int i = 0, j = 0;
   for (i=0; i<n; ++i)
	for (j=0; j<n; ++j)
	   a[n*i+j] = b[j]; 
}

int main(){
  int n = 1000;
  int a[n*n];
  int b[n];
  int i = 0;
  for (i=0; i<n; ++i){
     b[i] = i;
  }
  copy1(n, a, b);
		
  return 0;
}
