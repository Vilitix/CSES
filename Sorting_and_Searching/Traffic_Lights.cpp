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
    cin >> m >>n;
    vector<int> tab(n) ;
    set <int> s;
    s.insert(0),s.insert(m);
    multiset<int> gap;
    gap.insert(m);
    for(int k=0;k<n;k++){
        int x;
        cin >> x;
        s.insert(x);
        auto it = s.find(x);
        auto ne = next(it);
        auto p = prev(it);
        auto el = gap.find(*ne - *p);
        if (el != gap.end()) gap.erase(el);
        gap.insert(*it-*p);
        gap.insert(*ne-*it);
        cout << *gap.rbegin() << " \n"[k==n-1];
    }
}

int main()
{
    fastio();
    solve();

    return 0;
}