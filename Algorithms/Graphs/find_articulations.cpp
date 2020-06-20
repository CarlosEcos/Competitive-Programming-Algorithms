
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<int>> adj;
vector <bool> used;
vector <int> tin, low;
set <int> articulations;
int timer = 0;

void dfs(int v, int p = -1){
	used[v] = true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for(auto to : adj[v]){
		if(to == p) continue;
		if(used[to]){
			low[v] = min(low[v], low[to]);
		}
		else{
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(low[to] >= tin[v] && p!=-1){
				articulations.insert(v);
			}
			++children;
		}
	}
	if(p==-1 && children > 1){
		articulations.insert(v);
	}
}

void find_cutpoints(){
	int n = adj.size();
	used.resize(n, false);
	tin.resize(n, -1);
	low.resize(n, -1);
	for(int i = 0 ; i < n ; i++){
		if(!used[i]){
			dfs(i);
		}
	}
	cout << "Articulations points\n";
	for(auto x : articulations){
		cout << x << " ";
	}
}




