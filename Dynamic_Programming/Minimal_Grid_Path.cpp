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


pair<int,int> itoc(int k,int n){
    return mp(k/n,k%n);
}


bool is_in(int i, int j, int n){
    return i>=0 && i<n && j>=0 && j<n;
}

string bfs2(vector<string>& adj) //useless TLE
{
    int n = size(adj);
    string res = string(1,adj[0][0]);
    set<pair<int,int>> q1,q2;   
    q1.insert(mp(0,0));
    for(int i = 0;i<2*n-2;i++){
        char min_char = 'z'+1;
    
        for (auto x: q1) {
            pair<int,int> coord = x;
            if (coord.second+1<n){
                min_char = min(min_char, adj[coord.first][coord.second+1]);
            }
            if (coord.first+1<n){
                min_char = min(min_char, adj[coord.first + 1][coord.second]);
            }
        }
        res+=min_char;
        q2.clear();
        for (auto x: q1) {
            pair<int,int> coord = x;
            if ((coord.second+1<n) && adj[coord.first][coord.second+1]==min_char ){
                q2.insert(mp(coord.first,coord.second+1));
            }
            if (coord.first+1<n && adj[coord.first+1][coord.second]==min_char){
                q2.insert(mp(coord.first+1,coord.second));
            }
        }
        q1 = q2;
    }
    return res;
}

string bfs(vector<string>& adj) {
    int n = size(adj);
    string res = string(1, adj[0][0]);
    vector<pair<int,int>> q1, q2;
    q1.push_back(mp(0, 0));
    
    for(int step = 0; step < 2*n-2; step++) { 
        char min_char = 'z' + 1; 
        for(auto coord : q1) {
            if(coord.first + 1 < n) {
                min_char = min(min_char, adj[coord.first + 1][coord.second]);
            }
            if(coord.second + 1 < n) {
                min_char = min(min_char, adj[coord.first][coord.second + 1]);
            }
        }
        
        res += min_char; 
        q2.clear();
        
        for(auto coord : q1) {
            if(coord.first + 1 < n && adj[coord.first + 1][coord.second] == min_char) {
                q2.push_back(mp(coord.first + 1, coord.second));
            }
            if(coord.second + 1 < n && adj[coord.first][coord.second + 1] == min_char) {
                q2.push_back(mp(coord.first, coord.second + 1));
            }
        }
        
        sort(q2.begin(), q2.end());
        q2.erase(unique(q2.begin(), q2.end()), q2.end());
        q1 = q2;
    }
    
    return res;
}

void solve()
{ 
    int n;
    cin >> n;
    vector<string> mat(n);
    for(int i = 0;i<n;i++){
        cin >> mat[i];
    }
    cout << bfs(mat) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}

