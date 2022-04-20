// There are N events in Geek's city. You are given two arrays start[] and end[] denoting starting and ending day of the events respectively. Event i starts at start[i] and ends at end[i].
// You can attend an event i at any day d between start[i] and end[i] (start[i] ≤ d ≤ end[i]). But you can attend only one event in a day.
// Find the maximum number of events you can attend.

// Example 1:
// Input:
// N = 3
// start[] = {1, 2, 1}
// end[] = {1, 2, 2}
// Output:
// 2
// Explanation:
// You can attend a maximum of two events.
// You can attend 2 events by attending 1st event
// at Day 1 and 2nd event at Day 2.

// Example 2:
// Input:
// N = 3
// start[i] = {1, 2, 3}
// end[i] = {2, 3, 4} 
// Output :
// 3
// Explanation:
// You can attend all events by attending event 1
// at Day 1, event 2 at Day 2, and event 3 at Day 3.



//Solution Approach :-  Greedy Approach 
// if we try to attend any event as late as possible then we can attend maximum no of meetings
// Sort the meetings according to end days
class Solution {
  public:
    int maxEvents(int start[], int end[], int n) {
        vector<pair<int,int>> v;
        unordered_set<int> s;    //calender for booking a date 

        //inserting all the meetings in a vector
        for(int i=0;i<n;i++){
        	v.push_back({start[i], end[i]});   //sorting in ascending order
        }

        sort(v.begin(), v.end());    //sort in ascending order

        for(int i=v.size()-1;i>=0;i--){
        	if(s.find(v[i].second) == s.end()){   //check if ending day is booked or not 
        		s.insert(v[i].second);          // if not, then insert it in set
        	}
        	else{
        		int e=v[i].second;
        		while(e>=v[i].first){
        			if(s.find(e) == s.end()){   //check if day e is booked or not 
        				s.insert(e);
        				break;
        			}
        			e--;
        		}        	
        	}
        }
        return s.size();   //return how many days are marked in set
    
    }
};

//Another Solution :- using priority queue
class Solution {
 public:
   int maxEvents(int start[], int end[], int N) {
      vector<pair<int,int>> v;
      // inserting all the meetings in a vector
      for(int i = 0; i < N; i++)
          v.push_back({start[i],end[i]});
      
      sort(v.begin(),v.end());   // sort all the meeting according to first and then second day
      
      priority_queue<int,vector<int>,greater<int>> pq; // min Heap
      int cnt = 0; // Max meetings
      int i = 0, d = 0;
      while(!pq.empty() || i < N){
          if(pq.size() == 0)
              d = v[i].first; // cheking if it is the first meeting
          
          /* inserting all the meetings whose starting day is smaller than
          the current day.
          */
          while(i < N && v[i].first <= d)
              pq.push(v[i++].second);
          // removing the meeting that we have taken into in our count(cnt)
          pq.pop();
          
          cnt++; // incrementing the max count
          d++; // incrementing the current day
          
          /* removing all the meetings whose ending time is smaller than d
           because those meetings can not be taken into the answer */
          while(!pq.empty() && pq.top() < d) pq.pop();
      }
      return (cnt);
  
   }
};


//Third Solution :- 
class MyComp {
    public:
    bool operator() (const int &a, const int &b) {
        return a > b;
    };
};

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        list<pair<int, int>> ar;
        for(int i = 0; i < N; i++) ar.push_back({start[i], end[i]});
        
        ar.sort();
        
        priority_queue<int, vector<int>, MyComp> pQueue;
        int cur = 1, ans = 0;
        
        while(cur <= (int)1e5) {
            while(!ar.empty() && ar.front().first == cur) {
                pQueue.push(ar.front().second);
                ar.pop_front();
            }
            
            while(!pQueue.empty() && pQueue.top() < cur) pQueue.pop();
            if(!pQueue.empty()) {
                ++ans;
                pQueue.pop();
            }
            
            ++cur;
        }
        
        return ans;
    }
};