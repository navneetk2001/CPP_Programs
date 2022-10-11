https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1




//Solution Approach :- 
string findSum(string X, string Y) {
	int i=X.size()-1, j=Y.size()-1;

	string res="";
	int carry=0;
	int sum;

	while(i>=0&&j>=0){
	   sum=(X[i]-'0' + Y[j]-'0' + carry);
	   res+=((sum%10)+'0');
	   carry=sum/10;

	   i--;   j--;
	}

	while(i>=0){
	   sum=(X[i]-'0' + carry);
	   res+=((sum%10)+'0');
	   carry=sum/10;

	   i--;
	}

	while(j>=0){
	   sum=(Y[j]-'0' + carry);
	   res+=((sum%10)+'0');
	   carry=sum/10;

	   j--;
	}

	if(carry>0){
		res+=(carry+'0');
	}

	while(res.back()=='0'){
	   	res.pop_back();
	}

	reverse(res.begin(),res.end());

	if(res.size()==0){
	  	res="0";
	}

	return res;
}




//Second Solution :- 
string findSum(string x, string y) 
{    
    string ans="";
    int sum=0, carry=0;
    int i=x.size()-1, j=y.size()-1;
    
    while(i>=0 || j>=0){
        sum = 0;
        if(i>=0){
            sum = (x[i--]-'0');
        }
        if(j>=0){
            sum += (y[j--]-'0');
        }
        sum += carry;
        carry = sum/10;
        sum %= 10;
        ans = to_string(sum)+ans;
    }
    
    // Corner Case 1 : If Carry has some value then append it at front
    if(carry!=0){
        ans = to_string(carry)+ans;
    }
    
    // Corner Case 2 : If Leading Zero, count leading Zeros 
    int count=0;
    for(int i=0; i<ans.length(); i++){
       	if(ans[i]=='0'){
         	count++;
       	}
       	else{
         	break;
       	}
    }
    
    // Corner Case 3 : If result string has leading Zero then trim
    if(count==ans.length()) {
    	return "0";
    }
    return ans.substr(count);
}



//Third SOlution :-
string findSum(string x, string y) {
    int i=x.size()-1, j=y.size()-1, carry=0;
    string res;

    while(i>=0 || j>=0 || carry){
        int sum1=0,sum2=0;
        if(i>=0) sum1=x[i--]-'0';
        if(j>=0) sum2=y[j--]-'0';
        int ans=sum1+sum2+carry;
        char d=(ans%10)+'0';
        res.push_back(d);
        carry=ans/10;
    }
    
    reverse(begin(res),end(res));
    while(res.size() and res[0]=='0') res.erase(res.begin());
    if(!res.size()) return "0";
    return res;
}