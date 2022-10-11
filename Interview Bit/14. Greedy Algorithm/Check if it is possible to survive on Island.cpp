https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1




//Solution Approach :-
// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int totalRequiredFood = M * S;           //food needed to survive on the island
        int noOfDaysShopIsAvailable = S-S/7;     //mo of days shop remains open b/c it is closed on sunday
        int totalAvailableFood = N * noOfDaysShopIsAvailable;    //total food you can buy
        
        if(totalRequiredFood > totalAvailableFood){
            return -1;
        }
        return ceil(totalRequiredFood/(float)N);
    }
};




//Second Solution :- 
int minimumDays(int s, int n, int m){
    if(m > n) return -1;
    if(s>= 7 && 6*n - 7*m < 0) return -1;
    return ceil(s*m*1.0/n);
}




//Third Solution :- 
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday=S/7;
        int canBuy=S-sunday;
        
        int overall=S*M;
        int cnt=overall/N;
        
        if(overall%N != 0){
            cnt=(overall/N)+1;
        }
        if(cnt <= canBuy){
            return cnt;
        }
        else{
            return -1;
        }
    }
};
