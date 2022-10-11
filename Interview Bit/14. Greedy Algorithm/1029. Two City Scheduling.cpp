https://leetcode.com/problems/two-city-scheduling/



//Solution Approach :-
//Here we will calculate relative cost and then sort this relative cost accordingly
//And after this we will figure out in which case we should go to city A and in which case to city B accordingly

class Solution {
public:
	static bool relativeCost(vector<int> &first, vector<int> &second){  //sort on the basis of difference of going from city A and City B
		return first[1]-first[0] > second[1]-second[0];
	}

    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), relativeCost);

        for(int i = 0; i < costs.size()/2; i++){
        	sum += costs[i][0];
        }
        for(int i = costs.size()/2; i < costs.size(); i++){
        	sum += costs[i][1];
        }

        return sum;
    }
};



ALGORITHM :-
// Input: costs = [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Compute the cost of sending every person to City A.
// The cost will be 10 + 30 + 400 + 30 = 470
// Compute the difference if a Person is sent to City B
// D1 -> 20 - 10 = 10
// D2 -> 200 - 30 = 170
// D3 -> 50 - 400 = -350
// D4 -> 20 - 30 = -10
// If the last two persons are sent to City B instead of City A, you can save maximum, as those are the persons costing more to City A.
// Sort the diff.
// D3, D4, D1, D2
// Now pick N persons which has least diff and send them to City B.
// Add the diff cost to the total
// 470 + (-350) + -(10) = 110
// return cost.