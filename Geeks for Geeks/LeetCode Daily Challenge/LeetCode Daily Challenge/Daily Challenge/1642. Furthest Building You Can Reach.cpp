// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
// While moving from building i to building i+1 (0-indexed),
// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

// Example 1:
// Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
// Output: 4
// Explanation: Starting at building 0, you can follow these steps:
// - Go to building 1 without using ladders nor bricks since 4 >= 2.
// - Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
// - Go to building 3 without using ladders nor bricks since 7 >= 6.
// - Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
// It is impossible to go beyond building 4 because you do not have any more bricks or ladders.

// Example 2:
// Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
// Output: 7

// Example 3:
// Input: heights = [14,3,19,3], bricks = 17, ladders = 0
// Output: 3




//Solution Approach :-
int furthestBuilding(vector<int>& A, int bricks, int ladders) {
    priority_queue<int> pq;
    
    int i=0;                             //starting from 0th building
    for(i = 0; i < A.size() - 1; i++){
    	if(A[i+1] <= A[i]) continue;     //if next building is smaller than current building then simply move to next building
        int diff = A[i + 1] - A[i];      //else calculate the number of bricks required to go to next building
        
        if(diff<=bricks){        //if that diff is less than remaining number of bricks 
        	bricks-=diff;        //then remove that number of bricka and climb to the next building using those bricks
        	pq.push(diff);       //push diff in priority queue so that we may regain those bricks if we later need it by using a ladder insted of bricks 
        }
        else if(ladders>0){     //elseif ladder is remaining 
        	if(pq.size()){      //if there is any element remaining in priority queue
        		int tp=pq.top();    //find the top element of priority queue
        		if(tp > diff){  //if our top element is greater than curr difference, then we can regain those bricks and use a ladder instead;
	        		bricks+=tp;   //we will regain some bricks and use a ladder for them 
	        		pq.pop();    //pop that current top element
	        		pq.push(diff);    //now push the current diff in priority queue
	        		bricks-=diff;    //now remove those bricks that you have used
	        	}
        	}
        	ladders--;    //use a ladder for the previous buildings if above condition arose
        }
        else{
        	break;
        }
    }
    return i;   //return the index that you have reached
}


//Second Solution :- Using multiset instead
int furthestBuilding(vector<int>& A, int bricks, int ladders) {
    multiset<int> s;
    for (int i = 0; i < A.size() - 1; i++) {
        int d = A[i + 1] - A[i];
        if (d > 0)
            s.insert(A[i + 1] - A[i]);
        if (s.size() > ladders) {
            bricks -= *s.begin();
            s.erase(s.begin());
            if (bricks < 0) return i;
        }
    }
    return A.size() - 1;
}



//Third Solution :-
// Explanation :- 
// Heap heap store k height difference that we need to use ladders.
// Each move, if the height difference d > 0,
// we push d into the priority queue pq.
// If the size of queue exceed ladders,
// it means we have to use bricks for one move.
// Then we pop out the smallest difference, and reduce bricks.
// If bricks < 0, we can't make this move, then we return current index i.
// If we can reach the last building, we return A.length - 1.

int furthestBuilding(vector<int>& A, int bricks, int ladders) {
    priority_queue<int> pq;
    for (int i = 0; i < A.size() - 1; i++) {
        int d = A[i + 1] - A[i];
        if (d > 0)
            pq.push(-d);
        if (pq.size() > ladders) {
            bricks += pq.top();
            pq.pop();
        }
        if (bricks < 0)
            return i;
    }
    return A.size() - 1;
}



//✔️ Solution IV (Using map)
//Again, this wouldn't perform any better than using priority_queue / heap, but this one's a very commonly used data structure, so I am putting the solution using this as well. Also, this might actually be more space efficient if there are multiple jumps of same height in our path since we wouldn't have to store each of them separately & just maintain their count.

int furthestBuilding(vector<int>& H, int bricks, int ladders) {
	map<int, short> mp;
	int n = size(H), i = 0, jumpHeight = 0;
	for(; i < n - 1; i++) {
		jumpHeight = H[i + 1] - H[i];
		if(jumpHeight <= 0) continue;
		mp[jumpHeight]++;
		if(ladders--<=0){                
			bricks -= begin(mp) -> first;
			if(!--begin(mp) -> second) 
				mp.erase(begin(mp));
		}
		if(bricks < 0) return i;
	}
	return i;
}