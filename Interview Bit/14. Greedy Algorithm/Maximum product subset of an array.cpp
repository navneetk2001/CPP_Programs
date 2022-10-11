https://practice.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1




//Solution Approach :-
class Solution{
public:
    long long int findMaxProduct(vector<int>&a, int n){
        if(n == 1){
            return a[0];
        }

        long long int prod = 1, mod = 1e9+7;
        int zeroes = 0, negs = 0;    //maintain a negative count and zero count
        int maxNeg = INT_MIN;          //Also maintain a maxNegative in case if we have odd number of negCount
        
        for(int i=0; i<n; i++){
            if(a[i] == 0){
                zeroes++;
                continue;
            }
            else if(a[i] < 0){
                negs++;
                maxNeg = max(maxNeg, a[i]);
            }
            prod = (prod * a[i]) % mod;
        }
        
        if(zeroes == n){
            return (0);
        }
        if(negs == 1 && zeroes + negs == n){
            return (0);
        }
        if(negs & 1 == 1){   //if odd number of negative number are present in the array
            prod /= maxNeg;
        }
        return (prod);  
    }
};




//Second Solution :-
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        sort(a.begin(),a.end());
        if(n == 1){
            return a[0];
        }
        
        long long int prod =1, mod=1e9+7;
        int zeroes = 0,negCnt=0;     //Maintain negCount and ZeroCount in the array
        int maxNeg = INT_MIN;        //Maintain a maximum negative throughout the array
        
        for(int i=0;i<n;i++){
            if(a[i]<0){
                negCnt++;
            }
            if(a[i]==0){
                zeroes++;
            }
        }   
        
        long long int negProd =1;
        if(negCnt % 2 == 0){
            for(int i=0; i<n; i++){
                if(a[i]<0){
                    negProd=(negProd*a[i])%mod;
                }
            }
        }
        else{
            for(int i=0;i<negCnt-1;i++){
                negProd=(negProd*a[i])%mod;
            }
        }
        
        if(zeroes == n){
            return (0);
        }
        if(negCnt==1 && zeroes+negCnt==n){
            return (0);
        }
        
        for(int i=0;i<n;i++){
            if(a[i]>0){
                prod=(prod*a[i])%mod;
            }
        }
            
        return (negProd*prod)%mod; 
    }
};



