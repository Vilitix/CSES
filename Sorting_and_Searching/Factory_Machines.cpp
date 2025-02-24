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

bool is_possible(ll val,int t, vector<int> tab){
    ll total = 0;
    for(int i = 0;i<size(tab);i++){
        total+= val/(ll)tab[i];
        if (total>=t) return true;
    }
    return false;
}

void solve()
{ 
    int n,t;
    cin >> n >> t;
    vector<int> tab(n) ;
    for(int k=0;k<n;k++) cin>> tab[k];
    sort(tab.begin(),tab.end());
    ll l = tab[0],r=t*1ll*tab[n-1];
    ll res = r;
    while(l<=r){
        ll mid = (l+r)/2;
        if (is_possible(mid,t,tab)){
            res = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
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