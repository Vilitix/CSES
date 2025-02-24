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
    vector<int> tab(n) ;
    for(int k=0;k<n;k++) cin>> tab[k];
    vector<ll> prefix(n);
    map<ll,int> occ;
    occ[0]++;
    ll res = 0;
    prefix[0] = tab[0];
    res+=occ[prefix[0]-x];
    occ[tab[0]]++;
    for(int i = 1;i<n;i++){
        prefix[i] += tab[i] + prefix[i-1];
        res+=occ[prefix[i]-x];
        occ[prefix[i]]++;

    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}