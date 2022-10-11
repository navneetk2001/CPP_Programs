//  Given a string A with lowercase english alphabets and you have to return a string in which, with each character its frequency is written in adjacent.

// Input 1: abbhuabcfghh
// Ouput 1: a2b3h3u1c1f1g1

//Solution Approach :-
//Maintain frequency array of characters. and also maintain visited array so that we can maintain which characters we have already written their frequency.


// First Method :-
string Solution::solve(string A) {
    int n=A.size();
    string ans;
    vector<int>freq(26,0);
    for(int i=0;i<n;i++){
        freq[A[i]-'a']+=1;
    }

    for(int i=0;i<n;i++){
        if(freq[A[i]-'a']!=0){
            ans+=A[i]+to_string(freq[A[i]-'a']);
            freq[A[i]-'a']=0;
        }
    }
    return ans;
}


//Second Method :-
string Solution::solve(string A) {
    string s;
    int arr[27]={0};
    for(auto i: A){
        arr[i-'a']++;
    }
    for(auto i: A) {
        if(arr[i-'a']>0){
            s+=i;
            s+=char((arr[i-'a'])+'0');
            arr[i-'a']=0;
        }
    }
    return s;
}


//Third Method :-
string Solution::solve(string A) {
    vector<int> arr(26,0);
    queue<char> c;
    for(auto i: A){
        if(arr[i-'a']==0) c.push(i);
        arr[i-'a']++;
    }
    string ans="";
    while(!c.empty()) ans+=c.front()+to_string(arr[c.front()-'a']),c.pop();
    return ans;
}



