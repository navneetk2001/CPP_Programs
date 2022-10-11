https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#




//Solution Approach :-
class Solution{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left,right;    //one for smaller to left and other for smaller to right
        stack<pair<int,int>> s1,s2;
    
        int pseudo_index =-1;   //Nearest smaller to left
        for (int i=0;i<n;i++)
        {
            if(s1.size()==0){
                left.push_back(pseudo_index);
            }
            else if(s1.size()>0 && s1.top().first<arr[i]){
                left.push_back(s1.top().second);
            }
            else if(s1.size()>0 && s1.top().first>=arr[i]){
                while(s1.size()>0 && s1.top().first>=arr[i]){
                    s1.pop();
                }
                if (s1.size()==0){
                    left.push_back(pseudo_index);
                }
                else{
                    left.push_back(s1.top().second);
                }
            }
            s1.push({arr[i],i});
        }
    
        int pseudo_index1 = n;     //Nearest smaller to right
        for (int i=n-1;i>=0;i--)
        {
            if(s2.size()==0){
                right.push_back(pseudo_index1);
            }
            else if(s2.size()>0 && s2.top().first<arr[i]){
                right.push_back(s2.top().second);
            }
            else if (s2.size()>0 && s2.top().first >= arr[i]){
                while(s2.size()>0 && s2.top().first >= arr[i]){
                    s2.pop();
                }
                if (s2.size()==0){
                    right.push_back(pseudo_index1);
                }
                else{
                    right.push_back(s2.top().second);
                }
            }
            s2.push({arr[i],i});
        }
        reverse(right.begin(),right.end());    //reverse the obtained array
    
        long long ans=INT_MIN;         //calculate the Solution
        long long curr_ans;
        for(long long i=0;i<n;i++)
        {
            curr_ans = (long)(right[i]-left[i]-1)*arr[i];
            ans=max(ans,curr_ans); // taking max after finding area
        }
        return ans;
    }
};





//Second Solution :-
class Solution{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long histo[], int n)
    {
        stack<int> st;
        long long maxA=0;
        long long width=1;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
                long long height=histo[st.top()];
                st.pop();
                if(st.empty()){
                    width=i;
                }
                else{ 
                    width=i-st.top()-1;
                }
                maxA=max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};




//Third Solution :-
class Solution{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long A[], int n)
    {
        stack<int> st;
        long long res = 0;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && A[st.top()] >= A[i]){
                long long tp = st.top();
                st.pop();
              
                long long curr = A[tp] * (st.empty() ? i : (i - st.top() - 1));
                res = max(res, curr);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            long long tp = st.top();
            st.pop();
            
            long long curr = A[tp] * (st.empty() ? n : (n - st.top() - 1));
            res = max(res, curr);
        }
        return res;
    }
};