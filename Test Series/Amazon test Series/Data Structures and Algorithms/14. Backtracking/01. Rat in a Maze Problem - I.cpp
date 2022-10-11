https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1





//Solution Approach :-
class Solution{
    public:
    void solve(int i, int j, string move, vector<string> &res, vector<vector<int>> &m, vector<vector<int>> &visited, int n){
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
        visited[i][j]=1;                                //make it visited and then go in 4 direction
        solve(i+1,j,move+"D",res,m,visited,n);
        solve(i,j-1,move+"L",res,m,visited,n);
        solve(i,j+1,move+"R",res,m,visited,n);
        solve(i-1,j,move+"U",res,m,visited,n);
        
        visited[i][j]=0;    // backtracking step unvisit the position
    }
    
    vector<string> findPath(vector<vector<int>>&m, int n) {
        vector<vector<int>> visited(n, vector<int> (n,0));
        vector<string> res;
    
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return res;
        }
    
        solve(0, 0, "", res, m, visited, n);
        return res;
    }
};




//Second Solution :-
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string ds;
        vector<string>ans;
        solve(m,0,0,ds,ans);
        return ans;
    }
    
    void solve(vector<vector<int>>&m,int r,int c,string ds,vector<string>&ans){
        if(!m[r][c]){
        	return;
        }
        
        if(r== m.size()-1 && c == m[0].size()-1){
            ans.push_back(ds);
            return;
        }
        
        m[r][c] =0;
        
        //down
        if(r<m.size()-1){
            ds.push_back('D');
            solve(m,r+1,c,ds,ans);
            ds.pop_back();
        }
        
        // up 
        if(r>0){
	        ds.push_back('U');
	        solve(m,r-1,c,ds,ans);
	        ds.pop_back();
        }
        
        //right
        if(c<m[0].size()-1){
	        ds.push_back('R');
	        solve(m,r,c+1,ds,ans);
	        ds.pop_back();
        }
        
        //left
        if(c>0){
	        ds.push_back('L');
	        solve(m,r,c-1,ds,ans);
	        ds.pop_back();
        }

        m[r][c] = 1;
    }
};




//Third Solution :-
vector<string> res;
int trav(vector<vector<int>> &m, int n, int i, int j, string str){
    if(i>-1 && j> -1 && i<n && j<n && m[i][j]==1){
	    if(i==n-1 && j==n-1){
	        res.push_back(str);
	        return 0;
	    }
	 
	    m[i][j]=0;
	    trav(m, n,i+1,j,str+'D');
	    trav(m, n,i,j+1,str+'R');
	    trav(m, n,i,j-1,str+'L');
	    trav(m, n,i-1,j,str+'U');
	    m[i][j]=1;
	}
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[n-1][n-1]==0 || m[0][0]==0){
        return res;
    }
    trav(m, n, 0, 0, "");
    return res;
}




//Fourth Solution :-
class Solution{
    public:
    int xmov[4] = {-1,1,0,0};
    int ymov[4] = {0,0,-1,1};
    string moves = "UDLR";
    
    bool isValid(int i,int j,int n,vector<vector<int>>&vis,vector<vector<int>> &m){
        if(i >= 0 and j >= 0 and i < n and j < n and !vis[i][j] and m[i][j])return true;
        return false;
    }
    void solve(int i,int j,int n,string &s,vector<vector<int>> &m,vector<vector<int>>&vis,vector<string>&ans){
        if(i == n-1 and j == n-1){
            ans.push_back(s);
            return;
        }
        
        for(int k=0; k<4; k++){
            int ii = i+xmov[k];
            int jj = j+ymov[k];
            if(isValid(ii, jj, n, vis, m)){
                vis[ii][jj] = 1;
                s += moves[k];
                solve(ii,jj,n,s,m,vis,ans);
                s.pop_back();
                vis[ii][jj] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0] == 0){
        	return ans;
        }
        
        string s = "";
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        solve(0,0,n,s,m,vis,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};    