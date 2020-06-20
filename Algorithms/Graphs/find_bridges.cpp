
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<int>> adj;
vector <int> low, tin;
vector <bool> used;
vector <pair<int,int>> bridges;
int timer = 0;

void dfs(int v, int p = -1){
	used[v] = true;
	tin[v] = low[v] = timer++;
	for(auto to : adj[v]){
		if(to == p) continue;
		if(used[to]){
			low[v] = min(low[v], low[to]);
		}
		else{
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] > tin[v]){
				bridges.pb({to, v});
			}
		}
	}
}

void find_bridges(){
	int n = adj.size();
	used.resize(n, false);
	tin.resize(n, -1);
	low.resize(n, -1);
	for(int i = 0 ; i < n ; i++){
		if(!used[i]) dfs(i);
	}
	cout << "Bridges\n";
	for(auto x : bridges){
		cout << x.first << " " << x.second << "\n";
	}
}
