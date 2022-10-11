https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/


#include <bits/stdc++.h>
using namespace std;
const int N = 501;
const int INF = 1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];
int n, m;

vector<pair<int,int>> movements = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}  
};

bool isValid(int x, int y){
	return x>=0 && y>=0 && x<n && y<m;
}


int bfs(){
	int mx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			mx = max(mx, val[i][j]);
		}
	}

	queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mx == val[i][j]){
				q.push({i,j});
				lev[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}

    int ans = 0;
    while(!q.empty()){
    	auto v = q.front();
    	int v_x = v.first, v_y = v.second;
    	q.pop();

    	for(auto movement : movements){
    		int childX = movement.first + v_x;
    		int childY = movement.second + v_y;

    		if(!isValid(childX,childY)) continue;
    		if(!vis[childX][childY]){
    			q.push({childX,childY});
    			lev[childX][childY] = lev[v_x][v_y] + 1;
    			vis[childX][childY] = 1;
    			ans = max(ans, lev[childX][childY]);
    		}
    	}
    }
    return ans;
}

void reset(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			lev[i][j] = INF;
			vis[i][j] = 0;
		}
	}
}


int main(){
	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;
		reset();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>val[i][j];
			}
		}

    	cout<<bfs()<<endl;
	}
}