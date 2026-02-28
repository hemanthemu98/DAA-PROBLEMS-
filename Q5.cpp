#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* node, string code, map<char, string>& codes) {
    if(!node) return;
    if(node->ch != '\0') {
        codes[node->ch] = code;
        return;
    }
    generateCodes(node->left, code + "0", codes);
    generateCodes(node->right, code + "1", codes);
}

int main() {
    int n;
    cin >> n;
    vector<char> chars(n);
    vector<int> freq(n);
    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> freq[i];
    }
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }
    while(pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* parent = new Node('\0', l->freq + r->freq);
        parent->left = l;
        parent->right = r;
        pq.push(parent);
    }
    Node* root = pq.top();
    map<char, string> codes;
    generateCodes(root, "", codes);
    cout << "Character Huffman Code" << endl;
    for(char c : chars) {
        cout << c << " " << codes[c] << endl;
    }
    return 0;
}
