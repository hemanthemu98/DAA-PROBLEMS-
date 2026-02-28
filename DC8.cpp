#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    long long sum = 0;
    for(int l = 0; l < N; l++) {
        bool special = false;
        for(int i = 0; i < N && !special; i++) {
            for(int j = i; j < N && !special; j++) {
                int cnt = 0;
                for(int p = i; p <= j; p++) if(A[p] > A[l]) cnt++;
                if(cnt == k) special = true;
            }
        }
        if(special) sum += A[l];
    }
    cout << sum << endl;
    return 0;
}
