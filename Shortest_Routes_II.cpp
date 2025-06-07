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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1,vector<int>(n+1,-1));
    vector<pair<pair<int,int>,int>> arc;
    vector<vector<int>> dist(n+1,vector<int>(n+1,LLONG_MAX));
    for(int i = 0;i<n;i++){
        dist[i][i] = 0;
    }
    for(int i = 0;i<m;i++){
        int a,b,p; 
        cin >> a >> b >> p;
        g[a][b] = p;
        arc.pb(mp(mp(a,b),p));
        dist[a][b] = min(p,dist[a][b]);
    }
    for(int i = 0)
    for(int j = 1;j<=n;j++){


        for(int l = 1;l<=n;l++){
            for(int k = 1;k<=n;k++){
                dist[j][l][k] = (k==0 && j == l ? 0:LLONG_MAX);
            }   
        }
    }
    for(int i = 0;i<q;i++){
        int x,y;
        cin >> x >> y;
        cout << (dist[x][y][n] == LLONG_MAX ? -1:dist[x][y][n]) << endl;
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}