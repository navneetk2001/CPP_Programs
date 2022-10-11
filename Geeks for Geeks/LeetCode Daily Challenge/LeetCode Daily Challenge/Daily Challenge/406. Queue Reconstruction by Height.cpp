// You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
// Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue). 

// Example 1:
// Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
// Explanation:
// Person 0 has height 5 with no other people taller or the same height in front.
// Person 1 has height 7 with no other people taller or the same height in front.
// Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
// Person 3 has height 6 with one person taller or the same height in front, which is person 1.
// Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
// Person 5 has height 7 with one person taller or the same height in front, which is person 1.
// Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

// Example 2:
// Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
// Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]




//Solution Approach :-
// Intuition :
// Sort the array in decreasing order of their heights and if two people have same height, sort them in increasing order of their [1] index. (We used compare function for this)
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]] => [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
// Now we constructed an array res which will have elements in order of sorted array at indexes based on the index of their [1] position.

// Now insert the elements according to the order in res
// [[7,0]] (insert [7,0] at index 0)
// [[7,0],[7,1]] (insert [7,1] at index 1)
// [[7,0],[6,1],[7,1]] (insert [6,1] at index 1)
// [[5,0],[7,0],[6,1],[7,1]] (insert [5,0] at index 0)
// [[5,0],[7,0],[5,2],[6,1],[7,1]] (insert [5,2] at index 2)
// [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] (insert [4,4] at index 4)
// Time Complexity : O(N * N)
// Space Complexity : O(N)

class Solution {
public:
    //Compare function for the logic of sort 
    static bool compare(vector<int>& a, vector<int> & b){
        if(a[0] == b[0]){         //if heights equal, then sort the second value on basis of ascending order
            return a[1] < b[1];
        }
        return a[0] > b[0];     //else sort in descending order
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){   
        int n = people.size();
        sort(people.begin(), people.end(), compare); //Sort the array acc. to comp function.
        vector<vector<int>> res;                     //To store the final array to be returned
        
        for(int i = 0; i < n; i++){
            int idx = people[i][1];
            res.insert(res.begin() + idx, people[i]); //Inserting the element at desired position.
        }
        return res;
    }
};



//Solution 2 :-
// We put people in an array of length n. The number k means that we should put this person in the kth empty position from the beginning. The empty position mean that there will be higher or equal height person coming in here, so leave these positions out first. For everyone, we should first insert the lower h person. For the person who has same h we should first insert the person has larger k value. For everyone to put in, it takes O(n) time to find kth empty position, so it will take the O(n^2) time for all people.
// E.g.
// input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// sort: [[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]]
// step1: [[  ,  ], [  ,  ], [  ,  ], [  ,  ], [4,4], [  ,  ]]
// step2: [[  ,  ], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
// step3: [[5,0], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
// step4: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [  ,  ]]
// step5: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [7,1]]
// step6: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++){
            int cnt, j;
            for(cnt = 0, j = 0; j < res.size(); j++){ //empty count start from 0
                if(res[j].empty()){
                    if(cnt==people[i][1]) break;
                    cnt++;
                }
            }
            res[j]=people[i];
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};




//Solution 3:
// This method is an optimization of method 2. In solution 2, it takes O(n) time to find kth empty position for everyone. If you can find the kth empty position using the binary search method, it will save a lot of time. To use a binary search, you need to have a data structure to record the current position is the nth empty positions. The easiest thing to think about is an array, but each time you put in a person, you need to update the empty count value after this position in the array. It's still takes O(n) time. If we use the binary index tree, we can get the nth information with the complexity of O(logn), and we can use the O(logn) complexity to update the subsequent position.

class Solution {
public:
    vector<int> BIT;
    int n;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int>(n+1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
        for(int i = 2; i <= n; i++) update(i, 1);  // BIT[1] is the 0th empty position, so we didn't add 1
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n, vector<int>());
        for(int i = 0; i < n; i++){
            int l=0, r=n;
            while(l<r){
                int mid=l+(r-l)/2;
                if(getsum(mid+1)<people[i][1]) l=mid+1; // we need get the index mid empty information, but actually it's stored in BIT[mid+1]
                else r=mid;
            }
            res[l]=people[i];
            update(l+1, -1);
        }
        return res;
    }
    void update(int x, int v){
        for(int i = x; i <= n; i+=(i&-i)){
            BIT[i]+=v;
        }
    }
    int getsum(int x){
        int sum=0;
        for(int i = x; i > 0; i-=(i&-i)){
            sum += BIT[i];
        }
        return sum;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};