/*
The standard way of multiplying an m-by-n matrix by an n-by-p matrix has complexity O(mnp). 
If all of those are "n" to you, it's O(n^3),
*/

void multiply(int A[][N], int B[][N], int C[][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            C[i][j] = 0; 
            for (int k = 0; k < N; k++) 
            { 
                C[i][j] += A[i][k]*B[k][j]; 
            } 
        } 
    } 
} 
