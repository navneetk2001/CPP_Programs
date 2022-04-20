Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.
Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation :- Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{   //Using BFS to find shortest path
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
			    pair<int,int>p=q.front();
			    q.pop();
				int x=p.first, y=p.second;
				if(x==TargetPos[0] && y==TargetPos[1])
					return steps;

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




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

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
		    pair<int,int>p=q.front();
		    q.pop();
			int x=p.first, y=p.second;
			if(x==TargetPos[0] && y==TargetPos[1])
				return steps;

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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends