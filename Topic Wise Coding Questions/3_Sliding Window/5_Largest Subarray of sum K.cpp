https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1




//Solution Approach :-
class Solution{
public:
    int lenOfLongSubarr(int a[],  int n, int k) { 
       	map<int,int> m;
    	m[0] = -1;
    	int sum=0, ans=0;
    	
    	for(int i=0;i<n;i++){
           	sum+=a[i];
           	if(m.find(sum-k) != m.end()){
               	int idx = m[sum-k];
               	ans = max(ans,i-idx);
           	}
           	if(m.find(sum)==m.end()){
           		m[sum]=i;
           	}
       	}
       	return ans;
    }  
};



//Second Solution :-
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int ln=0,sum=0;
    map<int,int> m;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        if(sum==K){
        	ln=max(i+1,ln);
        }
        if(m.find(sum)==m.end()){
        	m[sum]=i;
        }
        if(m.find(sum-K)!=m.end()){
        	ln=max(ln,i-m[sum-K]);
        }
    }
    return ln;

}