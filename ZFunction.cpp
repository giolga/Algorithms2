#include <bits/stdc++.h>
using namespace std;

string text, pattern;
vector<int> zTable(0);

void construtTable() {
    string patternText = pattern + "$" + text; // Added a delimiter
    zTable.resize(patternText.size(), 0);
    //left pointer and right pointer;
    int left = 0, right = 0;
    cout << patternText << endl;
    int n = patternText.size();
    for(int k = 1; k < n; k++) {
        if(k > right)  {
            int matchingChars = 0;
            while(k + matchingChars < n && patternText[matchingChars] == patternText[k+matchingChars]) 
                matchingChars++;
            
            zTable[k] = matchingChars;
            if(matchingChars){
                left = k;
                right = matchingChars + k - 1;
            }
        }
        else {
            int p = k - left;
            if(zTable[p] < right - k + 1) {
                zTable[k] = zTable[p];
            }
            else {
                int i = right + 1;
                while(i < n && patternText[i] == patternText[i - k])
                    i++;
                zTable[k] = i - k;
                left = k;
                right = --i;
            }
        }
    }
}

void search() { 
    construtTable();
    for(int i = 0; i < zTable.size(); i++) {
        if(zTable[i] >= pattern.size()) {
            cout << "Matching found at " << i - pattern.size() << endl;
        }
    }

    for(int i = 0; i < zTable.size(); i++) {
        cout << zTable[i] << " ";
    }
}

int main() {
    cin >> pattern >> text;
    
    search();
}
//aaab             
// aabaabbaababbaaab
// aabza
// abzcaabzaabza