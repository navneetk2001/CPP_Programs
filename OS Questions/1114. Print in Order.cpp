// Suppose we have a class:
// public class Foo {
//   public void first() { print("first"); }
//   public void second() { print("second"); }
//   public void third() { print("third"); }
// }
// The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
// Note: We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

// Example 1:
// Input: nums = [1,2,3]
// Output: "firstsecondthird"
// Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

// Example 2:
// Input: nums = [1,3,2]
// Output: "firstsecondthird"
// Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.




//Solution Approach :-
// I actually started learning about threads recently only and even my first attempt was to take 2 mutex and lock/unlock them in order desired by us. That solution is actually accepted in leetcode.
// However, while researching for difference between mutex and conditional_variable usage, i realised that the way mutex are being used here are totally wrong.

// Some points that must be taken note of are:
// -> Mutex are used for mutual exclusion i.e to safe gaurd the critical sections of a code.
// -> Semaphone/condition_variable are used for thread synchronisation(which is what we want to achieve here).
// -> Mutex have ownership assigned with them, that is to say, the thread that locks a mutex must only unlock it. Also, we must not unlock a mutex that has not been locked (This is what most programs have got wrong).
// -> If the mutex is not used as said above, the behavior is undefined, which however in our case produces the required result.

// References:
// -> If the mutex is not currently locked by the calling thread, it causes undefined behavior.
// -> The precondition for calling unlock is holding an ownership of the mutex, according to (std)30.4.1.2

class Foo {
public:
    int count = 0;
    mutex mtx;
    condition_variable cv;
    
    Foo() {
        count = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);    //first lock using mutex
		
        // while(count != 1){     // No point of this wait as on start count will be 1, we need to make the other threads wait.
        //     cv.wait(lck);
        // }
        
        printFirst();   // printFirst() outputs "first". Do not change or remove this line.
        count = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        
        while(count != 2){
            cv.wait(lck);
        }
        
        printSecond();     // printSecond() outputs "second". Do not change or remove this line.
        count = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        
        while(count != 3){
            cv.wait(lck);
        }
        
        printThird();    // printThird() outputs "third". Do not change or remove this line.
    } 
};



//Second Solution :- Using std::promise
class Foo {
private:
  std::promise<void> p1;
  std::promise<void> p2;

public:
  void first(function<void()> printFirst) {
    printFirst();
    p1.set_value();
  }

  void second(function<void()> printSecond) {
    p1.get_future().wait();
    printSecond();
    p2.set_value();
  }

  void third(function<void()> printThird) {
    p2.get_future().wait();
    printThird();
  }
};



//Third Solution :- Using 2 mutex
//Idea is grab and release locks in order.
class Foo {   
    mutex m1, m2;
public:
    Foo() {
        m1.lock(), m2.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();    // printFirst() outputs "first". Do not change or remove this line.
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        printSecond();   // printSecond() outputs "second". Do not change or remove this line.
        m1.unlock();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        printThird();   // printThird() outputs "third". Do not change or remove this line.
        m2.unlock();
    }
};