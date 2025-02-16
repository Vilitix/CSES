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
    queue<int> qr;
    for(int i = 1;i<=n;i++){
        qr.push(i);
    }
    bool ok = false;
    while (!qr.empty()){
        int el = qr.front();
        qr.pop();
        if (ok){
            cout << el << " ";
        }
        else{
            qr.push(el);
        }
        ok=!ok;
    }
    cout << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}