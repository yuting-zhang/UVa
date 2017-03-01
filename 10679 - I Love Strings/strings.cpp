#include <bits/stdc++.h>

using namespace std;

struct node_t {
    node_t* fail;
    bool term, match, explored;
    node_t* children[52];
};

node_t pool[1000050];
int pool_index;

node_t *root;

char S[100050];
char T[1050];
node_t *term[1000];


int get_index(char alpha) { 
    if (islower(alpha))
        return alpha - 'a';
    else
        return alpha - 'A' + 26;
}

void insert(int index) {
    node_t *node = root;
    int length = strlen(T);
    for (int i = 0; i < length; i++) {
        int child = get_index(T[i]);
        if (!node->children[child])
            node->children[child] = &pool[pool_index++];
        node = node->children[child];
    }

    node->term = true;
    term[index] =  node;
}

void build_fail() {
    queue<node_t*> q;
    q.push(root);
    root->fail = nullptr;
    while (!q.empty()) {
        node_t *node = q.front();
        q.pop();
        for (int i = 0; i < 52; i++) {
            if (!node->children[i]) 
                continue;

            node_t *pi = node->fail;
            while (pi) {
                if (pi->children[i]) {
                    node->children[i]->fail = pi->children[i];
                    break;
                }
                pi = pi->fail;
            }
            if (!pi)
                node->children[i]->fail = root;
            q.push(node->children[i]);
        }
    }
}

void query() {
    node_t *node = root;
    for (int i = 0; i < strlen(S); i++) {
        int child = get_index(S[i]);
        while (!node->children[child] && node != root)
            node = node->fail;
        if (!node->children[child])
            continue;
        node = node->children[child];
        if (!node->explored) {
            node_t *temp = node;
            while (temp != root) {
                temp->match = true;
                temp->explored = true;
                temp = temp->fail;
            }
        }
    }
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        memset(pool, 0, sizeof pool);
        pool_index = 0;
        root = &pool[pool_index++];

        int q;
        scanf(" %s ", S); 
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf(" %s ", T);
            insert(i);
        }
        build_fail();
        query();
        for (int i = 0; i < q; i++)
            printf("%c\n", term[i]->match ? 'y' : 'n');
    }
    return 0;
}
