//Problem: Count the numbers in the range from a to b, where the digit k occurs d times exactly

#include <bits/stdc++.h>
#define pb push_back
#define all(s) s.begin(),s.end()
using namespace std;


int dp[18][18][2];
vector <int> digits;
int k, d;

int go(int pos, int cnt, int f){
	if(cnt > d) return 0;
	if(pos == digits.size()){
		if(cnt == d) return 1;
		return 0;
	}
	int &ret = dp[pos][cnt][f];
	if(ret != -1) return ret;
	ret = 0;
	int hi = digits[pos];
	if(f) hi = 9;
	for(int i = 0 ; i <= hi ; i++){
		ret += go(pos+1, cnt + (i==k), f || (i<digits[pos]));
	}
	return ret;
}

int solve(int x){
	digits.clear();
	memset(dp, -1, sizeof(dp));
	while(x > 0){
		digits.pb(x%10);
		x /= 10;
	}
	reverse(all(digits));
	return go(0,0,0);
}

int main(){
	int a, b;
	cin >> a >> b >> k >> d;
	cout << solve(b) - solve(a-1);
}
