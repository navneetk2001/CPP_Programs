https://leetcode.com/problems/boats-to-save-people/




//Solution Approach :-
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int n = people.size();
        int l = 0, r = n-1;
        
        while(l <= r) {
            if(people[l] + people[r] <= limit){   // lightest person + heaviest person sum <= limit they can go together
                l++;
                r--;
            } 
            else{       // if sum is over the limit, heaviest will go alone.
                r--;
            }
            count++;
        }
        return count;
    }
};




//Second Solution :- 
//We always put the next heaviest person on the boat, plus the lightest person if combined weight is within the limit.

int numRescueBoats(vector<int>& ppl, int limit, int boats = 0) {
	sort(begin(ppl), end(ppl));
	for (int i = 0, j = ppl.size() - 1; i <= j; ++boats, --j) {
		if (ppl[i] + ppl[j] <= limit){
			++i;
		}
	}
	return boats;
}