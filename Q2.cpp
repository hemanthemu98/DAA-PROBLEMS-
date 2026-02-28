#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        arrival[i] = h * 60 + m;
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        departure[i] = h * 60 + m;
    }
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int platforms = 0, max_platforms = 0;
    int i = 0, j = 0;
    while(i < n && j < n) {
        if(arrival[i] <= departure[j]) {
            platforms++;
            max_platforms = max(max_platforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    cout << "Minimum number of platforms required = " << max_platforms << endl;
    return 0;
}
