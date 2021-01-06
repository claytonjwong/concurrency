#include <iostream>
#include <thread>

using namespace std;

class Task {
public:
    void operator()() const {
        std::cout << "Hello, Concurrent World!" << std::endl;
    }
};

int main() {
    Task task;
    thread t(task);
    t.join();
    return 0;
}
