#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int len = s.length();
    if(isPowerOfTwo(len)) {
        k /= 2;
    } else {
        k *= 2;
    }
    stack<char> st;
    for(char c : s) {
        while(!st.empty() && st.top() > c && k > 0) {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    string res;
    while(!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    cout << res << endl;
    return 0;
}
