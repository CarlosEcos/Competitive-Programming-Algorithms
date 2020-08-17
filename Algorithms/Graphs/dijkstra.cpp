
#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
#define INF 1e9
using namespace std;

vector <vector<pair<int,int>>> adj;
vector <int> d;
vector <bool> used;

void dijkstra(int v){
	int n = adj.size();
	used.resize(n, false);
	d.resize(n, INF);
	priority_queue<pair<int,int>> pq;
	d[v] = 0;
	pq.push({0, v});
	while(!pq.empty()){
		int a = pq.top().second;
		pq.pop();
		if(used[a]) continue;
		used[a] = true;
		for(auto u : adj[a]){
			if(d[a] + u.second < d[u.first]){
				d[u.first] = d[a] + u.second;
				pq.push({-d[u.first], u.first});
			}
		}
	}
}



