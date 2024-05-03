#include <bits/stdc++.h>
using namespace std;

int main() {
    float a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;

    float determinant = a * e - b * d;
    
    if (determinant == 0) {
         cerr << "No unique solution exists." <<   endl;
        return 1;
    }

    float x1 = (c * e - b * f) / determinant;
    float y2 = (a * f - c * d) / determinant;

    cout << fixed << setprecision(3) << x1 << endl;
    cout << fixed << setprecision(3) << y2 << endl;

    return 0;
}