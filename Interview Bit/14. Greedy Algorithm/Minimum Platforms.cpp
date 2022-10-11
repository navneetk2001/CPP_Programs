https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1




//Solution Approach :-
//Intuition: At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of trains that have arrived but not departed yet. Total platforms needed at one time can be found by taking the difference of arrivals and departures at that time and the maximum value of all times will be the final answer.

class Solution{
public:https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1




//Solution Approach :-
//Intuition: At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the count of trains that have arrived but not departed yet. Total platforms needed at one time can be found by taking the difference of arrivals and departures at that time and the maximum value of all times will be the final answer.

class Solution{
public:
    //Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
        sort(arr,arr+n);
        sort(dep,dep+n);
     
        int ans = 1;     
        int count = 1;   //platform needed
        int i=1, j=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){      //if arrival time of second train is less than departure time of first then one more platform needed
                count++;
                i++;
            }
            else{            //else one platform can be reduced
                count--;
                j++;
            }
            ans = max(ans, count);      //updating the value with the current maximum
        }
        return ans;
    }
};




//Second Solution :-
int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],dep[i]});
    }

    sort(v.begin(),v.end());      //sort on the basis of arrival time
    priority_queue<int , vector<int> , greater<int>>q;     //min heap priority queue
    q.push(v[0].second);
    
    for(int i=1;i<n;i++){
        if(v[i].first > q.top()){
            q.pop();
        }
        q.push(v[i].second); 
    }
    return q.size();
}



//Third Solution  :- Brute Force Approach
//Intuition: Take each interval of arrival and departure one by one and count the number of overlapping time intervals. This can easily be done using nested for-loops. Maintain the maximum value of the count during the process and return the maximum value at the end.

int countPlatforms(int n,int arr[],int dep[]){
    int ans=1; //final value
    for(int i=0;i<=n-1;i++){
        int count=1;                // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] && arr[j]<=dep[i])){
                count++;
            }
        }
        ans=max(ans, count); //updating the value
    }
    return ans;
 }




//Fourth Solution :-
int findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int ans = 1;
	multiset<int> ms;
	
	for(int i=0; i<n; i++){
	    int leave = -1;
	    for(auto e : ms){
	        if(e < arr[i]){
	            leave = max(leave, e);
	        }
	    }
	    if(leave != -1){
	        ms.erase(leave);
	    }
	    ms.insert(dep[i]);
	    ans = max(ans, (int)ms.size());
	}
	return ans;
}
    //Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
        sort(arr,arr+n);
        sort(dep,dep+n);
     
        int ans = 1;     
        int count = 1;   //platform needed
        int i=1, j=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){      //if arrival time of second train is less than departure time of first then one more platform needed
                count++;
                i++;
            }
            else{            //else one platform can be reduced
                count--;
                j++;
            }
            ans = max(ans, count);      //updating the value with the current maximum
        }
        return ans;
    }
};




//Second Solution :-
//Intuition: Take each interval of arrival and departure one by one and count the number of overlapping time intervals. This can easily be done using nested for-loops. Maintain the maximum value of the count during the process and return the maximum value at the end.

int countPlatforms(int n,int arr[],int dep[]){
    int ans=1; //final value
    for(int i=0;i<=n-1;i++){
        int count=1;                // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] && arr[j]<=dep[i])){
                count++;
            }
        }
        ans=max(ans, count); //updating the value
    }
    return ans;
 }




//Third Solution :-
int findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int ans = 1;
	multiset<int> ms;
	
	for(int i=0; i<n; i++){
	    int leave = -1;
	    for(auto e : ms){
	        if(e < arr[i]){
	            leave = max(leave, e);
	        }
	    }
	    if(leave != -1){
	        ms.erase(leave);
	    }
	    ms.insert(dep[i]);
	    ans = max(ans, (int)ms.size());
	}
	return ans;
}