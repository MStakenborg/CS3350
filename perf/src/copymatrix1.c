
void copymatrix1(int n, int (*src)[n], int (*dst)[n])
{
   int i,j;
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        dst[i][j] = src[i][j];
}

int main(){
   int n = 8192;

   int A[n][n], B[n][n];
   int i, j;
   for (i=0; i<n; ++i)
       for (j=0; j<n; ++j)
	   A[i][j] = i+j;

   copymatrix1(n, A, B);

   return 0;
}

