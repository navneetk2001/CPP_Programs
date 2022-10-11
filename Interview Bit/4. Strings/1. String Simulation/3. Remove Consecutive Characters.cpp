// Given a string A and integer B, remove all consecutive same characters that have length exactly B.

// Input 1:
// A = "aabcd"
// B = 2
// Output 1: "bcd"
// Explanation 1: "aa" had length 2.

// Input 2:
// A = "aabbccd"
// B = 2
// Output 2: "d"
// Explanation 2: "aa", "bb" and "cc" had length of 2.

//Hint 1
// You need to check if certain blocks of consecutive same characters have a length of exactly B.
// Can you do this using a counter of sorts??

//Solution Approach
// You need to maintain a counter of the count of the present character.
// If it is exactly B and a new charcter comes next, you need to remove this block
// of B characters. This can be done just by maintaing a seperate answer string and
// appending to it when the length is not B.


// First Method :-
string Solution::solve(string A, int B) {
    string res="";

    for(int i=0;i<A.size();i++){
        if(i<A.size()-1 && A[i]==A[i+1]){
            int count=1;
            while(i<A.size()-1 && A[i]==A[i+1]){
                i++;
                count++;
            }

            int left=count%B;
            while(left--){
                res+=A[i];
            }
        }
        else{
            res+=A[i];
        }
    }
    return res;
}

//Second Method :-
string Solution::solve(string A, int B) {
	int n =A.size();
	string s = "";
	int i=0,j=0;
	while(i<n)
	{
	    string temp = "";
	    int j=i;
	    while(j<n && A[i]==A[j]){
	        temp+=A[j];
	        j++;
	    }
	    if(temp.size()!=B){
	        s += temp;
	    }
	    i=j;
	}
	return s;
}


//Third Method :-
string Solution::solve(string A, int B) {
    int n = A.size();
    int count = 1;
    char a = A[0];
    string ans;
    int i = 1;
    while(i<n){
        if(A[i]==a) {
            count++;
        }
        else{
            if(count!=B){
                while(count--) {
                    ans += a;
                }
            }
            count = 1;
            a = A[i];
        }
        i++;
    }
    if(count!=B){
        while(count--) ans += a;
    }
    return ans;
}


//Fourth Method :-
string Solution::solve(string A, int B) {
    string s;
    for(int i=0;i<A.size();i++)
    {
        int k=1,count=1;
         while(A[i]==A[i+k])
        {
            count++;
            k++;
        }
        if(count==B)
        {
            i=i+B-1;
            continue;
        }
        s.push_back(A[i]);
    }
    return s;
}

