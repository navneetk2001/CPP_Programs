https://leetcode.com/problems/maximum-units-on-a-truck/



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



//Second Soution :- 
// Intuition:
// The constraint that "boxes per unit" will be max 1000 allows us to use 1000 buckets to sort by boxes per unit.
// Ie., we can create an array where the indices represent 0 boxes per unit, 1 boxes per unit, 2 boxes per unit, 3 boxes per unit, ... 1000 boxes per unit. And the buckets[i] will represent the number of boxes at each index.

// Algorithm:
// take the given data and sort it into the 1000 buckets. this is O(n) because we loop over the given data once.
// loop over the buckets backwards- so that we start at a higher boxes per unit to get as many units as possible. in each iteration:
// check if the current bucket has any values (isn't -1).
// if the bucket has a value, check if the truck has space enough for all the boxes. if yes, load up all units.
// if the truck hasn't enough space, load up only the units you can.
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> buckets(1001, -1);
        int space_remaining_boxes = truckSize;
        int units_loaded = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (buckets[ boxTypes[i][1] ] == -1) {
                buckets[ boxTypes[i][1] ] = boxTypes[i][0];
            } 
            else { // already has a value
                buckets[ boxTypes[i][1] ] += boxTypes[i][0];
            }
            // optimization idea: when populating, track the highest and lowest boxesperunit for use as indices below
        }
        
        for (int i = 1000; i >= 0; --i) {
            if (buckets[i] == -1) continue;
            
            if (buckets[i] > space_remaining_boxes) { // case:not enough space on truck. eg., we have 2 box but truck space 1.
                units_loaded += space_remaining_boxes*i;
                return units_loaded;
            } else {
                units_loaded += buckets[i]*i; // i is 10units/box. buckets[i] is 2 boxes. total units is 20.
                space_remaining_boxes -= buckets[i]; // space_remaining is in units of boxes.
            }
            
        }
        return units_loaded;
    }
};

// Time: O(n)
// space: O(1000). we create an array of 1000 buckets.



//Third Solution :-
bool compare(vector<int> v1, vector<int> v2){
    return v1[1] > v2[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int totalUnits = 0, i = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        while (truckSize>0 && i<boxTypes.size()){
            if(boxTypes[i][0] <= truckSize){
                totalUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                int canTake = truckSize;
                truckSize -= canTake;
                totalUnits += canTake * boxTypes[i][1];
            }   
            i++;
        }
        return totalUnits;
    } 
};