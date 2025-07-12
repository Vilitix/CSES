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


struct Fenw {
    vector<int> tree;
    int size;
    
    Fenw(int n) : size(n), tree(n + 1, 0) {}
    
    void add(int idx, int val) {
        while (idx <= size) {
            tree[idx] =(tree[idx]+ val)%MOD;
            idx += idx & (-idx);
        }
    }
    
    int sum(int idx) {
        int s = 0;
        while (idx > 0) {
            s = (tree[idx]+ s)%MOD;
            idx -= idx & (-idx);
        }
        return s;
    }
};

void solve()
{ 
    int n;
    cin >> n;
    vector<int> tab(n) ;
    map<int,int> m;
    vector<int> order;
    for(int i=0;i<n;i++) cin>> tab[i],m[tab[i]]++;
    int incr = 0;
    Fenw tree(n); 
    for(auto &x:m){
        x.second = ++incr;
    }
    for(auto &x:tab){
        x=m[x];
    }
    ll res = 0;
    for(auto x:tab){
        ll curr = 1 + tree.sum(x-1);
        res = (res + curr)%MOD;
        tree.add(x,curr);
    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}