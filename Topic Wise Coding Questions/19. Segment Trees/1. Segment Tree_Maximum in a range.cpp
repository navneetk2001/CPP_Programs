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
