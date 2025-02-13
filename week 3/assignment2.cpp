#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<long long> h(m), d(n);

    for (int i = 0; i < m; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    sort(h.begin(), h.end());
    sort(d.begin(), d.end());

    int i = 0, j = 0, count = 0;
    while (i < m && j < n) {
        if (d[j] >= h[i]) { 
            count++;
            i++;
        }
        j++; 
    }

    cout << count; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        if (i > 0) cout << "\n"; 
        solve();
    }

    return 0;
}