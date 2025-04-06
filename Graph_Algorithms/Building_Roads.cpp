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

void solve()
{ 
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i =0;i<m;i++){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<bool> visited(n+1,false); 
    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (int u : g[v]) {
            if (!visited[u])
                dfs(u);
        }
    };
    int prev = -1;
    vector<pair<int,int>> to_add;
    for(int i = 1;i<=n;i++){
        if (!visited[i]){
            dfs(i);
            if (prev!=-1){
                to_add.pb(mp(prev,i));
            }
            prev = i;
        }
    }
    cout << to_add.size() << endl; 
    for(auto [a,b]:to_add){
        cout << a << " " << b << endl;
    }

}

int main()
{
    fastio();
    solve();
    return 0;
}
