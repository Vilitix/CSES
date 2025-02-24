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
    ll current = 0;
    int currind = 0;
    int res = 0;
    for(int i = 0;i<n;i++){
        current += tab[i];
        while (current>x){
            current-=tab[currind];
            currind++;
        }
        if (current == x) res++;
    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}