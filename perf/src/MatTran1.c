
/* To compile: gcc -O3 -o MatTran1 MatTran1.c */

#include <stdlib.h>

/* Traverse the trapezoidal space (i, j) where
   i0 <= i < i1
   j0 + (i - i0) * dj0 <= j < j1 
   
   Author: Matteo Frigo
*/
void MatTran1(int *A, 
	      int lda, int i0,  int i1,
	      int j0,  int dj0, int j1)
{//----------------------------------------
    const int THRESHOLD = 4; 

    int di, dj, dj2, di2, i, j, x;

 tail:
    di = i1 - i0; 
    dj = j1 - j0;
    
    if (dj >= 2 * di && dj > THRESHOLD) {
	dj2 = dj / 2;
	MatTran1(A, lda, i0, i1, j0, dj0, j0 + dj2);
	j0 += dj2; dj0 = 0; goto tail;
    } else if (di > THRESHOLD) {
	di2 = di / 2;
	MatTran1(A, lda, i0, i0 + di2, j0, dj0, j1);
	i0 += di2; j0 += dj0 * di2; goto tail;
    } else {
	for (i = i0; i < i1; ++i) {
	    for (j = j0; j < j1; ++j) {
		x = A[j * lda + i];
		A[j * lda + i] = A[i * lda + j];
		A[i * lda + j] = x;
	    }
	    j0 += dj0;
	}
    }
}


int main()
{//--------
    int i, j, n, *A, m;
    
    n = 16384;
    A = (int*)malloc(sizeof(int)*n*n);
    
    for (i=0; i<n; ++i){
	m = i*n;	
	for (j=0; j<n; ++j)
	    A[m+j] = i+j;
    }
    
    MatTran1(A, n, 0, n, 0, 1, n);
    
    free(A);
    
    return 0;
}

