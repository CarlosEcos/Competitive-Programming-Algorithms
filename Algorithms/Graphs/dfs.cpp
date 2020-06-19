
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;

vector <vector<int>> adj;
vector <bool> used;

void dfs(int v){
	if(used[v]) return;
	used[v] = true;
	for(auto u : adj[v]){
		dfs(u);
	}
}


