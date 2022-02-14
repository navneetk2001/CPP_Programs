// You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
// Return the rearranged number with minimal value.
// Note that the sign of the number does not change after rearranging the digits.

// Example 1:
// Input: num = 310
// Output: 103
// Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
// The arrangement with the smallest value that does not contain any leading zeros is 103.

// Example 2:
// Input: num = -7605
// Output: -7650
// Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
// The arrangement with the smallest value that does not contain any leading zeros is -7650.




//Solution :-
class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        if(num==0) return num;
        if(num<0){
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s);
        }
        sort(s.begin(), s.end());
        if(s[0]=='0'){
            for(int i=0; i<s.length(); i++){
                if(s[i]!='0'){
                    swap(s[i], s[0]);
                    break;
                }
            }
        }
        return stoll(s);
    }
};


//Solution :- 
class Solution {
public:
    long long smallestNumber(long long nums) {
        vector<int>v;
        long long d = nums;
        long long ans=0;
        d = abs(d);
        long long k=0,count=0;
        while(d>0){
            int a = d%10;
            d = d/10;
            if (a==0){
                count++;
            }
            v.push_back(a);
        }
        if (v.size()==1){
            return nums;
        }
        if (nums>0){
            sort(v.begin(), v.end());
            if (v[0]==0){
            ans = v[count]*pow(10,count);
            for(int i=count+1;i<v.size();i++){
                ans = ans*10+v[i];
            }
            }
            else{
                for (int i=0;i<v.size();i++){
                ans = ans*10+v[i];
            }
            }
            return ans;
        }
        else if (nums<0){
            sort(v.begin(), v.end(), greater<int>());
            for (int i=0;i<v.size();i++){
                ans = ans*10+v[i];
            }
            return ans*-1;
        }
        return nums;
    }
};

 
//Solution using min & max heap
class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0)
            return 0;
        vector<int>temp;
        int r,z=0;
        string ans="";
        long long ll;
        if(num>0){
            priority_queue<int,vector<int>,greater<int>>pq;
            while(num>0)
            {
                r=num%10;
                num/=10;
                if(r==0)
                    z++;
                else
                    pq.push(r);
            }
            ans+=to_string(pq.top());
            pq.pop();
            while(z--)
                ans+="0";
            while(!pq.empty())
            {
                ans+=to_string(pq.top());
                pq.pop();
            }
             ll = stoll(ans);
        }
        else
        {
              priority_queue<int>pq;
            num*=-1;
            while(num>0)
            {
                r=num%10;
                num/=10;
                if(r==0)
                    z++;
                else
                    pq.push(r);
            }
           
          
            while(!pq.empty())
            {
                ans+=to_string(pq.top());
                pq.pop();
            }
              while(z--)
                ans+="0";
      ll = std::stoll(ans);
          ll*=-1;
        }
      
        return ll;
    }
};