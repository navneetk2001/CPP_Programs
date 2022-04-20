// You are given a array of strings A of length N.
// You have to return another string array which contains all possible special strings.
// A special string is defined as a string with length equal to N, 
// and ith character of the string is equal to any character of the ith string in the array A.

// Input 1:
// A = ['ab', 'cd']
// Input 2:
// A = ['aa', 'bb']

// Output 1:
// ['ac', 'ad', 'bc', 'bd']
// Output 2:

// ['ab', 'ab', 'ab', 'ab']

//Solution Approach :- 
First, lets see how many strings can be formed.
There are N strings and let K be the maximum length of any string in the array A.
Since, we can choose any of the K characters from each of the N strings.
So, the time complexity will be O(KN).

We can simply use a brute force recursive method, to find all the strings.
Let the recursive function have two parameters (i, j), 
where i denotes the index of the string in the array A, and j denotes the index of the character of the ith string.

From here, we can go to two states (i + 1, j) and (i, j + 1).
We have to take care of the base cases. Simply add all the strings to a list or an array and return it.



//First Solution :-
string str;           // store the current string
vector<string> ans;   //store the answer

void find(vector<string> &arr,int i){
    if(i==arr.size()){    
        ans.push_back(str);
        return;
    }

    string curr_str=arr[i];
    for(int j=0;j<curr_str.size();j++){
        str.push_back(arr[i][j]);
        find(arr,i+1);
        str.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A){
    ans.clear();
    find(A,0);
    return ans;
}


//Second Solution :-
vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string> ans, fans;
    ans.push_back("");
    if(A.size() == 0)return ans;
    string s = A[A.size()-1];

    A.pop_back();
    ans = specialStrings(A);
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<ans.size(); j++)
        {
            fans.push_back(ans[j] + s[i]);
        }
    }
    return fans;
}


//Third Solution :- 


