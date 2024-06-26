#include <iostream>
#include <thread>
#include <vector>
void thread_function(int thread_id) {
    std::cout << "Thread " << thread_id << " is running." << std::endl;
    // ���⿡ �����尡 ������ �۾��� �߰��� �� �ֽ��ϴ�.
}
int main() {
    const int num_threads = 10; // ������ ������ ��
    std::vector<std::thread> threads;
    // ������ ����
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_function, i); // i�� ������ ID�� ����
    }
    // ��� �����尡 ����� ������ ���
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    std::cout << "All threads have finished." << std::endl;
    return 0;
}