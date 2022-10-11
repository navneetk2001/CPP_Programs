// You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
// Return the maximum total number of units that can be put on the truck.

// Example 1:
// Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
// Output: 8
// Explanation: There are:
// - 1 box of the first type that contains 3 units.
// - 2 boxes of the second type that contain 2 units each.
// - 3 boxes of the third type that contain 1 unit each.
// You can take all the boxes of the first and second types, and one box of the third type.
// The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

// Example 2:
// Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
// Output: 91




//Solution Approach :-
class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),myfunction);   //custom sort (in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units)
		
        int ans=0;
        for(auto box: boxTypes){             //greedily pick boxes till capacity is full
            int x=min(box[0],truckSize);     //choose minimum boxes from available boxes and capacity left
            ans += x * box[1];                 //adding units in ans
            truckSize -= x;                  //reduce the capacity
            if(!truckSize){                  //capacity full
            	break; 
        	}
        }
        return ans;
    }
};




//Second Solution :-
// This time we will store info into sizeBucket, an array of 1001 elements (to cover all the provided range) all set to 0 and that we will populate while also storing the extremes of said range in minBucket and maxBucket, increasing each bucket of size boxType[1] by boxType[0] (how many we have) as we go. Be sure to add, not to assign here, since we do not know if we would be given multiple entries of the same size.
// Once done, we can loop through the boxes we bucket-sorted going from maxBucket to minBucket (included) and following a logic specular to the previous one.
// This bucket sorting version, which despite using buckets, turns out to be even more efficient in terms of space too:

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        int res = 0, sizeBucket[1001] = {}, maxBucket = INT_MIN, minBucket = INT_MAX;
    
        for(auto &boxType: boxes){    // bucket sorting tthe boxes and recording the bucket range
            maxBucket = max(maxBucket, boxType[1]);
            minBucket = min(minBucket, boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
		
        for(int i = maxBucket, size, currBatch; i >= minBucket; i--){     // carrying as many larger sized boxes as we can first
            size = sizeBucket[i];
            if(!size) continue;
            currBatch = min(size, truckSize);
            truckSize -= currBatch;
            res += currBatch * i;
            if(!truckSize) break;
        }
        return res;
    }
};




//Third Solution :-
//Finally, I wanted to try if storing each available size of a bucket in a set would help (think of some edge cases in which you would get very sparse ranges of sizes), but it boils down to another nlgn approach, so not too performing and just marginally better than the first:

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        int res = 0, sizeBucket[1001] = {}, currBatch;
        set<int, greater<int>> bucketSizes;
    
        for (auto &boxType: boxes) {       // bucket sorting tthe boxes and recording the bucket range
            bucketSizes.insert(boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
	
        for (int size: bucketSizes) {     	// carrying as many larger sized boxes as we can first
            currBatch = min(sizeBucket[size], truckSize);
            truckSize -= currBatch;
            res += currBatch * size;
            if (!truckSize) break;
        }
        return res;
    }
};


