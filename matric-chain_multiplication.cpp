#include <bits/stdc++.h>
using namespace std;

int matrix_chain_multiplication(int p[], int n) {
    int m[n][n];
    for(int i = 0; i < n; i++) m[i][i] = 0; //diagonally zeros

    for(int l = 2; l < n; l++) {
        for(int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k <= j - 1; k++) {
                int x = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];//main formula
                m[i][j] = min(x, m[i][j]);
            }
        }
    } 

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++) {
            if(j < i) {
                cout << 0 << " ";
                continue;
            }
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return m[1][n-1];
}

int main() {
    int arr[] = {2,4,5,3,4};// given four matrices 5x4 4x6 6x2 2x7
    int n = sizeof(arr) / sizeof(arr[0]);// defines size of array

    cout << matrix_chain_multiplication(arr, n) << " operations";

    
    return 0;
}