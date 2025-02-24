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
    if (n==1){ 
        cout << 1 << endl;
        return;
    }
    if (n<4){
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (n==4){
        cout << "2 4 1 3" << endl;
        return;
    }
    for(int i=1;i<=(n/2);i++){
        cout << 2*i << " ";
    }
    for(int i=0;i<=((n-1)/2);i++){
        cout << 2*i +1 << " \n"[i==(n-1)/2];
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}