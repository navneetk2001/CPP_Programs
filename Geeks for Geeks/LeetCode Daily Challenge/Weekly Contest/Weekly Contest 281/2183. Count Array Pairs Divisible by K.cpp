// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
// 	0 <= i < j <= n - 1 and
// 	nums[i] * nums[j] is divisible by k.
 

// Example 1:
// Input: nums = [1,2,3,4,5], k = 2
// Output: 7
// Explanation: 
// The 7 pairs of indices whose corresponding products are divisible by 2 are
// (0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
// Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
// Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2.    

// Example 2:
// Input: nums = [1,2,3,4], k = 5
// Output: 0
// Explanation: There does not exist any pair of indices whose corresponding product is divisible by 5.



//Solution :- Using gcd 
Explanation:-
If we have a number x and we want to find number y,such that x*y%k==0.
If we remove common factors of x and k,then we only have to find y such that k (after removing common factors with x) divides y.
Common factor between x and k is gcd (x,k).
k after removing common factors= k/gcd(x,k)
Now we need to find y such that y has one factor=k,for this we can find factors of every number and store in the array.
Time Complexity:- O(n*sqrt(max element of nums))


class Solution {
public:
    vector<int>factors;
    long long countPairs(vector<int>& nums, int k) {
        factors.resize(100001,0);
        long ans=0;
        for(auto & num:nums){
            int gcd=__gcd(num,k);
            int findMultipleOfThis=k/gcd;
            ans+=factors[findMultipleOfThis];
            getFactor(num);
        }
        return ans;
    }
    void getFactor(int &num){
        for(int i=1;i<=sqrt(num);i++)
            if(num%i==0){
                factors[i]++;
                if(i!=num/i)
                factors[num/i]++;
            }
    }
};


//Solution Approach :- 

// My aproach is to iterate to the numbers
// and find the maximum factor of this number nums[i]
// which also devide our number k name it num

// Then adding all the count of previous numbers 
// who are divisible by k / num

// Example [1, 2, 3, 4 5] k = 2

// In iteration 0 our count = [0, 0, 0, 0, 0, 0] and so on, not necessary for this example
// nums[0] = 1, so the maximum factor of 1 that also divide 2 is 1 so make num = 1
// now in previous numbers the numbers which are divisible by (k / num = 2) are count[k / num] = 0
// make ans += 0
// ans -> 0
// increase the count of the factors of num[0], so updated count = [0, 1, 0, 0, 0, 0]

// iteration 1
// num[1] = 2, maximum factor which divides (k = 2) is num = 2
// so count previous numbers which are divisible by (k / num = 1) is count[k / num] = 1
// ans += count[k / num]
// ans -> 1
// update count with factors , count = [0, 2, 1, 0, 0, 0]

// iteration 2
// num[2] = 3, maximum factor which divides k is num = 1
// ans += (count[k / num] = 1)
// ans -> 2
// count = [0, 3, 1, 1, 0, 0]

// iteration 3
// num[3] = 4, maximum factor which divides k is num = 2
// ans += (count[k / num] = 1)
// ans -> 5
// count = [0, 4, 3, 1, 0, 0]

// iteration 4
// num[4] = 5, maximum factor which divides k is num = 1
// ans += (count[k / num] = 2)
// ans -> 7
// count = [0, 5, 3, 1, 0, 1]

finally return ans = 7

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int count[100001] = {0};
        long long ans = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int num = 1;
            
//             To check what is the maximum factor that can be achived from the number nums[i] that also exist in k.
            
            for (int j = 1; j * j <= nums[i]; j++)
                if (nums[i] % j == 0)
                {
                     if (k % j == 0)
						num = max(num, j);

					if (k % (nums[i] / j) == 0)
						num = max(num, nums[i] / j);
                }
            
//             Adding all the numbers who are previous to the ith element and are divisibe by k / num.

            ans += count[k / num];
            
//             Updating the count of all the factors of a numbers untill ith index.
            
            for (int j = 1; j * j <= nums[i]; j++)
                if (nums[i] % j == 0)
                {
                    if (j * j == nums[i])
                        count[j]++;
                    else
                    {
                        count[j]++;
                        count[nums[i] / j]++;
                    }
                }
        }
        
        return ans;
    }
};



//Solution :- BruteForce
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
       long long i;
       long long c=0;
       long long v=(long long)(k); 
        
        for(i=0;i<nums.size()-1;i++)
        {
            long long j;
            for( j=i+1;j<nums.size();j++)
            {
                long long a=(long long)nums[i];
                long long b=(long long)nums[j];
                long long m=a*b;
                if(m%v==0)
                    c++;
            }
        }
        return c;
    }
};