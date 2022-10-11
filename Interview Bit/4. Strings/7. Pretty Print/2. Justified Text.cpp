// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified. You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
// Pad extra spaces ' ' when necessary so that each line has exactly L characters. Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of text, it should be left justified and no extra space is inserted between words.
// Your program should return a list of strings, where each string represents a single line.

// Example:
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length. 


//Hint :-
// This problem is more of simulation. Take care of some of corner cases like space distribution in different lines.
// Try to write an elegant solution.

//Solution Approach :-
// Corner Cases:
// 1. A line other than the last line might contain only one word. What should you do in this case?
//    In this case, that line should be left-justified.
// 2) Have you noticed that the last line is an exception in terms of spaces?
// This is more of a simulation problem. The more elegant your code, the less chances of it being bug prone, and more marks in the interview.
// Give a lot of thought to the structure of the code before you start coding.


//First Solution :-
// Notes:
// For a fully-justified line, the number of spots where we could add extra spaces is equal to
// (number of words on the line - 1) since we add spaces only inbetween words.
// Then we can compute the number of spaces we should add into each of these spots as
// (number of extra spaces / (number of words on the line - 1)).
// However, this leads to left over extra spaces the number of which is computed by
// (number of extra spaces % (number of words on the line - 1))

// In the loop where we construct a fully-justified line, we compute the number of "left over" extra spaces beforehand. These left over spaces are appended to the line in addition to the words, first space, and extra spaces as long as there is at least one remaining. Everytime a left over space is used, the number is decremented.

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> sol;     // Holds the solution
        int curWord = 0;        // An index into words array
        
        // Continue building lines if there are more words
        while (curWord < words.size()) {
            // After the next while loop, firstWord holds the index of the first word on our line and curWord holds the index of the last word on our line
            int firstWord = curWord;
            int numCharsOnLine = words[curWord].size();
            
            // Add the next word to the line while adding the word does not push us past the maxWidth
            // Note: We must account for the minimum of one space between each word
            //       This is why we have words[curWord+1].size() + 1
            while (curWord + 1 < words.size() && numCharsOnLine + words[curWord+1].size() + 1 <= maxWidth) {
                numCharsOnLine += words[curWord+1].size() + 1;
                curWord += 1;
            }
            
            // Compute the number of words on the next line and the number of extra spaces we need to fill in the line
            int numWordsOnLine = curWord - firstWord + 1;
            int numExtraSpaces = maxWidth - numCharsOnLine;
            
            string line = "";   // Holds the next line
            
            // Determine if the next line will be fully-justified or left-justified
            if (curWord < words.size() - 1 && numWordsOnLine > 1) {
                
                int paddingPerWord = numExtraSpaces / (numWordsOnLine - 1);    // Line will be fully justified
                int leftOverSpaces = numExtraSpaces % (numWordsOnLine - 1);
                
                string padding = string(paddingPerWord, ' ');       // Construct line and evenly distribute extra spaces
                
                // Add each word except the last one
                while (firstWord < curWord) {
                    line.append(words[firstWord]);
                    line.push_back(' ');
                    line.append(padding);
                    if (leftOverSpaces > 0) {
                        line.push_back(' ');
                        leftOverSpaces -= 1;
                    }
                    
                    firstWord += 1;
                }
                
                // Add the last word on the line
                line.append(words[firstWord]);
            }
            else {
                // Line will be left justified
                while (firstWord < curWord) {
                    line.append(words[firstWord]);
                    line.push_back(' ');
                    
                    firstWord += 1;
                }
                
                // Add the word on the line
                line.append(words[firstWord]);
                
                // Add padding at the end of the line
                string padding = string(numExtraSpaces, ' ');
                line.append(padding);
            }
            
            // Done constructing our line
            // Add the constructed line to the solution
            sol.push_back(line);
            
            // Move curWord to the first word on the next line and repeat
            curWord += 1;
        }
        
        return sol;
    }
};


//Second Solution :-
class Solution{
public:
vector<string> fullJustify(vector& words, int maxWidth) {
    vector<string>vec;
    int i = 0;
    
    while(i<words.size()){
        int j = i+1;
        int sum = words[i].length();
        int curr = 0;
        while(j<words.size() and sum+words[j].size()+1+curr<=maxWidth)
        {
            sum += words[j].length();
            j++;
            curr++;
        }
        string now = "";
        int extra = (curr==0)?0:(maxWidth - sum)/curr;
        int more = (curr==0)?0:(maxWidth - sum)%curr;
        if(j==words.size())
        {
            for(int k=i;k<j;k++)
            {
                now += words[k];
                now += " ";
            }
            now.pop_back();
        }
        else
        {
             for(int k=i;k<j;k++)
            {
                now += words[k];
                if(k==j-1)
                    break;
                for(int g=0;g<extra;g++)
                {
                    now += " ";
                }
                if(more)
                {
                    now += " ";
                    more--;
                }
            }
        }
       
        cout<<now.length()<<" ";
        while(now.length()<maxWidth)
            now += " ";
        vec.push_back(now);
        i=j;
    }
    
    return vec;
}
};


//Third Solution :-
vector<string> Solution::fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
}


//Fourth Solution :-
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    short int k = 0, ls = 0;
    for (short int i = 0; i<A.size(); i+=k)
    {
        k = ls = 0;
        while (i+k<A.size() && ls + k + A[i+k].size() <= B)
        {
            ls += A[i+k].size();
            ++k;
        }
        string tmp = A[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= A.size()) tmp += " ";
            else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');
        result.emplace_back(tmp);
    }
    return result;
}

