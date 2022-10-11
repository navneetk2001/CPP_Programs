#include <bits/stdc++.h>
using namespace std;

int a[100005], tree[100005 * 4];     //globally declare array and segment tree


void build(int ind, int low, int high)
{
    if(low == high){               // Leaf node will have a single element :- Base Case
        tree[ind] = a[low];
        return;
    }
   
    int mid = (low + high)/2;

    build(2*ind+1, low, mid);        // Recurse on the left child
    build(2*ind+2, mid+1, high);      // Recurse on the right child

    tree[ind] = max(tree[2*ind+1], tree[2*ind+2]);        // Internal node will have the maximum of both of its children
}


int query(int ind, int low, int high, int l, int r){
	if(low >= l and high <= r){    //if l and r completely lies inside the range
		return tree[ind];
	}

	if(high < l || low >  r){      //if l and r doesnot completely lies inside the range
		return INT_MIN;
	}

	//In case l or r overlaps in the range
	int mid = (low + high)/2;
	int left = query(2*ind+1, low, mid, l, r);
	int right = query(2*ind+2, mid+1, high, l, r);
	return max(left, right);
}


//single update
//call from main as update(0, 0, n-1, node, val)
void pointUpdate(int ind, int low, int high, int node, int val){
	if(low == high){
		tree[low] += val;
	}
	else{
		int mid = (low+high)/2;
		if(node <= mid && node >= low){
			pointUpdate(2*ind+1, low, mid, node, val);
		}
		else{
			pointUpdate(2*ind+2, mid+1, high, node, val);
		}

		tree[ind] = tree[2*ind+1] + tree[2*ind+2];
	}
}


int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	build(0, 0, n-1);    //build a segment tree

	int q;               //no of queries
	cin>>q;

	while(q--){
		int l, r;
		cin>>l>>r;

		cout<<query(0, 0, n-1, l, r)<<endl;
	}
	cout<<endl;

	return 0;
}




//Lazy Propagation :-
void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}