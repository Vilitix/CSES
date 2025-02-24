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
    vector<pair<int,int>> t;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        t.pb(mp(x,y));
    }
    sort(t.begin(),t.end(),[](pair<int,int> &a,pair<int,int> &b){return a.second<b.second;});
    int current = 0;
    int current_e=0;
    for(int i = 0;i<n;i++){
        if (current_e<=t[i].first){
            current_e = t[i].second;
            current+= 1;
        }
    
    }
    cout << current << endl;

    
}

int main()
{
    fastio();
    solve();

    return 0;
}