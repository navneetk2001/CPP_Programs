https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1





//Solution :-
class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int,int>>q;
       	vector<int>v;
       	for(int i=0;i<n;i++){
           	int diff=abs(x-arr[i]);
           	if(diff!=0){
           		q.push({diff,-1*arr[i]});
           	}
           	if(q.size()>k){
	           	q.pop();
           	}
       }

       	while(!q.empty()){
           	v.push_back(-1*q.top().second);
           	q.pop();
       	}
       	reverse(v.begin(), v.end());
       	return v;
    }
};




//Solution Approach :-
static bool cmp(pair<int,int> a ,pair<int,int> b){
	if(a.first == b.first){
		return a.second > b.second;
	}
	else{
		return a.first < b.first;
	}
}
 
vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
	vector<pair<int,int>> v;
	for(int i=0;i<arr.size();i++){
	  	v.push_back({abs(arr[i] - x), arr[i]});
	}

	sort(v.begin(),v.end(),cmp);
	vector<int> ans;
	
	for(int i=0;k>0 && i<v.size();i++){
	  	if(v[i].second != x){
	  		k--;
	  		ans.push_back(v[i].second);
		}
	}
	return ans;
}




//Second Solution :-
vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
    vector<int> res;
    int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int i=idx-1;
    int j=idx + (arr[idx] == x);
        
    while(k--){
        int a = INT_MAX;
        int b = INT_MAX;
            
        if(i>=0) a = abs(x-arr[i]);
        if(j<n) b = abs(x-arr[j]);
            
        int mini = min(a, b);
        if(mini == b) res.push_back(arr[j++]);
        else res.push_back(arr[i--]);
    }
    return res;
}



//Third Solution :-
class Solution{   
public:
   	vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
		vector<int> res;
		vector< pair<int,int>> temp;

       	int j, l, diff;
       	for(int i=0;i<n;i++){
           	diff = abs(arr[i] - x);
           	if(diff != 0){
               	temp.push_back(make_pair(diff, i));
           	}
       	}
       
       	sort(temp.begin(), temp.end());
       
       	for(int i=0;i<k;i++){
           	j = temp[i].first;
           	l = temp[i].second;
           	if(temp[i].first == temp[i+1].first){
               	if(temp[i+1].second > temp[i].second){
                   	res.push_back(arr[temp[i+1].second]);
                   	if(res.size()<k){
                       	res.push_back(arr[temp[i].second]);
                   	}
               	}
               	i++;
           	}
           	else{
               	res.push_back(arr[l]);
           	}
       	}
       	return res;
   	}
};



//Fourth Solution :-
vector<int> printKClosest(vector<int> arr, int n, int k, int x) 
{
    auto y = upper_bound(arr.begin(),arr.end(),x);
    int index = y-arr.begin();
    int low = index - 1 ;
    while(low>=0 && x - arr[low] == 0)
        low--;
        
    while(index<n && x - arr[index] == 0)
        index++;
        
    vector<int> v ;
    while(k--)
    {
        if(low>=0 && index<n)
        {
            if(abs(arr[low]-x) < abs(arr[index]-x))
                v.push_back(arr[low--]);
                
            else
                v.push_back(arr[index++]);
                
                
        }
        else if( low >= 0 )
            v.push_back(arr[low--]);
            
        else if(index < n)
            v.push_back(arr[index++]);
            
            
    }
    return v;
}



//Fifth Solution :- (Not for gfg)
class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        priority_queue<pair<int,int>> pq;    //first->diff, second->element itself
        for(int i=0;i<n;i++){
            int diff = abs(arr[i]-x);
            if(diff==0){
                continue;
            }
            pq.push({diff,arr[i]});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};