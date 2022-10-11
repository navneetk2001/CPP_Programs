// Find if Given number is power of 2 or not. 
// More specifically, find if given number can be expressed as 2^k where k >= 1.

// Input: number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)


//Hint :-
// There is no shortcut to this problem.
// We need to divide the number by 2 till it is greater than 1.
// At any point, if the last digit is odd, then the number is not a power of 2.

// For example,
// If the number is 10. 
// 10 has 0 as the last digit, so it is even
// Next step, 10 / 2 = 5
// 5 is odd, so the answer is 0.

//Solution Approach :-
// Loop until n not equal to 1 and also n is even :
//         n divided by 2
// IF n is equal to 1
//         return 1
// ELSE 
//     return 0
// Lets see how we would implement division by 2.
// The division process is just the simulation of human division process.
// Start from the first digit. If the current digit is less than 2, then we append the next digit to current digit, and append 0 to our answer.


//First Solution :-
int Solution::power(string A) {
    int N = A.length();
    int num = A[0]-'0';
    for(int i = 1; i<N; i++){ 
        num = (num*10)+(A[i]-'0');
    }

    if(num == 1) return 0;

    int power = log(num)/log(2);
    if(pow(2,power) == num) {
        return 1;
    }
    else {
        return 0;
    }
}


//Second Solution :-
//Method 2 : for eg: 8 - 1000 and 7 - 0111. So 1000&0111 = 0. 
int Solution::power(string A) {
    int N = A.length();
    int num = A[0]-'0';

    for(int i = 1; i<N; i++){ 
        num = (num*10)+(A[i]-'0');
    }
    if(num==1){
        return 0;
    }
    if((num & (num-1))==0){
        return 1;
    }
    return 0;
}


//Third Solution :-
int Solution::power(string A) {
    int i,j,k,l,m,n,num=0;
    n =A.size();
    for(i=0;i<n;i++){
        num = num*10 + (A[i]- '0');
        if(num>INT_MAX){
            return 0;
        }
    }
    m = num;
    
    if(num==1){
        return 0;
    }
    m = (!(num&(num-1)));
    return m;
}


//Fourth Solution :-
bool check0str(string a){
    int n = a.size();
    for(int i=0; i<n-1; i++)
    if(a[i] != '0') return false;
    if(a[n-1] == '1') return true;
    return false;
}

int Solution::power(string a) {
    int n = a.size();
    
    int j=0;
    while(a[j] == '0') j++; 
    if(n-j == 1 & a[0] == '1') return 0;
    
    while(!check0str(a)){
        
        if((a[n-1] - '0')%2 == 1) return 0;
        
        int carry = 0;
        string temp = "";
        for(int i=0; i<n; i++){
            temp.push_back('0' + carry+(a[i] - '0')/2);
            carry = (a[i] - '0')%2 == 1 ? 5: 0;
        }
        a = temp;
    }
    return 1;
}


//Fifth Solution :-
int Solution::power(string A)
{
    long double num = stold(A);
    if(num==1){
        return 0;
    }
    if(floor(log2(num)) == ceil(log2(num))){
        return 1;
    }
    return 0;
}
