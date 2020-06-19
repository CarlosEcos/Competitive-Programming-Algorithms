#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;
typedef long long ll;

class Huffman{
	int minlength(vector <char> &v){
		int n = v.size();
		int freq[26];
		for(auto c : v){
			freq[c-'a']++;
		}
		multiset <int> s;
		int ans = 0, best1 = 0, best2 = 0;
		for(int i = 0 ; i < 26 ; i++) s.insert(freq[i]);
		while(s.size() > 1){
			best1 = *s.begin();
			s.erase(s.begin());
			best2 = *s.begin();
			s.erase(s.begin());
			s.insert(best1 + best2);
			ans += best1 + best2;
		}
		return ans;
	}
};
