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
    vector<pair<pair<int,int>, int>> tab;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        auto p = mp(l, r);
        tab.pb({p,i});
    }
    vector<bool> res1(n,false),res2(n,false);
    int min_end = INT_MAX,max_end = -INT_MAX;
    sort(tab.begin(), tab.end(),[](pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;});
    for (int i = n - 1; i >= 0; i--)
    {
        if (min_end <= tab[i].first.second){
            res1[tab[i].second] = true;
        }
        min_end = min(min_end,tab[i].first.second);
    }
    for (int i = 0; i < n; i++)
    {
        if (max_end >= tab[i].first.second){
            res2[tab[i].second] = true;
        }
        max_end = max(max_end,tab[i].first.second);
    }
    for(int i = 0;i<n;i++){
        cout << res1[i] << " \n"[i==n-1];
    }
    for(int i = 0;i<n;i++){
        cout << res2[i] << " \n"[i==n-1];
    }
}

int main()
{
    fastio();
    solve();
    return 0;
}