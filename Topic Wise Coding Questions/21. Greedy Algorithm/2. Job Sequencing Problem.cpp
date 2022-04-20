// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

// Example 1:
// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

// Example 2:
// Input:
// N = 5
// Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}
// Output:2 127
// Explanation: 2 jobs can be done with maximum profit of 127 (100+27).



//Solution Approach :- Greedy Approach 
static bool cmp(Job job1, Job job2){
    return job1.profit > job2.profit;
} 
    
    
vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr + n, cmp);
    vector<int> ans (2, 0);

    int maxD = INT_MIN;
    for(int i = 0; i < n; i++){
        maxD = max(maxD, arr[i].dead);
    }

    vector<bool>v(maxD, false);

    for(int i = 0; i < n; i++){
        auto curr = arr[i];
        for(int j = curr.dead - 1; j >= 0; j--){
            if(v[j] == false){
                v[j] = true;
                ans[0]++;
                ans[1] += curr.profit;
                break;
            }
        }
    }
    return ans;
} 


// Second Solution :- Priority Queue
int[] JobScheduling(Job arr[], int n)
{
  PriorityQueue<Job> pq = new PriorityQueue<Job>(n, new Comparator<Job>() {
        public int compare(Job n1, Job n2) {
            if(n1.profit<n2.profit){
             return 1;   
            }else if(n1.profit>n2.profit){
               return -1;  
            }
            return 0;
     }
    });

   int maxSlot = Integer.MIN_VALUE;
   
   for(int i=0;i<n;i++){
       pq.offer(arr[i]);
       maxSlot = Math.max(arr[i].deadline,maxSlot);
   }
   
   int []dp = new int[maxSlot];
   for(int i=0;i<maxSlot;i++){
       dp[i] = -1;
   }
   int ans=0;
   int cnt=0;
   
   while(!pq.isEmpty()){
       
       Job j = pq.poll();
       int p = j.profit;
       int d = j.deadline;
       
       for(int i=d-1;i>=0;i--){
           if(dp[i]==-1){
               dp[i]=p;
               cnt++;
               break;
           }
       }
   }
   
   for(int i=0;i<maxSlot;i++){
       if(dp[i]!=-1){
           ans += dp[i];
       }
   }
   int []res = new int[2];
   res[0]=cnt;
   res[1] = ans;
   return res;
}

