// Compare two version numbers version1 and version2.
// If version1 > version2 return 1,
// If version1 < version2 return -1,
// otherwise return 0.
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

// Here is an example of version numbers ordering:
// 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

// Input: version1 = "1.01", version2 = "1.001"
// Output: 0
// Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

// Input: version1 = "1.0", version2 = "1.0.0"
// Output: 0
// Explanation: version1 does not specify revision 2, which means it is treated as "0".

// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
// Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.


//Solution Approach :-
//Can you split two versions on ‘.’? How can it help you?


// First Method :-
int Solution::compareVersion(string A, string B) {
    int n=A.size(),m=B.size();
    int i=0,j=0;
    
    while(i<n or j<m){
        string s1,s2;
        while(i<n and A[i]!='.') s1+=A[i],i++;
        while(j<m and B[j]!='.') s2+=B[j],j++;
        i++,j++;
        
        if(s1.empty()){
            if(stold(s2)==0) continue;
            else return -1;
        }
        if(s2.empty()){
            if(stold(s1)==0) continue;
            else return 1;
        }
        if(stold(s1)>stold(s2)) return 1;
        else if(stold(s1)<stold(s2)) return -1;
    }
    return 0;
}



//Second Method :-
int Solution::compareVersion(string A, string B) {
    long double i=0,j=0;
        
    long double n = A.size();
    long double m = B.size();
    
    while(i<n || j<m){
        long double n1 = 0;
        long double n2 = 0;  
        while(i<n && A[i]!='.'){
            n1 = n1*10 + A[i]-'0';
            i++;
        }
        while(j<m && B[j]!='.'){
            n2 = n2*10 + B[j]-'0';
            j++;
        }
        
        if(n1 > n2){
            return 1;
        }
        else if(n2 > n1){
            return -1;
        }
        else{
            i++;
            j++;
        }
    }
    return 0;
}

//Third Method :-
string extract(int &i, string str){
    if(i >= str.size()){
        return "0";
    }
    int temp = i;
    stringstream ss;
    ss.str("");
    while(str[temp] != '.' && temp < str.size()){
        ss << str[temp];
        temp++;
    }
    i = temp + 1;
    
    return ss.str();
}

string rem(string a){
    int i = 0;
    while(a[i] == '0' && i < a.size()){
        i++;
    }
    
    return a.substr(i);
}

int compareStr(string a, string b, int first){
    
    string A = rem(a);
    string B = rem(b);
    
    if(A.size() > B.size()){
        return 1;
    }
    else if(A.size() < B.size()){
        return -1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            int numa = A[i];
            int numb = B[i];
            if(numa > numb){
                return 1;
            }
            else if(numa < numb){
                return -1;
            }
        }
    }
    
    return 0;
}

int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0, first = 1;
    while(i < A.size() || j < B.size()){
        string numa = extract(i, A);
        string numb = extract(j, B);
        if(compareStr(numa, numb, first) == 1){
            return 1;
        }
        else if(compareStr(numa, numb, first) == -1){
            return -1;
        }
        first = 0;
    }
    return 0;
}

//Fourth Solution :-
int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0;
    
    while(i<A.length() && j<A.length()){
        string x="";
        string y="";
        
        while(i<A.length() && A[i]=='0'){
                i++;
        }
            
        while(i<A.length() && A[i]!='.'){
            x+=A[i];
            i++;
        }
        
        while(j<B.length() && B[j]=='0'){
                j++;
        }
            
        while(j<B.length() && B[j]!='.'){
            y+=B[j];
            j++;
        }
        
        if(x!=y){
            if(x.length()==y.length())
                return x.compare(y) > 0 ? 1: -1;
            return x.length()>y.length() ? 1:-1;
        }
        
        i++;
        j++;
    }
    
    while(i<A.length() && A[i]=='0'){
        i++;
    }
    
    while(j<B.length() && B[j]=='0'){
        j++;
    }
    
    if(i>=A.length() && j>=B.length()){
        return 0;
    }
    
    return i>j ? 1 : -1;
}

