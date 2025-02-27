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
    vector<int> price(n),pages(n) ;
    for(int i=0;i<n;i++) cin>> price[i];
    for(int i=0;i<n;i++) cin>> pages[i];
    vector<ll> nbpmax(x+1);
    for(int j = 0;j<n;j++){
        for(int i = x;i>0;i--){
            if (i>=price[j]) nbpmax[i] = max(nbpmax[i],pages[j]+nbpmax[i-price[j]]);
        }
    }
    cout << nbpmax[x] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}