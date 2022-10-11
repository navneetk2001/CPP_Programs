//https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

// Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
// The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1. Rest of the houses in Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.
// Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
// Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.
// Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.
// Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

// The queries can be of the following two types:
// 0 X Y : Bob moves towards the King's Mansion.
// 1 X Y : Bob moves away from the King's Mansion

// Sample Input
// 9
// 1 2
// 1 3
// 2 6
// 2 7
// 6 9
// 7 8
// 3 4
// 3 5
// 5
// 0 2 8
// 1 2 8
// 1 6 5
// 0 6 5
// 1 9 1

// Sample Output
// YES
// NO
// NO
// NO
// YES

// Explanation
// Query 1 Bob goes from 8 towards 1 meeting 2 in the path. Query 2 Bob goes from 8 away from 1 and never meets 2. Query 3 Bob goes from 5 away from 1 and never meets 6. Query 4 Bob goes from 5 towards 1 and never meets 6. Query 5 Bob goes from 1 away from 1 and meets finds Oliver at 9. he can take the following two paths 1 -> 2 -> 6 -> 9 OR 1 -> 2 -> 7 -> 8 9 appears in atleast one of them



//Solution Approach :-
/*checkk if the two nodes are in same subtree if yes then on the basis of 0,1 find which is ancestor */

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli intime[100005];
lli outTime[100005];

vector<bool> vis(100005,false);
lli timer=0;
vector<lli> adj[100005];

void dfs(lli node){
    vis[node]=true;
    intime[node]=timer++;

    for(auto child:adj[node]){
        if(vis[child]==false){
            dfs(child);
        }
    }
    outTime[node]=timer++;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n;
	cin>>n;

	lli m=n-1;

	while(m--){
		lli a,b;
		cin>>a>>b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	lli q;
	cin>>q;

	while(q--){        //No of queries
	    lli type,x,y;
	    cin>>type>>x>>y;     //Type , x point and y point

	    if(intime[x]>outTime[y]||intime[y]>outTime[x]){
	        cout<<"NO"<<endl;
	    }
	    else{
	        if(type==0){
	            if(intime[x]<intime[y])
	            {
	                cout<<"YES"<<endl;
	            }
	            else{
	                cout<<"NO"<<endl;
	            }
	        }
	        else{
	            if(intime[x]>intime[y])
	            {
	                cout<<"YES"<<endl;
	            }
	            else{
	                cout<<"NO"<<endl;
	            }
	        }
	    }
	}
}




//Second Solution :-
#include<bits/stdc++.h>
using namespace std;

int vertex;
vector<vector<int> > tree; //used for representing the tree
vector<bool> visited;

vector<int> starttime; // starttime[i] notes the time at which DFS enters node i
vector<int> endtime; // endtime[i] notes the time at which DFS exits node i
int timer = 0; // a global variable that stores the timer at that instant

void  makeTree()  // takes the input and creates a directed graph representing the tree
{
    scanf("%d",&vertex);
    tree.resize(vertex+1);

    for(int i = 1; i < vertex ; i++)
    {   int x,y;
        scanf("%d%d",&x,&y);

        tree[x].push_back(y);
    }
}

void measureTime(int v) // Performs Depth First Search
{
    visited[v] = 1;

    starttime[v] = timer++;

    for(int i = 0 ; i < tree[v].size() ; i++) // calling measureTime() for adjacent nodes of node v and performing DFS
    {
        if( visited [ tree[ v ][ i ] ] == 0  )
            measureTime(tree[v][i]);
    }
    endtime[v] = timer++;
}

int check(int x, int y)
{
    if( starttime[x] > starttime[y] && endtime[x] < endtime[y] ) // checks weather node x lies in the subtree of node y or not
        return 1;
    return 0;
}

int main()
{
    makeTree();

    visited.resize(vertex+1,0);
    starttime.resize(vertex+1,0);
    endtime.resize(vertex+1,0);

    measureTime(1);

    int q;
    scanf("%d",&q);

    while(q--)
    {
        int type,x,y;
		scanf("%d%d%d",&type,&x,&y);

        if( !check(x,y) && !check(y,x) )
        {
            printf("NO\n");
            continue;
        }

        if(type == 0)
        {
            if(check(y,x) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(check(x,y) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}


