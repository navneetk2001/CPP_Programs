// A generic microwave supports cooking times for:

// at least 1 second.
// at most 99 minutes and 99 seconds.
// To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,
// You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
// You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
// You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
// You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
// You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.
// There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.
// Return the minimum cost to set targetSeconds seconds of cooking time.
// Remember that one minute consists of 60 seconds.



//First Solution :- 
int getAns(int s, int x, int y, int min, int sec) {
    int target=(min*100)+sec;
    vector<int>v;
    while(target){
    	v.push_back(target%10);
    	target/=10;
    }
    reverse(v.begin(), v.end());
    int ans=0;
    for(int i=0;i<v.size();i++){
    	if(v[i]==s){
    		ans+=y;
    	}
    	else{
    		ans+=(x+y);
    		s=v[i];
    	}
    }
    return ans;
}


class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ans=INT_MAX;
        if(targetSeconds>99){
        	int minutes=targetSeconds/60, seconds=targetSeconds%60;
        	if(minutes<100){
        		ans=min(ans,getAns(startAt,moveCost,pushCost,minutes,seconds));
        	}
        	minutes--, seconds+=60;
        	if(seconds<=99){
        		ans=min(ans,getAns(startAt,moveCost,pushCost,minutes,seconds));
        	}
        }
        else{
        	ans=min(ans,getAns(startAt,moveCost,pushCost,0,targetSeconds));
            if(targetSeconds>=60){
        		ans=min(ans,getAns(startAt,moveCost,pushCost,1,targetSeconds%60));
            }
        }
        return ans;
    }
};




//Second Solution :- 
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ans=INT_MAX;
        for(int m=0; m*60<=targetSeconds;m++){
        	int s=targetSeconds-m*60;
        	if(n>99 || s>99){
        		continue;
        	}

        	string ss=to_string(s);
        	string sm=to_string(m);
        	if(m==0){
        		sm="";
        	}
        	else{
        		while(ss.size()<2) ss="0"+ss;
        	}

        	string a = sm+ss;
        	int cost=0;
            char prevDig = startAt+'0';
            for(char &c:a){
            	if(c!=prevDig) cost+=moveCost;
            	cost+=pushCost;
            	prevDig=c;
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};