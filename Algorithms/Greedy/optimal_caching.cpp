#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;
typedef long long ll;

class OptimalCaching{
	int Futher_in_the_Future(vector<int> &task, int m){
		int n = task.size();
		vector <int> last(n), pref(n), nxt(n);
		vector <bool> used(n);
		for(int i = n-1 ; i >= 0 ; i--){
			nxt[i] = last[task[i]];
			last[task[i]] = i;
			pref[nxt[i]] = i;
		}
		set<pair<int,int>> s;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(used[task[i]]){
				s.erase({i, pref[i]});
				s.insert({nxt[i], i});
			}
			else if(s.size() < m){
				s.insert({nxt[i], i});
				used[task[i]] = true;
			}
			else{
				auto it = s.end(); it--;
				pair<int,int> p = *it;
				s.erase(p);
				used[task[p.second]] = false;
				s.insert({nxt[i], i});
				used[task[i]] = true;
				ans++;
			}
		}
		return ans;
	}
};
