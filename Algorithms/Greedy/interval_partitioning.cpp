#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> x, pair<int,int> y){
	if(x.second != y.second) return x.second < y.second;
	return x.first < y.first;
}

void interval_partitioning(vector<pair<int,int>> &L){
	sort(all(L));
	multiset <int> s;
	int ans = 0, n = L.size();
	s.insert(L[0].second);
	for(int i = 0 ; i < n ; i++){
		auto it = s.lower_bound(L[i].first);
		if(it == s.begin()){
			s.insert(L[i].second);
			continue;
		}
		it--;
		int rb = *it;
		s.erase(rb);
		s.insert(L[i].second);
	}
	cout << "Minimum number of disjoints sets : " << s.size() << "\n";
}
