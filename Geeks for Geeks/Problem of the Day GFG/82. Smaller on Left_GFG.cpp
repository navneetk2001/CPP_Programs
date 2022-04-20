// Given an array arr[ ] of N positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".

// Example 1:
// Input:
// N = 5
// arr[] = {2, 3, 4, 5, 1}
// Output: -1 2 3 4 -1
// Explanation: Greatest element on the left of 3 smaller than itself is 2, for 4 it is 3 and for 5 
// it is 1. Since 2 is the first element and  no element on its left is present, so it's 
// greatest smaller element will be -1 and for 1 no element smaller than itself is present 
// on its left, so it's greatest smaller element is -1.

// Example 2:
// Input:
// N = 3
// arr[] = {1, 2, 3} 
// Output: -1 1 2 



//Solution Approach :-
// first intution is : if array is sorted in descending order then answers would be -1 for the whole array
// left most element answer would be always -1
//need to do binary search instead of linear here but only possible if array is already sorted
//need to find another approach, we can use set which is self Balanced binary search tree or heaps also of course
//but heap and stack we wont use because we pop elements here that we will be needing.
//strictly smaller that means we dont need to worry about duplicate elements in set i think.
//means if there is any element larger than arr[i] if not then it will go to s.begin()
//now we got the next greatest element or same element so we will be going to its previous one to find the answer

vector<int> Smallestonleft(int a[], int n)
{
    vector<int>ans(n);
    set<int>st;
    for(int i=0;i<n;i++){
    	auto it=st.lower_bound(a[i]);
    	if(it==st.begin()){
    		ans[i]=-1;
    	}
    	else{
    		it--;
    		ans[i]=*it;
    	}
    	st.insert(a[i]);
    }
    return ans;
}



//Second Solution :-
vector<int> Smallestonleft(int arr[], int n){
    set<int, greater<int>> s1;
    vector<int> vec;
    vec.push_back(-1);
    s1.insert(arr[0]);
    set<int, greater<int> >::iterator itr;
    for(int i=1;i<n;i++){
        s1.insert(arr[i]);
        itr = s1.upper_bound(arr[i]);
        if(itr == s1.end()){
            vec.push_back(-1);
        }
        else{
            vec.push_back(*itr);
        }
    }
    return vec;
}


//Third Solution :-
// but this method takes a lot of time -> O(n*n) so we need to reduce it to O(nlogn) and 
// space could be O(n) for vector or set/map i think.
vector<int> Smallestonleft(int arr[], int n){
    vector<int> res;
    int store,max;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            res.push_back(-1);
            continue;
        }
        max=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && max<arr[j])
            {
                max=arr[j];
            }
        }
        if(max==0)
        {
            res.push_back(-1);
            continue;
        }    
        res.push_back(max);
    }
    return res;
}
    


