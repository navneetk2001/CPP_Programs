// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.
// Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

// Example 1:
// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output: 3
// Explanation: Knight takes 3 step to reach from (4, 5) to (1, 1):  (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).



//Solution Approach :-
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    //steps a knight can go
		int pos[8][2]={{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,-1}, {2,1}, {-1,-2}, {1,-2}};
		
		bool vis[N+1][N+1];      //visited Array
		memset(vis,0,sizeof(vis));

		vis[KnightPos[0]][KnightPos[1]]=1;   //Marking initial pos as true
		
		queue<pair<int,int>> q;      //Queue for BFS Traversal
		q.push({KnightPos[0], KnightPos[1]});
		int steps=0;

		while(!q.empty()){   
			int sz=q.size();

			while(sz--){
			    pair<int,int>p = q.front();
			    q.pop();

				int x=p.first, y=p.second;
				if(x==TargetPos[0] && y==TargetPos[1]){
					return steps;
				}

				for(int k=0;k<8;k++){
					int a=x+pos[k][0], b=y+pos[k][1];
					if(a>0 && a<=N && b>0 && b<=N && !vis[a][b]){
						q.push({a,b});
						vis[a][b]=1;
					}
				}
			}
			steps++;
		}
		return -1;
	}
};



//Second Solution :-
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    int x1= KnightPos[0];
    int y1= KnightPos[1];

    int x2= TargetPos[0];
    int y2= TargetPos[1];
    
    if(x1==x2 && y1==y2){
        return 0; // already at the destination case
    }
   
    queue<pair<int,int>>q; // stores the position to visit next
    q.push({x1-1,y1-1});
    
    vector<vector<int>> visited(N,vector<int>(N,0)); // stores the visited or not visited
    visited[x1-1][y1-1]=0;
    
    while(!q.empty()){
        auto curr= q.front();
        q.pop();
        int i= curr.first;
        int j= curr.second;

        if(i-2>=0 && j-1>=0 && i-2<N && j-1<N && visited[i-2][j-1]==0){
            visited[i-2][j-1]= 1+visited[i][j];
            q.push({i-2,j-1});
        }

        if(i-2>=0 && j+1>=0 && i-2<N && j+1<N && visited[i-2][j+1]==0){
            visited[i-2][j+1]= 1+visited[i][j];
            q.push({i-2,j+1});
        }

        if(i-1>=0 && j+2>=0 && i-1<N && j+2<N && visited[i-1][j+2]==0){
            visited[i-1][j+2]= 1+visited[i][j];
            q.push({i-1,j+2});
        }

        if(i+1>=0 && j+2>=0 && i+1<N && j+2<N && visited[i+1][j+2]==0){
            visited[i+1][j+2]= 1+visited[i][j];
            q.push({i+1,j+2});
        }
        
        if(i+2>=0 && j-1>=0 && i+2<N && j-1<N && visited[i+2][j-1]==0){
            visited[i+2][j-1]= 1+visited[i][j];
            q.push({i+2,j-1});
        }

        if(i+2>=0 && j+1>=0 && i+2<N && j+1<N && visited[i+2][j+1]==0){
            visited[i+2][j+1]= 1+visited[i][j];
            q.push({i+2,j+1});
        }

        if(i-1>=0 && j-2>=0 && i-1<N && j-2<N && visited[i-1][j-2]==0){
            visited[i-1][j-2]= 1+visited[i][j];
            q.push({i-1,j-2});
        }

        if(i+1>=0 && j-2>=0 && i+1<N && j-2<N && visited[i+1][j-2]==0){
            visited[i+1][j-2]= 1+visited[i][j];
            q.push({i+1,j-2});
        }
    }
    return visited[x2-1][y2-1];
}



//Third Solution :-
/*  
    Time complexity: O( abs( KX - TX ) * ( KY - TY ) )
    Space complexity: O( abs( KX - TX ) * ( KY - TY ) ) 

    where 'KX' denotes x-coordinate of knight, 'TX' denotes x-coordinate of the target, 
    'KY' denotes y-coordinate of the knight and 'TY' denotes y-coordinate of the target.
*/

