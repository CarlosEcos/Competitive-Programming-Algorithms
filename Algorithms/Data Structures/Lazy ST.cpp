
#include <bist/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int N = 1e6;
int tree[4*N], lazy[4*N], a[N];

int merge(int a, int b)//op a realizar

void build(int node, int start, int end){
	if(start == end){
		tree[node] = a[start];
		return;
	}
	int mid = (start+end)/2;
	build(2*v, start, mid);
	build(2*v+1, mid+1, end);
	tree[node] = merge(tree[2*node], tree[2*node+1]);
}

void push(int node, int start, int end){
	if(!lazy[node]) return;
	tree[node] += val;
	if(start != end){
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = 0;
	return;
}

void update(int node, int start, int end, int l, int r, int val){
	push(node,start,end);
	if(start > end || l > end || start > r) return;
	if(l <= start && end <= r){
		tree[node] += val;
		return;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, l, r, val);
	update(2*node+1, mid+1, end, l, r, val);
	tree[node] = merge(tree[2*node], tree[2*node+1]);
}

int query(int node, int start, int end, int l, int r){
	push(node, start, end);
	if(start > end || start > r || end < l) return 1e9;
	if(l <= start && end <= r) return tree[node];
	int mid = (start+end)/2;
	return merge(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
}

int main() {
	int n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	build(1,1,n);
	return 0;
}


