Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin has planted several of his infamous Pumpkin Bombs in various locations in a building. Help Spiderman activate his Spidey Sense and identify the impact zones. 
He has a blueprint of the building which is a M x N matrix that is filled with the characters O, B, and W where: 
O represents an open space.
B represents a bomb.
W represents a wall.
You have to replace all of the Os (open spaces) in the matrix with their shortest distance from a bomb without being able to go through any walls. Also, replace the bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a bomb and an open space replace the corresponding 'O' with -1.

Example 1:
Input: N = 3, M = 3
A[] = {{O, O, O}, 
       {W, B, B}, 
       {W, O, O}}
Output: {{2, 1, 1}, 
         {-1, 0, 0},  
         {-1, 1, 1}}
Explanation: The walls at (1,0) and (2,0) are replaced by -1. The bombs at (1,1) and 
(1,2) are replaced by 0. The impact zone for the bomb at (1,1) includes open spaces 
at index (0,0), (0,1) and (2,1) with distance from bomb calculated as 2,1,1 respectively.
The impact zone for the bomb at (1,2) includes open spaces at index (0,3) and (2,2) 
with distance from bomb calculated as 1,1 respectively.

Example 2:
Input: N = 2, M = 2
A[] = {{O, O},
       {O, O}} 
Output: {{-1, -1}
         {-1, -1}



//B :- Source
//W :- Wall/Block
//O :- Open Space         


//Solution Approach :- Multi Source Shortest Path (Unweighted graph)
#define pi pair<int,int> 
public:
vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
{ 
    queue<pi> q;
    vector<vector<int>> ans(M , vector<int> (N,-1));
    for(int i=0; i< M; i++ ){
        for(int j=0; j < N; j++ ){
            if(matrix[i][j] == 'B' ){
                q.push({i,j});
                ans[i][j] = 0;
            }
           
        }
    }
    
    int x[] = {0,0,1,-1};    //row direction
    int y[] = {-1,1,0,0};    //Column Direction
    int lvl = 0;
    while(q.size()){
        lvl++;
        int qs = q.size();
        while(qs -- ){
            
            auto it = q.front();
            q.pop();
            
            for(int i=0;i < 4; i++ ){
                int r = it.first + y[i];
                int c = it.second + x[i];
                
                if(r < 0 || r >=M || c <0 || c >= N || matrix[r][c] != 'O' || ans[r][c] != -1 ){
                    continue;
                }
                
                ans[r][c] = lvl;
                
                q.push({r,c});
            }
        }
    }
    
    return ans;
} 



//Second Solution  :-
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>> ans(M , vector<int> (N,INT_MAX));
        queue<pair<int,int>>q;

        for(int i=0; i< M; i++){
	        for(int j=0; j < N; j++){
	            if(matrix[i][j] == 'B'){
	                q.push({i,j});
	                ans[i][j] = 0;
	            }
	            else if(matrix[i][j] == 'W'){
	            	ans[i][j]=-1;
	            }
	        }
    	}
    
	    int dx[4] = {0,1,0,-1};    //row direction
	    int dy[4] = {1,0,-1,0};    //Column Direction

	    while(!q.empty()){
	    	int i=q.front().first;
	    	int j=q.front().second;

	    	q.pop();

	    	for(int k=0;k<4;k++){
	    		int x = i + dx[k];
	    		int y = j + dy[k];

	    		if(x>=0 && x<M && j>=0 && j<N && matrix[x][y]=='O' && ans[x][y] > ans[i][j]+1){
	    			ans[x][y]=ans[i][j]+1;
	    			q.push({x,y});
	    		}
	    	}
	    }

	    for(int i=0; i< M; i++){
	        for(int j=0; j < N; j++){
	            if(ans[i][j] == INT_MAX){
	                ans[i][j] = -1;
	            }
	        }
    	}
    
    	return ans;
    } 
};