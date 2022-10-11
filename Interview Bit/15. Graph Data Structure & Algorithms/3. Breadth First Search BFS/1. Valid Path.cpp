https://www.interviewbit.com/problems/valid-path/




//Solution Approach :- 
// Intutition -> here is given there is  rectangle , which has no of vertex is equal to ((x+1)*(y+1)) no of vertex containing & inside the rectangle
// there are n circles inside the rectangle we have to start from (0 , 0) to reach (x , y) we dont have to touch any circles , or not lie inside any circle
// if there exist any path following above condition
// Approach -> we can move in 8 dirns from a given vertex-> check boundary , visited & not lie inside the circle make a matrix of all the vertex , which are lieing inside the circle or not

// all 8- direction move
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={0,1,-1,1,-1,0,1,-1};

string Solution::solve(int x, int y, int n, int r, vector<int> &X, vector<int> &Y) {
   	vector<vector<bool>> mat(x+1,vector<bool>(y+1));
  
   	for(int i=0;i<=x;i++)
   		for(int j=0;j<=y;j++){
		   	bool flag=false;
		   	for(int k=0;k<X.size();k++){       // check each point is inside of any circle or not
		       	if((X[k]-i)*(X[k]-i)+(Y[k]-j)*(Y[k]-j)<=r*r){
		           	flag=true;
		           	break;
		       	}
		   	}
		  	mat[i][j]=flag;
   		}
   	}
  
   	if(mat[0][0]==true){     // if starting index is inside of any circle
   		return "NO";
   	}

    queue<pair<int,int>> q;
    q.push({0,0});

    mat[0][0]=true;        //using the same bool matrix to make visited
    
    while(!q.empty()){
        pair<int,int> top=q.front();
        q.pop();
       
        if(top.first==x && top.second==y){          //reach our destination
        	return "YES";
        }
        
        for(int i=0;i<8;i++){            //go in all 8 possible directions
            int newx=dx[i]+top.first;
            int newy=dy[i]+top.second;
           
            if(newx>=0 && newx<=x && newy>=0 && newy<=y && mat[newx][newy]==false){             // if inside the boundary and not inside of any circle
               	q.push({newx,newy});
               	mat[newx][newy]=true;     //visit the co-ordinates    
            }
        }
    }
    return "NO";
}

/*  Time Complexity:  x*y*n + n*n
Space Complexity = (x+1) * (y+1) + (n*n)   */




//Second Solution :-  DFS
int dx[8]={1,1,0,-1,0,-1,-1,1};
int dy[8]={1,0,1,0,-1,-1,1,-1};

bool isvalid(int x, int y, int r, vector<int> &E, vector<int> &F){
    for(int i=0;i<E.size();i++){
        int x1 = E[i], y1 = F[i];
        if((x-x1)*(x-x1) + (y-y1)*(y-y1) <= r*r){
            return 0;
        }
    }
    return 1;
}


bool dfs(int i, int j, int A, int B, int C, int D, vector<int> &E, vector<int> &F, vector<vector<bool>> &visited){
    if(i==A && j==B && isvalid(i,j,D,E,F)){
        return true;
    }

    if(i>=0 && j>=0  && i<=A && j<=B && isvalid(i,j,D,E,F) && visited[i][j]==0){
        visited[i][j]=1;
        for(int k=0;k<8;k++){
            bool check = dfs(i+dx[k],j+dy[k],A,B,C,D,E,F,visited);
            if(check){
                return true;
            }
        }
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> visited(A+1,vector<bool>(B+1,0));
    bool check = dfs(0,0,A,B,C,D,E,F,visited);
   
    if(check){
        return "YES";
    }
    return "NO";
}



//Third Solution :- 
#define pii pair<int,int>

int par[1000+5];
int rnk[1000+5];
bool vis[1000+5];

void initialise(){
    for(int i=0;i<=1000;i++){
        par[i]=i;
        rnk[i]=1;
        vis[i]=false;
    }
}

int findPar(int node){
    if(par[node]==node)return node;
    return par[node]=findPar(par[node]);
}

void makeUnion(int a,int b){
    int parA=findPar(a);
    int parB=findPar(b);

    if(parA==parB)return;
    if(rnk[parA]<rnk[parB])par[parB]=parA;
    else if(rnk[parB]<rnk[parA])par[parA]=parB;
    else{
        rnk[parA]++;
        par[parB]=parA;
    }
}


bool findBlockage(int root,int X,int Y,int N,int R,vector<pair<int,pii>>vec){
    int top=0;
    int bottom=INT_MAX;
    int left=INT_MAX;
    int right=0;

    for(int i=0;i<N;i++){
        if(par[vec[i].first]==root){
            int x=vec[i].second.first;
            int y=vec[i].second.second;
            top=max(top,y+R);
            bottom=min(bottom,y-R);
            left=min(left,x-R);
            right=max(right,x+R);
        }
    }
    if(top>=Y and bottom<=0)return true;
    if(right>=X and left<=0)return true;
    if(top>=Y and right>=X)return true;
    if(left<=0 and bottom<=0)return true;
    return false;
}

string Solution::solve(int X, int Y, int N, int R, vector<int> &E, vector<int> &F) {
    vector<pair<int,pii>> vec;
    int id=0;
    for(int i=0;i<N;i++){
        vec.push_back({id,{E[i],F[i]}});
        id++;
    }

    initialise();

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i==j)continue;
            int x1=vec[i].second.first;
            int x2=vec[j].second.first;

            int y1=vec[i].second.second;
            int y2=vec[j].second.second;

            if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) <= (4*R*R)){
                makeUnion(vec[i].first,vec[j].first);
            }
        }
    }

    for(int i=0;i<N;i++){
        if(!vis[par[vec[i].first]]){
            vis[par[vec[i].first]]=1;
            bool ret = findBlockage(par[vec[i].first],X,Y,N,R,vec);
            if(ret)return "NO";
        }
    }
    return "YES";
}




