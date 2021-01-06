#include <iostream>
#include <thread>

using namespace std;

void hello(const string& s) {
    std::cout << "Hello, " << s << " World!" << std::endl;
}

int main() {
    thread t(hello, string("Concurrent"));
    t.join();
    return 0;
}
