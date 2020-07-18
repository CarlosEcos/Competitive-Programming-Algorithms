
#include <bits/stdc++.h>
#define fastio ios_base::sync_wiht_stdio(0);cin.tie(0);
#define pb push_back
#define all(s) s.begin(),s.end()
using namespace std;

vector<vector<int>> g;
vector <int> order;
vector <bool> used;

void dfs(int v){
	used[v] = true;
	for(auto u : g[v]){
		if(!used[u]){
			dfs(u);
		}
	}
	order.pb(v);
}

void top_sort(){
	used.resize(n, false);
	for(int i = 0 ; i < n ; i++){
		if(!used[i]) dfs(i);
	}
	reverse(all(order));
	cout << "Topological Sorting\n";
	for(auto x : order) cout << x << " ";
}

