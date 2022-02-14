// In a long hallway some soldiers are walking from left to right and some from right to left all at the same speed.
// Every time while walking they cross through another soldier they salute and move ahead.
// Given a string A of length N showing the soldiers' direction they are walking. 
// '<' denotes a soldier is walking from right to left, and '>' denotes a soldier is walking from left to right. 
// Return the number of Salutes done.


//Hint
Two soldiers only cross each other if the left soldier is '>' and the right soldier is '<'.

//Solution Approach :-
We have to check how many soldiers cross each other.
We have to count total number of pairs such that '>' comes before '<'.
So, lets fix the '>' and for each '>', lets count the number of '<' occuring to its right.
Sum of all such occurences is the answer.
Think of an efficient way to count '<' in a range of numbers.
We can simply take the suffix sum of '<', then for each position '>', we add the current value of suffix sum to the answer.


// First Method :-
long Solution::countSalutes(string A) {
    long sum = 0;
    long rightCount = 0;
    for(char c:A){
        if(c=='>'){
            rightCount++;
        }
        else{        //Since a left moving soldier is seen, he will make salutes equal to the right moving soldiers on his left , ie., rightCount
            sum += rightCount;
        }
    }
    return sum;
}



//Second Method :-
long Solution::countSalutes(string A) {
	int n=A.size();
    long res = 0;
    long forwardArrow = 0;
    for(char c:A){
        if(c=='<'){
            res += forwardArrow;
        }
        else{        //Since a left moving soldier is seen, he will make salutes equal to the right moving soldiers on his left , ie., rightCount
        	forwardArrow++;
        }
    }
    return res;
}


//Third Method :-
long Solution::countSalutes(string A) {
    long ans = 0;
        long count = 0;
        int n = A.size();
        for(int i = n - 1; i >= 0; i--){
            if(A[i] == '<')
                count++;
            else ans += count;
        }
        return ans;
}
