https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos



//Recursion Solution :- 
// int day :- Represents current day
// int last :- represents last day on which work was done so that on the next day we can't choose that

int f(int day, int last, vector<vector<int>> &points){
    if(day==0){          //Base Case
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + f(day-1,task,points);
            maxi=max(maxi,point);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    return f(n-1,3,points);  //3 represents no task has been done
}



//Memoization Solution :-
int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {
    if(dp[day][last] != -1){
        return dp[day][last];
    }

    if(day == 0){
        int maxi = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != last) {
            int activity = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, activity);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));   //n*4 dp array 
  return f(n - 1, 3, points, dp);
}



//Tabulation Approach :-
int ninjaTraining(int n, vector < vector < int > > & points) {
    vector < vector < int > > dp(n, vector < int > (4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}



//Space-Optimization Code:-
int ninjaTraining(int n, vector < vector < int > > & points) {
    vector < int > prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector < int > temp(4, 0);
        for (int last = 0; last < 4; last++) {
            temp[last] = 0;
            for (int task = 0; task <= 2; task++) {
                if (task != last) {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}



