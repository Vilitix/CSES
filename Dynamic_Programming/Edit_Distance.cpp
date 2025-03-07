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

string s1,s2;
int ns1,ns2;

void complete(int n1, int n2, int** &dp){
    if (s1[n1] == s2[n2]){
        if (n2==0){dp[0][0] = min(dp[0][0],n1);return;}
        if (n1==0) dp[0][0] = min(dp[0][0],n1);
        else if(n1!=0){
            dp[n1][n2] = dp[n1+1][n2+1];
            complete(n1-1,n2-1,dp);
        }
    }
    else{
        dp[n1][n2] = 1+ min(dp[n1][n2+1],dp[n1+1][n2+1]);
        complete(n1-1,n2-1,dp);
    }
}

void solve()
{ 
    cin >> s1;
    cin >> s2;
    ns1 = size(s1);
    ns2 = size(s2);
    vector<vector<int>> dp(ns1+1, vector<int>(ns2+1));
    dp[size(s1)][size(s2)] = 0;
    for(int i = 0 ; i<=size(s1) ; i++ ){
        for(int j =0;j<=size(s2); j++ ){
            if (i==0) {dp[0][j] = j;}
            else if(j==0) {dp[i][0] = i;}
            else if (s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j],dp[i -1][j -1]));  
            }

    }
}
    cout << dp[size(s1)][size(s2)] << endl;

}

int main()
{
    fastio();
    solve();
    return 0;
}