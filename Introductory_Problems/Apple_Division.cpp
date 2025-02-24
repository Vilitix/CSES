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
pair<ll,ll> backtrack(vector<ll> &tab,ll ind,ll curr_sum,ll tot){
    if (ind == size(tab)) return mp(abs(curr_sum-tot),curr_sum);
    ll old_val = abs(curr_sum-tot);
    ll new_val = abs(curr_sum+tab[ind]-tot);
    if (curr_sum>=tot) return mp(old_val,curr_sum);
    pair<ll,ll> res1 = mp(LLONG_MAX,0);
    if (new_val <  old_val) res1= backtrack(tab,ind+1,curr_sum+tab[ind],tot);
    pair<ll,ll> res2 = backtrack(tab,ind+1,curr_sum,tot);
    if (res1.first<res2.first){
        return res1;
    }
    else{
        return res2;
    }



}

void solve()
{ 
    ll n;
    cin >> n;
    vector<ll> tab(n) ;
    ll sum = 0;
    for(ll k=0;k<n;k++) cin>> tab[k],sum+=tab[k];
    pair<ll,ll> res = backtrack(tab,0,0,sum/2);
    cout<< abs(res.second-(sum-res.second)) << endl;  

}

int main()
{
    fastio();
    solve();
    return 0;
}