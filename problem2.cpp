#include<bits/stdc++.h>
using namespace std;

int n, m, k;
double balance;

struct Edge {
    int u, v, w;
};

int main()
{
    cin >> n >> m >> k;

    Edge edge[2*m+1];
    for(int i = 1; i <= 2*m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }

    int n_state[n+1]={0}; // block id (0..k-1) assigned to each node (1-indexed)
    int cnt_state[k]={0}; // number of nodes assigned to each of the k blocks

    for(int i = 1; i <= n; i++){
        cin >> n_state[i];
        cnt_state[n_state[i]]++; // increment node count for the block this node belongs to
    }

    int cnt = 0;        // edge-cut: number of cross-block edges
    long long cnt_v = 0; // weighted edge-cut: sum of weights of cross-block edges
    for(int i = 1; i <= 2*m; i++){
        if(n_state[edge[i].u] != n_state[edge[i].v]){
            cnt++;
            cnt_v += edge[i].w;
        }
    }

    // max_element(cnt_state, cnt_state+k) returns a pointer/iterator to the
    // element with the largest value in cnt_state[0..k-1] (the heaviest block).
    // Operator * dereferences it to get that block's node count as an int.
    balance = (*max_element(cnt_state, cnt_state+k) * 1.0 / (n * 1.0 / k * 1.0));

    cnt   /= 2; // each undirected edge represented as two directed arcs, halve the counts
    cnt_v /= 2;

    cout << cnt << "\n" << cnt_v << "\n" << balance;

    return 0;
}
