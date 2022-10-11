// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 
// Example 1 :
// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a possible solution. 9 + 3 = 12 is divisible by 6 and 7 + 5 = 12 is also divisible by 6.

// Example 2:
// Input : arr = [2, 4, 1, 3], k = 4
// Output: False
// Explanation: There is no possible solution.




//Solution Approach :-
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> rem(k);
        for(int x : nums){
        	rem[x % k]++;
        }
        	
        if(rem[0] % 2){
        	return false;
        }
        
        for(int i = 1; i < k; ++i){
        	if(rem[i] != rem[k - i]){
        		return false;
        	}
        }
        return true;
    }
};




//Second Solution :-
//we need to find whether element can be made into pairs such that every pair gets divisible
//so reminder theory should come in mind, if reminder is remaining, we will pair that element with such a reminder that makes it divisible
//for example, 2%3==2 ans 1%3==1 and 2+1 makes 3 whose reminder would be 0, hence divisible
//We need to handle two cases :
/*  1) when reminder==0
    2) when reminder not equal to 0 */
bool canPair(vector<int> a, int k) {
    int n=a.size();
    if(n%2){               //if odd length: pairs can't be formed
        return false;
    }
    
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++){
        if(a[i]%k==0){
            if(mp.find(0)!=mp.end()){        //if zero exists we found a pair,freq of 0 is decreased!
                mp[0]--;              
                if(mp[0]==0){
                    mp.erase(0); //erase as pair is complete and no more zero reminder elements are left
                }
            }
            else{
                mp[0]++;  //if till now not found any 0 rem element increase its frequency
            }
        }
        else if(mp.find(k-a[i]%k)!=mp.end()){       //same goes for non zero reminder elements
           mp[k-(a[i]%k)]--;
           if(mp[k-(a[i]%k)]==0){
               mp.erase(k-(a[i]%k));
           }
       }
       else{
           mp[a[i]%k]++;
       }
    }
    if(mp.size()!=0){
        return false;        //if map is not empty means some elements can't be paired!
    }                        
    return true;
}


