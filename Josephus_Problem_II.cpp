#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    mod_set;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() { 
    int n, k;
    cin >> n >> k;
    mod_set s;
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    
    auto current = k%n;
    while (!s.empty()) {
        auto el = s.find_by_order(current);
        cout << *el << " ";
        s.erase(el);
        if (!s.empty()) current = (current + k) % s.size();
    }
    cout << endl;
}


int main()
{
    fastio();
    solve();
    return 0;
}