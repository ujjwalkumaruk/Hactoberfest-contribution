#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define test(t) int t; cin >> t; while(t--)
#define forr(I, a, b) for(register int I = a; I < b; I++)
#define pb push_back

int main(){
    fast;
    int N, M, u, v, temp;
    queue <int> my_queue;
    cin >> N >> M;
    vector<int> adj[N + 1];
    forr (i, 0, M) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool visited[N + 1];
    memset(visited, false, sizeof(visited));
    int source = 1;
    visited[source] = true;
    my_queue.push(source);
    while (!my_queue.empty()) {
        temp = my_queue.front();
        cout << temp << endl;
        my_queue.pop();
        vector<int> :: iterator it = adj[temp].begin();
        while (it != adj[temp].end()){
            // cout << *it << endl;
            if (visited[*it] == true){
                it++;
                continue;
            }
            visited[*it] = true;
            my_queue.push(*it);
            it++;
        }
    }
    return 0;
}
