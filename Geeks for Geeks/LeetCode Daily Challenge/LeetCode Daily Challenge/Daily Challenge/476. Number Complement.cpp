The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

Example 1:
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.



//Solution Approach :-  In this Approach we are just flipping those ith bit by multiplying with 0 and 1
int findComplement(int num){
    int res=0;
    long long pro=1;
    
    while(num>0){
        int bit=num%2;
        if(bit==0){
            res+=pro*1;
        }
        else{
            res+=pro*0;
        }
        pro=pro*2;
        num/=2;
    }
    return res;
}



//Second Solution :-  //Setting all the ith bit and then subtracting actual no from that no will give us required answer
int findComplement(int num){
    int temp=0,p=0;
    while(temp<num)
    {
        temp+=pow(2,p);
        p+=1;
    }
    return temp-num;
}

//For e.g : Like num=1001 then temp=1111 and ans=temp-num


//Third Solution :- Find the length of given number and then find the number with all those ith bit set  and then xor with actual numbers
int findComplement(int num){
    int binaryLength = floor(log2(num)) +1;  //it gives number of bits
    int mask = (long long int) (1 << binaryLength) - 1 ;  //it give maximum number
    return num ^ mask;
}
