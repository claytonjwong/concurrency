#include <iostream>
#include <thread>

using namespace std;

class scoped_thread {
    thread t;
public:
    explicit scoped_thread(thread& t) : t{move(t)} {
        if (!t.joinable())
            throw logic_error("No thread");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread& src) = delete;
    scoped_thread(const scoped_thread&& src) = delete;
    scoped_thread& operator=(const scoped_thread& rhs) = delete;
    scoped_thread& operator=(const scoped_thread&& rhs) = delete;
};

int main() {
    std::cout << "max threads: " << thread::hardware_concurrency() << std::endl
              << "thread id: " << this_thread::get_id() << endl;
    return 0;
}
