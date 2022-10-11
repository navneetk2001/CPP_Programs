// Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
// B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.
// Input 1:
//  A = "abadbc"
// Output 1:
//  "aabbdd"
// Explanation 1:
//     "a"      -   first non repeating character 'a'
//     "ab"     -   first non repeating character 'a'
//     "aba"    -   first non repeating character 'b'
//     "abad"   -   first non repeating character 'b'
//     "abadb"  -   first non repeating character 'd'
//     "abadbc" -   first non repeating character 'd'

//Hint :-
// Think of using queue data structure to maintain the first non-repeating character.

// We can do this using queue data structure and an hash array of size 26.
// -> Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
// -> Create a queue of char datatype.
// -> Store each character in queue and increase its frequency in the hash array.
// -> For every character of stream, we check front of the queue.
// -> If the frequency of character at the front of queue is one, then that will be the first non repeating character.
// -> Else if frequency is more than 1, then we pop that element.
// -> If queue became empty that means there are no non repeating character so we will append #.


//First Solution :-
string Solution::solve(string A) {
    queue<char> q;
    vector<int> freq(26,0);   //will store the frequency of each char.

    string ans="";    
    for(char ch:A){
        q.push(ch);     //push char into the queue
        freq[ch-'a']+=1;  //increase the character frequency by 1

        while(!q.empty() and freq[q.front()-'a']>1){
            q.pop();     //pop characters from queue until the frequency of first element in the queue becomes 1
        }
        if(!q.empty()){   
            ans+=q.front(); //if queue is not empty then add it to answer
        }
        else{
            ans+='#';     //if queue is empty means no such element found whose frequency is 1, then append #
        }
    }
    return ans;
}


//Second Solution :- Using Maps
string Solution::solve(string A) {
    map<char,int> m;
    int n=A.size();

    for(int i=0;i<n;i++)
        m.insert( pair<char,int>(A[i],0) );

    int j=0;

    string ans="";
    ans+=A[0];

    m[A[0]]++;

    for(int i=1;i<n;i++)
    {
        m[A[i]]++;
        
        if(A[j] != A[i])
            ans+=A[j];
        else
        {
            while(m[A[j]] != 1 && j<i)
                j++;
            
            if(j == i && m[A[j]] > 1)
            {
                ans+='#';
                j++;
            }
            else
                ans+=A[j];
        }
    }
    return ans;
}

//Third Solution :-
string Solution::solve(string A) {
    int n=A.size();
    string b;//finally this has to be returned
    queue<char> q;
    vector<int> v(26,0);
    for(int i=0;i<n;i++)
    {
        if(v[A[i]-'a']==0)
        {
            q.push(A[i]);//here q is maintained
            b.push_back(q.front());
            v[A[i]-'a']++;
            
        }
        else if(v[A[i]-'a']>0)
        {
            v[A[i]-'a']++;
            while(v[q.front()-'a']>1&&q.size()>0)
            {
                q.pop();
            }
            if(q.size()==0)
                b.push_back('#');
            else
                b.push_back(q.front());
            
        }
        
    }
    return b;
}

