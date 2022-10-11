// You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < n and set the value of arr at index i to x.
// You may repeat this procedure as many times as needed.
// Return true if it is possible to construct the target array from arr, otherwise, return false.

// Example 1:
// Input: target = [9,3,5]
// Output: true
// Explanation: Start with arr = [1, 1, 1] 
// [1, 1, 1], sum = 3 choose index 1
// [1, 3, 1], sum = 5 choose index 2
// [1, 3, 5], sum = 9 choose index 0
// [9, 3, 5] Done

// Example 2:
// Input: target = [1,1,1,2]
// Output: false
// Explanation: Impossible to create target array from [1,1,1,1].

// Example 3:
// Input: target = [8,5]
// Output: true
 



//Solution Approach :- O(nlogn) Solution
//Now minus the sum from the top element to get the previous element. If multiple operations were done on same element we have to do this same operation multiple times. Insted we can just return pq.top() % sum.
class Solution {
public:
    bool isPossible(vector<int>& A) {
        long total = 0;
        int n = A.size(), a;
        priority_queue<int> pq(A.begin(), A.end());

        for(int a : A){
            total += a;
        }

        while(true){
            a = pq.top(); 
            pq.pop();
            total -= a;
            if(a == 1 || total == 1){
                return true;
            }
            if(a < total || total == 0 || a % total == 0){
                return false;
            }
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};



//Second Solution :- 
//As we can see from the complexity analysis above, we perform no more than 44 operations. So, instead puting the input array into the heap, which takes O(n log n), we can do up to 44 linear scans to find the next maximum element.

bool isPossible(vector<int>& t) {
    auto s = accumulate(begin(t), end(t), (long long)0);
    auto i = max_element(begin(t), end(t)) - begin(t);
    while (s > 1 && t[i] > s / 2) {
        s -= t[i];
        if (s <= 1){
            return s;
        }
        t[i] = t[i] % s;
        s += t[i];
        i = max_element(begin(t), end(t)) - begin(t);
    }
    return s == t.size();
}



//Third Solution :-
// At first declare a priority queue (pq) to store all elements of target in decreasing order.
// Insert elements in pq and also calculate their sum.
// Iterate in loop and do operations untill all elements in pq becomes 1 (So we can only check if pq.top() is 1 or not).
// In loop exclude the top element from sum to get the remaining sum. Then find old element by deleting remaining sum from top elelmet as many times as possible (can be done by pq.top() % sum). Then delete the top elelment and add old element to the pq and also add it to sum to update it.
// In the middle check for the conditions which will indicate that all premetive elements were not 1.
// if(sum == 0 || sum >= pq.top()) return false;
// if(target.size() != 2 && old == 0) return false; or if(sum != 1 && old == 0) return false;
// Return true if the top element becomes 1. As we are not adding any element less than 1 so this gives correct result.

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;        //Priority queue for storing all the nums in taget in decreasing order.
        long long sum = 0; //for storing total sum

        for(auto num : target){ //adding the nums in pq and sum
            pq.push(num);
            sum+=num;
        }
        
        //iterating untill all elements in pq become 1 (in turn pq.top() will also become 1);
        while(pq.top() != 1){
            sum -= pq.top(); //removing the greatest element as it was last upadted when converting [1,1,1...] array to target. So we are left with sum of other elements.
            
            //when there are elements greeter than 1 then sum of other elements can not be 0 or sum can not be greater than top element because sum + x(any number>0) is pq.top().
            if(sum == 0 || sum >= pq.top()) return false;
            
            //if we delete all copies of sum from pq.top() we get an old element.
            int old = pq.top() % sum;    //Now minus the sum from the top element to get the previous element. If multiple operations were done on same element we have to do this same operation multiple times. Insted we can just return pq.top() % sum.
            
            //all old elements were > 0 so it can not be 0 unless sum is 1 (This is only possible if array has only 2 elements)
            if(sum != 1 && old == 0) return false;
            
            pq.pop();     //Deleting greatest element

            pq.push(old); //Adding old element to restore array.
            sum += old;   //Updating sum
        }
        
        //if all elements are 1 then return true
        return true;
    }
};