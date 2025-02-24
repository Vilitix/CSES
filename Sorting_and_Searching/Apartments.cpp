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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> want(n);
    for(int k=0;k<n;k++) cin>> want[k];
    vector<int> s(m);
    for(int k=0;k<n;k++) cin>> s[k];
    sort(s.begin(),s.end());
    sort(want.begin(),want.end());
    int iw = 0,is=0;
    int res = 0;
    while(iw<n && is<m){
        if(want[iw]<=s[is] + k ){
            if (want[iw]>=s[is] - k ){
                res++;
                is++;
                iw++;
            }
            else{
                iw++;
            }
        }
        else{
            is++;
        }
    }
    cout << res << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}