// There are two kinds of bots A and B in a 1-D array. A bot can only move left while B can only move right. There are also empty spaces in between represented by #. But its also given that the bots cannot cross over each other.
// Given the initial state and final state, we should tell if the transformation is possible.
// NOTE: There can be many bots of the same type in a particular array. 

// Example 1:
// Input:
// s1 = #B#A#
// s2 = ##BA#
// Output: Yes
// Explanation: Because we can reach the final state by moving 'B' to the right one step.

// Example 2:
// Input:
// s1 = #B#A#
// s2 = #A#B# 
// Output: No
// Explanation: Because the robots cannot cross each other.



//Solution Approach :-
class Solution{   
public:
    string moveRobots(string s1, string s2){
        int i=0, j=0, n=s1.size();
        while(i<n && j<n){
        	if(s1[i]=='#'){
        		i++;
        	}
        	else if(s2[j]=='#'){
        		j++;
        	}
        	else if(s1[i]!=s2[j]){   //robots are crossing each other
        		return "No";
        	}
        	else if(s1[i]=='B' and s2[j]=='B' and i>j){  //B can only move in right direction
        		return "No";
        	}
        	else if(s1[i]=='A' and s2[j]=='A' and i<j){  //A can only move in left direction
        		return "No";
        	}
        	else{
        		i++;
        		j++;
        	}
        }
        return "Yes";
    }
};