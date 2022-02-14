// You are given a string A which is a serialized string. You have to restore the original array of strings.
// The string in the output array should only have lowercase english alphabets.
// Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.
// For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.


//Solution Approach
We have to first find out at which position our individual string is ending.
Since, our string only consists of lower case english alphabets and out delimiter is `~`.
We can easily find out individual strings.
We just have to take out the substrings and insert it in a auxillary array which we will have to return.


// First Method :-
vector<string> Solution::deserialize(string A) {
    int n=A.size();
    vector<string>res;
    
    for(int i=0;i<n;i++){
        string s="";
        while(A[i]!='~'){
            if(isdigit(A[i])){
                i++;
            }
            else{
                s+=A[i];
                i++;
            }           
        }
        res.push_back(s);
    }
    return res;
}


//Second Method :-
Editorial
Fastest
Lightweight
vector<string> Solution::deserialize(string A) {
    string t = "";
    vector<string> ans;

    for( char c : A) {
        if (c <= 'z' && c >= 'a') {
            t += c;
        }
        if( c == '~') {
            ans.push_back(t);
            t = "";
        }
    }
    return ans;
}



//Third Method :-
vector<string> Solution::deserialize(string A) {
    vector<string> ret;
    int state = 0, begin = 0;
    
    for(int i=0; i < A.length(); i++){
        switch(state){
            // advance till meeting a digit
            case 0:
                if( isdigit(A[i]) ){
                    ret.push_back( A.substr(begin, i-begin) );
                    state = 1;
                }
                break;
            
            // advance till meeting a ~
            case 1:
                if( A[i] == '~'){
                    begin = i+1;
                    state = 0;
                }
                break;
                
            default:
                break;
        }
    }
    return ret;
}





