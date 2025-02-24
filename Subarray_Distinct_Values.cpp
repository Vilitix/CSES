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
    map<ll,ll> occ;
    int s = 0;
    ll res=0,nbel=0;
    for(int i = 0;i<n;i++){
        occ[tab[i]]++;
        nbel++;
        res+=nbel;
        if (size(occ) == x && (i==n-1 || !occ[tab[i+1]])){
            while(s<=i){
                occ[tab[s]]--;
                nbel--;
                if (occ[tab[s]] != 0) s++;
                else{
                    occ.erase(tab[s]);
                    s++;
                    break;
                }
            }
        }
    }

    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}