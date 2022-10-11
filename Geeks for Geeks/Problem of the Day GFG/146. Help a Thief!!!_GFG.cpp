// You have to help a thief to steal as many as GoldCoins as possible from a GoldMine. There he saw N Gold Boxes an each Gold Boxes consists of Ai Plates each plates consists of Bi Gold Coins. Your task is to print the maximum gold coins theif can steal if he can take a maximum of T plates.

// Example 1:
// Input:
// T = 3, N = 3 
// A[] = {1, 2, 3}
// B[] = {3, 2, 1}
// Output: 7
// Explanation: The thief will take 1 plate of coins from the first box and 2 plate of coins from the second plate. 3 + 2*2 = 7.

// Example 2:
// Input:
// T = 0, N = 3 
// A[] = {1, 3, 2}
// B[] = {2, 3, 1}
// Output: 0
// Explanation: The thief can't take any plates. So he can't steal any coins.
 



//Solution Approach :-
int maxCoins(int A[], int B[], int T, int N) {
    vector<pair<int,int>> v;
    int ans=0;
    
    for(int i=0;i<N;i++){
        v.push_back(make_pair(B[i],A[i]));
    }

    sort(v.begin(),v.end());
    for(int i=N-1;i>=0 && T!=0;i--){
        int no_of_plates=v[i].second;
        int no_of_coins=v[i].first;
        
        if(no_of_plates<T){
            ans+=no_of_plates*no_of_coins;
            T-=no_of_plates;
        }
        else{
            ans+=T*no_of_coins;
            T=0;
        }
    }
    return ans;
}




//Second Solution :-
bool static comp(pair<int, int> p1, pair<int, int> p2){
    return (p1.second > p2.second);
} 

int maxCoins(int A[], int B[], int T, int N) {
    if(T == 0){
    	return 0;
    }

    vector<pair<int, int >> vi;
    for(int i=0; i<N; i++){
        vi.push_back(make_pair(A[i], B[i]));
    }

    sort(vi.begin(), vi.end(), comp);
    int ans = 0;

    for(int i=0; i<N; i++){
        while(T > 0 and vi[i].first > 0){
            ans = ans + vi[i].second;
            T--;
            vi[i].first--;
        }
    }

    return ans;
}