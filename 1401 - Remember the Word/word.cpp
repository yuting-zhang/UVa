#include <bits/stdc++.h>

using namespace std;

#define MOD 20071027

struct node_t {
    node_t(): terminal(false) {
        memset(children, -1, sizeof children);
    }
    bool terminal;
    int children[26];
};

vector<node_t> nodes;

string line; 
vector<long long> memo;

long long solve(int pos) {
    if (pos == line.size())
        return 1;

    if (memo[pos] != -1)
        return memo[pos];

    long long &value = memo[pos];
    value = 0;
    int node = 0, index = pos;
    while (pos < line.size()) {
        node = nodes[node].children[line[pos] - 'a'];
        if (node == -1)
            break;
        if (nodes[node].terminal)
            value = (value + solve(pos + 1)) % MOD;
        pos++;
    }
    return value;
}

int main() {
    int S, cases = 0;
    
    while (cin >> line >> S) {
        cases++;
        cout << "Case " << cases << ": ";
        nodes = {node_t()};

        for (int i = 0; i < S; i++) {
            string word;
            cin >> word;
            int node = 0;
            for (int i = 0; i < word.size(); i++) {
                if (nodes[node].children[word[i] - 'a'] == -1) {
                    nodes[node].children[word[i] - 'a'] = nodes.size();
                    nodes.push_back(node_t());
                }
                node = nodes[node].children[word[i] - 'a'];
                if (i == word.size() - 1)
                    nodes[node].terminal = true;
            }
        }

        memo.assign(line.size(), -1);

        cout << solve(0) << "\n";
    }

    return 0;
}
