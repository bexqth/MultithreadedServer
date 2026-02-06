#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cndVar; //signaling the switch between consumer and producer
queue<int> buffer;
const unsigned int MAX_BUFFER_SIZE = 10;
int product = 0;

void producer() {
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cndVar.wait(lock, [] { //waits until the condition is true
            return buffer.size() < MAX_BUFFER_SIZE;
        });
        buffer.push(product);
        cout << "product " << product << " was added to the buffer" << endl;
        cout << "buffer size " << buffer.size() << endl;

        lock.unlock();
        cndVar.notify_one();

        this_thread::sleep_for(chrono::milliseconds(100));
        product++;
    }
    
}

void consumer() {
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cndVar.wait(lock, [] {
            return buffer.size() > 0;
        });

        int pickup = buffer.front();
        buffer.pop();

        cout << "product " << pickup << " was picked up from the buffer" << endl;
        cout << "buffer size " << buffer.size() << endl;
        
        lock.unlock();
        cndVar.notify_one();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
}

int main() {
    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();
    
    return 0;
}
