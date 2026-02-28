#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int max_len = 0;
    int i = 0;
    for(int j = 0; j < N; j++) {
        while(A[j] - A[i] > 10) i++;
        max_len = max(max_len, j - i + 1);
    }
    cout << max_len << endl;
    return 0;
}
