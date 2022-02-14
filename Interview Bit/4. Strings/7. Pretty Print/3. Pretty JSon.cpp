// Given a string A representating json object. Return an array of string denoting json object with proper indentaion.
// Rules for proper indentaion:
// Every inner brace should increase one indentation to the following lines.
// Every close brace should decrease one indentation to the same line and the following lines.
// The indents can be increased with an additional ‘\t’
// Note:
// [] and {} are only acceptable braces in this case.
// Assume for this problem that space characters can be done away with.

// Input 1:
//     A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
// Output 1:
//     { 
//         A:"B",
//         C: 
//         { 
//             D:"E",
//             F: 
//             { 
//                 G:"H",
//                 I:"J"
//             } 
//         } 
//     }

// Input 2:
//     A = ["foo", {"bar":["baz",null,1.0,2]}]
// Output 2:
//    [
//         "foo", 
//         {
//             "bar":
//             [
//                 "baz", 
//                 null, 
//                 1.0, 
//                 2
//             ]
//         }
//     ]


//Hint :-
This is more of a parsing/simulation problem. Think about the corner cases wisely.

//Solution Approach :-
This is more of a parsing problem.
Make sure you take a lot of time thinking about the corner cases and structure of the code before you start coding.
Fixing corner cases on the fly can make your code really ugly.
Note the following:
1. ‘{‘, ‘[’ have the same effect on the printing
2. '}', ‘]’ have the same effect as well
3. ‘:’ and ‘,’ are the only other 2 characters that matter.
Think about the behavior when you encounter the following characters.
Also think about the behavior based on the following character.


//First Solution :-
vector<string> Solution::prettyJSON(string str) {
	vector<string> ans;
	string temp = "";
	int cnt = 0;

	for(int i = 0; i < (int)str.size(); i++) {
	    if(str[i] == ' ') 
	    	continue;
	    else if(str[i] == '{') {
	        ans.push_back(temp);
	        ans[(int)ans.size() - 1].push_back('{');
	        cnt++;
	        temp += '\t';
	    }
	    else if(str[i] == '[') {
	        ans.push_back(temp);
	        ans[(int)ans.size() - 1].push_back('[');
	        cnt++;
	        temp += '\t';
	    }
	    else if(str[i] == '}') {
	        temp = "";
	        cnt--;
	        for(int j = 0; j < cnt; j++) temp += '\t';
	        ans.push_back(temp);
	        ans[(int)ans.size() - 1].push_back('}');
	    }
	    else if(str[i] == ']') {
	        temp = "";
	        cnt--;
	        for(int j = 0; j < cnt; j++) temp += '\t';
	        ans.push_back(temp);
	        ans[(int)ans.size() - 1].push_back(']');
	    }
	    else if(str[i] == ',') {
	        ans[(int)ans.size() - 1].push_back(str[i]);
	    }
	    else {
	        ans.push_back(temp);
	        while(str[i] != '{' && str[i] != '}' && str[i] != '[' && str[i] != ']' && str[i] != ',') {
	            ans[(int)ans.size() - 1].push_back(str[i]);
	            i++;
	        }
	        i--;
	    }
	}
	return ans;
}

//Second Solution :-
vector<string> Solution::prettyJSON(string A) {
    string indent="";
    vector<string> ans;
    string s=indent;
    for(int i=0;i<A.length();i++){
        if(A[i]==','){
            s+=A[i];
            ans.push_back(s);
            s=indent;
        }
        else if(A[i]=='['||A[i]=='{'){
            if(s!=indent) ans.push_back(s);
            s=indent;
            s+=A[i];
            ans.push_back(s);
            indent+="\t";
            s=indent;
        }
        else if(A[i]=='}'||A[i]==']'){
            if(s!=indent) ans.push_back(s);
            indent.pop_back();
            s=indent;
            s+=A[i];
            if(i<A.length()-1&&A[i+1]==',') s+=A[i+1],i++;
            ans.push_back(s);
            s=indent;
        }
        else s+=A[i];
    }
    return ans;



//Third Solution :-
vector<string> Solution::prettyJSON(string s) {
	vector<string> res;
	int indent = 0;
	char last = 0;
	string ans = "";
	for(auto ch:s){
		if(ch==' ')
		    continue;

		if(ch=='}' ||ch==']' )
		    indent--;

		if(last=='[' ||  last == '{' || ch==']' || ch == '}' || last == ',' || (last==':' && (ch=='{' || ch=='['))){
		    res.push_back(ans);
		    ans="";

		    for(int i=1;i<=indent;i++){
		        ans+="\t";
		    }
		}

		if(ch=='[' || ch=='{')
		    indent++;

		ans += ch;
		last = ch;
	}

	if(ans!="")
		res.push_back(ans);
	return res;
}


//Fourth Solution :-
void addLine(string& line, vector<string>& ans)
{
    if(line.size() != 0)
        ans.push_back(line);
    line.clear();
    
    return;
}

void addChar(char ch, int tabCount, string& line)
{
    if(line.size() == 0)
    {
        for(int i = 0; i < tabCount; i++)
        {
            line.push_back('\t');
        }
    }
    
    line.push_back(ch);
    
    return;
}

vector<string> Solution::prettyJSON(string A) 
{
    vector<string> ans;
    int tabCount = 0;
    string line;
    
    int pos = 0;
    while(pos < A.size())
    {
        char ch = A[pos];
        if(ch == ' ')
        {
            // do nothing
        }
        else if(ch == '[' || ch == '{')
        {
            addLine(line, ans);

            addChar(ch, tabCount, line);
            addLine(line, ans);

            tabCount++;
        }
        else if(ch == ',')
        {
            addChar(ch, tabCount, line);
            addLine(line, ans);
        }
        else if (ch == '}' || ch == ']')
        {
            addLine(line, ans);

            tabCount--;

            addChar(ch, tabCount, line);
            if(pos+1 < A.size() && A[pos + 1] == ',' )
            {
                pos++;
                addChar(A[pos], tabCount, line);
            }
            addLine(line, ans);
        }
        else
        {
            addChar(ch, tabCount, line);
        }

        pos++;
    }
    
    return ans;
}
