https://www.interviewbit.com/problems/snake-ladder-problem/




//Solution Approach :- 
int Solution::snakeLadder(vector<vector<int> > &l, vector<vector<int> > &s) {
    map<int,int> ladder,snake;
    
    for(vector<int>& p:l){
        ladder[p[0]]=p[1];
    }

    for(vector<int>& p:s){
        snake[p[0]]=p[1];
    }
    
    bool visited[101]={false};
    
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int level=0;
    while(!q.empty()){
        int sz=(int) q.size();
        while(sz--){
            int value=q.front();
            q.pop();
            
            if(value == 100){  //reached the destination then return no of steps
            	return level;
            }
            
            for(int i=1;i<=6;i++)   //start iterating for all 6 values from 1 to 6
            {
                if(value + i <= 100 && visited[value + i] == false)   //if new value is less than 100 and it is not visitedthen 
                {
                   	int temp = value + i;
                   	if(snake.find(temp) != snake.end()){      //if snake is on that new value then you will come down
                        visited[temp] = true;
                        temp = snake[temp];
                   	}
                   	if(ladder.find(temp) != ladder.end()){
                       visited[temp] = true;
                       temp = ladder[temp];
                   	}
                   
                	if(visited[temp] == false){   //if new temp is not visited then make it visited and then push it in the queue
                    	q.push(temp);
                    	visited[temp]=true;
                 	}
                }
           	}
        }
      	level++;    //increase number of steps after each operation
    }
   	return -1;
}



//Second Solution :- DP Solution 
int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B){
    int n = A.size(); int m = B.size();
    int snake[101]{}, ladder[101]{};
    
    for(int i=0;i<n;i++){
        ladder[A[i][1]] = A[i][0];
    }
    
    int danger[101]{};
    for(int i=0;i<m;i++){
        snake[B[i][1]] = B[i][0];
        danger[B[i][0]] = 1;
       
    }
    
    vector<int> dp(101,101);
    dp[1] = 0;
    for(int i=2;i<=100;i++){
        dp[i] = dp[ladder[i]];
        for(int j=1;j<=6;j++){
            if(i-j < 1){
            	break;
            }
            if(danger[i-j]){
            	continue;
            }
            dp[i] = min(dp[i],dp[i-j]+1);
        }
    }

    for(int i=2;i<=100;i++){
        dp[i] = min(dp[i],dp[snake[i]]);
        dp[i] = min(dp[i],dp[ladder[i]]);
        for(int j=1;j<=6;j++){
            if(i-j<1)break;
            if(danger[i-j])continue;
            dp[i] = min(dp[i],dp[i-j]+1);
        }
    }

    if(dp[100]==101){
    	return -1;
    }
    else return dp[100];
}




//Third Solution :-

int Solution::snakeLadder(vector<vector<int> > &l, vector<vector<int> > &s) {
    int rolls = 0 ; 
    vector<bool> vis(101,0) ;
    queue<int> q; 

    q.push(1) ; 
    vis[1] = 1 ; 
  
    unordered_map<int,int> umap ;
    for(auto & e:s){
    	umap[e[0]]= e[1];
    }

    for(auto & e:l){
    	umap[e[0]]= e[1];
    }
  
    while(q.size()){
        int siz = q.size() ; 
        rolls++ ;
       
        while(siz--){
            int val = q.front(); 
            q.pop(); 
            if(val == 100){
            	return rolls-1; 
            }

            for(int i =1 ;i<=6 ;i++){
                if(val+i>100){
                	break; 
                }
                int cur = umap.count(val+i) ? umap[val+i] : val+i;

                if(vis[cur] == 0){
                	q.push(cur);
                	vis[cur] = 1; 
                }
            }
        }
    }
    return -1 ;
}
