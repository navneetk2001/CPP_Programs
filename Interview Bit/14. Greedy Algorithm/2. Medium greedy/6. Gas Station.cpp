// Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].
// You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
// Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.
// You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

// Example Input :- A = [1, 2] B = [2, 1]
// Example Output :- 1

// Example Explanation : If you start from index 0, you can fill in A[0] = 1 amount of gas. Now your tank has 1 unit of gas. But you need B[0] = 2 gas to travel to station 1. If you start from index 1, you can fill in A[1] = 2 amount of gas. Now your tank has 2 units of gas. You need B[1] = 1 gas to get to station 0. So, you travel to station 0 and still have 1 unit of gas left over. You fill in A[0] = 1 unit of additional gas, making your current gas = 2. It costs you B[0] = 2 to get to station 1, which you do and complete the circuit.


//Hint :-
Try to find the relation between sum of gas and sum of cost for solution to exist.
When will you shift your starting point from 0?
Do you really need to cover every starting point? How can you use answer of above question to optimize this part?

//Solution Approach :- 
The bruteforce solution should be obvious. Start from every i, and check to see if every point is reachable with the gas available. Return the first i for which you can complete the trip without the gas reaching a negative number.
This approach would however be quadratic.
Lets look at how we can improve.
	1) If sum of gas is more than sum of cost, does it imply that there always is a solution ?
	2) Lets say you start at i, and hit first negative of sum(gas) - sum(cost) at j. We know TotalSum(gas) - TotalSum(cost) > 0. What happens if you start at j + 1 instead ? Does it cover the validity clause for i to j already ?


//First Solution :- BruteForce Algorithm
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.length;
        for(int i = 0; i < n; i++){
            int totalFuel = 0;
            int stopCount = 0, j = i;
            while(stopCount < n){
                totalFuel += gas[j % n] - cost[j % n];
                if(totalFuel < 0) break; // whenever we reach -ve
                stopCount++;
                j++;
            }
            if(stopCount == n && totalFuel >= 0) return i; // cover all the stops & our fuel left is 0 or more than that
        }
        return -1;
    }
};


//Second Solution :- Optimal Approach 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int total = 0;
        int diff = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){
            diff = gas[i] - cost[i];

            total += diff;
            current += diff;
            if(current < 0){
                start = i + 1;
                current = 0;
            }
        }

        if(total >= 0){
            return start;
        }

        return -1;
    }
};


//Third Solution :- 
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int front = 0, end = 0;
    int N = A.size();
    long s1 = 0, s2 = 0;
    bool endGoneAround = false;

    while (true){
        end++;
        if (end == N){
            end=0;
            endGoneAround = true;
        }

        int endMinus1 = (end==0) ? N-1: end-1;
        s1+=A[endMinus1];
        s2+=B[endMinus1];

        while (s2>s1 && front!= N){
            front++;
            s1 -= A[front-1];
            s2 -= B[front-1];
        }

        if (front == end && endGoneAround){
            return front;
        }
        if (front == N) return -1;
    }
    return -1;
}



