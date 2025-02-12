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
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> tab(n) ;
    for(int k=0;k<n;k++){
        int x;
        cin>> x;
        tab[k] = mp(x,k);
        }
    sort(tab.begin(),tab.end());
    int is=0,ie=n-1;
    while(is<ie){
        if ((tab[is].first + tab[ie].first)>x){
            ie--;
        }
        else if((tab[is].first + tab[ie].first)<x) {
            is++;
        }
        else{
            cout << tab[is].second+1 << " " << tab[ie].second+1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}