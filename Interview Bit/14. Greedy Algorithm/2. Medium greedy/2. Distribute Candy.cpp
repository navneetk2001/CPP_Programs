// There are N children standing in a line. Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
// 	1. Each child must have at least one candy.
// 	2. Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example:
// Input 1: A = [1, 2]
// Output 1: 3
// Explanation 1:
//     The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
//     So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

// Input 2: 
// A = [1, 5, 2, 1]
// Output 2: 7
// Explanation 2: Candies given = [1, 3, 2, 1]

//Hint :-
// Would greedily assigning the candy work here ?
// Where should you start from ?
// Should you start assigning the candies from the least rating guy to the guy with most rating or vice versa ?

//Solution Approach :- 
// Greedy works here ( Think of a supportive proof as as assignment ).
// Start with the guy with the least rating. Obviously he will receive 1 candy.
// If he did recieve more than one candy, we could lower it to 1 as none of the neighbor have higher rating.
// Now lets move to the one which is second least. If the least element is its neighbor, then it receives 2 candies, else we can get away with assigning it just one candy.
// We keep repeating the same process to arrive at optimal solution.


//First Solution :-
int candy(vector<int> &ratings){
	int size=ratings.size();
	if(size<=1){
		return size;
	}

	vector<int>num(size,1);
	for(int i=1; i<size; i++){
		if(ratings[i]>ratings[i-1]){
			num[i]=num[i-1]+1;
		}
	}

	for(int i=size-1; i>0 ;i--){
		if(ratings[i-1]>ratings[i]){
			num[i-1]=max(num[i]+1,num[i-1]);
		}
	}

	int result=0;
	for(int i = 0; i < size; i++){
		result+=num[i];
	}
	return result;
}



//Second Solution :-  
// Used greedy aproach:
// 	1. every student should get atleast one so initially give 1 candy to every student
// 	2. Now traverse left to right, whenever we get a higher rating, it should get more candy from its neighbour( left neighbour in the curr case) so give just one more candy than its left neighbour
// 	3. Now another case left when its right neighbour has higher rating, traverse from right, and if we get a higher rating, give it max(curr, 1+candy of its right). max ensures that for local maxima candies shuld be high than both neighbours;

int candy(vector<int>& r) {
        int n = r.size();
        vector<int> c(n, 1);
        for (int i = 1; i < n; i++)
            if (r[i] > r[i - 1]) c[i] = c[i - 1] + 1;
        for (int i = n - 2; ~i; i--)
            if (r[i] > r[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        int res = 0;
        for (auto t: c) res += t;
        return res;
    }



//Third Solution :- 
// Now, the question is can we do better? Do we really need two scans? If we do only forward scan, then the problem is we can not guarantee the right neighbor relationship holds. i.e. we don't know if the following order is descending (i>i+1>i+2>...). and that may cause issues. To fix that, we will detect the dips (the points at which the order switchs from increasing to decreasng). We will make sure all the local dips (minimum points) has only one candy and update its previous neighbors (which has hgher rates than its rate) accordingly. To do such update, we need to know when the decrease starts, so we use pPos to save that starting points.
// So the solution becomes: do the forward scan, if it is in an increasing order (child i rate > child i-1 order), check if it is a local dip (neg_peak == true): if so, update the candy number to make sure child i-1 has one candy. if not, just give one more candy to child i. If it is in an decreasing order (child i rate < child i-1 order)
// , just give one less candy to i. don't forget at last, we still need to make sure child N-1 has one or more candy. So O(1) space , O(N) time
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int len = ratings.size();
        if(len<=1) return len;
        
        int i, pPos, res=1, peak=1; // peak: # candies given to the i-1 child
        bool neg_peak = false; // flag to indicate if it is a local dip
        for(i=1; i<len;i++){
            if(ratings[i] >= ratings[i-1]) 
            {   // it is increasing
                if(neg_peak) 
                {  // it is a local dip, we need to make sure i-1 has one candy
                    res -= (peak-1) * (i-pPos - (peak>0));
                    peak = 1;
                    neg_peak = false;
                }
               // update child i candy number, if equal, set to 1
                peak = (ratings[i] == ratings[i-1])? 1:++peak;
                res += peak;
            }
            else
            { // decreasing, just give one less candy, if it is the starting point of a decrease, update pPos
                if(!neg_peak) {pPos = i-1; neg_peak = true;}
                res += --peak;
            }
        }
// don't forget to update res, if the last one is a local dip
        return !neg_peak? res : res - (peak-1) * (i-pPos - (peak>0));

    }
};





