Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.

Example 1:
Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()

Example 2:
Input:
N = 1
Output:
()

Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

//Steps :- (Backtracking + Recursion)
//1. Generate all Parenthesis (Balanced and Unbalanced - Both)
//2. Checking which one is balanced

void solve(vector<string> &ans, string temp, int open_cnt, int close_cnt, int n){
	if(close_cnt==n){
		ans.push_back(temp);
		return;
	}

	if(close_cnt<open_cnt){
		solve(ans, temp+')',open_cnt,close_cnt+1,n);
	}
	if(open_cnt<n){
		solve(ans, temp+'(',open_cnt+1,close_cnt,n);
	}
}

vector<string> AllParenthesis(int n){
	vector<string> ans;
	int open_cnt = 0, close_cnt = 0;
	string temp="";

	solve(ans,temp,open_cnt,close_cnt,n);

	return ans;
}




//Second Method :-

vector<string> generateParenthesis(int n)
{
    vector<string> two;
    vector<string> ans;
    if (n == 1) {
        two.push_back("{}");
        return two;
    } // Returning vector if n==1

    if (n == 2) {
        two.push_back("{{}}");
        two.push_back("{}{}");
        return two;
    } // Returning vector if n==2, as these are base cases

    two = generateParenthesis(
        n - 1); // Recursively calling the function

    // Assigning the previous values of vector into the
    // present function
    for (int i = 0; i < two.size(); i++) {
        string buf = "{", bug = "{", bus = "{";
        buf = buf + two[i] + "}";
        bug = bug + "}" + two[i];
        bus = two[i] + bus + "}";
        ans.push_back(buf);
        ans.push_back(bus);
        ans.push_back(bug);
    }

    // Removing the duplicate as kind of this {}{} remains
    // same in either way
    ans.pop_back();

    return ans;
}