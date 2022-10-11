// Given an array Arr of size N containing positive integers. Count number of smaller elements on right side of each array.

// Example 1:
// Input: N = 7
// Arr[] = {12, 1, 2, 3, 0, 11, 4}
// Output: 6 1 1 1 0 1 0
// Explanation: There are 6 elements right after 12. There are 1 element right after 1. And so on.

// Example 2:
// Input:
// N = 5
// Arr[] = {1, 2, 3, 4, 5}
// Output: 0 0 0 0 0
// Explanation: There are 0 elements right after 1. There are 0 elements right after 2. And so on.





//Solution Approach :-
vector<int> constructLowerArray(int *arr, int n) {
	vector<int> newArr;
	vector<int> ans;
	for(int i=n-1;i>=0;i--){
	  	auto itr=lower_bound(newArr.begin(),newArr.end(),arr[i]);
	  	if(itr == newArr.end()){
	     	ans.push_back(newArr.size());
	     	newArr.push_back(arr[i]);
	  	}
	  	else {
	      	int pos=itr-newArr.begin();
	      	ans.push_back(pos);
	      	newArr.insert(newArr.begin()+ pos,arr[i]);
	  	}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}




//Second Solution :- Merge Sort Solution
void merge(vector<pair<int,int>> &v, vector<int> &ans, int left, int mid, int right){
    int i=left, j=mid+1, k=0;
    vector<pair<int,int>> temp(right-left+1);

    // sorting in descending order
    while(i<=mid && j<=right){
        if(v[i].first > v[j].first){
            ans[v[i].second] += (right-j+1);
            temp[k++] = v[i++];
        }
        else{
            temp[k++]=v[j++];
        }
    }
    while(i<=mid){
        temp[k++]=v[i++];
    }
    while(j<=right){
        temp[k++]=v[j++];
    }
    k=0;
    for(i=left;i<=right;i++){
        v[i]=temp[k++];
    }
}

void mergeSort(vector<pair<int,int>> &v, vector<int> &ans, int left, int right){
    if(left < right){
        int mid = left+(right-left)/2;
        mergeSort(v,ans,left,mid);
        mergeSort(v,ans,mid+1,right);
        merge(v,ans,left,mid,right);
    }
}

vector<int> constructLowerArray(int *arr, int n) {
    vector<int> ans(n,0);
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }

    mergeSort(v,ans,0,n-1);
    return ans;
} 




//Third Solution :- solution using segment tree + coordinate compression :-
class Solution{
    int query(int si , int ss , int se , int qs , int qe , int st[]){
        if(ss > qe || qs > se)
        return 0;
        if(ss >= qs && se <= qe)
        return st[si];
        int mid = (ss + se) / 2;
        return query(2 * si + 1 , ss , mid , qs , qe , st) + query(2 * si + 2 , mid + 1 , se , qs , qe , st);
    }
    void update(int si , int ss , int se , int qi , int st[]){
        if(ss == se){
            st[si]++;
            return ;
        }
        int mid = (ss + se) / 2;
        if(qi <= mid)
        update(2 * si + 1 , ss , mid , qi , st);
        else
        update(2 * si + 2 , mid + 1 , se , qi , st);
        st[si] = st[2 * si + 1] + st[2 * si + 2];
    }
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    pair<int,int>p[n];
	    for(int i = 0 ; i < n ; i++){
	        p[i] = {arr[i] , i};
	    }

	    sort(p , p + n);
	    vector<int> res(n , 0);
	    int prev = -1 , cnt = -1;
	    for(int i = 0 ; i < n ; i++){
	        if(p[i].first != prev)
	        cnt++;
	        arr[p[i].second] = cnt;
	    }
	    int st[4 * n] ;
	    memset(st , 0 , sizeof(st));
	    for(int i = n - 1 ; i >= 0 ; i--){
	        res[i] = query(0 , 0 , n  - 1, 0 , arr[i] - 1 , st);
	        update(0 , 0 , n  - 1, arr[i] , st);
	    }
	    return res;
	}
};



//Fourth Solution :-
//I used Policy Based Data Structure, refer to this for idea.  Although the ones available online are of Set, and not Multi_set ( which we require ), so with little digging around, I found out that changing less<int> to less_equal<int> makes it a multi set XD. 
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
	vector<int> constructLowerArray(int *arr, int n) {
	    ordered_set s ;
	    vector<int> ans(n) ;
	    for(int i=n-1 ; i>=0 ; i--){
	        ans[i] = s.order_of_key(arr[i]) ;
	        s.insert(arr[i]) ;
	    }
	    return ans ;
	}
};



//Fifth Solution :-
//using Binary Indexed Tree (can also be solved with Segment Tree). Logic similar to Inversion Count (Hence can also be solved by making slight modifications to Merge function in Merge Sort). 
class Solution{
    int *bit;
    void update(int in,int n){
        for(int i=in;i<=n;i+=(i&-i)){
            bit[i]++;
        }
    }
    int query(int in){
        int ans=0;
        for(int i=in;i>0;i-=(i&-i)){
            ans+=bit[i];
        }
        return ans;
    }
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    bit = new int[n+1];
	    pair<int,int> a[n];
	    for(int i=0;i<n;i++){
	        a[i]={arr[i],i},bit[i+1]=0;
	    }
	    sort(a,a+n);
	    vector<int> ans(n);
	    for(int i=0;i<n;i++){
	        ans[a[i].second]=query(n)-query(a[i].second+1);
	        update(a[i].second+1,n);
	    }
	    return ans;
	}
};




//Sixth Solution :- LeetCode 
class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int,int>> temp(right - left + 1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
            }
        }
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j<=right){
            temp[k++] = v[j++];
        }
        
        for(int i=left;i<=right;i++){
            v[i] = temp[i-left]; 
        }
        
    }
    
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
    }
};