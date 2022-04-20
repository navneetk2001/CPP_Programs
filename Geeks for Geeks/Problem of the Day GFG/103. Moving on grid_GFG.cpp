// Given a grid with dimensions r x c, the two players (say JON and ARYA ) can move the coin over the grid satisfying the following rules:
// There is a coin on (1,1) cell initially.
// JON will move first.
// Both will play on alternate moves. In each move they can place coin on following positions if current position of coin is x,y
// (x+1,y), (x+2,y), (x+3,y), (x,y+1), (x,y+2), (x,y+3), (x,y+4), (x,y+5), (x,y+6)
// They can't go outside the grid. Player who cannot make any move will lose this game. Both play optimally.


// Example 1:
// Input: r = 1, c = 2
// Output: JON 
// Explanation: ARYA lost the game because he won't able to move after JON's move.  

// Example 2:
// Input: r = 2, c = 2
// Output: ARYA
// Explanation: After first move by JON(1,2 or 2,1) and second move by ARYA(2,2) JON won't able to move so ARYA wins.




//Approach :-
// Important Points to Note in order to solve this problem in O(1) one liner:
// r and c are given wrong in the question, it would be better to call r the x coordinate and c the y coordinate. Otherwise consider it matrix, and swap r and c. I have considered it matrix and used r and c interchangeably.
// If Arya wins at (i,j) then Arya wins at (i,j+7) as well. Similarly, if he wins at (i,j) then he also wins at (i+4,j).
// What I did:
// 	1. decreased r and c so I start with matrix starting at (0,0) instead of (1,1).
// 	2. found the position on the 0th row where last ARYA winning position will be found.
// 	3. found how far it is from (0,0) if it is a multiple of 7 then answer is ARYA else JON.


//Approach 2 :-
// it starts from (1, 1), to play optimum:
// 	1. For row, whoever left 4 steps to the end after his/her turn will win
// 	2. For column, whoever left 7 steps after his/her turn will win
// 	3. To win the game, you have to make sure the next player can't win either row or column 
// 	4. Since we started with JON, if (r - 1) % 7 == (c - 1) % 4 means if Jon won row, ARYA will win col, vice versa. we minus 1 for both row and col is because that the game starts from (1, 1)
// 	5. As it takes input in a different way 'r' stores value of column and vice versa. So either we can swap them at first or we can consider ‘c’ as value of row and ‘r’ as the value of column 	


//Solution Approach :-
class Solution {
  public:
    string movOnGrid(int r, int c) {
        return (--r - (--c % 4))%7 == 0 ? "ARYA":"JON" ;
    }
};


//Second Solution :-
class Solution {
 public:
   string movOnGrid(int r, int c) {
       // code here
      c = c^r;
      r = c^r;
      c = c^r;
      r=(r-1)&3;
      c=(c-1)%7;
      return(r==c?"ARYA":"JON");
     }
};


//Third Solution :-
string movOnGrid(int r, int c) {
    r = (r - 1) % 7;
    c = (c - 1) % 4 ;
    if(r!=c){ 
    	return "JON";
    }
    return "ARYA";
}


//Fourth Solution :-
string movOnGrid(int r, int c) {
    swap(r,c);
    r--, c--;

    if((r%4)==(c%7)){ 
    	return "ARYA";
    }
    return "JON";
}


