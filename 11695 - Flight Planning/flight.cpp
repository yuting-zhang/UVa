#include <bits/stdc++.h>

using namespace std;

typedef pair<int, bool> ib;

vector<int> get_diameter(const vector<vector<ib>> &adj_list, int start_node) {
    queue<int> q;
    vector<bool> visited(adj_list.size());
    q.push(start_node);
    visited[start_node] = true;

    int far = start_node;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : adj_list[u]) {
            if (!item.second)
                continue;

            int v = item.first;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> parent(adj_list.size());
    
    q.push(far);
    visited.assign(adj_list.size(), false);
    visited[far] = true;
    parent[far] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : adj_list[u]) {
            if (!item.second)
                continue;

            int v = item.first;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    while (far != -1) {
        path.push_back(far);
        far = parent[far];
    }
    return path;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        vector<vector<ib>> adj_list(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj_list[a - 1].push_back({b - 1, true});
            adj_list[b - 1].push_back({a - 1, true});
        }
        
        vector<int> diameter = get_diameter(adj_list, 0);

        int solution = n;
        pair<int, int> cancel, add;

        for (int i = 1; i < diameter.size(); i++) {
            int u = diameter[i - 1], v = diameter[i];

            ib *edge1, *edge2;

            for (auto &item : adj_list[u])
                if (item.first == v) {
                    edge1 = &item;
                    break;
                }
            for (auto &item : adj_list[v])
                if (item.first == u) {
                    edge2 = &item;
                    break;
                }

            edge1->second = false;
            edge2->second = false;

            vector<int> left_diameter = get_diameter(adj_list, u),
                        right_diameter = get_diameter(adj_list, v);

            int new_diameter = max(ceil((left_diameter.size() - 1) / 2.0) +
                                   ceil((right_diameter.size() - 1) / 2.0) + 1,
                                   max(left_diameter.size() - 1.0, 
                                       right_diameter.size() - 1.0));

            if (new_diameter < solution) {
                solution = new_diameter;
                cancel.first = u + 1;
                cancel.second = v + 1;
                add.first = left_diameter[left_diameter.size() / 2] + 1;
                add.second = right_diameter[right_diameter.size() / 2] + 1;
            }
            
            edge1->second = true;
            edge2->second = true;
        }
        printf("%d\n%d %d\n%d %d\n", solution, cancel.first, cancel.second,
                                     add.first, add.second);
    }

    return 0;
}
