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
    ll total = n*(n+1)/2;
    if (total&1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll used  = n;
    int n1 = 0;
    ll current = 0;
    string res1 = "";
    while(current<=(total/2)){
        current+=used;
        if (current <= (total/2)){
            res1 += to_string(used) + " ";
            n1++;
        }
        used--;

    }
    used++;
    current-=used;
    int to_not_use = (total/2 - current);
    if (to_not_use != 0){
        res1 += to_string(to_not_use);
        n1++;
    }
    res1+= "\n";
    cout << n1 << endl << res1;

    int n2 = 0;
    string res2 = "";
    for (int i = 1;i<=used;i++){
        if (i!=to_not_use){
            res2 += to_string(i) + " ";
            n2++;
        }
    }
    cout << n2 << endl << res2 << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}