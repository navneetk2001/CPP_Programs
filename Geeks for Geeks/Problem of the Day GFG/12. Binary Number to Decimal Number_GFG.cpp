Given a Binary Number B, find its decimal equivalent.
Example 1:
Input: B = 10001000
Output: 136

Example 2:
Input: B = 101100
Output: 44


//First Method :-
class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    int n=str.size();
		    int sum=0;
		    
		    for(int i=n-1,j=0;i>=0;i--,j++){
		        if(str[i]=='1'){
		            sum+=pow(2,j);
		        }
		    }
		    return sum;
		}
};


//Second Method :-
class Solution
{
	public:
		int binary_to_decimal(string str)
		{
		    string num = str;
            int dec_value = 0;
         
            // Initializing base value to 1, i.e 2^0
            int base = 1;
            int len = num.length();
            for (int i = len - 1; i >= 0; i--) {
                if (num[i] == '1')
                    dec_value += base;
                base = base * 2;
            }
         
            return dec_value;
		}
};