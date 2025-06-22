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
    int n;
    cin >> n;
    vector<int> tab(n);
    for(int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    
    map<int, int> occ;
    ll res = 0;
    int l = 0;
    for(int r = 0;r<n;r++){
        if (occ.find(tab[r])!=occ.end() && occ[tab[r]]>=l){
            l = occ[tab[r]]+1;
        }
        occ[tab[r]] = r;
        res+= r-l+1;
    }
    
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}

