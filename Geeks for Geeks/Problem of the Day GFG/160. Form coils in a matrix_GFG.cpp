Given a positive integer n that represents dimensions of a 4n x 4n matrix with values from 1 to 4*n*4*n filled from left to right and top to bottom. Your task is to form two coils from matrix and print the coils.
Follow the given examples for better understanding.

Example 1:
Input: n = 1
Output:
10 6 2 3 4 8 12 16
7 11 15 14 13 9 5 1 
Explanation: The matrix is 
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
So, the two coils are as given in the Ouput.

Example 2:
Input: n = 2
Output:
36 28 20 21 22 30 38 46
54 53 52 51 50 42 34 26
18 10 2 3 4 5 6 7 8
16 24 32 40 48 56 64

29 37 45 44 43 35 27 19
11 12 13 14 15 23 31 39
47 55 63 62 61 60 59 58
57 49 41 33 25 17 9 1  
Explanation:



//Solution Approach :-
//Very easy to solve if you have already done travelling matrix in spiral pattern problem. A slight difference is in that while travelling from top to down we do left++ and here we have to do left++ and right-- as well. Similar for other 3 directions as well.
//For the other coil just interchange the directions, 0 becomes 2, 2 becomes 0 and 1 becomes 3 , 3 becomes 1

vector<vector<int>> formCoils(int n) {
    n*=4;
    vector<vector<int>>V(n,vector<int>(n,0));
    vector<vector<int>>ret;
    vector<int>ret1,ret2;
    
    int cnt=1,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            V[i][j]=cnt++;
        }
    }

    int dir=0;
    int top=0,down=n-1,left=0,right=n-1;
    while(top<=down && left<=right){
        if(dir==0){
            for(i=top;i<=down;i++) ret1.push_back(V[i][left]);
            left++; right--;
        }
        else if(dir==1){
            for(i=left;i<=right;i++) ret1.push_back(V[down][i]);
            down--; top++;
        }
        else if(dir==2){
            for(i=down;i>=top;i--) ret1.push_back(V[i][right]);
            left++; right--;
        }
        else{
            for(i=right;i>=left;i--) ret1.push_back(V[top][i]);
            top++; down--;
        }
        dir=(dir+1)%4;
    }

    top=0,down=n-1,left=0,right=n-1,dir=0;
    while(top<=down && left<=right){
        if(dir==2){
            for(i=top;i<=down;i++) ret2.push_back(V[i][left]);
            left++; right--;
        }
        else if(dir==3){
             for(i=left;i<=right; i++) ret2.push_back(V[down][i]);
            top++; down--;
        }
        else if(dir==0){
            for(i=down;i>=top;i--) ret2.push_back(V[i][right]);
            left++; right--;
        }
        else {
            for(i=right;i>=left;i--) ret2.push_back(V[top][i]);
            top++; down--;
        }
        dir=(dir+1)%4;
    }
    
    reverse(ret1.begin(),ret1.end());
    reverse(ret2.begin(),ret2.end());
    
    ret.push_back(ret2);
    ret.push_back(ret1);
    
    return ret;
}


