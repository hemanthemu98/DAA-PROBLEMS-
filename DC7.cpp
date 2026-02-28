#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int rem = 0; rem < A.size() - 2; rem++) {
        int current_n = A.size();
        vector<int> medians;
        for(int len = 3; len <= current_n; len += 2) {
            for(int i = 0; i <= current_n - len; i++) {
                vector<int> sub(A.begin() + i, A.begin() + i + len);
                sort(sub.begin(), sub.end());
                int med = sub[len / 2];
                medians.push_back(med);
            }
        }
        int min_m = *min_element(medians.begin(), medians.end());
        auto it = find(A.begin(), A.end(), min_m);
        if(it != A.end()) A.erase(it);
    }
    long long sum = 0;
    for(int x : A) sum += x;
    cout << sum << endl;
    return 0;
}
