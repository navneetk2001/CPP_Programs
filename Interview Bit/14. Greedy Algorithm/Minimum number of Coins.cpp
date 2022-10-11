https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1




//Solution Approach :-
class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> coins { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        vector<int> res;
        int s = coins.size();
        
        for(int i=s-1;i>=0;i--) {
            while(coins[i] <= N){
                N -= coins[i];
                res.push_back(coins[i]);
            }
            if(N == 0) {
                break;
            }
        }
        return res;
    }
};




//Second Solution :-
vector<int> minPartition(int N){
    vector<int> currency = {2000,500,200,100,50,20,10,5,2,1};
    vector<int> change;
    int i=0;
    while(N>0)
    {
        while(currency[i]>N)i++;
        int qty=N/currency[i];
        N=N%currency[i];
        for(int x=1;x<=qty;x++)
            change.push_back(currency[i]);
        i++;
    }
    return change;
}



//Third Solution  :- 
class Solution{
public:
    vector<int> arr = {1 , 2 , 5 , 10 ,20 , 50 , 100 , 200 , 500 , 2000};
    vector<int> minPartition(int N)
    {
        if(N == 0){
            return {};
        }
        int i ;
        for(i = arr.size() - 1; i >= 0 && arr[i] > N ; i--);
        
        vector<int> res = {arr[i]};
        vector<int> curr = minPartition(N-arr[i]);
        
        res.insert(res.end() , curr.begin() , curr.end());
        return res;
    }
};

