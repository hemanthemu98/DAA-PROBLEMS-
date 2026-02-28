#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for(int i = 0; i < n; i++) {
        cin >> gas[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    int total = 0, start = 0, current = 0;
    for(int i = 0; i < n; i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        current += diff;
        if(current < 0) {
            start = i + 1;
            current = 0;
        }
    }
    cout << (total < 0 ? -1 : start) << endl;
    return 0;
}
