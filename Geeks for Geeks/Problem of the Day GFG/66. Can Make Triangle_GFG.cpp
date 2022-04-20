// Given an array A[] of N elements, You'd like to know how many triangles can be formed with side lengths equal to adjacent elements from A[].
// Construct an array of integers of length N - 2 where ith element is equal to 1 if it is possible to form a triangle with side lengths A[i], A[i+1], and A[i+2]. otherwise 0.
// Note: A triangle can be formed with side lengths a, b and c if a+b>c and a+c>b and b+c>a.

// Example 1:
// Input:
// N = 4
// A[] = {1, 2, 2, 4}
// Output:
// 1 0
// Explanation:output[0] = 1 because we can form a triangle with side lengths 1,2 and 2.
// output[1] = 0 because 2+2<4 so, we cannot form a triangle with side lengths 2,2 and 4.

// Example 2:
// Input: 
// N = 5
// A[] = {2, 10, 2, 10, 2}
// Output:
// 0 1 0
// Explanation: output[0] = 0 because 2+2<10 so, we cannot form a triangle with side lengths 2, 10 and 2. output[1] = 1 we can form a triangle with 
// side lengths 10,2 and 10. output[1] = 0 because 2+2<10 so, we canform a triangle with side lengths 2, 10 and 2.


//First Solution :- Sliding Window
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int n){
        int i=0,j=0;
        int k=3;
        vector<int>ans;
        
        while(j<n){
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                int a=arr[j];
                int b=arr[j-1];
                int c=arr[j-2];
                if((a+b>c)and (a+c>b) and (b+c>a)){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
}; 


//Second Solution :- 
bool check(int a,int b,int c){
   if(a+b>c && b+c>a && a+c>b)
       return true;
   else return false;
}

vector<int> canMakeTriangle(vector<int> A, int N){
   // code here
   vector<int>ans;
   for(int i=0;i<A.size()-2;i++){
       if(check(A[i],A[i+1],A[i+2])){
           ans.push_back(1);
       }
       else ans.push_back(0);
   }
   return ans;
}