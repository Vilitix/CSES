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
    vector<vector<int>> g(n+1);
    for(int i =0;i<m;i++){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> distTo(n+1,INT_MAX); 	 
	
	distTo[1] = 0;
	pq.push(make_pair(0,1));	
	vector<int> predecessor(n+1,-1);
	while( !pq.empty() ){
		int prev = pq.top().second;
		pq.pop();	
		vector<int>::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
            int next = *it;
			if( distTo[next] > distTo[prev] + 1){
				distTo[next] = distTo[prev] + 1;
                predecessor[next] = prev;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
    int current = predecessor[n];
    if (current != -1){
        cout << distTo[n]+1 << endl;
        vector<int> res;
        while(current != 1){
            res.pb(current);
            current = predecessor[current];
        }
        cout << 1 << " ";
        for(int i = res.size()-1;i>=0;i--){
            cout << res[i] << " ";
        }
        cout << n << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }



}

int main()
{
    fastio();
    solve();

    return 0;
}