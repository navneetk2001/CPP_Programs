// A hotel manager has to process N advance bookings of rooms for the next season. 
// His hotel has C rooms. Bookings contain an arrival date and a departure date. 
// He wants to find out whether there are enough rooms in the hotel to satisfy the demand. 
// Write a program that solves this problem in time O(N log N) .


//Solution Approach
Solution approach :

1. Create event points for every interval start, and end. 
2. Sort it according to the day. 
3. Now, iterate over them one by one. If you encounter a start, then the number of active guests increase by one. If you encounter an end, the number of active guests decrease by one. 
4. If at any point, the number of active guests exceed K, we know that scheduling is not possible. 

GOTCHAS : What if there are multiple start and end on the same day ? How should they be ordered ?

Happy Coding



// First Method :-
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int cnt=1;
    int i=0 , j=1;
    while(j< arrive.size())
    {
        if(depart[i]>arrive[j])
            cnt++;
        else
            i++;
            
        j++;
        
    }
    return cnt<= K;
    
}




//Second Method :-
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    for (int i=K; i<arrive.size();i++)
    {
        if (arrive[i]<depart[i-K])
            return false;
    }
    return true;
}



//Third Solution :-
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
sort(arrive.begin(),arrive.end());
sort(depart.begin(),depart.end());
int rooms=K;
int n=arrive.size();
int m=depart.size();
int i=0,j=0;
while(i<n||j<m)
{
    if(i<n && j<m)
    {
        if(arrive[i]<depart[j])
        {
            if(rooms==0)
                return false;
            rooms--;
            i++;
        }
        else
        {
            rooms++;
            j++;
        }
    }
    else if(i<n)
    {
        if(rooms==0)
            return false;
        rooms--;
        i++;
    }
    else
    {
        rooms++;
        j++;
    }

}
return true;

}


//Fourth Method :-
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
      map<int,int> m;
      for(auto&i:arrive) m[i]++;
      for(auto&i:depart) m[i]--;
      int count = 0;
      for(auto&i:m){
          count+=i.second;
          if(count<0 || count>K) return false;
      }
      return true;
  }


  //Fifth Method 
  class Solution {
    public:
    
    bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
        
        if(K == 0)
                return false;

        int N = arrive.size();
        
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
         
        sort(vec.begin(), vec.end());
        
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1) { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }
};

