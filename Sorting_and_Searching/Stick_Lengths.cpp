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
    vector<int> tab(n) ;
    for(int k=0;k<n;k++) cin>> tab[k];
    sort(tab.begin(),tab.end());
    ll c = 0;
    for(auto x:tab) c+=abs(tab[n/2]-x);
    cout << c << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}
