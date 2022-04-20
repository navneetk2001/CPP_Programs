// Given a non-negative number N in the form of string. The task is to apply at most one swap operation on the number N so that the result is just a previous possible number.
// Note:  Leading zeros are not allowed.

// Example 1:
// Input :
// S = "12435"
// Output: 12345
// Explanation: Although the number 12354 will be the largest smaller number from 12435. But it is 
// not possible to make it using only one swap. So swap 4 and 3 and get 12345.
 

// Example 2:
// Input: 
// S = " 12345"
// Output: -1
// Explanation: Digits are in increasing order. So it is not possible to make a smaller number from it.


//Approach :-
simple approach here is to traverse the string from backwards to find the non-decresing element and after that find the largest element smaller than previous selected element .
And after that swap the both and get answer.


//Solution Approach :-
class Solution{   
public:
    string previousNumber(string s){
        int n=s.size(); 
        int ind1=-1;
        for(int i=n-2;i>=0;i--){
        	if(s[i]>s[i+1]){
        		ind1=i;
        		break;
        	}
        }
        if(ind1==-1){
        	return "-1";
        }

        int ind2=-1;
        for(int i=ind1+1;i<n;i++){
        	if(s[i]<s[ind1]){
        		if(ind2==-1){
        			ind2=i;
        		}
        		else if(s[i]>s[ind2]){
        			ind2=i;
        		}
        	}
        }
        swap(s[ind1],s[ind2]);
        if(s[0]=='0'){
        	return "-1";
        }
        return s; 
    }
};



//Second Answer :-
string previousNumber(string S){
    int large=S.length()-2;
    int small=S.length()-1;
    while(large>=0 && S[large]<=S[large+1]){ 
    	large--;
    }

    if(large<0) return "-1";

    while(small>large && S[large]<=S[small]){ 
    	small--;
    }

    while(small>0 && S[small-1]==S[small]){
    	small--;
    }

    char temp=S[large];
    S[large]=S[small];
    S[small]=temp;

    if(S[0]=='0') return "-1";
    return S;
}
