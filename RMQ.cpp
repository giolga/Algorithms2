#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 21; // Maximum array size

int arr[MAX_N][MAX_N];
int n, a[MAX_N];

void RMQ(int arrSize) {
    int pox = 1; // Power of 2
    while (pow(2, pox) <= arrSize) {
        int range = pow(2, pox);

        for (int i = 1; i <= arrSize - range + 1; i++) {
            int rightRange = i + range - 1;
            arr[pox][i] = max(arr[pox - 1][i], arr[pox - 1][i + range / 2]);//min as well
        }
        pox++;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        arr[0][i] = a[i];
    }

    RMQ(n);

    cout << "Result:\n";
    for (int i = 0; i <= log2(n); i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) { // a = 5, 00000-101, a << 1 = 0000-1010 => a = 10
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
20
9 11 5 8 13 10 15 7 13 6 18 21 19 4 9 10 7 20 8 12
*/