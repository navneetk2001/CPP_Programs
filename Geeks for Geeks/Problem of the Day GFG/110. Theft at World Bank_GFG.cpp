// The worlds most successful thief Albert Spaggiari was planning for his next heist on the world bank. He decides to carry a sack with him, which can carry a maximum weight of C kgs. Inside the world bank there were N large blocks of gold. All the blocks have some profit value associated with them i.e. if he steals ith block of weight w[i] then he will have p[i] profit. As blocks were heavy he decided to steal some part of them by cutting them with his cutter.
// The thief does not like symmetry, hence, he wishes to not take blocks or parts of them whose weight is a perfect square. Now, you need to find out the maximum profit that he can earn given that he can only carry blocks of gold in his sack. 
// Note: The answer should be precise upto 3 decimal places.

// Example 1 :
// N = 3, C = 10
// w[] = {4, 5, 7}
// p[] = {8, 5, 4}
// Output: 7.857
// Explanation: As first blocks weight is 4 which is a perfect square, he will not use 
// this block. Now with the remaining blocks the most optimal way is to use 2nd block 
// completely and cut 5kg piece from the 3rd block to get a total profit of 5 + 2.857 = 7.857



//Solution Approach :-
//Choose according to per unit profit i.e. P[i]/W[i]
static bool cmp(pair<long double,long long>&a, pair<long double,long long>&b){
    return a.first>b.first;
}

long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
   vector<pair<long double,long long>>mp;
   for(int i=0;i<N;i++){
       mp.push_back({(double)p[i]/(double)w[i],w[i]});
   }

   sort(mp.begin(),mp.end(),cmp);
   long double profit=0;

   for(int i=0;i<mp.size();i++){
       long long m=sqrt(mp[i].second);
       if(mp[i].second!=m*m){
           if(C-mp[i].second>=0){
               profit+=mp[i].first*mp[i].second;
               C=C-mp[i].second;
           }
           else{
               long double x=mp[i].first*C;
               profit+=x;
               break;
           }
       }
   }
   return profit;
}




//Second Solution :- Fractional Knapsack (Using Priority Queue)
long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
    priority_queue< pair<long double , pair<long long,long long>> > pq;
    
    for(int i=0; i<N; i++){
        long double ratio= (double)p[i]/w[i];
        pq.push({ratio , {p[i] , w[i]} }); 
    }
    
    long double TotalProfit =0;
    
    while(!pq.empty() && C>0){
        long long profit=pq.top().second.first;
        long long weight=pq.top().second.second;
        
        long double ratio=pq.top().first;
        pq.pop();
        
        long long x=sqrt(weight);
        if(x*x==weight)
         continue;
        
        if(C > weight){
            TotalProfit +=  double(profit);
            C  -= weight;
        }else{
            TotalProfit +=  double(ratio*C);
            C -=C;
        }
    }
    return TotalProfit;
}


//Third Solution :-
bool perfectSquare(long long  n){
   long long  k = sqrt(n);
   return k * k == n;
}

static bool comp(pair<long long , long long>& a , pair<long long ,long long >& b){
   return a.second * b.first > a.first * b.second;
}


long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> P){
    pair<long long ,long long>p[N];
    for(int i = 0 ; i < N; i++){
    	p[i] = {w[i] , P[i]};
    }

    sort(p , p + N , comp);
    long double res = 0.0;

    for(int i = 0 ; i < N ; i++){
        long long cost = p[i].second , weight = p[i].first;
        if(perfectSquare(weight))
        	continue;
        
        if(weight <= C)
        {
            res += (double)cost;
            C -= weight;
        }
        else{
            res += (double)(cost * C) / (double)weight;
            break;
        }
    }
    return res;
}