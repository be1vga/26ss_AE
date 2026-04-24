#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;

    int      deg[n+1];   // unweighted degree: count of edges incident to each node
    long long wdeg[n+1]; // weighted degree: sum of weights of incident edges
    fill(deg,  deg+n+1,  0);
    fill(wdeg, wdeg+n+1, 0LL);

    long long arc_sum = 0;
    int u, v, w;
    for(int i = 1; i <= 2*m; i++){
        cin >> u >> v >> w;
        deg[u]++;      // each directed arc from u corresponds to one undirected edge incident to u
        wdeg[u] += w;  // accumulate the arc's weight as u's weighted-degree contribution
        arc_sum  += w;
    }

    // max_element(deg+1, deg+n+1) returns a random-access iterator pointing to the
    // maximum element in the half-open range [deg+1, deg+n+1) (1-based nodes 1..n).
    // Operator * dereferences that iterator to obtain the actual integer value.
    cout << *max_element(deg+1,  deg+n+1) << "\n";  // maximum degree
    cout << *min_element(deg+1,  deg+n+1) << "\n";  // minimum degree
    cout << *max_element(wdeg+1, wdeg+n+1) << "\n"; // maximum weighted degree
    cout << *min_element(wdeg+1, wdeg+n+1) << "\n"; // minimum weighted degree
    cout << arc_sum / 2 << "\n"; // total edge weight; arc_sum counts each edge twice

    return 0;
}
