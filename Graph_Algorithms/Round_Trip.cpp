#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() { 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    vector<int> visited(n+1, 0);
    vector<int> parent(n+1, -1);
    vector<int> cycle;
    bool found = false;
    function<void(int, int)> dfs = [&](int node, int par) {
        visited[node] = 1;
        parent[node] = par;
        
        for (int next : g[node]) {
            if (found) return; 
            
            if (next == par) continue; 
            
            if (visited[next] == 1) {
                int curr = node;
                cycle.clear();
                cycle.pb(next); 
                
                while (curr != next) {
                    cycle.pb(curr);
                    curr = parent[curr];
                }
                cycle.pb(next);
                if (cycle.size() > 3) {
                    found = true;
                    return;
                }
            } else if (visited[next] == 0) {
                dfs(next, node);
            }
        }
        
        visited[node] = 2;  
    };
    for (int i = 1;i<=n;i++){
        if ((!visited[i]) && !found){
            dfs(i,-1);
        }
    }
    if (found){
        cout << cycle.size() << endl;
        for(int el:cycle){
            cout << el << " ";
        }
        cout << endl;
        return;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}