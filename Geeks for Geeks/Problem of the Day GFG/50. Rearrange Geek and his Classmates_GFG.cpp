Geek and his classmates are playing a prank on their Computer Science teacher. They change places every time the teacher turns to look at the blackboard. 
Each of the N students in the class can be identified by a unique roll number X and each desk has a number i associated with it. Only one student can sit on one desk. 
Each time the teacher turns her back, a student with roll number X sitting on desk number i gets up and takes the place of the student with roll number i.
If the current position of N students in the class is given to you in an array, such that i is the desk number and a[i] is the roll number of the student sitting on the desk, can you modify a[ ] to represent the next position of all the students ? 


Example 1:
Input:
N = 6
a[] = {0, 5, 1, 2, 4, 3}
Output: 0 3 5 1 4 2
Explanation: After reshuffling, the modified 
position of all the students would be {0, 3, 5, 1, 4, 2}.

Example 2:
Input:
N = 5
a[] = {4, 3, 2, 1, 0}
Output: 0 1 2 3 4 
Explanation: After reshuffling, the modified 
position of all the students would be {0, 1, 2, 3, 4}.



//T.C :- O(n) and S.C :- O(n)
class Solution {
  public:
    void prank(long long a[], int n){
        vector<int>v(a,a+n); //copy a in v
        for(int i=0;i<n;i++){
        	a[i]=v[a[i]];
        }
    }
};




//Optimised Approach :- We do,not need extra space so we will have to store two numbers in 
// one place in array at one time such that we can have both current no and no after reshuffling
// We will store it like :-  a[i]= a[i] + n * a[a[i]]
//We will get that new no. will be :- a[i]/6   and prev no as :- a[i]%6
class Solution {
  public:
    void prank(long long nums[], int n){
        for(int i=0;i<n;i++){
            nums[i] = nums[i] + n*(nums[nums[i]]%n);
        }
      
        for(int i=0;i<n;i++){
            nums[i] = nums[i]/n;
        }
    }
};


// This Problem uses the logic where 
// we can store two numbers in one joint number and extract those two numbers after
// j= a + b * n  ( n can be any number larger than both a and b)
// To get initial value of a we do a%nTo get the value of b we do a/n
// a = a + b * n = 3 + 2*5 = 13
// j% n = 13 % 5 = 3 = a
// j / n = 13 / 5 = 2 = b
// So we will use this technique to store two numbers in one location.
// for(int i=0;i<n;i++)
//     {
//         nums[i] = nums[i] + n*(nums[nums[i]]);
//     }
// but there is a problem what if the nums[nums[i]] is already a joint number (a+b*n) but we need the original value before any modification 
// so we need to extract the original value using j%n where j in joint number.
// so we will use this if number is not modified then there will be no effect since n is larger than every num else we get the original value before modification.


//Third Solution :-
void prank(long long a[], int n){
        // code here
        vector<int>v(n,0);
        unordered_map<long long,long long>umap;
        for(long long i=0;i<n;i++)
        {
           umap[a[i]]=i;
        }
        
        for(long long i=0;i<n;i++)
        {
            //swap(a[i],a[umap[i]]);
            v[umap[i]]=a[i];
            //swap(a[i],a[umap[i]]);
            
        }
        for(long long i=0;i<n;i++)
        {
            a[i]=v[i];
        }
        
        
    }