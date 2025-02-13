#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<long long> energy(n);

    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    if (n == 1) { 
        cout << "YES" << endl;
        return;
    }

    long long currentEnergy = energy[0]; 

    for (int i = 1; i < n; i++) {
        if (currentEnergy < x) { 
            cout << "NO" << endl;
            return;
        }

        currentEnergy -= x; 
        currentEnergy = max(currentEnergy, energy[i]); 
    }

    cout << "YES" << endl; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
