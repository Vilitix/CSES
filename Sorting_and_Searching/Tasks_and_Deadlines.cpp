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
    vector<pair<int,int>> tab(n);
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        tab[i] = mp(x,y);
    }
    sort(tab.begin(), tab.end(),[](pair<int,int> &a, pair<int, int> &b){ if (a.first == b.first) return b.second<a.second;else{return a.first<b.first;}});
    ll current = 0,res=0;
    for(int i = 0;i<n;i++){
        current+= tab[i].first;
        res+= tab[i].second-current;
    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}