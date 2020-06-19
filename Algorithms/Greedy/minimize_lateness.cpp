#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;

#define deadline first
#define timer second


void minimize_lateness(vector<pair<int,int>> &L){
	sort(all(L));
	int total = 0, ans = 0, n = L.size();
	for(int i = 0 ; i < n ; i++){
		total += L[i].timer;
		ans = max(ans , total - L[i].deadline);
	}
	cout << ans << "\n";
}

