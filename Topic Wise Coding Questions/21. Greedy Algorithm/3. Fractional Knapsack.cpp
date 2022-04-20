Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:240.00
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 

Example 2:
Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item we can have is 160.00 from the given capacity of sack.



//Solution Approach :- Greedy Approach
class Solution
{
    static bool cmp(Item a1, Item a2){
        //int divided or added by double gives double only.
        return a1.value/(0.0 + a1.weight) > a2.value/(0.0 + a2.weight);     //decreasing order
    }
    
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, cmp);
        double curr_W = W, max_val = 0;
        for(int i=0; i<n; i++){
            if(arr[i].weight<=curr_W){
                max_val += arr[i].value;
                curr_W -= arr[i].weight;
                    if(curr_W == 0)     
                    	break;
            }
            else{
                double frac = curr_W/arr[i].weight;
                max_val += arr[i].value * frac;
                curr_W -= arr[i].weight * frac;
                break;
            }
        }
        return max_val;
    }
};


//Second Solution :- 
#define S second
#define F first
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,pair<int,int>>> v(n);
        for(int i=0; i<n; i++)
        {
            v[i] = {(double)arr[i].value/arr[i].weight ,{arr[i].value, arr[i].weight}};
        }

        sort(v.begin(), v.end(), greater<pair<double,pair<int,int>>>());
        
        double ans = 0;
        for(int i=0; i<n; i++)
        {
            if(W == 0) 
            	break;
            
            if(W >= v[i].S.S)
            {
                W -= v[i].S.S;
                ans += v[i].S.F;
            }
            else
            {
                ans += v[i].F*W;
                W = 0;
            }
        }
        return ans;
    }
};


//Third Solution :- Using max Heap and finding Value to Weight Ratio of each item
struct comp{
    bool operator()(pair<double, Item> &p1, pair<double, Item> &p2){
        return p1.first <= p2.first;
    }
};



double fractionalKnapsack(int W, Item arr[], int n)
{
    priority_queue<pair<double, Item>, vector<pair<double, Item>>, comp> pq;
    for(int i = 0; i < n; i++){
        double curr = (double)arr[i].value/(double)arr[i].weight;
        pq.push({curr, arr[i]});
    }
    double ans = 0;
    while(W > 0 && pq.empty() == false){
        auto curr = pq.top();
        pq.pop();
        ans += curr.first*(std::min(W, curr.second.weight));
        W -= min(W, curr.second.weight);
    }
    return ans;
}
