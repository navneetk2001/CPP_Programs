// Given a positive number k, we need to find a minimum value of positive integer n, such that XOR of n and n+1 is equal to k. If no such n exist then print -1.

// Example 1:
// Input: k = 3
// Output: 1
// Explaination: 1 xor 2 = 3.

// Example 2:
// Input: k = 6
// Output: -1
// Explaination: There is no such n, so that, n xor n+1 = k.



//Solution Approach :- 
// start from small input (Binary Representation)
// we can easily see some pattern if we do some dry run for 1 to 7
// we can say if n is even we get xor as 1 but we need minimum 
// if k=1 => we can say n=2
// if k=3 => we can see n=1

// we can say if k&(k+1) => 0, then answer would be k/2
// and in any other case answer would be -1


class Solution{
public:
    int xorCal(int k){
        if(k==1) return 2;
        if(k & (k+1) == 0) return k/2;
        return -1;
    }
};



//Another Approach :-
int xorCal(int k){
    if(k%2==0){
        return -1;
    }
    else{
        if(k==1){
            return 2;
        }
        int n1=k/2,n2=(k-n1);
        
        n1=log2(n1); n2=log2(n2);
        if(n1!=n2){
            return k/2;
        }
        else{
            return -1;
        }
    }
}

//Solution :-
class Solution{
public:
    int xorCal(int k){
        // code here
        if(k==1)return 2;
        if(k%2==0)return -1;
        int n=k/2;
        if((n^(n+1))==k)return(n);
        return -1;
        
    }
};


//Solution :-
class Solution{
public:
   int xorCal(int k){
       if(k==3)return 1;
       else if(k==1)return 2;
       else if(k==7)return 3;
       else if(k==15)return 7;
       else if(k==31)return 15;
       else if(k==63)return 31;
       else return -1;
   }
};