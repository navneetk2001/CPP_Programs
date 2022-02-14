#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool activityCompare(vector<pair<int,int>> s1 , vector<pair<int,int>> s2)
{
    return (s1[1] < s2[1]);
}

int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    int n=activities.size();
    sort(activities.begin(), activities.end(), activityCompare);

    int i, j;
    int cnt=0;

    i = 0;
    cnt=1;   //first activity always gets selected
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
        // If this activity has start time greater than or equal to the finish time of previously selected activity, then select it
      if (activities[j].first >= activities[i].second)
      {
          cnt+=1;
          i = j;
      }
    }
    return cnt;
}


int main()
{
	vector<pair<int,int> >activities({7,9},{0,10},{4,5},{8,9},{4,10},{5,7});
	cout<<countActivites(activities)<<endl;

	return 0;
}

