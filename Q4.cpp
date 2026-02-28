#include <bits/stdc++.h>
using namespace std;

struct Job {
    int deadline, profit, index;
};

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].deadline;
        jobs[i].index = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].profit;
    }
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });
    int max_deadline = 0;
    for(auto& j : jobs) max_deadline = max(max_deadline, j.deadline);
    set<int> slots;
    for(int i = 1; i <= max_deadline; i++) slots.insert(i);
    vector<int> selected;
    int total_profit = 0;
    for(auto& j : jobs) {
        auto it = slots.upper_bound(j.deadline);
        if(it != slots.begin()) {
            --it;
            selected.push_back(j.index + 1);
            total_profit += j.profit;
            slots.erase(it);
        }
    }
    sort(selected.begin(), selected.end());
    cout << "Selected Jobs: [";
    for(size_t i = 0; i < selected.size(); i++) {
        cout << "J" << selected[i];
        if(i < selected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Maximum Profit = " << total_profit << endl;
    return 0;
}
