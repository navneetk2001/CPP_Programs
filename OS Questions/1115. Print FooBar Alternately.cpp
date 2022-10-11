// Suppose you are given the following code:
// class FooBar {
//   public void foo() {
//     for (int i = 0; i < n; i++) {
//       print("foo");
//     }
//   }

//   public void bar() {
//     for (int i = 0; i < n; i++) {
//       print("bar");
//     }
//   }
// }
// The same instance of FooBar will be passed to two different threads:
// thread A will call foo(), while
// thread B will call bar().
// Modify the given program to output "foobar" n times.

 
// Example 1:
// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.

// Example 2:
// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.




//Solution Approach :- 
// This is basically a semaphore. We use the flag fooTurn in the predicate of wait() to determine if the lock should be freed.
// Because there are only two states (foo and bar), we can get away with using a boolean for the flag and notify_one(). If there were more states, we could scale this using an int flag and notify_all().
// If you're wondering why foo runs for the first time at all despite the cv.wait(), it's because the line is actually a shorthand for while (!fooTurn) { cv.wait(lock); }. Since fooTurn is initialized as true, the cv.wait() gets ignored.

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn = true;  // is it foo's turn to run?

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return fooTurn; });
      
          printFoo();
      
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return !fooTurn; });
      
          printBar();
      
            fooTurn = true;
            cv.notify_one();
        }
    }
};




//Second Solution :- Solution using 2 Semaphores
#include <semaphore.h>

class FooBar {
private:
    int n;
    sem_t foo_sem;
    sem_t bar_sem;
    
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foo_sem, 0, 1);
        sem_init(&bar_sem, 0, 0);
    }
    
    ~FooBar() {
        sem_destroy(&foo_sem);
        sem_destroy(&bar_sem);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
                // lock foo semaphore
            sem_wait(&foo_sem); 
              // printFoo() outputs "foo". Do not change or remove this line.
          printFoo();
                // unlock bar semaphore
            sem_post(&bar_sem); 
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
                // lock bar semaphore
            sem_wait(&bar_sem); 
              // printBar() outputs "bar". Do not change or remove this line.
          printBar();
                // unlock foo semaphore
            sem_post(&foo_sem); 
        }
    }
};



//Third Solution :- Solution using 2 Mutex
class FooBar {
private:
    int n;
    mutex m1, m2;

public:
    FooBar(int n) {
        this->n = n;
        m2.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            m1.lock();
          // printFoo() outputs "foo". Do not change or remove this line.
          printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            m2.lock();
          // printBar() outputs "bar". Do not change or remove this line.
          printBar();
            m1.unlock();
        }
    }
};