// Given an equation of the form f(n) = f(n-1) + f(n-2) where f(0) = 1, F(1) = 1 , the task is to find the nth term of this sequence.
 
// Example 1:
// Input: n = 3
// Output: 3
// Explanation: f(3) = f(2) + f(1) = 3

// Example 2:
// Input: n = 2
// Output: 2
// Explanation: f(2) = f(1) + f(0) = 2



//Solution Approach :- O(log N)
class Solution {
public:
	long long int mod = 1e9+7;
    vector<vector<long long int>> multiply(vector<vector<long long int>> mat1, vector<vector<long long int>> mat2){
		
		vector<vector<long long int>> ans(2, vector<long long int>(2, 0));
		
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					ans[i][j] += mat1[i][k] * mat2[k][j] % mod;
				}
			}
		}
		return ans;
	}

	vector<vector<long long int>> f(vector<vector<long long int>> a, long long int n){
		if(n==1){       //Base Case
			return a;
		}
		vector<vector<long long int>> temp = f(a,n/2);
		if(n%2==0){
			return multiply(temp,temp);
		}
		else{
			return multiply(temp, multiply(temp,a));
		}
	}

    int FindNthTerm(long long int n) {
        vector<vector<long long int>> a = {{1, 1}, {1, 0}};
        vector<vector<long long int>> ans = f(a,n);

        return (int)ans[0][0] % mod;
    }
};