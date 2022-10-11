// N children are made to stand in a queue. Each of them is given a number A[i]. The teacher writes a number S on a page and passes it to the first child. Each child must add all the numbers they see on the page along with their own number, write the sum on the paper and pass it to the next person. 
// In the end, the teacher must determine if X can be formed by adding some of the numbers from the series of numbers written on the paper.

// Example 1:
// Input: 
// S = 1, N = 4, X = 7
// A = {1, 2, 4, 2}
// Output: yes
// Explaination: The final sequence of numbers on the paper is 1, 2, 5, 12, 22. Using 2 and 5 we can form 7. 

// Example 2:
// Input: 
// S = 100, N = 2, X = 500
// A = {51, 88}
// Output: no
// Explaination: The final sequence of numbers on the paper is 100, 151, 339. Using these numbers we cannot form 500.



//First Solution :-
class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        vector<long long >ans;
        ans.push_back(S);
        long long pre=S;
       
        for(int i =0;i<N;i++){
            long long cur=A[i]+pre;
            ans.push_back(cur);
            pre+=cur;
            
            if(pre>X){
                break;
            }
        }
        
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]<=X){
                X-=ans[i];
            }   
            if(X==0){
                return 1;
            }
        }
        return 0;
    }
};


//Second Solution :-
//We use lower bound, to find the index where element is greater than or equal to X. From there we just check if we can reduce X to zero or not

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[]){
        vector<long long> vec;
        vec.push_back(S);
        long long sum=S;
        for(int i=1;i<=N && sum<=X;i++){
            vec.push_back(sum+A[i-1]);
            sum+=vec[i];
        }
        
        N=vec.size();
        long long itr=lower_bound(vec.begin(),vec.end(),X)-vec.begin();
        for(int i=itr;i>=0;i--){
            if(vec[i]<=X){
                X-=vec[i];
            }
            if(X==0){
                return 1;
            }
        }
        return 0;
    }
};


