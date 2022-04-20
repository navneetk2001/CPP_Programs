Given an integer A find the Ath number whose binary representation is a palindrome.

NOTE:
Consider the 1st number whose binary representation is palindrome as 1, instead of 0
Do not consider the leading zeros, while considering the binary representation.

//Hint :-
Algorithm:

We can divide the set of palindrome numbers into some groups.
n-th group will have (2^(n-1) + 2^n = 3 * 2 ^(n-1) ) number of binary palindromes
With the given number, we can find the group to which it belongs to and the offset in that group.
As the leading zeros are not to be considered, we should use bit 1 as the starting bit and ending bit of the number in binary representation
And we will fill other bits based on the groupno and groupoffset
Based on the offset, we can find which bit should be inserted at the middle and which number(in binary form) (1 or 2 or 3 or 4 or ..) should be placed in both directions from middle

//Solution Approach :- 
Algorithm:

We can divide the set of palindrome numbers into some groups.
n-th group will have (2^(n-1) + 2^n = 3 * 2 ^(n-1) ) number of binary palindromes
With the given number, we can find the group to which it belongs to and the offset in that group.
As the leading zeros are not to be considered, we should use bit 1 as the starting bit and ending bit of the number in binary representation
And we will fill other bits based on the groupno and groupoffset
Based on the offset, we can find which bit should be inserted at the middle and which number(in binary form) (1 or 2 or 3 or 4 or ..) should be placed in both directions from middle
Let us construct the 8th binary palindrome number
The group number will be 2, and no.of elements 
before that group are 1 + 3 * 2^1 which is 4

So the offset for the 8th element will be 8 - 4
 - 1 = 3

And first 2^(groupno - 1) = 2^1, elements will 
have even length(in binary representation) of
2*groupno, next 2^groupno elements will have odd 
length(in binary representation) of 2*groupno + 1

Place bit 1 as the first bit and as the last bit 
(firstbit: 0, last bit: 2*groupno or 2*groupno - 1)

As the offset is 3, 4th(3 + 1) element in the
group, will have odd length and have 1 in the 
middle

Below is the table of middle bit to be used for 
the given offset for the group 2
offset    middle bit
  0            |
  1            |
  2            0
  3            1
  4            0
  5            1
And we should be filling the binary representation 
of number 0(((groupoffset) - 2^(groupno-1)) /2)
from middle n both directions
1 0 1 0 1
FirstElement Number MiddleElement Number LastElement
    1           0         1         0         1

The 8th number will be 21


//Solution :- 
int Solution::solve(int A) {
// Initially for length 1 binary palindrome there exists 1 so count = 1.
// We know the count increases for length as len:1,2,3,4,... then count:1,1,2,2,4,4,8,8,...
int len = 1;
int count = 1;

while(count < A){
    len++;
    count += 1 << (len-1)/2;// For length len, there exists 2^((len-1)/2) binary palindromes 
}                           // So we add that to count

count -= (1 << (len-1)/2); // Since count becomes >= A after while loop we remove last groups length
int offset = A-count-1; // Now offset is how much should we add to the first member of that group to get result

int ans = 1 << (len-1); // Ex: For A = 9, len = 5, so we create 10000 ; len-1 zeros are there
ans |= offset << (len/2); // Now for the same A, offset = 2, so we add 1000 to 10000; we moved 10 by len/2 to left which is 2

//Now our ans = 11000; now what we do is get 110 and reverse it (011) and OR it with ans.
offset = ans >> (len)/2;
int reverse = 0;

while(offset){
    reverse = reverse << 1;
    reverse |= offset & 1;
    offset = offset >> 1;
}

ans |= reverse; //11000 OR 00011 = 11011 = 27
return ans;
}


//First Solution :-
int Solution::solve(int A) {
    int prev=0,ans=1;
    for(int i=0;i<32;i++){
        long long int x=(1<<(i/2));// cout<<prev<<" "<<x<<endl;
        if(prev+x>=A){ 
            ans|=(1<<i);
            bool activate=0;
            for(int j=i-1;j>=(i+1)/2;j--){ //cout<<prev<<" "<<x<<" "<<prev+x/2<<" sum "<<endl;
                if(prev+x/2>=A&&activate!=1){
                    if(prev+x/2==A){activate=1;}
                }
                else{// cout<<j<<" correct "<<ans<<" added is "<<(1<<j)<<" and "<<(1<<(i-j))<<endl;
                    ans|=(1<<j);ans|=(1<<(i-j)); prev+=x/2;
                }
                x/=2;
            } return ans;
        }
        prev+=x;
    }
    return ans;
}



