// Given a number num, our task is to find the closest Palindrome number whose absolute difference with given number is minimum. If 2 Palindome numbers have same absolute difference from the given number, then find the smaller one.
 
// Example 1:
// Input: num = 9
// Output: 9
// Explanation: 9 itself is a palindrome number.

// Example 2:
// Input: num = 489
// Output: 484
// Expnataion: closest palindrome numbers from 489 are 484 and 494. Absolute difference between 489 and 494 is equal to the absolute difference between 484 and 489 but 484 is smaller than 494.


//Solution Approach :-
For any possible number, there is 5 cases:
Say the number is 4723

Case 1. The next closest palidrome has one digit extra : So here it will be 10001
Case 2. The next closest palindrome has one digit less: So here it will be 999
Case 3. The next closest palidrome has the same number of digits
For case 3 there are 3 subcases:
	-The middle digit remains same.Postfix is the mirror image of prefix. So here 47(prefix)74(postfix)-->4774
	-The middle digit increases by 1.Postfix is the mirror image of prefix. So here 4884
	-The middle digit decreases by 1.Postfix is the mirror image of prefix. So here 4664
Among these 5 candidates:
The candidate having the least absolute difference from the original number is the answer. In this case it is 4774.

class Solution {
public:
	long long int closestPalindrome(long long int num){
	    long long digits = 0, n1 = num;
        while(n1) {
            digits++;
            n1 /= 10;
        }
        
        if(digits == 1) return num;
        
        vector<long long> candidates;
        candidates.push_back(pow(10, digits-1)-1);
        candidates.push_back(pow(10, digits)+1);
        
        long long mid = (digits+1)/2;
        long long prefix = num / pow(10, digits-mid);
        vector<long long> v = {prefix, prefix-1, prefix+1};
        
        for(long long i:v) {
            string postfix = to_string(i);
            if(digits%2 != 0) postfix.pop_back();
            reverse(postfix.begin(),postfix.end());
            string c=to_string(i)+postfix;
            candidates.push_back(stol(c));
        }
        
        long long minDiff = LLONG_MAX, res;
        for(long long c:candidates) {
            if(abs(c-num) < minDiff) {
                minDiff = abs(c-num);
                res = c;
            } 
            else if(abs(c-num) == minDiff) {
                res = min(res, c);
            }
        }
        return res;
	}

};


//Second Solution :-
long long int N = 0;
bool comp(long long int a, long long int b) {
    return abs(N-a) < abs(N-b);
}

class Solution {
public:
    long long int mkPal(long long int num) {
        string s = to_string(num);
        int n = s.length();
        
        for(int i=0; i<n/2; i++){
            s[n-i-1] = s[i];
        }
        
        stringstream ss(s); 
        ss>>num;
        return num;
    }
    
	long long int closestPalindrome(long long int num){
	    long long int d = (to_string(num)).length();
	    if(d == 1) return num;
	    
	    N = num;
	    long long int ans[4] = {0};
	    ans[0] = mkPal(num-pow(10ll, (d-1)/2));
	    ans[1] = mkPal(num-pow(10ll, d/2));
	    ans[2] = mkPal(num);
	    ans[3] = mkPal(num+pow(10ll, d/2));
	    
	    sort(ans, ans+5, comp);
	    
	    return ans[0];
	}

};



//Third Solution :-

// Approach :-

// We know a palindrome is nothing but a reflection of its left or right part.
// There are some edge cases to consider though...
// If there is just one digit in a string, i.e. size of string is 1, we need to return str-1.
// If there is a string like 10,100,100,1000...etc, return str-1.
// If there is a string starting with 1 and ends with 1 but is filled with all zeroes in the midPart, return str-2.
// If string is filled with only 9s, return str+2
// Other than this exception cases, We need to find three palindromes, taking 1434 as example
// Mirror Image of left on Right. -> 1441
// Add 1 to left Part and append reverse of it -> 1551
// Subtract 1 from left Part and append reverse of it -> 1331
// Now just calculate difference and find answer as based upon the conditions of the question. 
// If it is already palindrome return the answer

 

class Solution {
public:
    bool all9s(string &str){
        for(auto c: str){
            if(c!='9'){
                return false;
            }
        }
        return true;
    }
    
    bool all0s(string &str, int start, int end){
        for(int i=start;i<end;i++){
            if(str[i]!='0'){
                return false;
            }
        }
        return true;
    }
    
    void REVERSE(string &str){
        reverse(str.begin(),str.end());
    }
    
