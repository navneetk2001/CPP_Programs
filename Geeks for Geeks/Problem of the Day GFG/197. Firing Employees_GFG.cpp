




//Solution Approach :- Using BFS:
class Solution{   
public:
    bool isPrime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int firingEmployees(vector<int> &arr, int n){
        vector<int> adj[n+1];
        int s=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                s=i+1;
            }
            else{
                adj[arr[i]].push_back(i+1);
            }
        }
        
        queue<int> q;
        vector<bool> vis(n+1,false);
        q.push(s);
        int ans=0,numSeniors=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();

                if(curr!=s && isPrime(numSeniors+curr)){
                    ans++;
                }
                for(auto u:adj[curr]){
                    if(vis[u]==false){
                        vis[u]=true;
                        q.push(u);
                    }
                }
            }
            numSeniors++;
        }
        return ans;
    }
};




//Second Solution :- DFS
const int N = 1e5;
int prime[N+1];

void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for(int i=2; i*i<=N; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=N; j+=i) {
                prime[j] = 0;
            }
        }
    }
}

class Solution{   
public:
    Solution() {
        sieve();
    }
    
    void dfs(int node, vector<vector<int>>& children, vector<int>& depth, int h) {
        depth[node] = h;
        for(int child : children[node]) {
            dfs(child, children, depth, h+1);
        }
    }
    
    int firingEmployees(vector<int> &arr, int n){
        vector<vector<int>> children(n+1);
        vector<int> depth(n+1, -1);
        
        for(int i=0; i<n; i++) {
            children[arr[i]].push_back(i+1);
        }
        dfs(children[0][0], children, depth, 0);
        
        int res = 0;
        for(int i=1; i<=n; i++) {
            if(depth[i]) {
                if(prime[depth[i]+i]) res++;
            }
        }
        return res;
    }
};





//Third Solution :- BFS
bool isPrime(int num) {
        if(num <= 1) return false;
        if (num <= 3)  return true; 
        
        int range = sqrt(num);
        // This is checked so that we can skip  middle five numbers in below loop 
        if (num % 2 == 0 || num % 3 == 0) {
            return false; 
        }
        
        for (int i = 5; i <= range; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false; 
            }
        }
        
        return true;
    }

    int firingEmployees(vector<int> &arr, int n){
        unordered_map<int,vector<int>> mp;
        int geek=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
            	mp[arr[i]].push_back(i+1);
            }
            else{
           		geek=i+1;
            }
            
        }
        
        queue<int> q;
        for(auto it:mp[geek]){
        	q.push(it);
        }
        
        int seniors=0;
        int cnt=0;
        while(!q.empty())
        {
            seniors++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int ind=q.front();
                q.pop();
                if(isPrime(ind+seniors)){
                	cnt++;
                }
                for(auto it:mp[ind]){
                 	q.push(it);
                }
            }                     
        }        
        return cnt;
    }
};




//Fourth Solution :- DFS
void markPrimes(int n){
    isPrime = new bool[n];
    isPrime[2]=true, isPrime[0]=isPrime[1]=false;
    for(int i=3;i<=n;i++){
        if(i&1){
            isPrime[i]=true;
        }
        else{
            isPrime[i]=false;
        }
    }
    for(int i=3;i*i<=n;i+=2){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=(i<<1)){
                isPrime[j]=false;
            }
        }
    }
}

void dfs(int src,int parentSum,int &ans){
    if(parentSum && isPrime[src+parentSum])
        ans++;
    for(auto it: adj[src]){
        dfs(it,parentSum+1,ans);
    }
}

int firingEmployees(vector<int> &arr, int n){
    markPrimes(2*n-1);
    adj = new vector<int>[n+1];
    int root;
    for(int i=0;i<n;i++){
        if(!arr[i]){
            root=i+1;
        }
        else{
            adj[arr[i]].push_back(i+1);
        }
    }

    int ans=0;
    dfs(root,0,ans);
    return ans;
}



//Fifth Solution :- sieve of Eratosthenes + dfs    
int count(int ind,vector<int> &dp,vector<int> &a){
       if(a[ind]==-1){
           
           return dp[ind]=0;
       }
       if(dp[ind]!=-1){
           return dp[ind];
       }
       return dp[ind]=1+count(a[ind],dp,a);
   }
   
   int firingEmployees(vector<int> &a, int n){
       int ans=0;    
       vector<int> dp(n,-1);
       int maxi=2*n+2;
       vector<int> prime(maxi,true);
       prime[0]=prime[1]=0;
       for(int i=2;i*i<=maxi;i++){
           if(prime[i]){
               for(int j=i+i;j<maxi;j+=i){
                   prime[j]=false;
               }
           }
       }
       
       for(int i=0;i<n;i++){
           a[i]--;
       }
       for(int i=0;i<n;i++){
           int totalManager=count(i,dp,a);
           if(a[i]!=-1 && prime[totalManager+i+1]){
               ans++;
           }
       }
       return ans;
   }