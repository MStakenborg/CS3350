
void copymatrix2(int n, int (*src)[n], int (*dst)[n])
{
   int i,j;
   for (j = 0; j < n; j++)
      for (i = 0; i < n; i++)
        dst[i][j] = src[i][j];
}

int main(){
   int n = 8192;

   int A[n][n], B[n][n];
   int i = 0, j = 0;
   for (i=0; i<n; ++i)
       for (j=0; j<n; ++j)
	   A[i][j] = i+j;

   copymatrix2(n, A, B);

   return 0;
}