//Second Solution :-
string conv(int digits, int num)
{
    num--;
    string s="";
    for(int i=0;i<digits;i++)
    s.push_back('0');

    for(int i=0;i<digits;i++)
    {
        s[i] = s[i] + (  ( num & (1<<i) ) != 0 ) ;
    } 

    reverse(s.begin(),s.end());
    return s;
}

int sol(string s)
{
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(s[i]=='1')
        ans = ans | (1 << i);
    }
    return ans;
}

int Solution::solve(int A) {
    /*
    if(A==1) return 1;
    else if(A==2) return 3;
    else
    {
        
        int req = floor(log(A)/log(2)) ;
                cout<<req<<endl;
        
        int pres=0;
        int prev=0;
        for(int i=2;i< pow(2,32);i=i*2)
        {
            prev=pres;
            pres =pres+i;
            if(pres > A)
            break;
        }
        
        prev = A -prev -1;
        cout<<prev<<endl;

        
        if(req%2==0)
        {
            int ans=0;
            int arr[2*req];
            for(int i= 2*req-1;i>=req;i--)
            {
                arr[i] = prev & (1<<i);
            }
            
            for(int i=0;i<req;i++)
            {
                arr[i] = arr[2*req -i -1];
            }
            
            ans = 1;
            int i;
            for(i=0;i<2*req;i++)
            {
                ans = ans | (arr[i]<<(i+1));
            }
            ans = ans | (arr[i]<<(i+1));
            return ans;
        }
        else
        {
            
            int ans=0;
            int arr[2*req];
            for(int i= 2*req-1;i>=req;i--)
            {
                arr[i] = prev & (1<<i);
            }
            
            for(int i=0;i<req;i++)
            {
                arr[i] = arr[2*req -i -1];
            }
            
            ans = 1;
            int i;
            for(i=0;i<2*req;i++)
            {   
                if(i<req)
                ans = ans | (arr[i]<<(i+1));
                else if(i==req)
                continue;
                else
                ans = ans | (arr[i]<<(i));
            }
            ans = ans | (1<<(i));
            return ans;            
        }
        
    } */


//Third Solution :- 
int convertStringToInt(string s)
{
    int num = 0;
  
    // convert binary string into integer
    for (int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}
  

int Solution::solve(int n) {
    // base case
    if (n == 1)
        return 1;
    n--;
  
    // stores the binary palindrome string
    queue<string> q;
  
    // add 2nd binary palindrome string
    q.push("11");
  
    // runs till the nth binary palindrome number
    while (!q.empty()) {
        // remove curr binary palindrome string from queue
        string curr = q.front();
        q.pop();
        n--;
  
        // if n==0 then we find the n'th binary palindrome
        // so we return our answer
        if (!n) {
            return convertStringToInt(curr);
        }
  
        int mid = curr.size() / 2;
  
        // if length is even .so it is our first case
        // we have two choices
        if (curr.size() % 2 == 0) {
            string s0 = curr, s1 = curr;
            s0.insert(mid, "0");
            s1.insert(mid, "1");
            q.push(s0);
            q.push(s1);
        }
          
        // if length is odd .so it is our second case
        // we have only one choice
        else {
            string ch(1, curr[mid]);
            string temp = curr;
            temp.insert(mid, ch);
            q.push(temp);
        }
    }
  
    return 0;
}


//Fourth Solution :- DP
int dp[33];
int t;

void dfs(int i,int j,int v){
	if(t==0 || i>j){
		t--;
		return;
	}

	dp[i]=0;
	dp[j]=0;

	dfs(i+1,j-1,0);
	if(t>0){
	dp[i]=1;
	dp[j]=1;
	dfs(i+1,j-1,1);
}

}

int Solution::solve(int n) {
	memset(dp,0,sizeof(dp));
	t=n;
	int l=1;
	dp[1]=1;
	while(t>0){
		dp[l]=1;
		dfs(2,l-1,0);
		l++;
	}

	int ans=0;

	for(int i=1;i<32;i++){
		if(dp[i]==1){
			ans|=1<<(i-1);
		}
	}
	return ans;
}