int minStepsHelper(pair<int, int> knightPosition, pair<int, int> targetPosition, vector<vector<int>> &dp) {
    // If knight is on the target position return 0.
    if (knightPosition.first == targetPosition.first && knightPosition.second == targetPosition.second) {
        return 0;
    } 
    else
    {
        // If already calculated then return that value.
        if (dp[abs(knightPosition.first - targetPosition.first)][abs(knightPosition.second - targetPosition.second)]) {
            return dp[abs(knightPosition.first - targetPosition.first)][abs(knightPosition.second - targetPosition.second)];
        } 
        else {
            int x1, y1, x2, y2;
            // (x1, y1) and (x2, y2) are the two positions which will be considered.
            
            if (knightPosition.first <= targetPosition.first) {
                if (knightPosition.second <= targetPosition.second) {
                    x1 = knightPosition.first + 2;
                    y1 = knightPosition.second + 1;
                    x2 = knightPosition.first + 1;
                    y2 = knightPosition.second + 2;
                } else {
                    x1 = knightPosition.first + 2;
                    y1 = knightPosition.second - 1;
                    x2 = knightPosition.first + 1;
                    y2 = knightPosition.second - 2;
                }
            } 
            else
            {
                if(knightPosition.second <= targetPosition.second) {
                    x1 = knightPosition.first - 2;
                    y1 = knightPosition.second + 1;
                    x2 = knightPosition.first - 1;
                    y2 = knightPosition.second + 2;
                } 
                else{
                    x1 = knightPosition.first - 2;
                    y1 = knightPosition.second - 1;
                    x2 = knightPosition.first - 1;
                    y2 = knightPosition.second - 2;
                }
            }

            dp[abs(knightPosition.first - targetPosition.first)][abs(knightPosition.second - targetPosition.second)] =
                min(minStepsHelper({x1, y1}, targetPosition, dp), minStepsHelper({x2, y2}, targetPosition, dp)) + 1;

            // Exchanging the coordinates x with y of both knight and target will result in same ans.
            dp[abs(knightPosition.second - targetPosition.second)][abs(knightPosition.first - targetPosition.first)] =
                dp[abs(knightPosition.first - targetPosition.first)][abs(knightPosition.second - targetPosition.second)];
            return dp[abs(knightPosition.first - targetPosition.first)][abs(knightPosition.second - targetPosition.second)];
        }
    }
}

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
    // There are 4 corner cases for which the minimum steps is 4.
    if ((knightPosition.first == 1 && knightPosition.second == 1 && targetPosition.first == 2 && targetPosition.second == 2) ||
        (knightPosition.first == 2 && knightPosition.second == 2 && targetPosition.first == 1 && targetPosition.second == 1)) {
        return 4;
    } 
    else if ((knightPosition.first == 1 && knightPosition.second == size && targetPosition.first == 2 && targetPosition.second == size - 1) ||
               (knightPosition.first == 2 && knightPosition.second == size - 1 && targetPosition.first == 1 && targetPosition.second == size)) {
        return 4;
    } 
    else if ((knightPosition.first == size && knightPosition.second == 1 && targetPosition.first == size - 1 && targetPosition.second == 2) ||
               (knightPosition.first == size - 1 && knightPosition.second == 2 && targetPosition.first == size && targetPosition.second == 1)) {
        return 4;
    } 
    else if ((knightPosition.first == size && knightPosition.second == size && targetPosition.first == size - 1 && targetPosition.second == size - 1) ||
               (knightPosition.first == size - 1 && knightPosition.second == size - 1 && targetPosition.first == size && targetPosition.second == size)) {
        return 4;
    } 
    else 
    {
        dp[1][0] = 3;
        dp[0][1] = 3;
        dp[1][1] = 2;
        dp[2][0] = 2;
        dp[0][2] = 2;
        dp[2][1] = 1;
        dp[1][2] = 1;
        return minStepsHelper(knightPosition, targetPosition, dp);
    }
}
