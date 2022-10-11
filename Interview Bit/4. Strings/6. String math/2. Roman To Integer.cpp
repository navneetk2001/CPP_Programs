// Given a string A representing a roman numeral.
// Convert A into integer.
// A is guaranteed to be within the range from 1 to 3999.
// NOTE: Read more details about roman numerals at Roman Numeric System

//Hint :-
// Note how the number XVI(10+5+1) and XIV(10-1+5) differs.
// In one case we are adding the numeric value of a letter and in other case we are subtracting it. How can you simulate this?

//Solution Approach :-
// The key is to notice that in a valid Roman numeral representation the letter with the most value always occurs at the start of the string.
// Whenever a letter with lesser value precedes a letter of higher value, it means its value has to be added as negative of that letter’s value.
// In all other cases, the values get added.


// First Method :-
int Solution::romanToInt(string A) {
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0, i = 0, n = A.size();
    while(i <= n-1){
        if(m[A[i]] < m[A[i+1]]){
            ans-=m[A[i]];
        }
        else{
            ans+=m[A[i]];
        }
        i++;
    }
    return ans;
}


//Second Method :-
int sanu(char A){
    if(A=='I') return 1;
    if(A=='V') return 5;
    if(A=='X') return 10;
    if(A=='L') return 50;
    if(A=='C') return 100;
    if(A=='D') return 500;
    if(A=='M') return 1000;
    
}

int Solution::romanToInt(string A) {
    int n=A.size();
    int sum=0;
    if(n==0) return 0;
    sum+=sanu(A[n-1]);
    for(int i=n-2; i>=0; i--){
        if(A[i]=='I'&&(A[i+1]=='X'|| A[i+1]=='V')){
            sum-=1;
        }
        else if(A[i]=='X'&&(A[i+1]=='C'|| A[i+1]=='L')){
            sum-=10;
        }
        else if(A[i]=='C'&&(A[i+1]=='D'|| A[i+1]=='M')){
            sum-=100;
        }
        else{
            sum+=sanu(A[i]);
        }
    }
    return sum;
}


//Third Method :-
int Solution::romanToInt(string s) {
    int len=s.size();
    int i=0;
    int sum=0;
    while(i<len)
    {
        if(s[i]=='M'){
            sum=sum+1000;
            i=i+1;
        }
        else if(s[i]=='I' && i+1<len && s[i+1]=='V'){
            sum=sum+4;
            i=i+2;
        }
        else if(s[i]=='I' && i+1<len && s[i+1]=='X'){
            sum=sum+9;
            i=i+2;
        }
        else if(s[i]=='I'){
            sum=sum+1;
            i=i+1;
        }
        else if(s[i]=='X' && i+1<len && s[i+1]=='L'){
            sum=sum+40;
            i=i+2;
        }
        else if(s[i]=='X' && i+1<len && s[i+1]=='C'){
            sum=sum+90;
            i=i+2;
        }
        else if(s[i]=='X'){
            sum=sum+10;
            i=i+1;
        }
        else if(s[i]=='C' && i+1<len && s[i+1]=='D')
        {
            sum=sum+400;
            i=i+2;
        }
        else if(s[i]=='C' && i+1<len && s[i+1]=='M')
        {
            sum=sum+900;
            i=i+2;
        }
        else if(s[i]=='C')
        {
            sum=sum+100;
            i=i+1;
        }
        else if(s[i]=='V')
        {
            sum=sum+5;
            i=i+1;
        }
        else if(s[i]=='L')
        {
            sum=sum+50;
            i=i+1;
        }
        else if(s[i]=='D')
        {
            sum=sum+500;
            i=i+1;
        }
    }
    return sum;
}








