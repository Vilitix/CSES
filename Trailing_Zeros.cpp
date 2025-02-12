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
    ll n;
    cin >> n;
    int res = 0;
    for(int i = 1;i<13;i++){
        res+=n/(int)pow(5,i);
    }
    cout << res << endl;

}


int main()
{
    fastio();
    solve();
    return 0;
}