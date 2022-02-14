// Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.
// (For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)
// Return the number of good subarrays of A.

//Hint 
To directly count the subarrays with exactly B different integers is hard but to find the count of subarrays with at most B different integers is easy.
So think how will you find the number of subarray with at most B distinct integers and try to find a solution to the problem.

//Solution Approach :-
Approach:
To directly count the subarrays with exactly B different integers is hard but to find the count of subarrays with at most B different integers is easy.
So the idea is to find the count of subarrays with at most B different integers, let it be C(B), and the count of subarrays with at most (B - 1) different integers, let it be C(B - 1) and finally take their difference, C(B) – C(B – 1) which is the required answer.
Count of subarrays with at most B different elements can be easily calculated through the sliding window technique.
The idea is to keep expanding the right boundary of the window till the count of distinct elements in the window is less than or equal to B and when the count of distinct elements inside the window becomes more than B, start shrinking the window from the left till the count becomes less than or equal to B. Also for every expansion, keep counting the subarrays as right – left + 1 where right and left are the boundaries of the current window.
Time Complexity: O(|A|)
Space Complexity: O(|A|)


//First Solution
int subarray(vector<int> &A,int B){
    int n=A.size();
    int i=0;
    int j=0;
    map<int,int> m;
    int count=0;

    while(i<n){
        m[A[i]]++;
        while(m.size()>B)
        {
            m[A[j]]--;
            if(m[A[j]] == 0)
            {
                m.erase(A[j]);
            }
            j++;
        }
        count+=(i-j+1);
        i++;
    }
    return count;
}

int Solution::solve(vector<int>&A, int k) {
    return subarray(A,k) - subarray(A,k-1);
}

//Second Solution
int Solution::solve(vector<int> &A, int B) {
    int l=0;
    int ans=0;
    int prev=0;
    int r=0;
    int n=A.size();
    int vis[n+1]={0};
    int cnt=0;

    while(r<n)
    {
        if(vis[A[r]]==0)
        {
            cnt++;
        }
        vis[A[r]]++;
        while(cnt>B)
        {
            vis[A[l]]--;
            if(vis[A[l]]==0)
            {
                cnt--;
            }
            l++;
            prev=0;
        }
        while(vis[A[l]]>1)
        {
            prev++;
            vis[A[l]]--;
            l++;
        }
        if(cnt==B)
        {
            ans+=prev+1;
        }
        r++;
    }
    return ans;
}

//Third Solution
int Solution::solve(vector<int> &A, int B) {
    int size=(int) A.size();
    int count=0;
    for(int i=0;i<size;i++){
        count+=solve(A,i+1,B);
    }
    return count;
}

int solve(vector<int> A, int k, int B){
    unordered_map<int ,int > val_count;
    int i=0,j=0;
    int count=0,temp=0;
    int size=(int) A.size();
    while(j<size){
        if(val_count.find(A[j])==val_count.end()) val_count[A[j]]=1;
        else {
            val_count[A[j]]=val_count[A[j]]+1;
            // cout<<"val "<<val_count[A[j]]<<endl;
        }
        if(j-i+1<k) j++;
        else if((j-i+1)==k){
            temp=0;
            for(auto i=val_count.begin();i!=val_count.end();i++){
               if((*i).second !=0){
                //    cout<<k<<endl;
                    // cout<<(*i).first<<' '<<(*i).second<<endl;
                    // cout<<"sdsd"<<endl;
                    temp++;
               }
            }
            val_count[A[i]]--;
            i++;j++;
            if(temp==B) {
                count++;
                // cout<<count<<endl;
            }
        }
    }
    return count;
}


