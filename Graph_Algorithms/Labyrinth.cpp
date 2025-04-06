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
    int apos = -1;
    int bpos = -1;
    vector<vector<bool>> mat(n,vector<bool>(m,false));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin >> x;
            if (x=='.')mat[i][j] = true;
            if (x=='A') mat[i][j] = true,apos=i*m+j;
            if (x=='B') mat[i][j] = true,bpos=i*m+j;
        }
    }
    // pair second element is ascii of L,R,U,D
    vector<vector<pair<int,int>>> g(n*m,vector<pair<int,int>>());
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (mat[i][j]){
                if (i>0 && mat[i-1][j]) g[i*m+j].pb(mp((i-1)*m+j,'U'));
                if (j>0 && mat[i][j-1]) g[i*m+j].pb(mp((i)*m+j-1,'L'));
                if (i<(n-1) && mat[i+1][j]) g[i*m+j].pb(mp((i+1)*m+j,'D'));
                if (j<(m-1) && mat[i][j+1]) g[i*m+j].pb(mp((i)*m+j+1,'R'));
            }
        }
    }
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> distTo(n*m,INT_MAX); 	 
	
	distTo[apos] = 0;
	pq.push(make_pair(0,apos));	
	vector<pair<int,char>> predecessor(n*m,mp(-1,-1));
	while( !pq.empty() ){
		int prev = pq.top().second;
		pq.pop();	
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			if( distTo[next] > distTo[prev] + 1){
				distTo[next] = distTo[prev] + 1;
                predecessor[next] = mp(prev,it->second);

				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
    pair<int,int> current = predecessor[bpos];
    if (current.first != -1){
        cout << "YES " << endl;
        cout << distTo[bpos] << endl;
        string res = "";
        while(current.first != apos){
            res+= current.second;
            current = predecessor[current.first];
        }
        res+=current.second;
        reverse(res.begin(),res.end());
        cout << res << endl;
    }
    else{
        cout << "NO" << endl;
    }



}

int main()
{
    fastio();
    solve();

    return 0;
}