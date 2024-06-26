#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

class BankAccount
{
public:
	void deposit(int amount)
	{
		balance.fetch_add(amount);
		cout << "잔액 : " << balance << endl;
	};
	void withdraw(int amount)
	{
		balance.fetch_add(-amount);
		cout << "잔액 : " << balance << endl;
	};

private:
	atomic<int> balance =1000;
};

// count 횟수만큼 amount를 입금(deposit)
void deposit_iter(BankAccount& ba, int amount, int count);

// count 횟수만큼 amount를 출금(withdraw)
void withdraw_iter(BankAccount& ba, int amount, int count);

int main()
{
	BankAccount ba;
	//deposit_iter, withdraw_iter 스레드 객체로 생성
	thread t1(deposit_iter, ref(ba), 100, 100);
	thread t2(withdraw_iter, ref(ba), 100, 100);
	//amount = 100, count = 100
	t1.join();
	t2.join();

	return 0;
}

void deposit_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		ba.deposit(amount);
	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		ba.withdraw(count);
	}

}