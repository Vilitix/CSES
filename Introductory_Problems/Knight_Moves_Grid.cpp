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

int isin(int x,int y,int n){
    return x<n && y<n && x>=0 && y>=0;
}

void solve()
{ 
    int n;
    cin >> n;
    vector<int> dx = {2,2,1,-1,-2,-2,1,-1};
    vector<int> dy = {-1,1,2,2,1,-1,-2,-2};
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    queue<pair<int,int>> q;
    q.push(mp(0,0)); // approche bottom up
    dp[0][0] = 0;
    while(!q.empty()){
        auto [curx,cury] = q.front();
        q.pop();
        for(int i = 0;i<8;i++){
            int cx = curx+dx[i];
            int cy = cury+dy[i];
            if (isin(cx,cy,n)){
                if (dp[cx][cy] == INT_MAX){
                    q.push(mp(cx,cy));
                    dp[cx][cy] = min(1+dp[curx][cury],dp[cx][cy]);
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << dp[i][j] << " \n"[j==n-1];
        }
    }

     
}

int main()
{
    fastio();
    solve();
    return 0;
}