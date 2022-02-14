/*
@csalgo

Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

@csalgoe
cf

*/



#include<iostream>
#include <string>
using namespace std;


int keypad(int num, string output[], string dialer[]){
    
    if(num==0){
        output[0]="";
        return 1;
    }
    
    int lastDigit=num%10;
    int smallInput= num/10;
    string smallOutput[10000];
    
    int smallOutputSize = keypad(smallInput, smallOutput, dialer);

    string op = dialer[lastDigit];
    
    int k=0;
    for(int i=0;i<op.size();i++){
        for(int j=0;j<smallOutputSize;j++){

            output[k++]=smallOutput[j]+op[i];
        }
    }
    return k;
}


int keypad(int num, string output[]) {
	string dialer[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    return keypad(num, output, dialer);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}




// #include<iostream>
// #include <string>
// using namespace std;


// void keypad(int num, string output, string dialer[]){
    
//     if(num==0){
//         cout<<output<<endl;;
//         return ;
//     }
    
//     int lastDigit=num%10;
//     int smallInput= num/10;
//     string smallOutput=" ";
    
//     keypad(smallInput, smallOutput, dialer);
//     keypad(lastDigit,smallOutput,dialer);
// }


// int keypad(int num, string output[]) {
// 	string dialer[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
//     return keypad(num, output, dialer);
// }

// int main(){
//     int num;
//     cin >> num;

//     string output=" ";
//     int count=keypad(num, output);
   
//     return 0;
// }