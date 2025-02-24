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
    int n,m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m) ;
    for(int k=0;k<n;k++){
        int x;
        cin >> x;
        a.insert(x);

    }
    for(int k=0;k<m;k++) cin>> b[k];
    for(int i = 0;i<m;i++){
        auto res = a.upper_bound(b[i]);
        if (res == a.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *(--res) << endl;
            a.erase(res);
        }

    }
    


}

int main()
{
    fastio();
    solve();
    return 0;
}