// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output: -1
// Explanation: No path exists and destination cell is blocked.



//Solution Approach :-
void solve(int i,int j, string move, vector<string>&res, vector<vector<int>> &m, vector<vector<int>>&visited,int n){
    if(i==n-1 && j==n-1){
        res.push_back(move);
        return;
    }

    if(i<0 || j<0 || i>n-1 ||j>n-1){
        return;
    }

    // base cases 
    if(visited[i][j]==1 || m[i][j]==0){   //visited firstly or blocked
        return;
    }

    // down left right up (sorted order traversal)
    visited[i][j]=1;   //make it visited and then go in 4 direction
    solve(i+1,j,move+"D",res,m,visited,n);
    solve(i,j-1,move+"L",res,m,visited,n);
    solve(i,j+1,move+"R",res,m,visited,n);
    solve(i-1,j,move+"U",res,m,visited,n);
    
    visited[i][j]=0;    // backtracking step unvisit the position
}

vector<string> findPath(vector<vector<int>>&m, int n) {
    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<string> res;

    if(m[0][0]==0 || m[n-1][n-1]==0){
        return res;
    }

    solve(0,0,"",res,m,visited,n);
    return res;
}



//Second Solution :-
class Solution{
    public:
    vector<string>res;
    string str="";

    void dfs(vector<vector<int>> &m,int i,int j,int row,int col)
    {   
        if(i==(row-1) && j==(col-1)){ 
        	res.push_back(str); 
        	str=""; 
        	return;
        }

        if(valid(m,i,j,row,col)){   
        	m[i][j]=2;
            dfs(m,i,j+1,row,col);str+='R';
            dfs(m,i,j-1,row,col);str+='L';
            dfs(m,i+1,j,row,col);str+='D';
            dfs(m,i-1,j,row,col);str+='U';
            
            m[i][j]=1;
            int p=str.size();
            str = str.substr(0,p-2);
        }
    }
    
    bool valid(vector<vector<int>> &m,int i,int j,int row,int col)
    {
        if(i<0||j<0||i>=row||j>=col){
        	return false;
        }
        else{
            if(m[i][j]==1){
            	return true;
            }
            else if(m[i][j]==0 || m[i][j]==2){
            	return false;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>gas;
        gas.push_back("-1");
        
        int row= m.size();
        int col=m[0].size();
        
        dfs(m,0,0,row,col);
        sort(res.begin(),res.end());
        
        if(res.empty()==0){
        	return gas;
        }
        
        return res;
    }
};


//Third Solution :-
void fun(vector<vector<int>>&m,vector<string> &ans,int row,int col,int max_row,int max_col,string str){

	if(row==max_row-1 && col==max_col-1){
    	ans.push_back(str);
        return;
	}

    //upward validaton
    if(row-1>=0 && m[row-1][col]!=0){
    	string t=str;
    	t.push_back('U');
    	m[row][col]=0;
    	fun(m,ans,row-1,col,max_row,max_col,t);
    	m[row][col]=1;
    }

    //dowanward validation
    if(row+1<max_row && m[row+1][col]!=0){
    	string t=str;
    	t.push_back('D');
    	m[row][col]=0;
    	fun(m,ans,row+1,col,max_row,max_col,t);
    	m[row][col]=1;
    }

    //for left validation
    if(col-1>=0 && m[row][col-1]!=0){
    	string t=str;
    	t.push_back('L');
    	m[row][col]=0;
    	fun(m,ans,row,col-1,max_row,max_col,t);
    	m[row][col]=1;
    }

    //for right validation 
    if(col+1<max_col && m[row][col+1]!=0){
    	string t=str;
    	t.push_back('R');
    	m[row][col]=0;
    	fun(m,ans,row,col+1,max_row,max_col,t);
    	m[row][col]=1;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0]==0 || m[n-1][n-1]==0) 
    	return {"-1"};
    
    vector<string> s;
    fun(m,s,0,0,n,n,"");

    if(s.size()==0) 
    	return {"-1"};
    return s;
}