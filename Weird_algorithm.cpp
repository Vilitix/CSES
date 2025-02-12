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

int main()
{
    fastio();
    ll n;
    cin >> n;
    while(n>1){
        if (n%2==0){
            cout << n << " ";
            n/=2;
        }
        else{
            cout << n << " ";
            n = n*3+1;
        }
    }
    cout << 1 << endl;
    
    return 0;
}