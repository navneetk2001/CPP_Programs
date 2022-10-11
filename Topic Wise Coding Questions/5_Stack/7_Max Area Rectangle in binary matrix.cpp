https://leetcode.com/problems/maximal-rectangle/



//Solution Approach :-
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> left,right;
        stack<pair<int,int>> s1,s2;
        
        int pseudo_index =-1;       //nearest smaller to left
       
        for (int i=0;i<n;i++){
            if (s1.size()==0){
                left.push_back(pseudo_index);
            }
            else if (s1.size()>0 && s1.top().first<heights[i]){
                left.push_back(s1.top().second);
            }
            else if (s1.size()>0 && s1.top().first>=heights[i]){
                while(s1.size()>0 && s1.top().first>=heights[i]){
                    s1.pop();
                }
                if (s1.size()==0){
                    left.push_back(pseudo_index);
                }
                else{
                    left.push_back(s1.top().second);
                }
            }
            s1.push({heights[i],i});
        }
        
        int pseudo_index1 = n;   //Nearest smaller to right
        for (int i=n-1;i>=0;i--){
            if (s2.size()==0){
                right.push_back(pseudo_index1);
            }
            else if (s2.size()>0 && s2.top().first<heights[i]){
                right.push_back(s2.top().second);
            }
            else if (s2.size()>0 && s2.top().first >= heights[i]){
                while(s2.size()>0 && s2.top().first >= heights[i]){
                    s2.pop();
                }
                if (s2.size()==0){
                    right.push_back(pseudo_index1);
                }
                else{
                    right.push_back(s2.top().second);
                }
            }
            s2.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
        int m=INT_MIN;
        for (long long i=0;i<n;i++){
            m=max(m,(right[i]-left[i]-1)*heights[i]);// taking max after finding area
        }
        return m;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    histogram[j]+=1;
                }
                else{
                    histogram[j]=0;
                }
            }
            result = max(result, largestRectangleArea(histogram));
            //cout<<result<<" ";
        }
        return result;
    }
};



//Second Solution :- GFG Accepted
class Solution{
  public:
    int findarea(vector<int> &arr){
        int n = arr.size();
        vector<long long> left(n),right(n);
        stack<long long> stk;
        
        for(int i=0;i<n;i++){
            while(!stk.empty() and arr[i]<=arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                left[i]=0;
            }
            else{
                left[i]=stk.top()+1;
            }
            stk.push(i);
        }
    
        while(!stk.empty()){
            stk.pop();
        }
    
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() and arr[i]<=arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                right[i]=n-1;
            }
            else{
                right[i]=stk.top()-1;
            }
            stk.push(i);
        }
    
        long long maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, (right[i]-left[i]+1)*arr[i]);
        }
    
        return maxi;
    }
       
       
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v;
        for(int i=0;i<m;i++){
            v.push_back(M[0][i]);
        }
    
        int maxm = INT_MIN;
        maxm = max(maxm,findarea(v));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] == 0){
                    v[j] = 0;
                }
                else{
                    v[j] = v[j] + M[i][j];
                }
            }
            maxm = max(maxm, findarea(v));
        }
        return maxm;
    }
};




//Third Solution :-
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()){
        return 0;
    }
    int maxRec = 0;
    vector<int> height(matrix[0].size(), 0);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == '0'){
                height[j] = 0;
            }
            else{
                height[j]++;
            }
        }
        maxRec = max(maxRec, largestRectangleArea(height));
    }
    return maxRec;
}

int largestRectangleArea(vector<int> &height) {
    stack<int> s;
    height.push_back(0);
    int maxSize = 0;
    for(int i = 0; i < height.size(); i++){
        if(s.empty() || height[i] >= height[s.top()]){
            s.push(i);
        }
        else{
            int temp = height[s.top()];
            s.pop();
            maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
            i--;
        }
    }
    return maxSize;
}