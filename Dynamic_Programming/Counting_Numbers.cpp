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

ll dpa[20][10][2][2];
ll dp(const string &nb, int N,int old, bool lzero, bool t){
    if (dpa[N][old][lzero][t] != -1 ) return dpa[N][old][lzero][t];
    if (N == 0) return 1; 
    ll res = 0;
    int lower = 0;
    int higher = t ? nb[nb.length()-N]-'0' : 9;
    for(int i = lower; i<=higher;i++){
        if (i== old && !lzero){
            continue;
        }
        res+= dp(nb,N-1,i,lzero && (i==0),t && (i== higher));
    }
    return dpa[N][old][lzero][t]= res;
}

void solve()
{ 
    ll a,b;
    cin >> a >> b;
    string as = to_string(a-1);
    string bs = to_string(b);
    memset(dpa,-1,sizeof(dpa));
    ll res1 = dp(bs,bs.length(),-1,1,1);
    memset(dpa,-1,sizeof(dpa));
    cout << res1 - dp(as,as.length(),-1,1,1) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}