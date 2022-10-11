// You have a function printNumber that can be called with an integer parameter and prints it to the console.
// For example, calling printNumber(7) prints 7 to the console.
// You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

// Thread A: calls zero() that should only output 0's.
// Thread B: calls even() that should only output even numbers.
// Thread C: calls odd() that should only output odd numbers.
// Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

// Implement the ZeroEvenOdd class:
// ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
// void zero(printNumber) Calls printNumber to output one zero.
// void even(printNumber) Calls printNumber to output one even number.
// void odd(printNumber) Calls printNumber to output one odd number.
 

// Example 1:
// Input: n = 2
// Output: "0102"
// Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.

// Example 2:
// Input: n = 5
// Output: "0102030405"




//Solution Approach :-
class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int count;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        count = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mtx);
        for(int i = 1; i <= n; i++)
        {
            while(count != 0){
                cv.wait(lck);
            }
            //cout<<"in 0"<<endl;
            printNumber(0);
            //curr = i;
            if(i%2 == 1){
                //Odd num
                count = 1;
                lck.unlock();
                cv.notify_all();
            }else{
                count = 2;
                lck.unlock();
                cv.notify_all();
            }
            lck.lock();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mtx);
        for(int i = 2; i <= n; i+= 2)
        {
            while(count != 2){
                cv.wait(lck);
            }
            printNumber(i);
            count = 0;
            lck.unlock();
            cv.notify_all();
            lck.lock();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lck(mtx);
        for(int i = 1; i <= n; i+= 2)
        {
            while(count != 1){
                cv.wait(lck);
            }
            printNumber(i);
            count = 0;
            lck.unlock();
            cv.notify_all();
            lck.lock();
        }
    }
};




//Second Solution :- Using 3 Semaphore
class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem_z, 0 ,1);
        sem_init(&sem_o, 0 ,0);
        sem_init(&sem_e, 0 ,0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&sem_z);
            printNumber(0);
            if (i%2 == 0)
                sem_post(&sem_e);
            else
                sem_post(&sem_o);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+= 2) {
            sem_wait(&sem_e);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            sem_wait(&sem_o);
            printNumber(i);
            sem_post(&sem_z);
        }
    }
};



//Third Solution :-  condition_variable solution
class ZeroEvenOdd {
private:
    int n;
    mutex mx;
    condition_variable cv;
    atomic<int> num_to_print;
    atomic<int> current;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        num_to_print = 0;
        current = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        do_work(printNumber, [&]{return num_to_print == 0;});
    }

    void even(function<void(int)> printNumber) {
        do_work(printNumber, [&]{return num_to_print != 0 && num_to_print % 2 == 0;});
    }

    void odd(function<void(int)> printNumber) {
         do_work(printNumber, [&]{return num_to_print % 2 != 0;});
    }
    
protected:
   void do_work(function<void(int)> print, function<bool()> eval)
    {
        while(current <= n)
        {
            unique_lock<mutex> ul(mx);
            cv.wait(ul, [&]{return eval() || current > n;});
            if(current > n) break;
            print(num_to_print);
            num_to_print = num_to_print == 0 || num_to_print == n ? ++current : 0;
            cv.notify_all();
        }
    }
};



//Fourth Solution :- Using 3 mutex
class ZeroEvenOdd {
private:
    int n;

    std::mutex mzero, modd, meven;
    int i;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        i = 1;
        meven.lock();
        modd.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i <= n){
            mzero.lock();
            if(i > n){
                modd.unlock();
                meven.unlock();
                break;
            }
            printNumber(0);
            if(i % 2) modd.unlock();
            else meven.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i <= n){
            meven.lock();
            if(i > n) break;
            printNumber(i++);
            mzero.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i <= n){
            modd.lock();
            if(i > n) break;
            printNumber(i++);
            mzero.unlock();
        }
    }
};
