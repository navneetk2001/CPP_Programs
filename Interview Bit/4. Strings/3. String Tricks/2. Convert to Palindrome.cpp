Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.
If it is possible then return 1 else return 0.


//Hint :-
We can solve this problem by finding the position of mismatch. We start looping in the string by keeping two pointers at both the ends which traverse towards mid position after each iteration, this iteration will stop when we find a mismatch, as it is allowed to remove just one character we have two choices here,

//Solution Approach :-
We can solve this problem by finding the position of mismatch. We start looping in the string by keeping two pointers at both the ends which traverse towards mid position after each iteration, this iteration will stop when we find a mismatch, as it is allowed to remove just one character we have two choices here,
At mismatch, either remove character pointed by left pointer or remove character pointed by right pointer.
We will check both the cases, remember as we have traversed equal number of steps from both sides, this mid string should also be a palindrome after removing one character, so we check two substrings, one by removing left character and one by removing right character and if one of them is palindrome then we can make complete string palindrome by removing corresponding character, and if both substrings are not palindrome then it is not possible to make complete string a palindrome under given constraint.
Time Complexity : O(len(A))


// First Method :-
int Solution::solve(string A) {
    int j=A.length()-1,i=0,count=0;
    while(i<=j){
        if(count>1) return 0;
        if(A[i]!=A[j]){
            count++;
            i++;
            continue;
        }
        i++;
        j--;
    }
    return 1;
}


//Second Method :-
bool check(string &A, int i, int j){
    while(i<j){
        if(A[i]!=A[j])return false;
        i++;
        j--;
    }
    return true;
}

int Solution::solve(string A) {
    int i=0;
    int j=A.size()-1;
    bool found=false;
    bool out=false;
    
    while(i<j){
        if(A[i]!=A[j]){
            out=out||check(A,i+1,j);
            out=out||check(A,i,j-1);
            found=true;
            break;
        }
        i++;
        j--;
    }
    
    if(!found)return 1;
    return out;
}


//Third Method :-
int Solution::solve(string A) {
    int left = 0;
    int right = A.size()-1;
    int count = 0;
    while(left<right)
    {
        if(A[left]==A[right]){left++;right--;}
        else if(A[left+1]==A[right]){count++;left++;}
        else if(A[left]==A[right-1]){count++;right--;}
        else return 0;
    }
    if(count == 0 and left == right) return 1;
    if(count == 1) return 1;
    return 0;
}

//Fourth Method :-
bool palindrome(string s){
    int start = 0, end = s.length()-1;
    while(start<end){
        if(s[start++] != s[end--]) return 0;
    }
    return 1;
}
int Solution::solve(string A) {
    
    int n = A.length();
    int start = 0, end = n-1;
    
    // Find the Mismatch indexes
    while(start<end){
        if(A[start] == A[end]){
            start++;
            end--;
        }
        else{
            break;
        }
    }
    
    // Try to delete start index char or end index char. if any of the string is palindrome
    // we can delete exactly one element.
    if(start<end){
        string s1 = A.substr(0,start) + A.substr(start+1);
        string s2 = A.substr(0,end) + A.substr(end+1);
        return palindrome(s1) || palindrome(s2);
    }
    return 1;
    
    
}



