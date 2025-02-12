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

int main()
{
    fastio();
    int n;
    cin >> n;
    vector<int> tab(n+1,0) ;
    for(int k=1;k<n;k++){
        int x;
        cin >> x;
        tab[x]++;
    }
    for(int i=1;i<=n;i++){
        if (tab[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
    

    return 0;
}