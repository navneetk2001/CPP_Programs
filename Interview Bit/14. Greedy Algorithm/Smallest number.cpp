https://practice.geeksforgeeks.org/problems/smallest-number5829/1



//Solution Approach :- 
string smallestNumber(int s, int d){
    if((9*d) < s){   //is given sum is greater than maximum possible sum
        return "-1";
    }
    string ans = "";
    
    for(int i=d-1; i>=0; i--){     //now start iterating from the last of digits
        if(s>9){                 //if remaining sum is greater than 9 then add 9 to the last digit
            ans = '9' + ans;
            s -= 9;
        }
        else{               //if remaining sum is not greater than 9
            if(i==0){       //if its the first digit, then add the remaining sum to the string at 0th position
                ans = to_string(s) + ans;
            }
            else{           //if it's not the first digit 
                ans = to_string(s-1) + ans;    //then add remaining sum-1 to the answer
                i--;                           //and decrement one more place
                while(i>0){                    //iterate till you reach first position
                    ans = '0' + ans;           //and add '0' to the answer
                    i--;                       //decrement it
                }
                ans = '1' + ans;               //add '1' to the first digit and return ans
                break;
            }
        }
    }
    return ans;
}




//Second Solution :- 
string smallestNumber(int s, int d){
    string ans="";
    
    for(int i=0;i<d;i++){
        if(i==0){
            for(int j=1;j<=9;j++){
                int num=j;
                
                if(s-num<=(d-i-1)*9){
                    ans+=to_string(num);
                    s-=num;
                    break;
                }
            }
        }        
        else{
            for(int j=0;j<=9;j++){
                int num=j;
                
                if(s-num<=(d-i-1)*9){
                    ans+=to_string(num);
                    s-=num;
                    break;
                }
            }
        }
    }
    
    if(s==0) return ans;
    else return "-1";
}




//Third Solution :- 
string smallestNumber(int S, int D){
   string ans="";
   while(D>0)
   {
       if (S>9)
       {
           ans+='9';
           S-=9;
       }
       else if (D>1)
       {
           if (S==1)
           {
               ans+='0';
           }
           else
           {
               ans+=to_string(S-1);
               S=1;
           }
       }
       else if (D==1)
       {
           ans+=to_string(S);
           S=0;
       }
       D--;
   }
   reverse(ans.begin(), ans.end());
   if (S!=0)
   {
       return "-1";
   }
   return ans;
}



//Fourth Solution :- 
int digitalSum(int a){
    int sum = 0;
    while(a){
        sum += a%10;
        a /= 10;
    }
    return sum;
}

string smallestNumber(int S, int D){
    int start = pow(10,D-1);
    int stop = pow(10,D);
    for(int i=start;i<stop;i++){
        if(digitalSum(i) == S){
            return to_string(i);
        }
    }
    return "-1";
}