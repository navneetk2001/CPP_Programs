https://leetcode.com/problems/design-hashset/




//Description :-
// Two stacks (first solution) are natural fit for this problem. It's easier to implement during the contest. Using a single list (second solution) is faster, but it's a bit trickier to maintain the current position.
// One thing that is unclear is what should we do if we visit exactly the same url. In the real browser, that would not create a history item. But for this problem we are supposed to do. They should better clarify that int the description!



//Solution :- Using 2 Stacks :- 
// It’s not difficult to realize that we need a stack so that back can be implemented. However, what to do for forward. Because you want the ability to visit all pages in the backward as well as the forward direction, we need to store the URLs whenever we go back. If you see the order in which we want to visit, you will quickly realize that we need two stacks. One to store history and another to store the next URLs in case we go back.
// Two special cases:
// You must always have at least one element in the history stack which is the page that you are currently at.
// But for the forward stack, this condition is not necessary.

// Two Stacks :- 
// The top of the first stack is the first element in the back history. And the top of the other stack - first element of the forward history. Move urls from one stack to another as you go back and forward.

class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
	
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();           // Reset the forward stack.
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();           // Reset the forward stack.
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1) { // Always keep at least one element in the stack. 
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};




//Second Solution :- Using Lists
class BrowserHistory {
public:
    list<string> history;
    list<string> :: iterator it;

    BrowserHistory(string homepage) { 
        history.push_back(homepage); 
        it = history.begin();                //pointing it to first position
    }

    void visit(string url) {
       auto del = it;
       del++;
       history.erase(del, history.end());         //erase all the history after the url
       history.push_back(url);                    //add visited url to the history
       it++;                                      //update iterator
    }

    string back(int steps) {
        while(it!=history.begin() && steps--){
            it--;
        }
        return *it;
    }

    string forward(int steps) {
        while(it!=--history.end() && steps--){
            it++;
        }
        return *it;
    }
};









//Solution :- Using Vector
class BrowserHistory {
public:
    vector<string> history;
    int pos = 0;
    BrowserHistory(string homepage) { 
        history.push_back(homepage); 
    }

    void visit(string url) {
        ++pos;
        history.resize(pos);
        history.push_back(url);
    }

    string back(int steps) {
        pos = max(0, pos - steps);
        return history[pos];
    }

    string forward(int steps) {
        pos = min((int)history.size() - 1, pos + steps);
        return history[pos];
    }
};



//Third Solution :- C++. The = operator in c++ returning a reference works perfectly here!.
class BrowserHistory {
public:
    string stack[5005];
    int p, t;	// current pointer, stack's top
    
    BrowserHistory(string homepage) {
        stack[p = t = 0] = homepage;
    }
    
    void visit(string url) {
        stack[t = ++p] = url;
    }
    
    string back(int steps) {
        return stack[p = max(0, p-steps)];
    }
    
    string forward(int steps) {
        return stack[p = min(t, p+steps)];
    }
};




//Fourth Solution :-
// First of all if you are attempting this problem so let me tell you these kind of problems teach you a lot and have vast application in the industry.Try to have the essence of this question.Give your time to it if you haven't and then come back again.
// If you are still reading this i assume you have given your shot to this question.
// Coming to the solution,it asks you to create browser history.First of all create an array browser
// and an integer posto keep track of position.
// BrowserHistory-Just push the homepage to the browser array.
// Visit-There are two parts of this function.If you are at any position between (0 - browser.size()-2) then increase the position and resize the array holding only elements upto the current position else if you were at the end then just add that element to the array.
// Back-You need to move back the given number of steps from your current position and return the corresponding element.The catch was you cannot move behind 0.Hence if your pos changes to less than 0.You make it 0 and return browser[0].
// Forward-Just like back ,here you cannot exceed the last element and return the last element if your pos exceeds it.

class BrowserHistory {
public:
    vector<string>browser;
    int pos=0;
    BrowserHistory(string homepage) {
        browser.push_back(homepage);
    }
    
    void visit(string url) {
        pos++;
        if(pos<=browser.size()-1){
            browser[pos]=url;
            browser.resize(pos+1);
        }
        else browser.push_back(url);       
    }
    string back(int steps) {
        pos-=steps;
        if(pos<0)pos=0;
        return browser[pos];
    }
    
    string forward(int steps) {
       pos+=steps;
        if(pos>browser.size()-1)pos=browser.size()-1;
        return browser[pos];
    }
};