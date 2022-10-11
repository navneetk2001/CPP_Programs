// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// Example 1:
// Input:
// N = 7, K = 4
// A[] = {1,2,1,3,4,2,3}
// Output: 3 4 4 3
// Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
// Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4. Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4. Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.

// Example 2:
// Input:
// N = 3, K = 2
// A[] = {4,1,1}
// Output: 2 1



//Solution Approach :- sliding window plus hashing
class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        vector<int> ans;                   //answer vector
        set<int> st;                       //to tell answer
        map<int,int> mp;                   //use to keep track whether to del element or not
        
        
        for(int i=0;i<k;i++){       //first window
        	mp[a[i]]++;             //increase freq count of elements
         	st.insert(a[i]);        //put in set so that only unique elements make a diff
        }
        ans.push_back(st.size());   //put answer for first window in the ans vector
        
        for(int i=k;i<n;i++){
            mp[a[i-k]]--;           //decrease freq of previous window element
            if(mp[a[i-k]]==0){      //that means it no longer is in our current window
                st.erase(a[i-k]);
                mp.erase(a[i-k]);   //erase it from map as well as set
            }
            mp[a[i]]++;                    //increase current element's frequency
            st.insert(a[i]);              //insert in set
            ans.push_back(st.size());     //push into answer
        }
         
        return ans; 
    }
};



//Second Solution :-
class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        map<int,int> mp;
        vector<int> v;
        int i=0,j=k-1;
       
        while(i<=j){
           mp[a[i]]++;
           i++;
        }
        
        i=0;
        while(j<n){
            v.push_back(mp.size());
            mp[a[i]]--;
            if(mp[a[i]]==0){
                mp.erase(a[i]);
            }
            i++;
            j++;
            mp[a[j]]++;
       }
       return v;
    }
};

