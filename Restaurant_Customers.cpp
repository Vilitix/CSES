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
    vector<pair<int,bool>> s;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        s.pb(mp(x,true));
        s.pb(mp(y,false));
    }
    sort(s.begin(),s.end());
    int current = 0;
    int res = 0;
    for(int i = 0;i<size(s);i++){
        current+= s[i].second ? 1 : -1;
        res = max(res,current);
    }
    cout << res << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}