// Professor McGonagall teaches transfiguration at Hogwarts. She has given Harry the task of changing himself into a cat. She explains that the trick is to analyze your own DNA and change it into the DNA of a cat. The transfigure spell can be used to pick any one character from the DNA string, remove it and insert it in the beginning. 
// Help Harry calculates minimum number of times he needs to use the spell to change himself into a cat.

// Example 1:
// Input: 
// A = "GEEKSFORGEEKS" 
// B = "FORGEEKSGEEKS"
// Output: 3
// Explanation:The conversion can take place 
// in 3 operations:
// 1. Pick 'R' and place it at the front, 
//    A="RGEEKSFOGEEKS"
// 2. Pick 'O' and place it at the front, 
//    A="ORGEEKSFGEEKS"
// 3. Pick 'F' and place it at the front, 
//    A="FORGEEKSGEEKS"

// Example 2:
// Input: 
// A = "ABC" 
// B = "BCA"
// Output: 2
// Explanation: The conversion can take place 
// in 2 operations:
// 1. Pick 'C' and place it at the front, 
//    A = "CAB"
// 2. Pick 'B' and place it at the front, 
//    A = "BCA"



//First Solution :-
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	if(A.length()!=B.length()){  //check of unequal length
	    	return -1;
	    }
	    int n=A.length(), i=0, j=n, sum=0, cnt=0;

	    //check for frequency of character in both the strings
	    for(int i=0;i<n;i++){
	    	sum+=A[i];
	    	sum-=B[i];
	    }

	    if(sum!=0){    //if all the character frequency are not same
	    	return -1;
	    }
        
        i=n-1, j=n-1;
	    while(i>=0 and j>=0){  //traversing from last element 
	    	if(A[i]==B[j]){    //if ith char in both are same keep on decreasing 
	    		i--;
	    		j--;
	    	}
	    	else{      //else increase the count and decrease i in first string
	    		cnt++;
	    		i--;
	    	}
	    }
	    return cnt;
    }
};


//Second Solution :-
int transfigure (string A, string B) {
    if (A.size() != B.size()) return -1;

    int odd_char = 0;
    for (int i = 0; i < A.size(); i++) 
    	odd_char += A[i] - B[i];

    if (odd_char) 
    	return -1;


    int a_index = A.size()-1, b_index = B.size()-1, count = 0;
    while (a_index >= 0) {
        if (B[b_index] != A[a_index]) count++;
        else b_index--;
        a_index--;
    }
    return count;
}



//Third Solution :- Simple C++ Solution using map
int transfigure (string A, string B)
{
	// Your code goes here
	int n = A.length(), m = B.length();
	
	if(n != m)
	    return -1;
	    
	map<char, int> mp1, mp2;
	
	for(char it : A)
	mp1[it]++;
	
	for(char it : B)
	mp2[it]++;
	
	if(mp1 != mp2)
	    return -1;
	
	int ans = 0;
	
	int i=n-1, j = n-1;
	
	while(i >= 0)
	{
	    if(A[i] == B[j])
	    j--;
	    else
	    ans++;
	    
	    i--;
	}
	
	return ans;
}


//Fourth Solution :-
// Idea :-
// If strings are not anagrams with respect to each other, answer is -1.
// Minimum Number of Operations = Len(B) - Max Length of subsequence of reverse(B) in reverse(A)

int transfigure (string A, string B)
    {
        vector<int> dp1(125),dp2(125);
        for(auto& c:A){
            dp1[c]++;
        }
        for(auto& c:B){
            dp2[c]++;
        }
        
        for(int i=0;i<125;i++){
            if(dp1[i]!=dp2[i]){
                return -1;
            }
        }
        
        //  find the longest subsequence of rev(B) in rev(A)
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        
        int n = A.length(),m = B.length(),j = 0;
        for(int i=0;i<n;i++){
            if(A[i]==B[j]){
                j++;
            }
            if(j==m){
                break;
            }
        }
        
        return m - j;
    }

