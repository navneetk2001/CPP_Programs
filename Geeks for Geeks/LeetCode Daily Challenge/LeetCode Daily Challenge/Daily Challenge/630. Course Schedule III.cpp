// There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
// You will start on the 1st day and you cannot take two or more courses simultaneously.
// Return the maximum number of courses that you can take.

// Example 1:
// Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
// Output: 3
// Explanation: 
// There are totally 4 courses, but you can take 3 courses at most:
// First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
// Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
// Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
// The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

// Example 2:
// Input: courses = [[1,2]]
// Output: 1

// Example 3:
// Input: courses = [[3,2],[4,3]]
// Output: 0




//Solution Approach :-
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b){  //sort on the basis of end time
            return a[1] < b[1];
        });

        priority_queue<int> q;    //max heap priority queue to store the duration
        
        int sum = 0;                  //total time till now
        for(auto i : courses) {
            sum += i[0];           //adding the duration in sum
            q.push(i[0]);          //push it in priority queue
            if(sum > i[1]) {       //if sum is greater than end time then remove top element
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};




//Second Solution :-
// Approach :
// The main concept here is doing the courses first whose deadline is shorter and if you cant do that course before deadline see if you can minimise the total time taken by replacing the previous longest course with the current course as any previous couse had smaller deadline than current.
// So what we can do is the following :
// At first sort the courses in increasing order of their deadline/lastday. So that the courses with shorter deadlines are done before others. Also declare a priority queue for storing the length of the courses done. Along with that declare a variable which stores the total time taken till now.
// Iterating over the arrayif the sum of current course dutration and the previous total durartion is less than lastday of that course then we can do that course. So add its duration to total duration and add it to the priority queue.
// If the previous condition is not met we cant do the course. So we can try to minimise the total time taken so that we can make more room for new course in future. So if any course is done before (we can check that be checking the priority queu is empty or not) we check if it is the longest course till now, if its not then replace the previous longest course with current course. For this remove the top course time from queue and total time and add current course time to both. This replace will work every time as the current lastday is always less than any of previous lastday.
// If a course doesnt fullfill any condition then skip it (As you can't do it any way).
// At last the priority queue will only contain the courses which were done. So total number of courses is the size of the queue which is returned.
// Note : The comp function compares the lastday of each course for sorting.


class Solution{
public:
    //comparartor function to comare if the lastday of a course
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>> &courses){        
        //soring according to lastday in increasing order.
        sort(courses.begin(), courses.end(), comp);
        
        //priority queue to store duration of couses
        priority_queue<int> maxD;

        int time = 0; // time to store the total time taken
        for (auto course : courses){
            
            //if total time taken including this course is lesser than or equal to the last day then add couse to queue and add the time to total time
            if (time + course[0] <= course[1]){
                time += course[0];
                maxD.push(course[0]);
            }
            
            //else if there are element in priority queue then check if current course is shorter than the max previous couse then just replace that with current
            else if (!maxD.empty() && maxD.top() >= course[0]){
                time = time - maxD.top() + course[0]; //replacing max previous course with current in toytal time
                maxD.pop();                           //taking out max previous
                maxD.push(course[0]);                 //adding current course
            }
        }
        
        //as queue only contains the courses taken so size of queue is the number of courses.
        return maxD.size();
    }
};