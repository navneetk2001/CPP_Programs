//https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

// Example
// Sample Input 0 :-
// 5 3
// 0 1
// 2 3
// 0 4
// Sample Output 0 :- 6
// Explanation 0 :- Persons numbered [0,1,4] belong to one country, and those numbered [2,3] belong to another. The UN has 6 ways of choosing a pair:
// [0,2], [0,3], [1,2], [1,3], [4,2], [4,3]



//Solution Approach :-
#include <iostream>
#include <list>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <cmath>
using namespace std;
    
void dfs(int src, vector<int>&vis, vector<int>g[], int &counter){
    vis[src] = 1;
    counter++;

    for(auto x:g[src]){
        if(!vis[x]){
            dfs(x,vis,g,counter);
        }
    }
}
    
int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<int>g[v];
    for(int i=0;i<e;i++){
    	int x,y;
        cin>>x>>y;
    
        g[x].push_back(y);
        g[y].push_back(x);    
    }
    
    vector<int>solution;
    vector<int>vis(v,0);

    for(int i=0;i<v;i++){
    	if(!vis[i]){
    		int counter=0;
    		dfs(i,vis,g,counter);
    		solution.push_back(counter);
    	}
    }
    
    int val = v*(v-1) / 2;
    
    for(int i=0;i<solution.size();i++){    
        int x = (solution[i]*(solution[i]-1)) / 2;
        val=val-x;
    }
    cout<<val<< endl;
    return 0;
}



//Second Solution :-
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool vis[100005];

int func(vector <int> v[], int x)
{
    queue <int> q;
    q.push(x);
    vis[x] = true;
    int c = 0,i,f;
    while ( !(q.empty()) ) {
        f = q.front();
        c++;
        q.pop();

        for ( i = 0; i < v[f].size(); i++ ) {
            if (!vis[v[f][i]]) {
                vis[v[f][i]] = true;
                q.push(v[f][i]);
            }
        }
    }
    return c;
}

int main()
{
    int n,l,i,x,y,j,k;
    long long ans = 0;
    memset(vis, false, sizeof(vis));
    cin >> n >> l;
    vector <int> v[n+2];
    while ( l-- ) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector <int> p;
    for ( i = 0; i < n; i++ ) {
        if ( !vis[i] ) {
            p.push_back(func(v,i));
        }
    }
    
    k = (int)(p.size());
    int a[k+2],sum=0;
    for ( i = p.size()-1; i >= 0; i-- ) {
        sum += p[i];
        a[i] = sum;
    }
    for ( i = k-2; i >= 0; i-- ) {
        ans += p[i]*a[i+1];
    }
    cout << ans << endl;
    return 0;
}


//Third Solution :- Using Union-Rank
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> p;
    vector<int> rank;

public:
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }

    int findSet(int i) {
        return (p[i] == i ? i : (p[i] = findSet(p[i])));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

long long getNumberOfWaysToPair(int N, vector<pair<int, int> > sameCountry) {
    int I = sameCountry.size();
    UnionFind uf(N);
    for (int i = 0; i < I; i++)
        uf.unionSet(sameCountry[i].first, sameCountry[i].second);
    map<int, int> countryCount;
    for (int i = 0; i < N; i++)
        countryCount[uf.findSet(i)]++;
    long long total = 0;
    for (int i = 0; i < N; i++)
        total += N - countryCount[uf.findSet(i)];
    return total / 2;
}

int main() {
    int N, I;
    cin >> N >> I;
    vector<pair<int, int> > sameCountry;
    for (int i = 0; i < I; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        sameCountry.push_back(p);
    }
    cout << getNumberOfWaysToPair(N, sameCountry) << endl;
    return 0;
}