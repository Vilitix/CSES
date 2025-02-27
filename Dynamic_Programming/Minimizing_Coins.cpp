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
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto &x:coins) cin >> x;
    vector<int> to_x(x+1,INT_MAX);
    to_x[0] = 0;
    for(int i = 0;i<x+1;i++){
        for(auto x:coins){
            if (i>=x && to_x[i-x]!=INT_MAX) to_x[i] = min(to_x[i],to_x[i-x]+1);
        }
    }
    if (to_x[x] == INT_MAX){
        cout << -1 << endl;
        return;
    }
    cout << to_x[x] << endl;
    
}


int main()
{
    fastio();
    solve();
    return 0;
}