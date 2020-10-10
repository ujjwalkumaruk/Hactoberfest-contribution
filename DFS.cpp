#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define test(t) int t; cin >> t; while(t--)
#define forr(I, a, b) for(register int I = a; I < b; I++)
#define pb push_back

int N;
void DFS(int vertex, bool visited[], vector<int> adj[]){
    cout << vertex << " ";
    visited[vertex] = true;
    for (int a : adj[vertex]) {
        if (!visited[a]) 
            DFS(a, visited, adj);
    }
}

int main(){
    fast;
    int M, u, v, start = 1;
    cin >> N >> M;
    vector<int> adj[N + 1];
    bool visited[N + 1];
    memset (visited, false, sizeof(visited));
    forr (i, 0, M) {
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    DFS(start, visited, adj);
    cout << endl;
    return 0;
}
