// You have the four functions:

// printFizz that prints the word "fizz" to the console,
// printBuzz that prints the word "buzz" to the console,
// printFizzBuzz that prints the word "fizzbuzz" to the console, and
// printNumber that prints a given integer to the console.
// You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

// Thread A: calls fizz() that should output the word "fizz".
// Thread B: calls buzz() that should output the word "buzz".
// Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
// Thread D: calls number() that should only output the integers.
// Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

// "fizzbuzz" if i is divisible by 3 and 5,
// "fizz" if i is divisible by 3 and not 5,
// "buzz" if i is divisible by 5 and not 3, or
// i if i is not divisible by 3 or 5.
// Implement the FizzBuzz class:

// FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
// void fizz(printFizz) Calls printFizz to output "fizz".
// void buzz(printBuzz) Calls printBuzz to output "buzz".
// void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
// void number(printNumber) Calls printnumber to output the numbers.
 

// Example 1:
// Input: n = 15
// Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]

// Example 2:
// Input: n = 5
// Output: [1,2,"fizz",4,"buzz"]




//Solution Approach :- C++ mutex / condition_variable
class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while(count <= n && (count % 3 != 0 || count % 5 == 0)){
                cv.wait(lock);
            }
            if (count > n) return;
            printFizz();
            ++count;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 == 0)){
                cv.wait(lock);
            }
            if (count > n) return;
            printBuzz();
            ++count;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 != 0)){
                cv.wait(lock);
            }
            if (count > n) return;
            printFizzBuzz();
            ++count;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 == 0 || count % 3 == 0)){
                cv.wait(lock);
            }
            if (count > n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};



//Second Solution :-
class FizzBuzz {
private:
    int n;
    atomic<int> current;
    mutex mx;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        current = 1;
    }
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) 
    {
        do_work([&](int i){printFizz();}, [&]{return (current % 3 == 0 && current % 5 != 0);});
    }
    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) 
    {
        do_work([&](int i){printBuzz();}, [&]{return (current % 5 == 0 && current % 3 != 0);});
    }
    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) 
    {
        do_work([&](int i){printFizzBuzz();}, [&]{return (current % 5 == 0 && current % 3 == 0);});
    }
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) 
    {
        do_work(printNumber, [&]{return (current % 5 != 0 && current % 3 != 0);});
    }
protected:
    void do_work(function<void(int)> printFunc, function<bool()> evalFunc)
    { 
        while(current <= n)
        {
            unique_lock<mutex> ul(mx);
            cv.wait(ul, [&]{return (evalFunc() || current > n);});
            if(current > n) break;
            printFunc(current);
            ++current;
            cv.notify_all();
        }
    }
};


//Third Solution :-
//We can take advantage of condition variables predicate feature to our advantage so that only one thread is waken up to do its job.

class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        i = 1;
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while( true ){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return i>n || (i%3 == 0 && i%5 != 0);});
            if( i > n ) break;
            printFizz(); i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while( true ){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return i>n || (i%3 != 0 && i%5 == 0);});
            if( i > n ) break;
            printBuzz(); i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while( true ){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return i>n || (i%3 == 0 && i%5 == 0);});
            if( i > n ) break;
            printFizzBuzz(); i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while( true ){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return i>n || (i%3 != 0 && i%5 != 0);});
            if( i > n ) break;
            printNumber(i++);
            cv.notify_all();
        }
    }
};