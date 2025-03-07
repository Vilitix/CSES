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
    vector<int> tab(n) ;
    for(int i=0;i<n;i++) cin>> tab[i];
    set<int> s;
    for(int i = 0;i<n;i++){
        vector<int> to_add;
        for(auto x:s){
            to_add.pb(x+tab[i]);
        }
        for(auto x:to_add)s.insert(x);
        s.insert(tab[i]);
    }
    cout << s.size() << endl;
    for(auto x:s){
        cout << x << " "; 
    }
    cout << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}