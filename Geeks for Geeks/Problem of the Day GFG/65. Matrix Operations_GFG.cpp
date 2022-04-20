// Given a binary matrix of dimensions M * N. One can perform the given operation in the matrix.
// If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
// If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction from up, right, down, or left to the directions right, down, left, and up respectively.
// Initially you start from cell(0, 0), moving in right direction.

// The task is to find the first cell of the matrix  which leads to outside the matrix from the traversal of the given matrix from the cell (0, 0) by performing the operations.

// Example 1:
// Input:
// matrix[][] = {{0,1},
//               {1,0}}

// Output: (1,1)

// Example 2:
// Input: 
// matrix[][] = {{0, 1, 1, 1, 0},
//               {1, 0, 1, 0, 1},
//               {1, 1, 1, 0, 0}}
// Output: (2,0)



//Solution Approach :-
//We need to know when we are outside of our boundary
class Solution{
public:
   bool check(int i, int j, int n, int m){
        if(i<0 || j<0 || i>= n || j>=m){
            return true;
        }else{
            return false;
        }
    }

    pair<int,int> endPoints(vector<vector<int>> matrix){
	   int n= matrix.size();
       int m= matrix[0].size();
       int i=0;
       int j=0;
       char direction='R';
       while(true){
           int ni=i;
           int nj=j;
           if(matrix[i][j]==0){               
               if(direction=='R'){
                   j++;
               }else if(direction=='D'){
                   
                   i++;
                   
               }else if(direction=='L'){
                   j--;
               }else{
                   i--;
               } 
           }else{
               matrix[i][j]=0;
               if(direction =='R'){
                  direction= 'D';
               }else if(direction=='D'){
                   direction='L';
               }else if(direction=='U'){
                   direction='R';
               }else{
                   direction='U';
               }
           }
           if(check(i,j,n,m)==true){
               return {ni,nj};
           }   
       }
    }
};


//Second Solution :-
pair<int,int> endPoints(vector<vector<int>> matrix)
{
    stack<pair<int,int>>st;
    int m=matrix.size();
    int n=matrix[0].size();
    int i=0;
    int j=0;
    char k='r';
     
    while( i>=0 && j>=0 && i<m && j<n)
    {
        
        if(matrix[i][j]==0)
        {
            st.push({i,j});
           if(k=='r')
           j++;
           else if(k=='l')
           j--;
           else if(k=='u')
           i--;
           else if(k=='d')
           i++;
        
            
        }
        else
        {   st.push({i,j});
            if(k=='r')
            {
                matrix[i][j]=0;
                k='d';
                i++;
            }
            else if(k=='u')
            {
                matrix[i][j]=0;
                k='r';
                j++;
            }
           else if(k=='d')
            {
                matrix[i][j]=0;
                k='l';
                j--;
            }
            else if(k=='l')
            {
                matrix[i][j]=0;
                k='u';
                i--;
            }                      
        }            
    }
    return st.top();
}

