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
    vector<pair<int,int>> tab(n) ;
    for(int k=0;k<n;k++){
        int x;
        cin >> x;
        tab[k] = mp(x,k);
    }
    sort(tab.begin(),tab.end());
    int round = 1;
    for(int i = 1;i<n;i++){
        if (tab[i].second < tab[i-1].second){
            round++;
        }
    }
    cout << round << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}