// Given an array with n objects colored red, white or blue, 
// sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: Using library sort function is not allowed.

// Example :
// Input : [0 1 2 0 1 2]
// Modify array so that it becomes : [0 0 1 1 2 2]

//Solution Approach :-
// There are multiple approaches possible here. We need to make sure we do not allocate extra memory.
// Approach 1:

// Count the number of red, white and blue balls.
// Then in another pass, set initial redCount number of cells as 0, next whiteCount cell as 1 and next bluecount cells as 2.
// *Requires 2 pass of the array. *

// **Approach 2: **
// Swap the 0s to the start of the array maintaining a pointer, and 2s to the end of the array.
// 1s will automatically be in their right position.

//First Solution :- Inplace Sorting
void Solution::sortColors(vector<int> &nums) {
    int high = nums.size()-1;
    int low = 0;
    int mid = 0;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid],nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


//Second Solution
void Solution::sortColors(vector<int> &A) {
	map<int,int>mp;
	for(int i=0;i<A.size();i++){
	    mp[A[i]]++;
	}

	vector<int>ans;
	for(int i=0;i<=2;i++){
	    while(mp[i]--)
	    ans.push_back(i);
	}

	A=ans;
}

//Third Solution
void Solution::sortColors(vector<int> &A) {
    int red =0, blue =A.size()-1, color = 0;
    while(color <= blue){            //we arrange 0's and 2's, 1's will already be in place
        if(A[color]==0)
        {
            swap(A[red++],A[color++]);
        }
        else if(A[color]==2)
        {
            swap(A[blue--],A[color]);
        }
        else
        {
            color++;
        }
    }
}


//Fourth Solution :-

//counting sort is the key here
void Solution::sortColors(vector<int> &A) {
    int n=A.size();
    vector<int> freq(3,0);
    for(int i=0;i<n;i++){freq[A[i]]++;}
    for(int i=0;i<n;i++){
        if(freq[0]>0){
            A[i]=0;
            freq[0]--;
        }
        else if(freq[1]>0){
            A[i]=1;
            freq[1]--;
        }
        else{
            A[i]=2;
        }
    }
}


//since inbuilt sort functions are not allowed here,so tried using my quicksort
//just to implement quicksort,anyways this gives TLE
int partition(vector<int> &A,int lo,int hi){
    
    int k=lo;
    for(int j=lo;j<hi;j++){
        if(A[j]<A[hi]){
            swap(A[j],A[k++]);
        }
    }
    swap(A[k],A[hi]);
    return k;
}
void kickSort(vector<int>& A,int lo,int hi){
    if(lo>=hi){return ;}
    int p=partition(A,lo,hi);
    kickSort(A,lo,p-1);
    kickSort(A,p+1,hi);
}
void Solution::sortColors(vector<int> &A) {
    kickSort(A,0,A.size()-1);
}


//Fifth Solution :-
void sortColors(vector& nums) {

    // take counts of 0, 1, 2 
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    // Add counts of 0,1,2
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 0){
            zeroCount++;
        }
        else if(nums[i] == 1){
            oneCount++;
            
        }
        else if(nums[i] == 2){
            twoCount++;
        }
    }
    
    //Add in array 0,1,2  as count becomes 0
    for(int i=0;i<nums.size();i++){
        if(zeroCount!=0){
            nums[i] = 0;
            zeroCount--;   
        }
        else if(oneCount!=0){
            nums[i] = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            nums[i] = 2;
            twoCount--;
        }
    }
}
