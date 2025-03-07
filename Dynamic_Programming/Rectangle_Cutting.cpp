#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;



int top_down(int i, int j, vector<vector<int>> &dp){
    if (dp[i][j] != INT_MAX) return dp[i][j];
    else if(i == j ){
        return dp[i][j]=0;
    }
    else{
        int curr_min = INT_MAX;
        for(int k = 1;k<j;k++){
            curr_min = min(curr_min,1+ top_down(i,k,dp) + top_down(i,j-k,dp));
        }
        for(int l = 1;l<i;l++){
            curr_min = min(curr_min, 1 + top_down(l,j,dp) + top_down(i-l,j,dp));
        }
        return dp[i][j] = curr_min;
    }
}

int bottom_up(int a, int b){
    vector<vector<int>> dp(a+1,vector<int>(b+1,INT_MAX));
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1;k<j;k++){
                dp[i][j] = min(dp[i][j],1+ dp[i][k] + dp[i][j-k]);
            }
            for(int l = 1;l<i;l++){
                dp[i][j] = min(dp[i][j], 1 + dp[l][j] + dp[i-l][j]);
            }

        }
    }
    return dp[a][b];
}


void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{ 
    int a;
    int b;
    cin >> a >> b;
    cout << bottom_up(a,b) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}