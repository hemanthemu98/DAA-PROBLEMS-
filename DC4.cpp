#include <bits/stdc++.h>
using namespace std;

int maxCrossing(vector<int>& nums, int l, int m, int r) {
    int left_sum = INT_MIN, sum = 0;
    for(int i = m; i >= l; i--) {
        sum += nums[i];
        left_sum = max(left_sum, sum);
    }
    int right_sum = INT_MIN;
    sum = 0;
    for(int i = m + 1; i <= r; i++) {
        sum += nums[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}

int maxSubArray(vector<int>& nums, int l, int r) {
    if(l == r) return nums[l];
    int m = l + (r - l) / 2;
    int left = maxSubArray(nums, l, m);
    int right = maxSubArray(nums, m + 1, r);
    int cross = maxCrossing(nums, l, m, r);
    return max({left, right, cross});
}

int main() {
    vector<int> arr = {-2,-5,6,-2,-3,1,5,-6};
    cout << maxSubArray(arr, 0, arr.size() - 1) << endl;
    return 0;
}
