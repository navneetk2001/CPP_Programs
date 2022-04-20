// Given an array numbers[] of N positive integers and a positive integer X, The task is to find the number of ways that X can be obtained by writing pair of integers in the array numbers[] next to each other. In other words, find the number of ordered pairs (i,j) such that i != j and X is the concatenation of numbers[i] and numbers[j]

// Example 1:
// Input:
// N = 4 
// numbers[] = {1, 212, 12, 12}
// X = 1212
// Output:
// 3
// Explanation:
// We can obtain X=1212 by concatenating:
// numbers[0] = 1 with numbers[1] = 212
// numbers[2] = 12 with numbers[3] = 12
// numbers[3] = 12 with numbers[2] = 12

// Example 2:
// Input: 
// N = 3
// numbers[] = {11, 11, 110}
// X = 11011
// Output:
// 2
// Explanation:
// We can obtain X=11011 by concatenating:
// numbers[2] = 110 with numbers[0] = 11
// numbers[2] = 110 with numbers[1] = 11




//Solution Approach :-
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        long long ans = 0;
        map<string, int>mp;  //string comparison
        string tmp = to_string(X);
        for(auto i:numbers){
        	mp[to_string(i)]++;
        }

        for(int i=0;i+1<tmp.size();i++){
        	string p=tmp.substr(0,i+1);   //Partitioning the string X each time with different i and checking the partition in map
        	string q=tmp.substr(i+1);
        	long long f1=mp[p];
        	long long f2=mp[q];
        	if(p==q){                     // if both partitions are same
        		ans+=f1*(f1-1);
        	}
        	else{                         // if both partitions are different
        		ans+=f1*f2;
        	}
        }
        return ans;
    }
}; 

//Explanation for above Solution :- 
// 1.first convert all vector element into string using to_string function.
// 2. convert X into string.
// 3. take a loop of size X.
// 4. take two string first and second within loop .
// 5. check substring of X if it exist then multiply the values.
//  such as s="12345"   first=1 and second=2345
// if 1 and 2345 pairs exists in map then multiply how much time 1 occurs and how much time 2345 occurs .



//Second Solution :-
class Solution{
    public:
    long long countPairs(int n, int x, vector<int> nums){
       map<int,int>mp;
       long long c=0;
       for(auto &num:nums)
            mp[num]++;
       
       int back=0;int tail=0;int mul=1;
       int digits =log10(x);
       for(int i=0;i<digits;i++){
           int tail=x%10;
           back=(tail*mul)+back; mul*=10;
           x=x/10;
           if(tail==0)
             continue;

           if(mp.find(x)!=mp.end()&&mp.find(back)!=mp.end()){
                if(x==back){
                     if(mp[x]>1)
                        c+=(mp[x]*(mp[x]-1));
                }
                else{
                    c+=(mp[x]*mp[back]);
                }
              
             }
       }
       return c;
    }
}; 