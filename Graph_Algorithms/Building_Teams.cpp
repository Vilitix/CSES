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
    vector<int> wteam(n+1,-1);
    vector<bool> visited(n+1, false);
    function<bool(int,int)> bfs = [&](int s,int team) 
    {
        queue<pair<int,int>> q;  
        visited[s] = true;
        wteam[s] = team;
        q.push(mp(s,team));
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            wteam[curr.first] = curr.second;
            q.pop();
            for (int x : g[curr.first]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(mp(x,3-curr.second));
                }
                else if(wteam[x] == curr.second){
                    return false;
                }
            }
        }
        return true;
    };
    for(int i = 1;i<=n;i++){
        if (!visited[i]){
            if (!bfs(i,1)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout << wteam[i] << " ";
    }
    cout << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}