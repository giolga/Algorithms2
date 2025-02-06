#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int LOG = 14;

vector <int> children[MAX_N];
int up[MAX_N][LOG];// up[v][j] is 2 ^ j-th ancestor of v
int depth[MAX_N];

void dfs(int a) {
    for (int b : children[a]) {
        depth[b] = depth[a] + 1;
        up[b][0] = a; // a is a parent of b

        for (int j = 1; j < LOG; j++) {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }

        dfs(b);        
    }
    
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);

    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
        if( k && (1 << j))
            a = up[a][j];
    }

    if(a == b) return a;

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0]; // == up[b][0]
}

int main() {
    int n;
    cin >> n;

    for(int v = 0; v < n; v++) {
        int cnt;
        cin >> cnt;

        for(int j = 0; j < cnt; j++) {
            int c;
            cin >> c;
            children[v].push_back(c);
        }
    }

    dfs(0);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << get_lca(a, b) << endl;
    }
}