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
    int n,k;
    cin >> n >> k;
    vector<int> tab(n) ;
    ll sum = 0;
    for(int i=0;i<n;i++) cin>> tab[i],sum+=tab[i];
    ll ans = LLONG_MAX;
    ll l = *max_element(tab.begin(),tab.end()),r = sum;

    while(l<=r){
        ll nbpart = 1,res = 0,current=0;
        ll p = (r+l)/2;
        for(int i = 0;i<n;i++){
            if (((current+tab[i])<=p) || current == 0) current+=tab[i];
            else{
                res = max(current,res);
                current = tab[i];
                nbpart++;
            }
        }
        res = max(current,res);
        if (nbpart<=k)ans = min(ans,res),r=p-1;
        else{l=p+1;}
    }
    cout << ans << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}