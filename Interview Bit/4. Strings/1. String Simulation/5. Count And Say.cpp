// The count-and-say sequence is the sequence of integers beginning as follows: 
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
// 21 is read off as one 2, then one 1 or 1211.
// Given an integer n, generate the nth sequence.
// Note: The sequence of integers will be represented as a string.
// Example:
// if n = 2, the sequence is 11.


// First Method :-
string Solution::countAndSay(int A) {
    if(A==1) return "1";
    if(A==2) return "11";

    string ans="11";
    for(int i=3;i<=A;i++){
        string temp_str="";
        ans=ans+'&';
        int count=1;
        for(int j=1;j<ans.length();j++){
            if(ans[j]!=ans[j-1]){
                temp_str=temp_str+to_string(count);
                temp_str=temp_str+ans[j-1];
                count=1;
            }
            else{
                count++;
            }
        }
        ans=temp_str;
    }
    return ans;
}



//Second Method :-
string Solution::countAndSay(int n) {
    string a="1",b="1",c="";
    n--;
    int count=0,val;
    while(n--){
        int l=a.length();
        count=1;
        val=a[0]-'0';
        c="";
        for(int i=1;i<l;i++){
            if(a[i-1]==a[i]){
                count++;
                continue;
            }
            else{
                b="";
                while(count){
                    b+=(count%10+'0');
                    count=count/10;
                }
                reverse(b.begin(),b.end());
                c+=b;
                c+=(val+'0');
                val=a[i]-'0';
                count=1;
            }
        }
        b="";
        while(count){
            b+=(count%10+'0');
            count=count/10;
        }
        reverse(b.begin(),b.end());
        b+=(val+'0');
        c+=b;
        //cout<<c<<endl;
        a=c;
    }
    return a;
}



//Third Method :-
string Solution::countAndSay(int A) {
    string s[A+2];
    s[1] = "1";
    s[2] = "11";
    for(int i = 3; i <= A; i++) {
        s[i] = "";
        for(int j = 0; j < s[i-1].length(); j++) {
            char x = s[i-1][j];
            int count = 1;
            while((j+1) < s[i-1].length() && s[i-1][j+1] == x) {
                count++;
                j++;
            }
            string sCount = "";
            while(count > 0) {
                int y = count % 10;
                count = count / 10;
                char c = y + '0';
                sCount.push_back(c);
            }
            string iCount = "";
            for(int j = sCount.length() - 1; j >= 0; j--) {
                iCount += sCount[j];
            }
            s[i] += iCount;
            s[i] += x;
        }
    }
    return s[A];
}





//Fourth Method :-
string cntsay(string str){
	int n=str.size();
	int cnt=1;
	string res="";
	for(int i=0;i<n-1;i++){
		if(str[i]==str[i+1])
			cnt++;
		else{
			res+=to_string(cnt);
			res+=str[i];
			cnt=1;
		}
	}
	res+=to_string(cnt);
	res+=str[n-1];

	return res;
}

string Solution::countAndSay(int n) {
	if(n==1)
		return “1”;
	return cntsay(countAndSay(n-1));
}