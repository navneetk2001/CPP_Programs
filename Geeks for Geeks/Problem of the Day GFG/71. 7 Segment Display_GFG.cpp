// Using seven segment display, you can write down any digit from 0 to 9 using at most seven segments. Given a positive number N and then a string S representing a number of N digits. You have to rearrange the segments in this N digit number to get the smallest possible N digit number. This number can have leading zeros. You can not waste any segment or add any segment from your own. You have to use all of the segments of the given N digits.
// Note: You can refer this diagram for more details

// Example 1:
// Input:
// N = 6
// S = "234567"
// Output: 000011
// Explanation: 234567 has a total of 28 segments and we can rearrange them to form 000011 which has 28 segments too. 000011 is the
// smallest possible number which can be formed on rearrangement.

// Example 2:
// Input:
// N = 3
// S = "011"
// Output: 011
// Explanation:
// 011 has a total of 10 segments and this is the smallest number with 10 segments.



//Solution Approach :-
string sevenSegments(string S, int N) {
    int arr[]={6,2,5,5,4,5,6,3,7,5};

    int sum=0;
    for(int i=0;i<N;i++){
        sum+=arr[S[i]-'0'];
    }

    int ans[N];
    for(int i=0;i<N;i++)
    {
        ans[i]=2;
        sum-=2;
    }

    int i=0;
    while(sum>=4 and i<N){
        ans[i]+=4;
        sum-=4;
        i++;
    }

    ans[N-1]+=sum;

    string res="";
    for(int i=0;i<N;i++){
        if(ans[i]==6) res+='0';
        else if(ans[i]==2) res+='1';
        else if(ans[i]==3) res+='7';
        else if(ans[i]==4) res+='4';
        else if(ans[i]==7) res+='8';
        else res+='2';
    }
    return res;
}




//Second Approach :-
string sevenSegments(string S, int N) {
    int seg[10] = {6,2,5,5,4,5,6,3,7,5};
    
    int tseg = 0;
    for(int i=0; i<N; i++){
        tseg += seg[S[i]-'0'];
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<10; j++) {
            int lseg = tseg-seg[j];
            if(lseg >= 2*(N-i-1) and lseg <= 7*(N-i-1)) {
                S[i] = j+'0';
                tseg = lseg;
                break;
            }
        }
    }
    
    return S;
}



//Third Solution :-
// How to make n digit smallest number?
// Makes maximum number of MSBs 0 then 1 then 2 and so on depending on condition .
// However you need to have some minimum number (2) of LEDs for each n digits, fill them first ,then try making msbs zeroes , whatever lights you  have with you now is either 0,1,2,3 . use these to create the smallest number at LSB.

class Solution {
  public:
    int a[10]={6,2,5,5,4,5,6,3,7,5};
    string sevenSegments(string str, int n) {
       int lights=0;
       for(auto c:str){
           lights+=a[c-'0'];
       }
       
       int arr[n];
       memset(arr,0,sizeof(arr));
       
       for(int i=0;i<n;i++){
           lights-=2;
           arr[i]+=2;
       }
        
       for(int i=0;i<n;i++){
               int req=6-arr[i];
               if(lights>=req){
                   arr[i]+=req;
                   lights-=req;
               }
           
       }
       arr[n-1]+=lights;
       string ans;
       for(int i=0;i<n;i++){
           switch(arr[i]){
               case 2:{ans+="1";break;}
               case 6:{ans+="0";break;}
               case 5:{ans+="2";break;}
               case 4:{ans+="4";break;}
               case 3:{ans+="7";break;}
               case 7:{ans+="8";break;}
           }
       }
       return ans;
    }
};