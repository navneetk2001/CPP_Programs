// There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.
// An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')
// Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.
// Return minimum value % MOD where MOD = 10000003
// Example
// Here is the row having 15 seats represented by the String (0, 1, 2, 3, ......... , 14) -
//               . . . . x . . x x . . . x . .
// Now to make them sit together one of approaches is -
//                   . . . . . . x x x x . . . . .
// Following are the steps to achieve this -
// 1 - Move the person sitting at 4th index to 6th index -  
//     Number of jumps by him =   (6 - 4) = 2
// 2 - Bring the person sitting at 12th index to 9th index - 
//     Number of jumps by him = (12 - 9) = 3
// So now the total number of jumps made = 
//     ( 2 + 3 ) % MOD = 
//     5 which is the minimum possible jumps to make them seat together.
// There are also other ways to make them sit together but the number of jumps will exceed 5 and that will not be minimum.
// For example bring them all towards the starting of the row i.e. start placing them from index 0. 
// In that case the total number of jumps will be 
//     ( 4 + 6 + 6 + 9 )%MOD 
//     = 25 which is very costly and not an optimized way to do this movement


//Solution Approach :- 
// Lets take an exmaple: string :  .x..x..x.
// positions where x are present {1, 4, 7}
// Median is 4. So we will move all x near our median. 1st person would need to jump 2 steps and 3rd person would also need to jump 2 steps. Total answer = 4. 
// Can you prove why this approach works ?


//First Solution :-
int Solution::seats(string A) {
    vector<int> arr;
    for(int i=0;i<A.length();i++){
        if(A[i]=='x'){
            arr.push_back(i);
        }
    }

    int ans = 0 ;
    int mid = arr.size()/2;
    int start = 0;
    int end = 0;
    for(int i = 0 ; i<arr.size();i++){
        start = arr[i];
        end = arr[mid]-mid + i;
        ans= (ans+abs(end-start))%10000003;
    }
    return ans%10000003;
}


//Second Solution :-  
// Given str: ".....xxx......xx..xxx.x.."
// Extract indexes of 'x' :- idx: [5,6,7,14,15,18,19,20,22]
// Optimal Greedy Choice: To seat everyone around the center person.
// store mid = idx.size() / 2;
// STEP 1: Bring left people near to centre
// Initialize two pointers left & right and keep shifting left.
// Idea is to bring left pointer next to right;
//  [[[5,6,7,14,15]] ,18,19,20,22]
//                     L   R
// result  = result + (R - 1 - L);
// Update L = R - 1 (As now it's the new position)
//  [[[5,6,7,14,15]] ,18,19,20,22]
//               L R
// update L = 13 to signify this person moved right;
// STEP 2: Do same for right side.
// return result

int Solution::seats(string str) {
	int mod = 10000003;
	int n = str.size();

	vector<int> idx;
	for(int i = 0; i < n; i++){
		char c = str[i];
		if (c == 'x'){
			idx.push_back(i);
		}
	}

	int len = idx.size();
	int mid = len / 2;
	int result = 0;

	int left = mid - 1;
	while(left >= 0){
		int right = left + 1;
		result = result % mod + (idx[right] - 1 - idx[left]);
		idx[left] = idx[right] - 1;
		--left;
	}

	int right = mid + 1;
	while(right < idx.size()){
		int left = right - 1;
		result = result % mod + (idx[right] - 1 - idx[left]);
		idx[right] = idx[left] + 1;
		++right;
	}
	return result;
}


//Third Solution :- 
const int mod = 10000003;
int Solution::seats(string A) {
    //Find the median.
    vector<int> temp;
    for(int i = 0;i<A.size(); ++i) if(A[i]=='x') temp.push_back(i);
    //Median is middle element.
    int N = temp.size(),k,res=0;
    if(N==0) return 0;
    int med = temp[N/2];
    for(int i = N/2-1,k=med-1;i>=0;--i,--k){
        res=(res+k-temp[i])%mod;
    }
    for(int i = N/2+1,k=med+1;i<N;++i,++k){
        res=(res+temp[i]-k)%mod;
    }
    return res;
}



