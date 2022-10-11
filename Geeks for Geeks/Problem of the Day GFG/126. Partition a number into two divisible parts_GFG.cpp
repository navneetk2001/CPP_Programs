// Given a number (as string) and two integers a and b, divide the string in two non-empty parts such that the first part is divisible by a and the second part is divisible by b. In case multiple answers exist, return the string such that the first non-empty part has minimum length.

// Example 1:
// Input: 1200 4 3
// Output: 12 00
// Explanation: 12 is divisible by 4, and 00 is divisible by 3.
 
// Example 2:
// Input: 125 12 5
// Output: 12 5
// Explanation: 12 is divisible by 12, and 5 is divisible by 5.



//Solution Approach :-
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        vector<int> pr(s.size(), 0);
        vector<int> sr(s.size(), 0);

        for (int i = 0; i < s.size(); i++){
            if (i == 0){
                pr[i] = (s[i] - '0') % a;
            }
            else{
                pr[i] = (((pr[i - 1]) * 10 % a) % a + (s[i] - '0') % a) % a;
            }
        }

        int n = s.size();
        int mul = 1;
        for (int i = n - 1; i >= 0; i--){
            if (i == n - 1){
                sr[i] = (s[i] - '0') % b;
            }
            else{
                sr[i]=(((s[i]-'0')*mul%b)%b+(sr[i+1]))%b;
            }
            mul = mul * 10;
        }
        
        string p1;
        string p2;
        for (int i = 0; i < n; i++){
            if ((i+1)<n&&pr[i] == 0 && sr[i + 1] == 0){
                p1=s.substr(0,i+1);
                p2=s.substr(i+1);
                break;
            }
        }
        string ans=p1+" "+p2;
        return ans==" "?"-1":ans;
    }
};



//Second Solution :-
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        int n = S.length();
        for(int i = 1; i < n; i++) {
            string s1 = S.substr(0, i);
            string s2 = S.substr(i);
            if(stoi(s1) % a == 0 && stoi(s2) % b == 0){ 
                return s1 + " " + s2;
            }
        }
        return "-1";
    }
};

