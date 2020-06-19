//Problem: Find the number in range from a to b, which has the maximum product of the digits

#include <bits/stdc++.h>
#define all(s) s.begin(),s.end()
#define pb push_back
using namespace std;
typedef long long ll;

struct node{
	ll pos, f1, f2, f3, nxt;
	node(){}
	node(ll _pos, ll _f1, ll _f2, ll _f3, ll _nxt){
		pos = _pos;
		f1 = _f1;
		f2 = _f2;
		f3 = _f3;
		nxt = _nxt;
	}
};

vector <int> da, db;
ll dp[20][2][2][2][10];
node pref[20][2][2][2][10];

ll go(int pos, int f1, int f2, int f3, int last){
	if(pos == db.size()) return f3;
	ll &ret = dp[pos][f1][f2][f3][last];
	if(ret != -1) return ret;
	int low = 0, hi = 9;
	if(!f1) low = da[pos];
	if(!f2) hi = db[pos];
	ll cur = -1, maxi = -1;
	for(int i = low ; i <= hi ; i++){
		int nf1 = f1, nf2 = f2, nf3 = f3;
		if(!f1 && i > low) nf1 = 1;
		if(!f2 && i < hi) nf2 = 1;
		if(i == 0 && !f3){
			cur =  go(pos+1, nf1, nf2, f3, 0);
			if(cur > maxi) pref[pos][f1][f2][f3][last] = node(pos+1, nf1, 1, 0, 0);
			maxi = max(maxi, cur);
		}
		if(!f3 && i > 0) nf3 = 1;
 		cur = i*go(pos+1, nf1, nf2, nf3, i);
 		if(cur > maxi) pref[pos][f1][f2][f3][last] = node(pos+1, nf1, nf2, nf3, i);
 		maxi = max(maxi, cur);
	}
 	return ret = maxi;
}

void printsol(int pos, int f1, int f2, int f3, int nxt){
	if(pos == da.size()) return;
	node p = pref[pos][f1][f2][f3][nxt];
	if(p.f3) cout << p.nxt;
	printsol(pos+1, p.f1, p.f2, p.f3, p.nxt);
}

int main() {
	memset(dp,-1,sizeof(dp));
	ll a, b;
	cin >> a >> b;
	while(b > 0){
		db.pb(b%10);
		b /= 10;
	}
	reverse(all(db));
	while(a > 0){
		da.pb(a%10);
		a /= 10;
	}
	while(da.size() < db.size()) da.pb(0);
	reverse(all(da));
	go(0,0,0,0,0);
	printsol(0,0,0,0,0);
	return 0;
}


