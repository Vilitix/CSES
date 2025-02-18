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

struct Fenw {
    vector<int> tree;
    int size;
    
    Fenw(int n) : size(n), tree(n + 1, 0) {}
    
    void add(int idx, int val) {
        while (idx <= size) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    int sum(int idx) {
        int s = 0;
        while (idx > 0) {
            s += tree[idx];
            idx -= idx & (-idx);
        }
        return s;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> tab; // ((start,end),index)
    set<int> ends;
    map<int,int> coord_end;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        auto p = mp(l, r);
        tab.pb({p,i});
        ends.insert(r);
    }
    int id = 1;
    for (auto x : ends)
    {
        coord_end[x] = id++;
    }
    vector<int> res1(n),res2(n);
    Fenw tr(n);
    sort(tab.begin(), tab.end(),[](pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;});
    for (int i = n - 1; i >= 0; i--)
    {
        res1[tab[i].second] = tr.sum(coord_end[tab[i].first.second]);
        tr.add(coord_end[tab[i].first.second],1);
    }
    tr = Fenw(n+1);
    for (int i = 0; i < n; i++)
    {
        res2[tab[i].second] = tr.sum(ends.size()) - tr.sum(coord_end[tab[i].first.second] - 1);
        tr.add(coord_end[tab[i].first.second],1);
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