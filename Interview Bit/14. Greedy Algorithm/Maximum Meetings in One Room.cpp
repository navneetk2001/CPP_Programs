https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1



//Solution Approach :-
static bool comp(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b){
   	if(a.second.second == b.second.second){       //if end time of 2 meetings are equal then choose on basis on smaller index choose
       	return a.first < b.first;
   	}
    return a.second.second < b.second.second;       //else sort on the basis of finish time in ascending order
}

vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
   	vector<pair<int,pair<int,int>>>m;
    
    for(int i=0;i<N;i++){ 
       	m.push_back({i+1,{S[i],F[i]}});    //stores meeting number, {start time, finish time}
   	}
   	sort(m.begin(),m.end(),comp);          //sort on the basis of finish time in ascending order

	vector<int>ans;
	ans.push_back(m[0].first);

	int end = m[0].second.second;      //end time of first meeting
	for(int j = 1; j < N; j++){
       	if(end < m[j].second.first){     //if start time of current meeting is greater than endtime of previous meeting
           	ans.push_back(m[j].first);   //store meeting number in answer
           	end = m[j].second.second;    //update end time according yo current meeting
       	}
   	}
   	
   	sort(ans.begin(),ans.end());
   	return ans;
}




//Second Solution :-
struct node
{
    int start,end,ind;
};
bool cmp(node a,node b)
{
    if(a.end==b.end)
    return a.ind<b.ind;
    return a.end<b.end;
}
class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &e)
    {
        vector<node> v;
        vector<int>ans;
        node t;
        
        for(int i=0;i<s.size();i++)
        {
            t.start=s[i];
            t.end=e[i];
            t.ind=i+1;
            v.push_back(t);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        ans.push_back(v[0].ind);
        t=v[0];
        for(int i=1;i<s.size();i++)
        {
            if(v[i].start>t.end)
            {
                t=v[i];
                ans.push_back(v[i].ind);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
