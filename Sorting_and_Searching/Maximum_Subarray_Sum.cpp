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
    vector<ll> tab(n) ;
    ll maxi = -LLONG_MAX;
    for(int k=0;k<n;k++) {
        cin>> tab[k];
        maxi=max(tab[k],maxi);
        }
    ll current = 0;
    for(int i = 0;i<n;i++){
        current+=tab[i];
        maxi=max(maxi,current);
        if(current<0) current = 0;
    }
    cout << maxi << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}