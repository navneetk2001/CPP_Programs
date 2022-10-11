https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1





//Solution Approach :- 
static bool cmp(Job a, Job b){   //sort on the basis of profit in descending order
   	return a.profit > b.profit;
}

//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) { 
   	sort(arr, arr+n, cmp);

   	int ct = 0, profit = 0;
   	vector<int> sch(200, -1);

   	for (int i=0; i<n; i++){
       	int job = arr[i].dead;
       	for(int j = job; j>0; j--){
            if (sch[j]==-1){
               	ct++;
               	profit += arr[i].profit;
               	sch[j] = job;
               	break;
            }
       }
   }
   return {ct, profit};
} 




//Second Solution :-
class Solution {
public:
   //Function to find the maximum profit and the number of jobs done.
   	static bool cmp(Job a, Job b){
       	return a.profit > b.profit;    
   	}
   
   	vector<int> JobScheduling(Job arr[], int n){ 
       	sort(arr, arr+n, cmp);
       
       	vector<bool> visited(n, false);
       	int profit = 0;
       	int count = 0;
       
       	for(int i = 0; i<n; i++){
           	int curr_deadline = arr[i].dead;
           
           	while(curr_deadline > 0){
               	curr_deadline--;
               	if(visited[curr_deadline] == false){   
                   visited[curr_deadline] = true;
                   profit += arr[i].profit;
                   count++;
                   break;
               }
           }
       }
       
       return {count, profit};
   } 
};



//Third Solution :- 
struct compr{
public:
    bool operator()(const Job&j1,const Job&j2){
        if(j1.profit == j2.profit){
        	return j1.dead > j2.dead;
        }
        return j1.profit < j2.profit;
    }
};
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
            
        sort(arr,arr+ n ,[&](auto &j1 ,auto &j2){
            // if(j1.profit == j2.profit)return j1.dead < j2.dead; return j1.profit > j2.profit;
            // sorting on the basis of (decreasing)deadline as there will always be space for the end tasks
            return j1.dead > j2.dead;
        });
        
        int deads[102] , ans =0 ,c = 0;
        memset(deads,0,sizeof deads);

        priority_queue<Job,vector<Job>,compr>q;
        vector<Job>job;

        for(int i = 0 ;i < n ;i++ ){
            // find out the free slots bw current and next job  
            int slots = ((i!=n - 1)? arr[i].dead - arr[ i + 1].dead : arr[i].dead) ;
            
            // incldue the current job at hand it may or may not be the optimal unless we push to PQ.
            q.push(arr[i]);
            
            // while there are free slots left and q is not empty the q will give the max profit job at each iteration you can also see which jobs were taken from the job vector
            while(slots && !q.empty()){
                auto jobb = q.top();
                job.push_back(jobb);
                ans+= jobb.profit;
                slots--;
                q.pop();
                c++;
            }
            // this below code is of O(n^2) 
            // int curr = arr[i].dead;
            // while( curr >= 0 && deads[curr] != 0 ){
            //     curr--;
            // }
            // if(curr >= 0){
            //     deads[curr] = arr[i].id;
            //     ans+=arr[i].profit;
            //     c++;
            // }
            
        }
        
    return {c,ans};
    } 

