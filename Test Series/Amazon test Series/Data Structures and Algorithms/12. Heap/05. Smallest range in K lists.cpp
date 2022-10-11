// Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

// Example 1:
// Input:
// N = 5, K = 3
// KSortedArray[][] = {{1 3 5 7 9},
//                     {0 2 4 6 8},
//                     {2 3 5 7 11}}
// Output: 1 2
// Explanation: K = 3
// A:[1 3 5 7 9]
// B:[0 2 4 6 8]
// C:[2 3 5 7 11]
// Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.

// Example 2:
// Input:
// N = 4, K = 3
// KSortedArray[][] = {{1 2 3 4},
//                     {5 6 7 8},
//                     {9 10 11 12}}
// Output: 4 9



//Solution Approach :-
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int i,minelem=INT_MAX,maxelem=INT_MIN,ans=INT_MAX,mini,maxi;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(i=0;i<k;i++){
            pq.push({arr[i][0],{i,0}});
            maxelem=max(maxelem,arr[i][0]);
        }

        while(1)
        {
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            minelem=p.first;
            
            if((maxelem-minelem)<ans){
                ans=maxelem-minelem;
                mini=minelem;
                maxi=maxelem;
            }
            if(p.second.second+1<n){
                maxelem=max(maxelem, arr[p.second.first][p.second.second+1]);
                pq.push({arr[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
            }
            else{    //if fully traversed
        	    break;
            }
        }
        return {mini,maxi};
    }
};



//Second Solution :-
pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k){
    set<pair<int,pair<int,int>>> s;
       
    for(int i = 0; i < k; i++){
        s.insert({KSortedArray[i][0],{i,0}});
    }
       
    pair<int,int> range = {0,100000};
    int minDiff = INT_MAX;

    while(true){
        auto p1 = *s.rbegin();   // max
        auto p2 = *s.begin();    // min
           
        int row = p2.second.first, col = p2.second.second;
           
        int currDiff = p1.first - p2.first;
        if(currDiff < minDiff){
            minDiff = currDiff;
            range = {p2.first,p1.first};
        }
        col++;
        if(col == n) break;
           
        s.erase(p2);
           
        int new_ele = KSortedArray[row][col];
        s.insert({new_ele,{row,col}});
    }
    return (range);
}



//Third Solution :-
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int a=0,b=INT_MAX;
        int sokth[k]={0};
         
        multiset<pair<int,int> > mst;
        for(int i=0;i<k;i++)
            mst.insert({arr[i][0], i});
         
        for(int i=0;i<n*k;i++){
            pair<int,int> front=*mst.begin(), back=*mst.rbegin();
            if(abs(back.first-front.first)<abs(b-a)){
                 a=front.first; b=back.first;
            }
            mst.erase(mst.begin());
            sokth[front.second]++;
            if(sokth[front.second]==n) break;
            mst.insert({arr[front.second][sokth[front.second]], front.second});
        }
        return {a,b};
    }
};



//Fourth Solution :- // approach is--
// we have to make a pririty queue to store the index, row_number and element also.
// travese the lists and keep on finding the min and max difference .if range of previous difference is greater than current min max difference ,update range.

#define p pair<int,pair<int,int>>
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<p,vector<p>,greater<p>> q;
    int mn=INT_MAX,mx=INT_MIN, range=INT_MAX;
    int low=0,high=0;
    
    for(int i=0;i<k;i++){
        q.push({arr[i][0],{i,0}});
        mn=min(arr[i][0],mn);
        mx=max(arr[i][0],mx);
    }
    
    while(true){
        p temp=q.top();
        q.pop();
        
       	int min1=temp.first;
       
        if(range >mx-min1){
            mn=min1;
            low=mn;
            high=mx;
            range=mx-mn;
            
        }

      	int i=temp.second.first;   //array number
      	int j=temp.second.second;  // index
      
      	if(j==n-1){    //if fully traversed
      		break;
      	}
      
      	q.push({arr[i][j+1],{i,j+1}});
      
      	if(mx <arr[i][j+1]){
          	mx=arr[i][j+1];
        }

    }
    return {low,high};
}
