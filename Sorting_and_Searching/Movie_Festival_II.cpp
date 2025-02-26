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

int search_fit(vector<int> &tab, int el){
    int l = 0,r=size(tab)-1;
    int ans = -1;
    while(l<=r){
        int p = (l+r)/2;
        if (tab[p]<=el){l = p+1,ans = p;}
        else {r = p-1;}
    }
    return ans;
}

void solve()
{ 
    int n,k;
    cin >> n >>k;
    vector<pair<int,int>> t;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        t.pb(mp(x,y));
    }
    sort(t.begin(),t.end(),[](pair<int,int> &a,pair<int,int> &b){
        if (a.second != b.second)return a.second<b.second;
        else{return a.first<b.first;}

    });
    int res = 0;
    multiset<int> current_e;
    for(int i = 0;i<k;i++)current_e.insert(0);
    for(int i = 0;i<n;i++){
        auto it = current_e.upper_bound(t[i].first);
        if (it != current_e.begin()){
            it--;
            current_e.erase(it);
            current_e.insert(t[i].second);
            res+= 1;
        }
        }
    cout << res << endl;

    
}

int main()
{
    fastio();
    solve();

    return 0;
}