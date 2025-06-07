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
    int n,a,b;
    cin >> n >> a >> b;
    if (a+b>n || (a+b != 0 && (((a+b)-max(a,b))==0))){
        cout << "NO" << endl;
    }
    else{
        cout << "YES " << endl;
        for(int i = n;i>0;i--)cout << i << " ";
        cout << endl;
        int curr = n;
        for (int i = 0;i<(n-(a+b));i++){
            cout << curr << " ";
            curr--;
        }
        int curr2 = curr-b;
        while(curr2>0){
            cout << curr2 << " ";
            curr2--;
        }
        for(int i =0;i<b;i++){
            cout << curr << " ";
            curr--;
        }
        cout << endl;
    }
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