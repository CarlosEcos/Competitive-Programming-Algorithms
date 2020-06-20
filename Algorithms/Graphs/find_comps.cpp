
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<int>> adj;
vector <bool> used;
vector <int> comp;

void dfs(int v){
	if(used[v]) return;
	used[v] = true;
	comp.pb(v);
	for(auto u : adj[v]){
		dfs(u);
	}
}

void find_comps(){
	int n = adj.size();
	used.resize(n, false);
	for(int i = 0 ; i < n ; i++){
		if(!used[i]){
			comp.clear();
			dfs(i);
			cout << "Component : ";
			for(auto x : comp) cout << x << " ";
			cout << "\n";
		}
	}
}


