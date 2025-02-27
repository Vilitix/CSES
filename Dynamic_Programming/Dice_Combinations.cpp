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
    vector<ll> nb(n+1);
    nb[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=6;j++){
            if (i>=j) nb[i]= (nb[i] + nb[i-j]) % MOD;
        }
    }
    cout << nb[n] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}