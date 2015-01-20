
/* To compile: gcc -O3 -o MatTran2 MatTran2.c */

#include <stdlib.h>

void MatTran2(int *A, int n)
{//------------------------------
    int i, j, tmp, in, inj, jni;

    for (i = 0; i < n; i++){
	in = i*n;	
	for (j = i+1; j < n; j++){
	    inj = in + j;
	    jni = j*n + i;	    
	    tmp = A[inj];
	    A[inj] = A[jni];
	    A[jni] = tmp;
	}
    }
}

int main()
{//-----------
    int i, j, n, *A, m;
    
    n = 16384;
    A = (int*)malloc(sizeof(int)*n*n);
    
    for (i=0; i<n; ++i){
	m = i*n;	
	for (j=0; j<n; ++j)
	    A[m+j] = i+j;
    }
    
    MatTran2(A, n);
    
    free(A);
    
    return 0;
}

