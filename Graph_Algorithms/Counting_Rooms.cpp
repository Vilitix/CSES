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

class UnionFind{
    private:
    vector<int> par;
    vector<int> sz;
    
    public:
     UnionFind(int n){
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
    
    int find(int u){
        // this optimisation was good.
        if(par[u] != par[par[u]])
            par[u] = find(par[par[u]]);        
        return par[u];
    }
    
    bool connected(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) 
            return true;
        return false;
    }
    
    bool join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) 
            return false;
        if(sz[u] <= sz[v]){
            sz[v] += sz[u];
            par[u] = v;
        }else{
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
};

void solve()
{ 
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> mat(n,vector<bool>(m,false));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin >> x;
            if (x=='.')mat[i][j] = true;
        }
    }
    UnionFind uf(n*m);
    int find_wall = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if ((i+1)<n && (mat[i][j] == mat[i+1][j]) && mat[i+1][j])uf.join(uf.find(i*m+j),uf.find((i+1)*m+j));
            if ((j+1)<m && (mat[i][j] == mat[i][j+1]) && mat[i][j+1])uf.join(uf.find(i*m+j),uf.find(i*m+j+1));
            if (!(mat[i][j]) && find_wall != -1) uf.join(uf.find(find_wall),uf.find(i*m+j));
            else if(!(mat[i][j]) && find_wall == -1){find_wall = i*m+j;}
        }
    }
    set<int> s;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            s.insert(uf.find(i*m+j));
        }
    }
    cout << s.size()-(find_wall!=-1 ? 1:0) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}