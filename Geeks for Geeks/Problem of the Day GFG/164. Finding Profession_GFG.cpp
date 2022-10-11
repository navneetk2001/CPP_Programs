// Consider a special family of Engineers and Doctors with following rules :
// Everybody has two children.
// First child of an Engineer is an Engineer and second child is a Doctor.
// First child of an Doctor is Doctor and second child is an Engineer.
// All generations of Doctors and Engineers start with Engineer.
// We can represent the situation using below diagram:
//                 E
//            /        \
//           E          D
//         /   \       /  \
//        E     D     D    E
//       / \   / \   / \   / \
//      E   D D   E  D  E  E  D
// Given level and position(pos) of a person in above ancestor tree, find profession of the person.

// Example 1:
// Input: level = 4, pos = 2
// Output: Doctor
// Explaination: It is shown in the tree given in question.

// Example 2:
// Input: level = 3, pos = 4
// Output: Engineer
// Explaination: Already given in the tree in question.




//Solution :-  
//if position of child is pos, and level is lvl, then position of its parents will be (pos+1)/2, and its level will be lvl - 1;

char profession(int level, int pos){
    if(pos == 1){  //base case ; if pos is '1', then it will always be engineer
        return 'e';
    }

    char par = profession(level-1, (pos+1)/2);
    if(par == 'e'){    //if parent is engineer
        if(pos%2==1){   // if parent :- engineer, then first child will be engineer otherwise doctor
            return 'e';
        }
        else{
            return 'd';
        }
    }
    else{             //if parent is a doctor
        if(pos%2==1){   // if parent :- doctor, then first child will be doctor otherwise engineer
            return 'd';
        }
        else{
            return 'e';
        }
    }
}



//Solution Approach :- 
// If you are your parent's second child (i.e your index is even) then you will have the opposite profession as your parent). And similarly, odd index means your profession is same as your parent. 
// pos's parent is (pos+1)/2, We use a bool flip to keep check on how many opposite professions we encounter while going till engineer ancestor. If flip is true, then our answer is DOCTOR, else it is ENGINEER.

char profession(int level, int pos){
    bool flip = false ;
    while(pos != 1){
        if(pos%2 == 0){
            flip = !flip ;
        }
        pos = (pos+1)/2 ;
    }
    return (flip ? 'd' : 'e') ;
}
//Pls note: we can stop our search to top if we reach pos = 1 since it is always its parents first child and wont affect flip ( pos = 1 always is an engineer and its parent is also engineer )


//Solution 2 - Without recursion
char profession(int level, int pos){
    int x = __builtin_popcount(pos-1);
    if(x&1) return 'd';
    return 'e';
}


//Solution 3 :- With Recursion
char profession(int level, int pos){
    if(pos == 1) return 'e';
    char par = profession(level - 1, (pos+1)/2);
    if(pos&1){
        return par;
    }
    if(par == 'e') return 'd';
    return 'e';
}






