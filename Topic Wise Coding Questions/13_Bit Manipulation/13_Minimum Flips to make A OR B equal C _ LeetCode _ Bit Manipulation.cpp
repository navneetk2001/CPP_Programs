class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
	    for(int i=0;i<32;i++){
		bool x=false, y=false, z=false;

		if(a&(1<<i))    // if ith bit of a is set or not 
			x=true;

		if(b&(1<<i))    // if ith bit of b is set or not
			y=true;

		if(c&(1<<i))    // if ith bit of c is set or not
			z=true;	

		if(z==false){
			if(x==true && y==true){
				res+=2;
			}
			else if(x==true || y==true){
				res+=1;
			}
		}
		else{
			if(x==false && y==false){
				res+=1;
			}
		}	
	}
	return res;
    }
};