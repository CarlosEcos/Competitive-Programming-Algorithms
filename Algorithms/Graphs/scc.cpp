
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<int>> adj, adjr;
vector <int> order, comp;
vector <bool> used;

void dfs1(int v){
	if(used[v]) return;
	used[v] = true;
	for(auto u : adj[v]){
		dfs1(u);
	}
	order.pb(v);
}

void dfs2(int v){
	if(used[v]) return;
	used[v] = true;
	comp.pb(v);
	for(auto u : adjr[v]){
		dfs2(u);
	}
}

void scc(){
	int n, m;
	cin >> n >> m;
	adj.resize(n);
	adjr.resize(n);
	for(int i = 0 , a, b; i < m ; i++){
		cin >> a >> b;
		adj[--a].pb(--b);
		adjr[b].pb(a);
	}
	used.resize(n, false);
	for(int i = 0 ; i < n ; i++){
		if(!used[i]){
			dfs1(i);
		}
	}
	for(int i = 0 ; i < n ; i++){
		used[i] = false;
	}
	for(int i = n-1 ; i >= 0 ; i--){
		if(!used[order[i]]){
			comp.clear();
			dfs2(order[i]);
			for(auto x : comp){
				cout << x << " ";
			}
			cout << "\n";
		}
	}
}


