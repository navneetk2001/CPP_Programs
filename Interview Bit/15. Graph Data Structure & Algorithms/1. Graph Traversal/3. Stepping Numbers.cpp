https://www.interviewbit.com/problems/stepping-numbers/




//Solution Approach :- 
// As we have already discussed in the Hint , We can think of it as a graph where every node is a stepping number.
// There will be an edge (directed edge) from node u to node v if

// v=u*10+LastDigit-1 ( This case only valid if LastDigit>0)
// OR
// v=u*10+LastDigit+1 ( This case only valid if LastDigit<9)
// where LastDigit is u%10 i.e. the last digit of u.

// Now we can simply do a dfs traversal from 1 to 9 and check if the number falls in the range or not. If it falls in the range increment the answer.
// Lets take a example:

// A = 10 B = 20
// start node = 0
// From 0, we can move to 1 2 3 4 5 6 7 8 9 [ these are not in our range so we don't add it ]
// now from 1, we can move to 12 and 10 
// from 2, 23 and 21
// from 3, 34 and 32
// .


void exploreAllPath(int value, int &a, int &b, vector<int> &ans){
    if(value > b){         // if answer exceeds "B"
    	return;
    }
    
    if(value>=a && value<=b){          // if answer in the range then store the result
        ans.push_back(value);
    }
    
    int back = value % 10;

    if((back)!=0){        // explore previous adjacent
        exploreAllPath(value*10+(back-1),a,b,ans);
    }

    if(back!=9){            // explore next adjacent
        exploreAllPath(value*10+(back+1),a,b,ans);
    }
}

vector<int> stepnum(int A, int B) {
   	vector<int> ans;

   	if(A==0){
   		ans.push_back(0);
   	}
   
	// start from 1 , 9 and explore all path
	for(int i=1;i<=9;i++){
	  	exploreAllPath(i,A,B,ans);
	}

	// lastly sort the answer
	sort(ans.begin(),ans.end());
	return ans;
}


/*
 let n= 2^(no of digit in B)= 2^(log10(B))
 space Complexity:  O(9*n) = O(n)
 time Complexity: n*log(n)  // size of ans
*/



//Second Solution :- BFS
// Intuition - suppose the starting number in the queue push the no. from 1 to 9
// then form the number by taking the digits one greater and one smaller
// this is bfs based question

vector<int> Solution::stepnum(int A, int B) {
    queue<int> q;
    vector<int> ans;
   
    // A= 10 , 213
    // push 1 to 9 in queue
    //for instance take value 2 from queue-> 21 , 23
    // after 21->213 , 210
    // 23 -> 232 , 234
   
    for(int i=1;i<=9;i++){
        q.push(i);
    }
   
    if(A==0){
        ans.push_back(0);
    }
   
    while(!q.empty()){
        int x=q.front();
        q.pop();
       
        if(x>=A && x<=B){
            ans.push_back(x);
        }
       
        if(x>B){
            break;
        }
       
        int last_digit=x%10;
       
        if(last_digit>=1 && last_digit<=9){
            int next_number_one_smaller=(x*10 + last_digit-1 );
            q.push(next_number_one_smaller);
        }
       
        if(last_digit>=0 && last_digit<=8){
            int next_number_one_greater=(x*10 + last_digit+1);
            q.push(next_number_one_greater);
        }
    }
    return ans;
}




//Third Solution :- DFS
vector<int> Ans;
void dfs(int len, int N, int M, int num = 0) {
    if(num >= N && num <= M) {
            Ans.push_back(num);
     }
     if(len == 0)
        return;
    

    if(num == 0) {
        for(int i = 1; i <= 9; ++i) {
            dfs(len - 1, N, M, i);
        }
        return;
    }

    int last_dig = num%10;
    if(last_dig == 0) {
    
        dfs(len - 1, N, M, (num * 10) + (last_dig + 1));
    
    } else if(last_dig == 9) {
    
        dfs(len - 1, N, M, (num * 10) + (last_dig - 1));
    
    } else {
        dfs(len - 1, N, M, (num * 10) + (last_dig - 1));
        dfs(len - 1, N, M, (num * 10) + (last_dig + 1));
    }
}

vector<int> Solution:: stepnum(int N, int M) {
    int len = 0;
    int temp = M;
    Ans.clear();
    while(temp) {
        temp /= 10;
        len++;
    }

    Ans.clear();
    dfs(len, N, M);
    sort(Ans.begin(), Ans.end());
    return Ans;
}