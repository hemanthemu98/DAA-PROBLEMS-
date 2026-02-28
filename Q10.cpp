#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> st(N), en(N);
    for(int i = 0; i < N; i++) {
        cin >> st[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> en[i];
    }
    int Q;
    cin >> Q;
    vector<int> plan_st(Q), plan_en(Q);
    for(int i = 0; i < Q; i++) {
        cin >> plan_st[i];
    }
    for(int i = 0; i < Q; i++) {
        cin >> plan_en[i];
    }
    for(int q = 0; q < Q; q++) {
        vector<pair<int, int>> courses;
        for(int i = 0; i < N; i++) {
            if(st[i] >= plan_st[q] && en[i] <= plan_en[q]) {
                courses.push_back({en[i], st[i]});
            }
        }
        sort(courses.begin(), courses.end());
        int count = 0, last = -1;
        for(auto& p : courses) {
            if(p.second >= last) {
                count++;
                last = p.first;
            }
        }
        cout << count;
        if(q < Q - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}
