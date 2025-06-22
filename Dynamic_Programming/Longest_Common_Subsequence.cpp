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
    cin >> n >> m;
    vector<int> tab1(n) ;
    vector<int> tab2(m) ;
    for(int i=0;i<n;i++) cin>> tab1[i];
    for(int i=0;i<m;i++) cin>> tab2[i];
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (tab1[i]==tab2[j]){
                if (i>0 && j>0 && dp[i][j] < dp[i-1][j-1]+1){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if (dp[i][j] < 1){
                    dp[i][j] = 1;
                }
            }
            else{
                if (i>0 && dp[i][j] < dp[i-1][j]){
                    dp[i][j] = dp[i-1][j];
                }
                if (j>0 && dp[i][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    vector<int> reconstruct;
    int j=m-1;
    int i = n-1;
    while(i >= 0 && j >= 0){
        if (tab1[i]==tab2[j]){
            reconstruct.pb(tab1[i]);
            --i;
            --j;
        }
        else if ((i>0 && j==0) || (i==0 && j==0) || (j>0 && i>0 && dp[i-1][j]>dp[i][j-1])){
            --i;
        }
        else{
            --j;
        }
    }
    cout << dp[n-1][m-1] << endl;
    reverse(reconstruct.begin(),reconstruct.end());
    for(int k = 0;k<size(reconstruct);k++){
        cout << reconstruct[k] << " ";
    }
    cout << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}