// You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
// You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
// Return the maximum number of white tiles that can be covered by the carpet.

// Example 1:
// Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
// Output: 9
// Explanation: Place the carpet starting on tile 10. 
// It covers 9 white tiles, so we return 9.
// Note that there may be other places where the carpet covers 9 white tiles.
// It can be shown that the carpet cannot cover more than 9 white tiles.

// Example 2:
// Input: tiles = [[10,11],[1,1]], carpetLen = 2
// Output: 2
// Explanation: Place the carpet starting on tile 10. 
// It covers 2 white tiles, so we return 2.


//First Solution :-  Sliding Window
// Intuition: it's always better to place a carpet at the beginning of a range. The reason is: if you shift a carpet one tile right, you might cover another white tile, but you definitely uncover the previous white tile.
// So, we sort tile ranges, and check how many white tiles we can cover, starting from the beginning of each range.
// To avoid TLE, we "drag" our carpet left-to-right, using the sliding window technique. It's a bit tricky for this problem:

// 1. We track the placement of the carpet in j (so the left side is tiles[j][0]).
// 2. When we can cover tiles[i], we add those tiles to cover and extend the sliding window (++i).
// 3. Otherwise, we compute partial cover of tiles[i] (total cover is cover + partial).
//     We remove tiles[j] from cover.
//     We move the carpet to the next tile (++j), shrinking the sliding window.

int maximumWhiteTiles(vector<vector<int>>& t, int len) {
    int res = 0, j = 0, cover = 0;
    sort(begin(t), end(t));
    for (int i = 0; res < len && i < t.size(); )     
        if (t[j][0] + len > t[i][1]) {         //carpet starting from j is exceeding this window(as this window is ending at i)
            cover += t[i][1] - t[i][0] + 1;   //this window is being extended to cover this patch also
            res = max(res, cover);        
            ++i;                          //let this window try to cover next patch by expanding its right end
        }
        else{                                  //carpet starting from jth patch is not able to cover this whole patch at i 
            int partial = max(0, t[j][0] + len - t[i][0]);   //Partial length covered by carpet in this patch
            res = max(res, cover + partial);    
            cover -= (t[j][1] - t[j][0] + 1);   //window will slide towards right hence remove the contribution of cover given by left most patch of current window. 
            ++j;                                //slide the window towards its right
        }
    return res;
}



//Second Solution :-
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());     //sort by tile start
        
        int ans = 0, total = 0, endIdx=0;                    // define endIdx i.e. index for tile chunk where the carpet ends.
        for(int startIdx = 0;startIdx<tiles.size();startIdx++) {

            int start = tiles[startIdx][0];     //align carpet with start of current tile chunk
            int end = start + carpetLen -1;     //given carpet length this is how far carpet end can go.
            
            // search on which tile chunk in given array would be the end of carpet.
            // note: here for each startIdx we see how far endIdx can go further
            // there won't be any case where for a startIdx we will need to move endIdx backwards.
            while(endIdx < tiles.size() && tiles[endIdx][1]<end) {
                total += tiles[endIdx][1]-tiles[endIdx][0]+1;
                endIdx++;
            }
            
            // if we have reached the end of array or carpet ended somwhere between tile chunks. then possible answer is total for this startIdx.
            if(endIdx==tiles.size() || tiles[endIdx][0] > end) {
                ans = max(ans, total);
            } 
            else{       // else if we only add tile chunk start to carpet end in our answer.
                ans = max(ans, total + (end - tiles[endIdx][0]+1));
            }
            
            total -= tiles[startIdx][1] - tiles[startIdx][0] + 1;      //since we move to next startIdx in next iteration, remove tiles from current startIdx
        }
        return ans;
    }
};



//Third Solution :- Prefix Array, Binary Search
class Solution {
public:
    // Time Complexity:- O(NlogN)
    // Space Complexity:- O(N)
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0,n = tiles.size();
        
        sort(tiles.begin(),tiles.end());
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = tiles[i][1] - tiles[i][0] + 1;
            if(i>0){
                arr[i] += arr[i-1];
            }
        }
        
        for(int i=0;i<n;i++){
            int leftEnd = tiles[i][0],rightEnd = tiles[i][0] + carpetLen - 1;
            
            int l = i,r = n - 1,left = i,right = i - 1;
            while(l<=r){
                int mid = (l+r)/2;
                if(tiles[mid][1]<=rightEnd){
                    right = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            
            int curr = 0;
            
            if(right!=i-1){
                curr += arr[right];
                if(left>0){
                    curr -= arr[left-1];
                }
            }
            
            if(right+1<n){
                curr += max(0,rightEnd-tiles[right+1][0]+1);
            }
            
            ans = max(ans,curr);
        }
        
        return ans;
    }
};
