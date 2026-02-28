#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n;
    vector<int> value(n), weight(n);
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    cin >> w;
    vector<pair<double, int>> items;
    for(int i = 0; i < n; i++) {
        items.push_back({(double)value[i] / weight[i], i});
    }
    sort(items.rbegin(), items.rend());
    double max_value = 0.0;
    for(auto& item : items) {
        int idx = item.second;
        if(w >= weight[idx]) {
            max_value += value[idx];
            w -= weight[idx];
        } else {
            max_value += (double)w * (double)value[idx] / weight[idx];
            w = 0;
        }
        if(w == 0) break;
    }
    cout << "Maximum value = " << fixed << setprecision(0) << max_value << endl;
    return 0;
}
