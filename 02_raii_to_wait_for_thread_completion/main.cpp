#include <iostream>
#include <thread>

using namespace std;

class thread_guard {
    thread& t;
public:
    explicit thread_guard(thread& t) : t{ t } {}
    ~thread_guard() {
        if (t.joinable())
            t.join();
    }
    thread_guard(const thread_guard& src) = delete;
    thread_guard(const thread_guard&& src) = delete;
    thread_guard& operator=(const thread& rhs) = delete;
    thread_guard& operator=(const thread&& rhs) = delete;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
