/* Dict : [TECH, TECHIE, ANY]

   Search : TECH :- TRUE
            TEM :- FALSE
            ANYTIME :- FALSE
            ANY :- TRUE

    GOAL :-Return true if query string is found else return false
*/

// Brute Force Approach :-
-> Search the given string in entire corpus by comparing all words
//Time Complexity :- O(Q*len(sq)*corpus_size)

    
// Second Approach :- 
-> Convert String to INT (MApping) :-

Char :-             a         b         c   
Char_weight :-      2         1         0      alphabet size :-10
Decimal No. Sys :-  3         2         4      s[i]-'a'+1
                    10^2*3   10^1*2     10^0+4
                    300        20         4

////Time Complexity :- O((No of Words * len(word)) + (No of queries * len(word) * size(collision_list)))


//Third Approach :- Using Tries
//Time Complexity :- O((No of Words * size(dict)) + (No of queries * size of each query))