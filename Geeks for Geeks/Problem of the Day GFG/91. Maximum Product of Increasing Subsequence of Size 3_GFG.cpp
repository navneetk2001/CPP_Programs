Given a sequence of non-negative integers, find the subsequence of length 3 having maximum product, with the elements of the subsequence being in increasing order.

Example 1:
Input:
n = 8
arr[ ] = {6, 7, 8, 1, 2, 3, 9, 10}
Output: 8 9 10
Explanation: 3 increasing elements of 
the given arrays are 8,9 and 10 which forms the subsequence of size 3 with maximum product.

Example 2:
Input:
n = 4
arr[ ] = {3, 4, 2, 1} 
Output: Not Present



//Solution Approach :-

//if we take current element as middle element then its left element shoud be net smaller element and right shoud be as maximum as possible
// Maximum Product  =  next smaller element * current element * maximum element
class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        vector<int>ans{-1,-1,-1},mx;
        for(int i=0;i<n;i++){
        	mx.push_back(arr[i]);
        }

        for(int i=n-2;i>=0;i--){        //maximum element as possible in the right
        	mx[i]=max(mx[i],mx[i+1]);
        }

        set<int>s;
        for(int i=1;i<n-1;i++){
        	s.insert(arr[i]);
        	auto it=s.lower_bound(arr[i]);
        	if(it!=s.begin() && arr[i]<mx[i+1]){
        		it--;
        		long long int curr = 1ll*(*it)*arr[i]*mx[i+1];
        		long long int prev_pro = 1ll*ans[0]*ans[1]*ans[2];
        		if(prev_pro<curr){
        			ans={*it,arr[i],mx[i+1]};
        		}

        	}
        }

        return ans;
    } 

};








//Second Approach :- IT code seems to coorect and near to approach can anyone optimise    
vector<int> maxProductSubsequence(int *arr , int n) 
{ 
   queue<int>q;
   vector<int>res;
   int f=arr[0];
   for(int i=1;i<n;i++){
       if(f>arr[i])
       {
          q.push(arr[i]); 
          f=arr[i];
       }
   }
   
   //6 7 8 9 10
   while(q.size()!=3){
	   if(q.size()<3){
	       res.push_back(-1);
	   }
	   q.pop();
   }

   while(!q.empty()){
       res.push_back(q.front());
       q.pop();
   }
   return res;
} 



