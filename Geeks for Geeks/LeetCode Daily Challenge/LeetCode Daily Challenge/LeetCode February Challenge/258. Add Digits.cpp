// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Example 1:
// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
// Since 2 has only one digit, return it.

// Example 2:
// Input: num = 0
// Output: 0



//  BruteForce Approach :- 
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>9){       //we will repeat the same procedue till num becomes one digit number
        	while(num>0){     //this will find sum of digits
        		sum+=(num%10);
        		num/=10;
        	}
        	num=sum;    //Make num as sum
        	sum=0;      //Make sum=0
        }
        return num;
    }
};


//Approach 2 :- Based on Observation :- O(1)
// We can observe based on a pattern which it is following :- 
// For E.g :- n=0 => sum=0,  n=10 => sum=1,  n=20 => sum=2
// Then we can derive that if we do => (num%9) we will get the sum as answer
class Solution {
public:
    int addDigits(int num) {
        if(num==0)
        	return 0;
        else if(num%9 == 0)
        	return 9;
        else
        	return num%9;
    }
};



//Approach 3 :- RECURSION 
class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num)
        {
            sum+=(num%10);
            num/=10;
        }
        if(sum<10)
            return sum;
        else
            return addDigits(sum);
    }
};