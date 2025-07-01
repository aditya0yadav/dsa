#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec) cin >> it;

    vector<int> pre(n);
    pre[0] = vec[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + vec[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - (l == 0 ? 0 : pre[l - 1]) << endl;
    }
}
