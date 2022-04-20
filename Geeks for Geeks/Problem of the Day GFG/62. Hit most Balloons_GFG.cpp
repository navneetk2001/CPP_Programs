// You are given an infinite two-dimensional grid. There are N balloons placed at certain coordinates of the grid. You have an arrow with yourself, which you will be using to shoot the balloons. You can select any point on the grid as your starting point and any point on the grid as the target point. When you fire the arrow, all ballons lying on the shortest path between the starting point and target point will be burst. Given the coordinates of the N ballons in an array arr, your task is to find out the maximum number of balloons that you can fire in one arrow shot.

// Example 1:
// Input:
// N = 3
// arr[] = {{1, 2}, {2, 3}, {3, 4}}
// Output:
// 3
// Explanation:
// If you position yourself at point (1,2) and fire the arrow aiming at the point (3,4).
// Then all the balloons will burst.

// Example 2:
// Input: 
// N = 3
// arr[] = {{2,2}, {0,0}, {1,2}} 
// Output:
// 2
// Explanation: 
// If you position yourself at point (2,2) and fire the arrow aiming at the point (0,0).
// Then the two balloons present at the two points will burst.




//Solution Approach :-
//We will check for slope. If hthe slopes are equal then that baloon will also get burst
//if the baloon is present where you are standing, then count++;

int mostBalloons(int N, pair<int, int> arr[]) 
{
       int res = 0;
       for(int i=0;i<N;i++)
       {
           double x1 = arr[i].first;    //x-coordinate
           double y1 = arr[i].second;   //y-coordinate

           unordered_map<double,int>m;
           int count = 0;
           for(int j=0;j<N;j++)
           {
               double x2 = arr[j].first;
               double y2 = arr[j].second;
               if(x1==x2 && y1==y2)     //balloon is present at same point
               {
                   count++;
               }
               else
               {
               		double slope = double(y2-y1)/double(x2-x1);
               		m[slope]++;
               }
           }
           auto it = m.begin();
           while(it!=m.end())
           {
               res = max(res,it->second+count);
               it++;
           }
       }
    return res;
 }


