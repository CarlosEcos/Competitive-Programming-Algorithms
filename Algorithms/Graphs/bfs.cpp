
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<int>> adj;
vector <int> d;

void bfs(int v){
	for(int i = 0 ; i < d.size() ; i++) d[i] = INF;
	queue <int> q;
	q.push(v);
	d[v] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(auto u : adj[v]){
			if(d[u] != INF) continue;
			d[u] = d[v] + 1;
			q.push(u);
		}
	}
	for(int i = 0 ; i < d.size() ; i++){
		cout << "Distance from " << v << " to " << i << " : " << d[i] << "\n";
	}
}


