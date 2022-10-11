https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1




//First Solution :- Using Graphs
//We will find indegree and outdegree of each node and if at any time if indegree is equal to n-1 and at same time outdegree is 0 then he is a celebrity
class Solution {
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
    	int indegree[n] = {0};
    	int outdegree[n]= {0};
    
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(M[i][j] == 1){    //if i knows j then increase indegree of j and outdegree of i
    				indegree[j]++;
    				outdegree[i]++;
    			}
    		}
    	}
    
    	for(int i = 0; i < n; i++){
    		if(indegree[i] == n-1 && outdegree[i] == 0){   //if at any time if indegree is equal to n-1 and at same time outdegree is 0 then he is a celebrity
    			return i;
    		}
    	}
    	return -1;
    }
};



//Second Solution :-  Using Stacks
int celebrity(vector<vector<int> >& M, int n) {
	stack<int> s;
	for (int i=0; i<n; i++){
	   	s.push(i);
	}
	while(s.size()!=1){
	   	int a=s.top();
	   	s.pop();
	   	
	   	int b=s.top();
	   	s.pop();
	   	
	   	if (M[a][b]==1){  //if a knows b means a is not celebrity but b might be so push b
	       	s.push(b);
	   	}
	   	else{             //if a dont knows b means b is not celebrity but a might be so push a
	       	s.push(a);
	   	}
	}   

	// after exiting while loop there will be only one candidate left in stack and that might be a celebrity so now check whether he is a celebrity or not
	
	int candidate = s.top();                    //This might be our answer
	for (int i=0; i<n; i++){
	   	if(i != candidate){                                         // if candidate knows himself then it senseless so check for all other
           if(M[i][candidate]==0 || M[candidate][i]==1){            // here i is a person so first it is checking if there is a person who dont know candidate or the candidate know any person than he is not celebrity
               return -1;
           }
		}
	}
	return candidate;
}



//Third Solution :-
int celebrity(vector<vector<int> >& M, int n){
	int c = 0;  //let's suppose c should be our celebrity
	for(int i=1;i<n;i++){
	   	if(M[c][i] == 1){   //if c knows i then c should not be celebrity so 'i' might be our celebrity
	   		c = i;
	   	}
	}

	for(int i=0;i<n;i++){
	   	if(i != c && (M[c][i] == 1 || M[i][c] == 0)){   //i != c because c is our celebrity and M[cel][i]==1 means if cel knows any ith person so it will not be our celebriity and M[i][cel]==0  it means no one is know celebritry it also not possible
	   		return -1;
	   	}
	}
	return c;
}



//Fourth Solution :-
int celebrity(int M[][], int n)
{   
    int potential = 0;
    for(int i=0;i<n;i++){
        int rsum = 0;
        for(int j=0;j<n;j++){
            rsum+=M[i][j];
        }
        if(rsum==0){
            potential = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=potential){
            if(M[i][potential]!=1){
                return -1;
            }
        }
    }
    return potential;
}