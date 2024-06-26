#include <iostream>
#include <thread>
#include <vector>
void thread_function(int thread_id) {
    std::cout << "Thread " << thread_id << " is running." << std::endl;
    // 여기에 스레드가 수행할 작업을 추가할 수 있습니다.
}
int main() {
    const int num_threads = 10; // 생성할 스레드 수
    std::vector<std::thread> threads;
    // 스레드 생성
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_function, i); // i는 스레드 ID로 전달
    }
    // 모든 스레드가 종료될 때까지 대기
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    std::cout << "All threads have finished." << std::endl;
    return 0;
}