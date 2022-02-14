#include<iostream>
#include<climits>
#include<string>
#include<unordered_map>
using namespace std;


string find_window(string s, string p){

	//Array as a frequency map
	int FP[256] ={0};
	int FS[256]={0};

	for(int i=0;i<p.length();i++){
		FP[p[i]]++;
	}

    int cnt=0;
    int start=0; //left contraction
    int start_idx=-1;  //start_idx for the best window
    int min_so_far=INT_MAX;
    int window_size;

	//Sliding window Algorithm
	for(int i=0;i<s.length();i++){
		//expand the window by including current character
		char ch=s[i];
		FS[ch]++;

		//count how many characters have been matched until now (string and pattern)
        if(FP[ch]!=0 and FS[ch]<=FP[ch]){
        	cnt+=1;
        }
        //another thing 
        //if all characters of pattern are found in the current window then start contracting
        if(cnt==p.length()){
        	//start contracting from the left to remove unwanted characters
        	while(FP[s[start]]==0 or FS[s[start]]>FP[s[start]]){
                FS[s[start]]--;
        		start++;
        	}

        	// note the window size
        	window_size = i - start +1;
        	if(window_size< min_so_far){
        		min_so_far=window_size;
        		start_idx=start;
        	}
        }
	}
	if(start_idx==-1){
		return "NO window found";
	}
	return s.substr(start_idx,min_so_far);
}

int main(){
	string s, p;
	cin>>s>>p;

	cout<<find_window(s,p)<<endl;

	return 0;
}