//Fourth Solution :- 
#include <bits/stdc++.h>
#define MAX 105

int mat[MAX][MAX];
int visited[MAX][MAX];
int max_x, max_y;
bool dist(int x, int y , int x1 , int y1 , int r) {
    if((x - x1) * (x - x1) + (y - y1 ) * (y - y1 ) <= r*r) {
        return true;
    }
    return false;
}
bool valid(int x, int y) {
    if(x >= 0 && x <= max_x  && y >= 0 && y <= max_y && mat[x][y] == 0 && visited[x][y] == 0) {
        return true;
    }
    return false;
}

string Solution::solve(int x, int y, int N , int R , vector<int> &X_cord, vector<int> &Y_cord) {
    memset(mat, 0 , sizeof(mat));
    memset(visited, 0 , sizeof(visited));
    max_x = x;
    max_y = y;
    vector<pair<int, int> > v;
    for(int i = 0; i < N; i++) {
        v.push_back(make_pair(X_cord[i], Y_cord[i]));
    }
    for(int i = 0; i <= x+ 1; i++) {
       for(int j = 0; j <= y+1; j++) {
            bool flag = true;
            for(int k = 0; k < N; k++) {
                if(dist(i, j , v[k].first , v[k].second, R)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
       }
    }
   // cout << mat[x][y] <<" " << dist(x, y, x, y, R) << endl;
    if(mat[0][0] == 1 || mat[x][y] == 1) {
        string ret = "NO";
        return ret;
    } else {
        visited[0][0] = 1;

        queue<pair<int , int> >q ;
        q.push(make_pair(0, 0));
        int dest1 = x;
        int dest2 = y;
        while(!q.empty()){
            pair<int , int > p1 = q.front();
            q.pop();
            int x  = p1.first;
            int y  = p1.second;
            if(x == dest1 && y == dest2) {
                string ret = "YES";
                return ret;
            }
            if(valid(x-1, y)) {
                visited[x-1][y] = 1;
                q.push(make_pair(x-1 , y));
            }
            if(valid(x, y-1)) {
                visited[x][y-1] = 1;
                q.push(make_pair(x , y-1));
            }
            if(valid(x+1, y)) {
                visited[x+1][y] = 1;
                q.push(make_pair(x+1 , y));
            }
            if(valid(x, y+1)) {
                visited[x][y+1] = 1;
                q.push(make_pair(x , y+1));
            }
            if(valid(x+1, y+1)) {
                visited[x+1][y+1] = 1;
                q.push(make_pair(x+1 , y+1));
            }
            if(valid(x+1, y-1)) {
                visited[x+1][y-1] = 1;
                q.push(make_pair(x+1 , y-1));
            }
            if(valid(x-1, y+1)) {
                visited[x-1][y+1] = 1;
                q.push(make_pair(x-1 , y+1));
            }
            if(valid(x-1, y-1)) {
                visited[x-1][y-1] = 1;
                q.push(make_pair(x-1 , y-1));
            }
        }
        string ret = "NO";
        return ret;
    }

}