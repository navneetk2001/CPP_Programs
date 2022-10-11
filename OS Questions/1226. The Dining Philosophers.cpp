// Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

// Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
// Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
// Design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.
// The problem statement and the image above are taken from wikipedia.org

// The philosophers' ids are numbered from 0 to 4 in a clockwise order. Implement the function void wantsToEat(philosopher, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork) where:
// philosopher is the id of the philosopher who wants to eat.
// pickLeftFork and pickRightFork are functions you can call to pick the corresponding forks of that philosopher.
// eat is a function you can call to let the philosopher eat once he has picked both forks.
// putLeftFork and putRightFork are functions you can call to put down the corresponding forks of that philosopher.
// The philosophers are assumed to be thinking as long as they are not asking to eat (the function is not being called with their number).
// Five threads, each representing a philosopher, will simultaneously use one object of your class to simulate the process. The function may be called for the same philosopher more than once, even before the last call ends.

// Example 1:
// Input: n = 1
// Output: [[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3],[2,1,2],[2,2,2],[4,0,3],[4,1,2],[0,2,1],[4,2,2],[3,2,1],[3,1,1],[0,0,3],[0,1,2],[0,2,2],[1,2,1],[1,1,1],[3,0,3],[3,1,2],[3,2,2],[1,0,3],[1,1,2],[1,2,2]]
// Explanation:
// n is the number of times each philosopher will call the function.
// The output array describes the calls you made to the functions controlling the forks and the eat function, its format is:
// output[i] = [a, b, c] (three integers)
// - a is the id of a philosopher.
// - b specifies the fork: {1 : left, 2 : right}.
// - c specifies the operation: {1 : pick, 2 : put, 3 : eat}.




//Solution Approach :- with 5 mutexes -> Deadlock prevention strategy
class DiningPhilosophers {
    mutex forks[5];
public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
            
            int left = philosopher % 5;          //left id 
			int right = (philosopher + 1) % 5;   //right id
			
			if (philosopher % 2){
				swap(left, right);
			}

			lock_guard left_lock(forks[left]);
			lock_guard right_lock(forks[right]);
        
			pickRightFork();
			pickLeftFork();
			eat();
			putLeftFork();
			putRightFork();
	 }
};



//Second Solution :- ODD and EVEN Rule
//we can change the rules by numbering the forks 1 through 5 and insisting that the philosophers pick up the fork with the lower number first. The philosopher who is sitting between fork 1 and 2 and the philosopher who is sitting between forks 1 and 5 must now reach for the same fork first (fork 1) rather than picking up the one on the right. Whoever gets fork 1 first is now free to take another one. Whoever doesn't get fork 1 must now wait for the first philosopher to release it. Deadlock is not possible.
class DiningPhilosophers {
    int n;
    vector<std::mutex> fork_locks; 
public:
    DiningPhilosophers() {
        n = 5;
        fork_locks = vector<std::mutex>(n);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
		int left_id = philosopher % n;
        int right_id = (philosopher+1) % n;

        if (philosopher % n == 1) {
            fork_locks[right_id].lock();
            fork_locks[left_id].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[left_id].unlock();
            fork_locks[right_id].unlock();
        } 
        else{
            fork_locks[left_id].lock();
            fork_locks[right_id].lock();
            pickRightFork();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            fork_locks[right_id].unlock();
            fork_locks[left_id].unlock();
        }
    }
};



//Third Solution :- Using Semaphores
#include <semaphore.h>

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        for (int i=0; i<5; i++) {
            sem_t s;
            sem_init(&s, 0, 1);
            m_forks.push_back(s);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        //wait till left fork is available
		sem_wait(&m_forks[philosopher]);
        pickLeftFork();
        
        //wait till right fork is available
        sem_wait(&m_forks[(philosopher+1)%5]);
        pickRightFork();
        
        eat();
        
        putLeftFork();
        sem_post(&m_forks[philosopher]);
        
        putRightFork();
        sem_post(&m_forks[(philosopher+1)%5]);
    }
private:
    vector<sem_t> m_forks;
};