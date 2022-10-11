https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1




//Solution Approach :-
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int sum = 0;   //maintain sum 
        priority_queue<long long int,vector<long long int>, greater<long long int>> pq;  //min heap priority queue
        
        for(int i=0; i<n; i++){
            pq.push(a[i]);       //push all elements in queue
            sum += a[i];         //increment sum
        }
        
        while(k--){             //need to do exactly k negations
            int top = pq.top();    //we will get minimum element on top of min priority queue
            pq.pop();              //pop it
            
            sum -= top;            //remove top from sum
            sum += (-top);         //add negations of sum in the top
            pq.push(-top);         //push negations in priority queue
        }
        return sum;
    }
};




//Second Solution :-
long long int maximizeSum(long long int a[], int n, int k){
    long long int sum = 0;
    int ans = 0;
    sort(a,a+n);

    for(int i=0; i<n && k; i++){
        if(a[i]<0){          //if number is negative, then make it a positive number
            a[i] = -a[i];
            k--;         //decrement count of k after making negative to positive
        }
    }

    sort(a,a+n);
    if(k>0){
        if(k%2){
            a[0] = -a[0];
        }
    }
    
    
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}



//Third Solution :-
class Solution {
public:
    long long int maximizeSum(long long int a[], int n, int k){
        // sort the elements in ascending order
        sort(a, a+n);
        int i=0;
        
        // while the elements are negative and negations are left
        while(i<n and k>0 and a[i]<=0){
            a[i] = -a[i];
            i++;
            k--;
        }
        
        // if k is odd
        if(k%2){
            if(i == 0){         // if all the elements are positive
                a[0] = -a[0];
            }
            else{                  // negate the minimum of a[i-1] and a[i]
                if(min(a[i], a[i-1]) == a[i]){
                    a[i] = -a[i];
                }
                else{
                    a[i-1] = -a[i-1];
                }
            }
        }
        // return the sum
        return accumulate(a, a+n, 0);
    }
};



//Fourth Solution :-
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int j = 0;
        while(k){
            if(a[j]<=0){
                a[j] *= -1;
                j++;
                k--;
            }
            else if(k&1 and j!=0){
                a[j-1] *= -1;
                break;
            }
            else if(k&1 and j==0){
                a[j] *= -1;
                break;
            }
            else if(k%2==0) break;
        }
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum += a[i];
        }
        return sum;
    }
};
