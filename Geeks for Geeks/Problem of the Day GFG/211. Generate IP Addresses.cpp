https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1




//Solution Approach :- For loop literal - O(N^4)
// We scan all position 3 dots (.) can insert. We will partition the string to 4 parts. Check the valid number of 4 parts. If valid, add it to the vector.
// Note: It sure not valid if 4 parts have length smaller than 4 or larger than 4 * 3 = 12. Here are the solution:

class Solution{
  public:
    bool isValidNumber(string p) {
        int n = p.size();
        if (n >= 2 && p[0] == '0'){
            return false;
        }
        if (n >= 4){
            return false;
        }
        return stoi(p, nullptr, 10) <= 255;
    }

    vector<string> genIp(string &s) {
        int n = s.size();
        if (n < 4 || n >= 13){
            return vector <string> {};
        }

        vector <string> res;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    string p1(s.begin(), s.begin() + i + 1);
                    string p2(s.begin() + i + 1, s.begin() + j + 1);
                    string p3(s.begin() + j + 1, s.begin() + k + 1);
                    string p4(s.begin() + k + 1, s.end());
                    if (isValidNumber(p1) && isValidNumber(p2) && isValidNumber(p3) && isValidNumber(p4)){
                        res.push_back(p1 + "." + p2 + "." + p3 + "." + p4);
                    }
                }
            }
        }
        return res;
    }
};




//Second Solution :- BackTracking
class Solution{
    int n;
    vector<string> res;
  public:
    void rec(int ind, int partitions, string curr, string s){
        if(ind == n){
            if(partitions == 4){
            	curr.pop_back(), res.push_back(curr);
            }
            return;
        }
        if(partitions > 3)  return;
        
        for(int i=ind; i<ind+3 && i<n; i++){
            string sub = s.substr(ind, i-ind+1);
            if(stoi(sub) > 255 or (sub.length() > 1 && sub[0] == '0')){
            	continue;
            }
            
            string ne = curr + sub + '.';
            rec(i+1, partitions+1, ne, s);
        }
    }

    vector<string> genIp(string &s) {
        n = s.length();
        if(n < 4)   return {};
        rec(0, 0, "", s);
        return res;
    }

};



//Third Solution :- 
bool vali(string s)
{
    int n=s.length();
    if(n<=0 || n>3)
        return false;
    if(s[0]=='0' && n>1)
        return false;
    int p=stoi(s);
    if(p<0)
        return false;
    if(p>255)
        return false;
    return true;
}
string valid(string s,int n,int i,int j,int k)
{
    string s1=s.substr(0,i+1);
    string s2=s.substr(i+1,j-i);
    string s3=s.substr(j+1,k-j);
    string s4=s.substr(k+1,n-1-k);
    if(vali(s1) && vali(s2) && vali(s3) && vali(s4))
    {
        return s1+"."+s2+"."+s3+"."+s4;
    }
    return "";
}
vector<string> genIp(string &s) {
    vector<string>res;
    int n=s.length();
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                string d=valid(s,n,i,j,k);
                if(d.length()>0)
                {
                    res.push_back(d);
                }
            }
        }
    }
    return res;
}