    bool isPalindrome(string &S, int n){
        int i=0;
        int j=n-1;
        while(i<=j){
            if(S[i]!=S[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

	long long int closestPalindrome(long long int num){
	    string str=to_string(num);
	    int n=str.size();
	    
	    if(isPalindrome(str,n)==true){
	        return num;
	    }
        
        if(str.size()==1 || (str[0]=='1' && all0s(str,1,n)==true)){  // for numbers in range 1-9 or 100 1000 1000 etc
            return stoll(str)-1;
        }
        
        if(all9s(str)==true){  // All 9s , just add strNum+2
            return stoll(str)+2;
        }
        
        if(str[0]=='1' && str[n-1]=='1' && all0s(str,1,n-1)==true){  // 1001, 101, 11, 1000001, ....
            return stoll(str)-2;
        }
        
        string palindromeRootStr=str.substr(0,(n+1)/2);
        string left,right;
        
        right=palindromeRootStr;
        left=palindromeRootStr;
        REVERSE(right);
        right=right.substr(n%2);
        string MirrorLeftToRight=left+right;
        // cout<<"MirrorLeftToRight-> "<<MirrorLeftToRight<<endl;
        
        
        long long int IncrementedLeft=stoll(palindromeRootStr)+1;
        left=to_string(IncrementedLeft);
        right=to_string(IncrementedLeft);
        REVERSE(right);
        right=right.substr(n%2);
        string AddOneToLeftAndMirror=left+right;
        // cout<<"AddOneToLeftAndMirror-> "<<AddOneToLeftAndMirror<<endl;
        
        
        long long int DecrementedLeft=stoll(palindromeRootStr)-1;
        left=to_string(DecrementedLeft);
        right=to_string(DecrementedLeft);
        REVERSE(right);
        right=right.substr(n%2);
        string SubOneToLeftAndMirror=left+right;
        // cout<<"SubOneToLeftAndMirror-> "<<SubOneToLeftAndMirror<<endl<<endl;
        
        
        long long int JUST_MIRROR=stoll(MirrorLeftToRight);
        long long int ADD_ONE_MIRROR=stoll(AddOneToLeftAndMirror);
        long long int SUB_ONE_MIRROR=stoll(SubOneToLeftAndMirror);
        long long int ORIGINAL=stoll(str);
        
        int minDiff=INT_MAX;
        string res="";
        
        if(abs(ORIGINAL-JUST_MIRROR)<minDiff){ 
            res=MirrorLeftToRight;
            minDiff=abs(ORIGINAL-JUST_MIRROR);
        }
        if(abs(ORIGINAL-ADD_ONE_MIRROR)<minDiff){
            res=AddOneToLeftAndMirror;
            minDiff=abs(ORIGINAL-ADD_ONE_MIRROR);
        }
        if(abs(ORIGINAL-SUB_ONE_MIRROR)<minDiff){
            res=SubOneToLeftAndMirror;
            minDiff=abs(ORIGINAL-SUB_ONE_MIRROR);
        }
        
        if(abs(ORIGINAL-JUST_MIRROR)==minDiff && stoll(res)>JUST_MIRROR){
            res=MirrorLeftToRight;
        }
        if(abs(ORIGINAL-ADD_ONE_MIRROR)==minDiff && stoll(res)>ADD_ONE_MIRROR){
            res=AddOneToLeftAndMirror;
        }
        if(abs(ORIGINAL-SUB_ONE_MIRROR)==minDiff && stoll(res)>SUB_ONE_MIRROR){
            res=SubOneToLeftAndMirror;
        }
        
        return stoll(res);
	}
};



//Fourth Solution :-
Approach:-
//most likely this will be a ans 
    // if 10, 10000 and 197 ,17 like input is their so we have to upadte some thing       //in ans
    //the ans if most likely upper one becoz if fist half is same so on that way only       //we are going to found diff between ans and num is lesser
    // bet in the case of like 10000 their will be two ans 9999 and 10001 but 9999 is     //a ans and in 197 =>191 and 202 and 202 is and so for that sume times
    //we have to do sume plus minus of value 1 with only for one position else we      //found bigger abd diff
    

long long int make_pal(long long int num){
   string s=to_string(num);
   int n=s.length();
   int i=0,j=n-1;
   while(i<j){
       s[j]=s[i];
       i++;
       j--;
   }
    return stoll(s);
}


long long int closestPalindrome(long long int num){
    long long int ans=make_pal(num);         

    int gap=abs(ans-num);     
    for(int i=0;i<15;i++){
        int z=pow(10,i);          
        //becoz only we have to change one number like in 23432 we have to                     //change 3rd no. 23432+100=13532 like something thwt
        if(num-z>0){                //check if z is bigger then our input
            long long int temp=make_pal(num-z);
            if(gap>=abs(temp-num)){
                if(gap==abs(temp-num)){
                    ans=min(temp,ans);            //if found same min diff two number then take min one
                }
                else{
                    ans=temp;
                }
            }
        }
        if(num+z<1e15){
           long long int temp=make_pal(num+z);
             if(gap>=abs(temp-num)){
                if(gap==abs(temp-num)){
                    ans=min(temp,ans);            //if found same min diff two number then take min one
                }
                else{
                    ans=temp;
                }
            }
        }
    }
    return ans;
}

