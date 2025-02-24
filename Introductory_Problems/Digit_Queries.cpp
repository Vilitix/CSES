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
    ll x;
    cin >> x;
    if (x==1){
        cout << 1 << endl;
        return;
    }
    ll ind = 1;
    ll curpow = 1;
    int nb_digit = 1;
    while(ind<=x){
        ind += nb_digit*(10*curpow - curpow);
        nb_digit++;
        curpow*=10;
    }
    nb_digit--;
    curpow/=10;
    ind-=nb_digit*(10*curpow - curpow);
    ll nb = curpow+((x-ind)/nb_digit);
    int indnb = (x-ind)%nb_digit;
    ll p10 = 1;
    for(int i = 0;i<nb_digit-indnb-1;i++){
        p10*=10;
    }
    cout << (nb/p10) % 10 <<endl;
    
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}