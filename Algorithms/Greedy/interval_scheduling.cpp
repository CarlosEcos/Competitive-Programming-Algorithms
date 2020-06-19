#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> x, pair<int,int> y){
	if(x.second != y.second) return x.second < y.second;
	return x.first < y.first;
}

void interval_scheduling(vector<pair<int,int>> &L){
	sort(all(L), cmp);
	int ans = 0;
	int n = L.size(), cur = -1;
	for(int i = 0 ; i < n ; i++){
		if(cur < L[i].first){
			ans++;
			cur = L[i].second;
		}
	}
	cout << "Maximum number of disjoints sets :" << ans << "\n";
}
