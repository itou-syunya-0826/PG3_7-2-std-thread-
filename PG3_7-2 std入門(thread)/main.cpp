#include <stdio.h>
#include <thread>

int current_thread = 1;

void print_thread(int thread_id) {
    while (true) {
        if (current_thread == thread_id) {
            printf("thread%d\n", thread_id);
            current_thread++;
            break;
        }
    }
}

int main() {
    std::thread t1(print_thread, 1);
    std::thread t2(print_thread, 2);
    std::thread t3(print_thread, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}