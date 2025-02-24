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

void print_tab(vector<int> tab){
    for(int i =size(tab)-1;i>=0;i--){
        cout << tab[i];
    }
    cout << endl;
}
void solve_r(vector<int> &current,int i, int depth){
    if (depth==0) return;
    for(int j=0;j<i;j++){
        current[j] = 1-current[j];
        print_tab(current);
        solve_r(current,j,depth-1);
    }

}

void solve()
{ 
    int n;
    cin >> n;
    vector<int> current(n,0);
    print_tab(current);
    solve_r(current,n,n);

}



int main()
{
    fastio();
    solve();

    return 0;
}