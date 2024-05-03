#include <bits/stdc++.h>
using namespace std;

string s, p;
int arr[100][100];

//CST-is kalibri var
//Me ro ar gyavdet ra geshvelebat 

int cmp(string sub) {
    string prefix = sub.substr(0, sub.size() - 1);
    string sufix = sub.substr(1);

    while(prefix.size() > 0) {
        if(prefix == sufix) return static_cast<int>(prefix.size());

        prefix.erase(prefix.size() - 1);
        sufix.erase(0, 1);
    }

    return 0;
}

void automata() {

    for(int i = 0; i < s.size() + 1; i++) {
        for(int j = 0; j < p.size(); j++) {
            if(s[i] == p[j]) {
                arr[i][j] = i + 1;
                break;
            }
        }
    }


    string Sub = "";
    for(int i = 1; i < s.size() + 1; i++) {
        Sub += s[i-1];
        for(int j = 0; j < p.size(); j++) {
            if(arr[i][j] > 0) continue;
            string temp = Sub + p[j];
            // cout << cmp(temp) << " ";
            int x = cmp(temp);
            arr[i][j] = x;
        }
    }

    for(int i = 0; i < s.size() + 1; i++) {
        for(int j = 0; j < p.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    cin >> s;
    cin >> p;

    automata();
    cout << 1;
}

/*
unabcuunabu 
unacb
*/

// s.substr(0, s.size() - 1);
// s.substr(1);