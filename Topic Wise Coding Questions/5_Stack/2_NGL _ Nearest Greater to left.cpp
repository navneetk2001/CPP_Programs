// Problem
// In case of this problem, an array is given and we have to find first greater element to the left of current element. 
// Similalrly, find the greater elements for each element in the array and if greater element is not available then return a default value based on the problem.

// Nearest greatest element to left example :- 
// Example -
// Input: [4, 5, 2, 0]
// Output: [-1, -1, 5, 2]

// Input: [1, 6, 4, 10, 2, 5]
// Output: [-1, -1, 6, -1, 10, 10]





//Solution Approach :- 
class Solution{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> v;         // creating a vector for storing result 
        stack <long long> s;         // creating a stack for temp. hold the values from array
        
        for (int i=0;i<n;i++){ 
            if(s.size() ==0){       // when stack size is empty there is no element in stack return output as -1;
                v.push_back(-1);
            }
            else if (s.size()>0 && s.top()>arr[i]){  // when there is element in stack and stack top is greater then array element 
                v.push_back(s.top());                // take stack top in the result vector 
            }
            else if (s.size()>0 && s.top()<=arr[i]){    // when there is element in stack and that element is less then array element 
                while(s.size()>0 && s.top()<=arr[i]){   // upto when there is element and stack top is less then array's element delete the element from stack
                    s.pop();                            // delete the element from stack
                }
                if (s.size()==0){                   // when stack became empty return -1
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);                 // push array in stack
        }
        return v;
    }
};

  

// Time Complexity: O(N)
// Auxiliary Space: O(N)