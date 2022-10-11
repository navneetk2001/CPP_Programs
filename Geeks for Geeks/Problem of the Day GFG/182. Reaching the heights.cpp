https://practice.geeksforgeeks.org/problems/reaching-the-heights1921/1



//Solution Approach :-
vector<int> reaching_height(int n, int a[]) {
    vector<int>ans;
    if(n==1){
        ans.push_back(a[0]);
        return ans;
    }

    sort(a,a+n);
    int start = 0;
    int end = n-1;
    
    if(a[0] == a[end]){
        ans.push_back(-1);
        return ans;
    }

    int flag=1;
    while(start<=end){
        if(flag==1){
            ans.push_back(a[end]);
            end--;
        }
        else{
                ans.push_back(a[start]);
                start++;
        }
        flag=!flag;
    }
    return ans;
}




//Second Solution :-
vector<int> reaching_height(int n, int v[]) {
    if(n == 0){
        return {-1};
    }
    
    sort(v,v+n);
    vector<int> ans;
    
    int i = 0, j = n-1, cnt = 0;

    while(i < j) {
        if(cnt%2 == 0){
            ans.push_back(v[j]);
            j--;
        }
        else {
            ans.push_back(v[i]);
            i++;
        }
        cnt++;
    }
    ans.push_back(v[i]);

    int up = 0,down = 0;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0){
            up += ans[i];
        }
        else{
            down += ans[i];
        }
    }
    
    if(up > down) return ans;
    return {-1};
}




//Third Solution :-
vector<int> reaching_height(int n, int a[]) {
    sort(a,a+n);
    
    vector<int>ans;
    int j=n-1,i=0;
    int s1=0,s2=0;
    
    while(i<=j){
        ans.push_back(a[j--]);
        s1+=ans.back();
        if(i<=j){
            ans.push_back(a[i++]);
            s2+=ans.back();
        }
    }
    
    if(s1==s2){
        return {-1};
    }
    
    return ans;
}