//  You are playing the Bulls and Cows game with your friend.
// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
// Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls. 
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

// Input 1: secret = "1807", guess = "7810"
// Ouput 1: "1A3B"
// Explanation 1: Bulls are connected with a '|':
// "1807"
//   |
// "7810"

// Input 2: secret = "1123", guess = "0111"
// Ouput 2: "1A1B"
// Explanation 2: Bulls are connected with a '|' 
// "1123"        "1123"
//   |      or     |
// "0111"        "0111"
// Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

//Hint 1
//The idea is to iterate over the numbers in secret and in guess and count all bulls right away. For cows maintain an array that stores count of the number appearances in secret and in guess. Increment cows when either number from secret was already seen in guest or vice versa.

//Solution Approach
//Easy, but interesting problem, because it can be solved in different ways.

// Let us first evaluate number of bulls B: by definition it is number of places with the same digit in secret and guess: 
// so let us just traverse our strings and count it.
// Now, let us evaluate both number of cows and bulls: B_C: 
// we need to count each digit in secret and in guess and choose the smallest of these two numbers. 
// Evaluate sum for each digit.
// Finally, number of cows will be B_C - B, so we just return return the answer!
// Complexity: both time and space complexity is O(1). Imagine, that we have not 4 lengths, but n, then we have O(n) time complexity and O(10) space complexity to keep our counters.



// First Method :-
string Solution::solve(string secret, string guess) {
    int bulls=0, cows=0;
    vector<int>ans(10);
    for(int i=0;i<secret.length();i++){
        int s = secret[i]-'0';
        int g = guess[i]-'0';

        if(s==g){
            bulls++;
        }
        else{
            if(ans[s]<0) cows++;
            if(ans[g]>0) cows++;
            ans[s]++;
            ans[g]--;
        }
    }

    string res = to_string(bulls) + "A" + to_string(cows) + "B";
    return res;
}



//Second Method :-
string Solution::solve(string secret, string guess) {
    int bulls=0, cows=0;
    vector<int>secretFreq(10);
    vector<int>guessFreq(10);
    for(int i=0;i<secret.length();i++){
        int s = secret[i]-'0';
        int g = guess[i]-'0';

        if(s==g){
            bulls++;
        }
        else{
            secretFreq[secret[i]-'0']++;
            guessFreq[guess[i]-'0']++;
        }
    }

    for(int i=0;i<10;i++){
        cows +=min(secretFreq[i],guessFreq[i]);
    }

    string res = to_string(bulls) + "A" + to_string(cows) + "B";
    return res;
}



//Third Method :-
string Solution::solve(string secret, string guess) {
    int len = secret.size();
    
    int secret_freq[10] = {0};
    int guess_freq[10] = {0};
    
    
    //Calculate freq of secret
    for(int idx = 0; idx < len; idx++) {
        int digit = secret[idx] - '0';
        secret_freq[digit]++;
    }
    
    //Calculate freq of guess
    for(int idx = 0; idx < len; idx++) {
        int digit = guess[idx] - '0';
        guess_freq[digit]++;
    }
    
    //Check for bulls (correct pos of elements)
    int bulls = 0;
    for(int idx = 0; idx < len; idx++ ) {
        if(secret[idx] == guess[idx]) {
            bulls++;
            int digit = secret[idx] - '0';
            secret_freq[digit]--;
            guess_freq[digit]--;
        }
    }
    
    int cows = 0;
    for(int idx = 0; idx < 10; idx++) {
        if(secret_freq[idx] > 0 && guess_freq[idx] > 0) {
            cows += min(secret_freq[idx], guess_freq[idx]);
        }
    }
    
    string bulls_str = to_string(bulls);
    string cows_str = to_string(cows);
    
    string res = bulls_str + "A" + cows_str + "B";

    
    return res;
}


