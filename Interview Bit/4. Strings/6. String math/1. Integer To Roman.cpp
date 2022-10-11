// Another question which belongs to the category of questions which are intentionally stated vaguely. 
// Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.
// Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version
// Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”
// For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.


//Hint :-
//Think of some essential numbers whose roman numeral representations can be used to construct other numbers. Its really similar to constructing numbers in different bases after that.

//Solution Approach :-
// It is very much like learning our own number system.
// All you need to know is how to write 0-9, 10, 20, 30, 40, 90, 100, 200, 300,… 900, 1000, 2000, 3000.
// You can derive rest of the numbers using the above.


// First Method :-
string Solution::intToRoman(int A) {
    vector<int>intCode{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string>roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string s;
    for(int i=0;i<intCode.size();i++){
        while(A>=intCode[i]){
            s+=roman[i];
            A-=intCode[i];
        }
    }
    return s;
}

//Second Method :-
string Solution::intToRoman(int A) {
    string str="";

    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;

    while(A>0)
    {
        int quo = A/num[i];
        A = A%num[i];
        while(quo)
        {
            str += sym[i];
            quo--;
        }
        i--;
    }
    return str;
}

//Third Method :-
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};    // 1000, 2000, 3000
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};      // 100, 200, 300, .. 900        
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};      // 10, 20, ... 90
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};      // 1, 2, ... 9
        
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

//Fourth Method :-
string intToRoman(int num) {
    string ans="";
    while(num>=1000){
        ans+="M";
        num-=1000;
    }
    
    if(num>=900){
        ans+="CM";
        num-=900;
    }
    else if(num>=500){
        ans+="D";
        num-=500;
    }
    else if(num>=400){
        ans+="CD";
        num-=400;
    }
    while(num>=100){
        ans+="C";
        num-=100;
    }
    
    if(num>=90){
        ans+="XC";
        num-=90;
    }
    else if(num>=50){
        ans+="L";
        num-=50;
    }
    else if(num>=40){
        ans+="XL";
        num-=40;
    }
    while(num>=10){
        ans+="X";
        num-=10;
    }
    
    if(num==9){
        ans+="IX";
        num-=9;
    }
    else if(num>=5){
        ans+="V";
        num-=5;
    }
    else if(num==4){
        ans+="IV";
        num-=400;
    }
    while(num>=1){
        ans+="I";
        num-=1;
    }
    return ans;
}