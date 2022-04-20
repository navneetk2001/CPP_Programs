// We have n chips, where the position of the ith chip is position[i].
// We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:
// position[i] + 2 or position[i] - 2 with cost = 0.
// position[i] + 1 or position[i] - 1 with cost = 1.
// Return the minimum cost needed to move all the chips to the same position.

// Example 1:
// Input: position = [1,2,3]
// Output: 1
// Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
// Second step: Move the chip at position 2 to position 1 with cost = 1.
// Total cost is 1.

// Example 2:
// Input: position = [2,2,2,3,3]
// Output: 2
// Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.

// Example 3:
// Input: position = [1,1000000000]
// Output: 1



//Solution Approach :-
//Approach intuition: We need to understand that the cost of moving from even to another even positon or cost of moving from one odd to another odd position is 0, and the cost of moving from odd to even or from even to odd is 1.
//So, we will calculate the chips at even position and chips at odd positions, cost of collecting all the even positioned chips at one even place is 0 and simultaneously, the cost of collecting the odd positioned chips at one odd place is also 0. Thus, in order to minimize the cost of moving all chips at one place, we need to find the minimum no of chips that need to be displaced from their position.

int minCostToMoveChips(vector<int>& position) {
    int odd=0,even=0;
    for(int i=0;i<position.size();i++)
    {
        if(position[i]%2==0)
            even++;
        else
            odd++;
    }
    return min(even,odd);
}