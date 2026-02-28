#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);
    for(int i = 0; i < n; i++) {
        cin >> activities[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> activities[i].second;
    }
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    vector<pair<int, int>> selected;
    selected.push_back(activities[0]);
    for(int i = 1; i < n; i++) {
        if(activities[i].first >= selected.back().second) {
            selected.push_back(activities[i]);
        }
    }
    cout << "Maximum number of activities = " << selected.size() << endl;
    cout << "Selected activities: ";
    for(size_t i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].first << ", " << selected[i].second << ")";
        if(i < selected.size() - 1) cout << ", ";
    }
    cout << endl;
    return 0;
}
