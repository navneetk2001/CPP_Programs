// Given an array of integers A of size N and an integer B.
// College library has N bags,the ith book has A[i] number of pages.
// You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

// A book will be allocated to exactly one student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
// Calculate and return that minimum possible number.

// NOTE: Return -1 if a valid assignment is not possible.

//Solution Approach 
Here we will solve what has been discussed in the previous hint :
Problem statement : Given fixed number of pages (V),  how many number of students we need?
Solution :
   simple simulation approach
   intially Sum := 0
   cnt_of_student = 0
   iterate over all books:
        If Sum + number_of_pages_in_current_book > V :
                  increment cnt_of_student
                  update Sum
        Else:
                  update Sum
   EndLoop;

    fix range LOW, HIGH
    Loop until LOW < HIGH:
            find MID_point
            Is number of students required to keep max number of pages below MID < M ? 
            IF Yes:
                update HIGH
            Else
                update LOW
    EndLoop;



// First Method :-
bool isValid(vector<int> &A, int B,int mid){
    int n=A.size();
	int student=1;
	int sum=0;

	for(int i=0;i<n;i++){
		sum+=A[i];

	    if(sum>mid){
		    student++;
		    sum=A[i];
	    }

	    if(student>B){
		    return false;
	    }
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(B>n) return -1;
    if(n==1) return A[0];
    int max_element =0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        max_element=max(max_element,A[i]);
    }

    int start=max_element;           
    int end=sum;

    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;

        if(isValid(A,B,mid)==true){
            res=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}


//Second Method :-
class Solution {
    public:
        bool isPossible(vector<int> &V, int M, int curMin) {
            int studentsRequired = 1;
            int curSum = 0;
            for (int i = 0; i < V.size(); i++) {
                if (V[i] > curMin) return false;
                if (curSum + V[i] > curMin) {
                    studentsRequired++;
                    curSum = V[i]; 
                    if (studentsRequired > M) return false;
                } else {
                    curSum += V[i];
                }
            }
            return true;
        }

        int books(vector<int> Vec, int M) {
            long long sum = 0;
            int N = Vec.size();

            if(N < M)
                return -1;

            for(int i = 0; i < N; ++i) {
                sum += Vec[i];
            }

            long long start = 0;
            long long end = sum, mid;
            int ans = INT_MAX; 
            while(start <= end) {
                mid = (start + end) / 2;
                if (isPossible(Vec, M, mid)) {
                    ans = min(ans, (int)mid);
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return ans;

        }
};