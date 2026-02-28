#include <bits/stdc++.h>
using namespace std;

bool can_pack(int S, int N, int W, int H) {
    int per_row = S / W;
    if(per_row == 0) return false;
    int rows_needed = (N + per_row - 1) / per_row;
    int total_height = rows_needed * H;
    return total_height <= S;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N, H, W;
        cin >> N >> H >> W;
        int low = max(W, H);
        int high = N * max(W, H);
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(can_pack(mid, N, W, H)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
