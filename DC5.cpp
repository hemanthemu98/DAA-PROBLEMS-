#include <bits/stdc++.h>
using namespace std;

int check(int mid, vector<int>& A, int M) {
    int n = A.size();
    int segments = 0;
    int i = 0;
    while(i < n) {
        int current_or = 0;
        int start = i;
        while(i < n && (current_or | A[i]) <= mid) {
            current_or |= A[i];
            i++;
        }
        if(i == start) return INT_MAX;
        segments++;
    }
    return segments;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int low = 0, high = (1LL << 31) - 1;
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(check(mid, A, M) <= M) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
