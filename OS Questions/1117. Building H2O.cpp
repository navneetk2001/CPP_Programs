// There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.
// There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

// In other words:
// If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
// If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
// We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

// Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

// Example 1:
// Input: water = "HOH"
// Output: "HHO"
// Explanation: "HOH" and "OHH" are also valid answers.

// Example 2:
// Input: water = "OOHHHH"
// Output: "HHOHHO"
// Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.



//Solution Approach :-
class H2O {
	std::mutex m;
	std::condition_variable cv;
	int turn;
public:
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);
        while(turn == 2){
        	cv.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++turn;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);
        while(turn < 2){
        	cv.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn = 0;
        cv.notify_all();
    }
};




//Second Solution :- by using mutex + condition_variable
// "h_count_" is the number of "H" and "o_count_" is the number of "O" so far.
// For hydrogen thread, it is allowed to produce hydrogen only when h_count_ <= (o_count_ * 2)
// For oxygen thread, it is allowed to produce oxygen only when (o_count_ * 2) <= h_count_

class H2O {
    std::mutex mtx_;
    std::condition_variable cv_;
    std::atomic<int> h_count_ = 0;
    std::atomic<int> o_count_ = 0;
public:
    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock lk(mtx_);
        cv_.wait(lk,[this](){
            return h_count_ <= (o_count_ * 2);
        });
        releaseHydrogen();
        h_count_++;
        reset();
        cv_.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock lk(mtx_);
        cv_.wait(lk,[this](){
            return (o_count_ * 2) <= h_count_;
        });
        releaseOxygen();
        o_count_++;
        reset();
        cv_.notify_all();
    }
    void reset(){
        if(h_count_ == 2 && o_count_ == 1){
            h_count_ = 0;
            o_count_ = 0;
        }
    };
};




//Third Solution :- Using Semaphores
//uses a custom semaphore class as C++11 doesn't have inbuilt construct for sempahore

class semaphore{
public:
  semaphore(int count_ = 0) : count{count_}
  {}

  void notify()
  {
    unique_lock<mutex> lck(mtx);
    ++count;
    cv.notify_one();
  }

  void wait()
  {
    unique_lock<mutex> lck(mtx);
    while(count == 0)
    {
      cv.wait(lck);
    }

    --count;
  }
  int value() {
      return count;
  }
private:

  mutex mtx;
  condition_variable cv;
  int count;
};

class H2O {
public:
    semaphore *h, *o;
    mutex m;
    H2O() {
        h = new semaphore(2);
        o = new semaphore(1);
    }

    void form_molecule() {
        if(h->value() == 0 and o->value() == 0) {
            h->notify();
            h->notify();
            o->notify();
        }
    }
    
    void hydrogen(function<void()> releaseHydrogen) {
        h->wait();
        releaseHydrogen();
        lock_guard<mutex> g(m);
        form_molecule();
    }

    void oxygen(function<void()> releaseOxygen) {
        o->wait();
        releaseOxygen();
        lock_guard<mutex> g(m);
        form_molecule();
    }
};





