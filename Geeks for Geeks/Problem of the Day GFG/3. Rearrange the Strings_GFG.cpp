Given a string containing uppercase alphabets and integer digits (from 0 to 9), the task is to print the alphabets in the lexicographical order followed by the sum of digits.

Example 1:

Input: S = "AC2BEW3"
Output: "ABCEW5"
Explanation: 2 + 3 = 5 and we print all
alphabets in the lexicographical order. 
Example 2:

Input: S = "ACCBA10D2EW30"
Output: "AABCCDEW6"
Explanation: 0+1+2+3 = 6 and we print all
alphabets in the lexicographical order. 





//We can use Counting Sort here :-
string rearrangeString(string s){
	vector<int>f(26,0);
	int sum=0;
	for(auto e:s){
		if(e>='A'&&e<='Z'){
			f[e-'A']++;
		}
		else{
			sum+=e-'0';
		}
	}

	string ans;
	for(int i=0;i<26;i++){
		while(f[i]){
			ans.push_back('A'+i);
			f[i]--;
		}
	}
	return (ans+to_string(sum));
}