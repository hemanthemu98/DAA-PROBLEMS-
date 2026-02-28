#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> x(m - 1), y(n - 1);
    for(int i = 0; i < m - 1; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> y[i];
    }
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    long long cost = 0;
    int h_pieces = 1, v_pieces = 1;
    int i = 0, j = 0;
    while(i < m - 1 || j < n - 1) {
        if(j == n - 1 || (i < m - 1 && x[i] >= y[j])) {
            cost += (long long)x[i] * v_pieces;
            h_pieces++;
            i++;
        } else {
            cost += (long long)y[j] * h_pieces;
            v_pieces++;
            j++;
        }
    }
    cout << cost << endl;
    return 0;
}
