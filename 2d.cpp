#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> vec(m, vector<int>(n));
    for(int i = 0; i < m ; i++) {
        for(int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    vector<vector<int>> pre(m, vector<int>(n));
    for(int i = 0; i < m ; i++) {
        for(int j = 0; j < n; j++) {
            pre[i][j] = vec[i][j];
            if(j > 0) pre[i][j] += pre[i][j - 1];
            if(i > 0) pre[i][j] += pre[i - 1][j];
            if(i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = pre[x2][y2];
        if(x1 > 0) sum -= pre[x1 - 1][y2];
        if(y1 > 0) sum -= pre[x2][y1 - 1];
        if(x1 > 0 && y1 > 0) sum += pre[x1 - 1][y1 - 1];
        cout << sum << endl;
    }
}
