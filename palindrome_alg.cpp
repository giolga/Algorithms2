#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int arr[256][256];
pair<int, char> pr[100];
int cnt;

void palindrome(string s, int arr[256][256]) {

   for(int k = 0; k < s.size(); k++) {
      
      for(int i = 0; i < s.size(); i++) {
         int j = k + i + 1;
         if(j <= s.size()-1) {
            if(s[i] == s[j]) arr[i][j] = arr[i+1][j-1];
            else arr[i][j] = min(arr[i][j-1], arr[i+1][j]) + 1;
         }
      }

   }
   
}

string removeChars(int row, int col, string s) {
   while(arr[row][col] != 0) {

      if(s[row] == s[col]) {
         row++;
         col--;
         continue;
      }
      int left = arr[row][col - 1];
      int down = arr[row + 1][col];
      if(left < down) {
        pr[cnt].first = col;
        pr[cnt].second = s[col];
        s.replace(col, 1, "-");
        col--;
        cnt++;
      } else {
         pr[cnt].first = row;
         pr[cnt].second = s[row];
        s.replace(row, 1, "-");        
         row++;
         cnt++;
      }

   }

   return s;
}

int main() {
   string s;
   cin >> s;

   palindrome(s, arr);

   for(int i = 0; i < s.size(); i++) {
      for(int j = 0; j < s.size(); j++) {
         cout << arr[i][j] << " ";
      }  
      cout << endl;
   }
   cout << arr[0][s.size() - 1] << endl;//characters need to be removed in order to get palindrome))

   string ans = removeChars(0, s.size() - 1, s);
   cout << ans << endl;

cout << cnt << endl;    

   for(int i = 0; i < cnt; i++) {
        cout << pr[i].first << " - " << pr[i].second << endl;
   }

}