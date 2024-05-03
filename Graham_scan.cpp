#include <bits/stdc++.h>
using namespace std;

int n, mn = INT_MAX;
pair <int, int> pr[100], mnPr;
pair <float, pair<int, int>> coordinate[100];

int direction(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    float area = (float)(b.first - a.first) * (float)(c.second - a.second) - (float)(b.second - a.second) * (float)(c.first - a.first);

    if (area > 0) return 1; //counter clock-wise
    if (area < 0) return -1; //clock-wise
    return 0;
}

void grahamScan(pair <float, pair<int, int>> coordinate[]) {
    vector <pair <int, int>> vt;
    vt.push_back(coordinate[0].second);
    vt.push_back(coordinate[1].second);
    vt.push_back(coordinate[2].second);

    for (int i = 3; i < n; i++) {
        while (vt.size() >= 2 && direction(vt[vt.size() - 2], vt[vt.size() - 1], coordinate[i].second) <= 0) {
            vt.pop_back();
        }
        vt.push_back(coordinate[i].second);
    }

    for(auto it : vt) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second; //x y
        if(mn > pr[i].second) {
            mn = pr[i].second;
            mnPr = pr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        coordinate[i].first = atan2(pr[i].second - mnPr.second, pr[i].first - mnPr.first);
        coordinate[i].second = pr[i];
    }

    sort(coordinate, coordinate + n);

    // cout << atan2(coordinate[3].second.second - coordinate[2].second.second, coordinate[3].second.first - coordinate[2].second.first) << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << coordinate[i].first << " " << coordinate[i].second.first << " " << coordinate[i].second.second << "\n";
    // }

    // cout << "Answer: \n";
    // cout << direction(coordinate[5].second, coordinate[7].second, coordinate[8].second);
    grahamScan(coordinate);
    return 0;
}

/*
    9
    3 3
    2 5
    8 1
    4 6
    10 4
    12 6
    13 5
    10 8
    6 10
*/