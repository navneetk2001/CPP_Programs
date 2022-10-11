https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1




//Solution Approach :-
class Solution{
    public:
    void findall(string word, int i, vector<string> &keypad, vector<string> &ans, int a[], int n){
        if(i == n){   
            ans.push_back(word);
            return;
        }
        string digit = keypad[a[i]];
        for(int j=0; j<digit.length(); j++){
            findall(word + digit[j], i+1, keypad, ans, a, n);
        }
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
       	vector<string> k(10);
		k[2] = "abc";
		k[3] = "def";
		k[4] = "ghi";
		k[5] = "jkl";
		k[6] = "mno";
		k[7] = "pqrs";
		k[8] = "tuv";
		k[9] = "wxyz";

		vector<string> ans;
		findall("", 0, k, ans, a, N);
		return ans;
    }
};




//Second Solution :-
unordered_map<int,string> m;
vector<string> res;
void help(int i, int n, int a[], string &ans){
	if(i==n){
	   	res.push_back(ans);
	   	return;
	}
	else{
	   	string temp = m[a[i]];
	   	for(int j=0;j<temp.size();j++){
	       	ans.push_back(temp[j]);
	       	help(i+1,n,a,ans);
	       	ans.pop_back();
	   	}
	}
}
vector<string> possibleWords(int a[], int n){
	string ans;
	m[2]="abc";
	m[3]="def";
	m[4]="ghi";
	m[5]="jkl";
	m[6]="mno";
	m[7]="pqrs";
	m[8]="tuv";
	m[9]="wxyz";
	help(0,n,a,ans);
	sort(res.begin(),res.end());
	return res;
}



//Third Solution :-
vector<string> possibleWords(int a[], int N){
	vector<string> vStr;

	unordered_map <int, vector<char>> um;
	int k=0;
	um[0];
	um[1];

	for(int i=2; i<=9; i++){
	   	for(int j=0; j < 3; j++){
	       	um[i].push_back((char)('a' + j + k + (i-2)*3));
	   	}
	   	if(i==7){
	       	um[7].push_back('s');
	       	k++;
	   	}
	   	if(i==9){
	       	um[9].push_back('z');
	   	}
	}
	string str = "";
	recGetWords(um, str, vStr, a, N, 0);

	return vStr;
}

