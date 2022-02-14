/*
Problem Statement :-
You are given an integer array 'ARR' of size 'N' and an integer 'S'. 
Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 
Return the list of pairs sorted in non-decreasing order of their first value. 
In case if two pairs have the same first value, the pair with a smaller second value should come first.
*/


//First Approach :- Brute Force :-
/*
Initialize a list to store our results.
For each element in the array 'ARR[i]', check if ('ARR[i]' + ‘ARR[j]’), equals to given sum or not, where ‘i’ < ‘j’ < ‘N’.
If the condition matches, add the pair('ARR[i]', ‘ARR[j]’) to the list. Sort the list of pairs as per the given output format 
and return this list.  */

/*

    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the size of the array.
    
*/

vector< vector<int> > pairSum(vector<int> &arr, int s){
    int n = arr.size();
    // Used to store result.
    vector< vector<int> > ans;
        
    // Checking sum for every element.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == s) {
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[j];
                ans.push_back(pair);
            }
        }
    }

    // Used to store final sorted result.
    vector<vector<int> > res(ans.size(),vector<int>(2,0));
    for(int i = 0; i < ans.size(); i++) {
        int a = ans[i][0], b = ans[i][1];

        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }
    sort(res.begin(),res.end());  
    return res;
}




//Second Approach :- Using HashMap
/*
Initialize a list to store our results.
For each element in the array ‘ARR[i]’, we will check whether there exists an element equals to ('S' - ‘ARR[i]’) already in the map.
If it exists we will add the pair('ARR[i]', ‘S’ - ‘ARR[i]’ ) ‘COUNT’ number of times to the list, 
where ‘COUNT’ represents the frequency of ('S' - ‘ARR[i]’) in the map.
Also, we will increment the frequency of the current element ('ARR[i]') in the map. 
Sort the list of pairs as per the given output format and return this list.
*/

/*

    Time Complexity: O(N^2)
    Space COmplexity: O(N)

    Where 'N' is the size of the array.
    
*/

#include <map>

vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n = arr.size();

    // Map to store frequency of elements.
    map<int, int> hash;

    // This will store the result.
    vector<vector<int>> ans;

    for (int ele : arr)
    {
        int count = hash[s - ele];

        vector<int> pair(2);
        pair[0] = ele;
        pair[1] = s - ele;

        while (count--)
        {
            ans.push_back(pair);
        }

        hash[ele] += 1;
    }

    // This will store the final result.
    vector<vector<int>> res(ans.size(), vector<int>(2, 0));

    // Sorting the 'ans' arrays element.
    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }

    // Finally sorting each pair in 'res'.
    sort(res.begin(), res.end());
    return res;
}