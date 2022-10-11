// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.




//Solution Approach :-
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);    //to store candies of each child, initially each has 1 candies
        if(n == 1){    //edge case
            return 1;
        }
        
        //from left to right, comparing i and i-1
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        //from right to left, comparing i and i+1
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1] + 1;
            }
        }
        
        
        int totalCandies = 0;      //total no of candies
        for(int i = 0; i < n; i++){
            totalCandies += candies[i];
        }
        
        return totalCandies;
        
    }
};



//Second Solution :- Used greedy aproach
// 1. every student should get atleast one so initially give 1 candy to every student
// 2. Now traverse left to right, whenever we get a higher rating, it should get more candy from its neighbour( left neighbour in the curr case) so give just one more candy than its left neighbour
// 3. Now another case left when its right neighbour has higher rating, traverse from right, and if we get a higher rating, give it max(curr, 1+candy of its right). max ensures that for local maxima candies shuld be high than both neighbours;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
        if(size<=1){
            return size;
        }

        vector<int>num(size,1);
        for(int i=1; i<size; i++){
            if(ratings[i]>ratings[i-1]){
                num[i]=num[i-1]+1;
            }
        }

        for(int i=size-1; i>0 ;i--){
            if(ratings[i-1]>ratings[i]){
                num[i-1]=max(num[i]+1,num[i-1]);
            }
        }

        int result=0;
        for(int i = 0; i < size; i++){
            result+=num[i];
        }
        return result;
    }
};




//Third Solution :-
class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        
        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i - 1]){
            	l[i] = l[i - 1] + 1;
            }
        }
        for (int i = n - 2; i>=0; i--){
            if (nums[i] > nums[i + 1]){
            	r[i] = r[i + 1] + 1;
            }
        }
        
        
        int res = 0;
        for (int i =0;i<n;i++){
            res+= max(l[i], r[i]);
        }
        return res;
    }
};