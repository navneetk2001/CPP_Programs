https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1




//Solution Approach :- 
/*
Time Complexity: O(n) 
Auxiliary Space: O(k)
*/
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    long long i = 0;
    long long j = 0;
    
    vector<long long> ans;
    list<long long> l;

    while(j<N){
        if(A[j]<0){               //if negative number found insert in list
            l.push_back(A[j]);
        }
        if(j-i+1<K){              //if window size is less than k
            j++;
        }
        else if ((j-i+1)==K){     //if window size equal to k
            if(l.size()==0){      //if list is empty then there is no negative integer in that window
                ans.push_back(0);
            }
            else{                 //else return front of list 
                ans.push_back(l.front());
            }
        
            if(A[i]<0){           //now start shrinking the window from left
              l.pop_front();      //if the number on left is negative then remove it from list
            }
            i++;    
            j++;
        }
    }
    return ans;
}  




//Second Solution :-
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    int i=0;
    int j=0;
    queue <long long> qu;
    vector <long long> v;
    
    while(j<N)
    {
        if(A[j]<0){
            qu.push(A[j]);
        }
        if(j-i+1<K){     // if window size less than increase j
            j++;
        }
        else if(j-i+1 == K){ // got exact window size of K
            if(qu.empty()){
                v.push_back(0); // suppose the three number //are there are no negative number so the output will be zero
            }
            else{
                v.push_back(qu.front());
                if(A[i] == qu.front()){
                    qu.pop();
                }
            }
            j++;
            i++;
        }
    }
    return v;
}



//Third Solution :-
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    if(k>n) return {};
    queue<int>q;
    vector<long long>ans;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }

    if(q.empty()){
        ans.push_back(0);
    }else{
        ans.push_back(arr[q.front()]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<0){
            q.push(i);
        }
        if(!q.empty() and q.front()<=i-k){
            q.pop();
        }
        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}