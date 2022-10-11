// In a given cartesian plane, there are N points. We need to find the Number of Pairs of  points(A, B) such that

// Point A and Point B do not coincide.
// Manhattan Distance and the Euclidean Distance between the points should be equal.
// Note: Pair of 2 points(A,B) is considered different from  Pair of 2 points(B ,A).
// Manhattan Distance = |x2-x1|+|y2-y1|
// Euclidean Distance   = ((x2-x1)^2 + (y2-y1)^2)^0.5, where points are (x1,y1) and (x2,y2).

// Example 1:
// Input:
// N = 2
// X = {1, 7}
// Y = {1, 5}
// Output: 0
// Explanation: None of the pairs of points have equal Manhatten and Euclidean distance.

// Example 2:
// Input:
// N = 3
// X = {1, 2, 1}
// Y = {2, 3, 3}
// Output: 2
// Explanation: The pairs {(1,2), (1,3)}, and {(1,3), (2,3)} have equal Manhatten and Euclidean distance.




//Solution Approach :-
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        map<pair<int,int>,int> mp;
        map<int,int>mp1,mp2;

        int cnt = 0;
        for(int i=0;i<N;i++){
            int x=X[i] , y=Y[i];

            cnt += mp1[x] + mp2[y] - 2 * mp[{x , y}];
            
            mp[{x, y}]++;
            mp1[x]++ , mp2[y]++;
        }
        return cnt ;
    }
};




//Second Solution :-

// LOGIC:
// Manhattan Distance  = |x2-x1|+|y2-y1|
// Euclidean Distance   = ((x2-x1)^2 + (y2-y1)^2)^0.5
// Let x = x2 - x1 and y = y2 - y1
// then,
//      Manhattan Distance  = x + y
//      Euclidean Distance   = ((x)^2 + (y)^2)^0.5
// We want,
// Manhattan Distance  =  Euclidean Distance
// =>   x + y = ((x)^2 + (y)^2)^0.5
// Squaring both sides,
// => (x + y)^2 = (x)^2 + (y)^2
// => (x)^2 + (y)^2 + 2xy = (x)^2 + (y)^2
// => 2xy = 0

// This means x = 0 or y = 0 or (x = 0 && y = 0 which means both points are same)
// So we need to find count of pairs having x coordinates equal or y coordinates equal.
// And finally subtract twice (as they have been considered twice) the pairs having both coordinates equal.

class Solution {
public:
   int numOfPairs(int X[], int Y[], int N) {
       unordered_map<int, int> m;
       int ans = 0;
       for(int i = 0; i < N; i++){
           ans += m[X[i]];
           m[X[i]]++;
       }
       m.clear();
       for(int i = 0; i < N; i++){
           ans += m[Y[i]];
           m[Y[i]]++;
       }
       unordered_map<unsigned int, int> m1;
       int ans1 = 0;
       for(int i = 0; i < N; i++){
           unsigned int x = 10e9 * X[i] + Y[i];
           ans1 += m1[x];
           m1[x]++;
       }

       return ans - 2 * ans1;
   }



//Third Solution :-
int numOfPairs(int x[], int y[], int n) {
    int ans = 0;
    unordered_map<int,int> xFreq, yFreq;
    unordered_map<string,int> xyFreq;

    for(int i = 0; i < n; i++) {
        string s = to_string(x[i]) + "," + to_string(y[i]);
        ans += xFreq[x[i]] + yFreq[y[i]] - 2*xyFreq[s];

        xFreq[x[i]]++;
        yFreq[y[i]]++;
        xyFreq[s]++;
    }

   return ans;
}



//Fourth Solution :-
// Eucledian distance is equal Manhattan distance if and only if x1 = x2 or y1 = y2

int numOfPairs(int X[], int Y[], int N) {
   map<int,vector<int>>mp1;  // Storing the frequency of similar x 
   map<int,vector<int>>mp2;  // Storing the frequency of similar y
   map<pair<int,int>,int>mp3;  // Storing the frequency of similar (x,y)
   
   for(int i = 0; i < N; i++){
       mp1[X[i]].push_back(Y[i]);
       mp2[Y[i]].push_back(X[i]);
       mp3[{X[i],Y[i]}]++;
   }

   int cnt = 0;
   for(auto it : mp1){
       vector<int>temp = it.second;    
       int size = temp.size();
       cnt += ((size)*(size-1))/2;  // Finding the count of pairs having similar x
   }

   for(auto it : mp2){
       vector<int>temp = it.second;
       int size = temp.size();
       cnt += ((size)*(size-1))/2;   // Finding the count of pairs having similar y
   }

   int temp = 0;
   for(auto it : mp3){
       temp += ((it.second)*(it.second-1))/2;  // Finding the count of pairs having similar (x,y)
   }
   
   return cnt - 2*temp;       
   // code here
}