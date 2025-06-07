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
    vector<vector<bool>> mat(n,vector<bool>(m,false));
    vector<int> monster,ends;
    int start;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin >> x;
            if (x=='.'){
                mat[i][j] = true;
            }
            if (x== 'A') start = i*m+j, mat[i][j] = true;
            if (x=='M') mat[i][j] = true,monster.pb(i*m+j);
            if (mat[i][j] && (i==0 || i==n-1 || j == 0 || j==m-1) ){
                ends.pb(i*m+j);
            }
        }
    }
    vector<vector<pair<int,int>>> g(n*m,vector<pair<int,int>>());
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (mat[i][j]){
                if (i>0 && mat[i-1][j]) g[i*m+j].pb(mp((i-1)*m+j,'U'));
                if (j>0 && mat[i][j-1]) g[i*m+j].pb(mp((i)*m+j-1,'L'));
                if (i<(n-1) && mat[i+1][j]) g[i*m+j].pb(mp((i+1)*m+j,'D'));
                if (j<(m-1) && mat[i][j+1]) g[i*m+j].pb(mp((i)*m+j+1,'R'));
            }
        }
    }
    vector<int> mpath(n*m,INT_MAX);
    vector<pair<int,int>> predecessor(n*m,mp(-1,-1));
    bool is_monster = true;
    bool final_res = false;
    int final_dest = -1;
    function<void(int)> bfs = [&](int s) 
    {
        queue<pair<int,int>> q;  
        vector<bool> visited(n*m, false);
        if (!is_monster){
            q.push(mp(s,0));
            visited[s] = true;
        }
        else{
            for(auto x:monster){
                q.push(mp(x,0));
                visited[x] = true;
            }
        }
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            if (is_monster) mpath[curr.first] = min(mpath[curr.first],curr.second);
            if (!is_monster && (curr.first%m == 0 || curr.first%m == m-1 || curr.first/m == 0 || curr.first/m == (n-1))){
                final_res = true;
                final_dest = curr.first;
                return;
        }
            q.pop();
            for (pair<int,int> x : g[curr.first]) {
                if ((!visited[x.first] && is_monster) || (!visited[x.first] && mpath[x.first]>(curr.second+1))) {
                    visited[x.first] = true;
                    if(!is_monster) predecessor[x.first] = mp(curr.first,x.second);
                    q.push(mp(x.first,curr.second+1));
            }
        }
    }
};
    bfs(-1); // bfs multi source monster
    is_monster = false;
    bfs(start);
    if (final_res){
        cout << "YES" << endl;
        vector<char> path;
        while(final_dest != start){
            path.pb(predecessor[final_dest].second);
            final_dest = predecessor[final_dest].first;
        }
        reverse(path.begin(),path.end());
        cout << path.size() << endl;
        for(auto x:path){
            cout << x;
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }



}

int main()
{
    fastio();
    solve();

    return 0;
}