https://www.spoj.com/problems/ADACYCLE/



// Ada the Ladybug is on a trip in Bugindia. There are many cities and some uni-directional roads connecting them. Ada is wondering about the shortest path, which begins in a city and ends in the same city. Since Ada likes short trips, she asked you to find the length of such path for each city in Bugindia.

// Input
// The first line will contain 0 <N ≤ 2000, the number of cities.
// Then N lines follow, each containing N integers 0 ≤ H ij  ≤ 1.. One means, that there is a road between i and j (zero means there isn't a road).

// Output
// Print N lines, the length of shortest path which begins in city i and ends in city i. If the path doesn't exist, print "NO WAY" instead.

// Example Input
// 5
// 0 1 1 1 1
// 1 0 0 0 1
// 0 0 1 1 0
// 0 0 1 0 0
// 0 0 0 1 0
// Example Output
// 2
// 2
// 1
// 2
// NO WAY

// Example Input
// 5
// 0 1 0 0 1
// 0 0 1 0 0
// 0 0 0 1 0
// 0 0 0 0 1
// 1 0 0 0 0
// Example Output
// 2
// 5
// 5
// 5
// 2




//Solution Approach :- BFS
#include <bits/stdc++.h>
using namespace std;
const int N=2222;
const int inf=0x3f3f3f3f;
typedef pair<int,int> p;

vector<int> adj[N];    //adjacency list
bool vis[N];          //visited array
int ans;



int bfs(int i){
    queue<p>q;                    //queue of pair type
    q.push(make_pair(0,i));

    while(!q.empty()){
        int top = q.front().second;    //top element
        int dis = q.front().first;     //distance 
        q.pop();

        for(int j=0;j<adj[top].size();j++){
            int tem = adj[top][j];
            if(!vis[tem])
            {
                vis[tem] = 1;
                if(tem == i){
                    return  dis + 1;
                }
                q.push(make_pair(dis+1, tem));
            }

        }
    }
    return inf;
}

int main(){
	int n;
    cin>>n;
    int temp;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>temp;
            if(temp){       //adjacency list
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++){
        ans = inf;
        if(adj[i].size()){
            memset(vis, false, sizeof(vis));
            ans = bfs(i);
        }
        if(ans == inf){
            cout<<"NO WAY"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}




//Running Solution :-
#include<bits/stdc++.h>
using namespace std;
const int N=2222;
const int inf=0x3f3f3f3f;
vector<int>vv[N];
bool vis[N];
int ans;
int n;
typedef pair<int,int> p;


int bfs(int i)
{
    queue<p>q;
    q.push(make_pair(0,i));

    while(!q.empty())
    {
        int top=q.front().second;
        int dis=q.front().first;
        q.pop();
        for(int j=0;j<vv[top].size();j++)
        {
            int tem=vv[top][j];
            if(!vis[tem])
            {
                vis[tem]=1;
                if(tem==i)
                    return  dis+1;
                    q.push(make_pair(dis+1,tem));
            }

        }
    }
    return inf;
}
int main()
{
    cin>>n;
    int tem;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&tem);
            if(tem)
            {
                vv[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=inf;
        if(vv[i].size())
        {
            memset(vis,false,sizeof(vis));
            ans=bfs(i);
        }
        if(ans==inf)
        {
            puts("NO WAY");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
}