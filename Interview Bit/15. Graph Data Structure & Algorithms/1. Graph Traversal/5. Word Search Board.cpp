https://www.interviewbit.com/problems/word-search-board/




//Solution Approach :- DFS
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool search_dfs(int x, int y, int index, vector<string> &matrix, string &target, int &row, int &column){
    if (index == target.size() - 1){     // reached the destination
        return true;
    }

    index++;
    for (int i = 0; i < 4; i++){          //explore all 4 direction
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newY >= 0 && newX < row && newY < column && matrix[newX][newY] == target[index]){         // inside boundary and matched character
            if (search_dfs(newX, newY, index, matrix, target, row, column)){
                return true;
            }
        }
    }
    return false;       // no match
}

int exist(vector<string> &matrix, string target){
    if (target == ""){       // if target is empty
        return 1;
    }
    int row = matrix.size();
    if (row == 0){
        return 0;
    }
    int column = matrix[0].size();

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (matrix[i][j] == target[0]){      // if first index matched start searching
                if (search_dfs(i, j, 0, matrix, target, row, column)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

/*
  T(n)= 4*T(n-1)+1 = O(4^n)
  Time Complexity: O(4^(row*column))
  space Complexity: O(row* column)
*/



//Second Solution :- 
pair<int,int> direc[4]={{1,0},{-1,0},{0,1},{0,-1}};

bool dfs(int i,int j,vector<string>& A,int index,string B){
    if(index==B.length()) return true;

    for(auto it:direc){
        int x=it.first+i; int y=it.second+j;

        if(x>=0 && x<A.size() && y>=0 && y<A[0].size() && A[x][y]==B[index]){
            if(dfs(x,y,A,index+1,B)) return true;
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].length();j++){
            if(A[i][j]==B[0]){
                if(dfs(i,j,A,1,B)) return true;
            }
        }
    }
    return false;
}
