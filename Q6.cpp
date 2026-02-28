#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> arrival(N), departure(N), preferred(N);
    for(int i = 0; i < N; i++) {
        cin >> arrival[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> departure[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> preferred[i];
    }
    vector<vector<pair<int, int>>> comp(K + 1);
    for(int i = 0; i < N; i++) {
        comp[preferred[i]].push_back({departure[i], arrival[i]});
    }
    int total = 0;
    for(int k = 1; k <= K; k++) {
        auto& cus = comp[k];
        sort(cus.begin(), cus.end());
        int count = 0;
        int last_end = -1;
        for(auto& p : cus) {
            if(p.second >= last_end) {
                count++;
                last_end = p.first;
            }
        }
        total += count;
    }
    cout << "Maximum number of customers that can dine = " << total << endl;
    return 0;
}
