#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
mutex mtx;

class BankAccount
{
public:
	void deposit(int amount)
	{
		this->balance += amount;
		cout << "�ܾ� : " << balance << endl;
	};
	void withdraw(int amount)
	{
		this->balance -= amount;
		cout << "�ܾ� : " << balance << endl;
	};

private:
	int balance = 1000;
};

// count Ƚ����ŭ amount�� �Ա�(deposit)
void deposit_iter(BankAccount& ba, int amount, int count);

// count Ƚ����ŭ amount�� ���(withdraw)
void withdraw_iter(BankAccount& ba, int amount, int count);

int main()
{
	BankAccount ba;
	//deposit_iter, withdraw_iter ������ ��ü�� ����
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
		mtx.lock();
		ba.deposit(amount);
		mtx.unlock();
	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		mtx.lock();
		ba.withdraw(count);
		mtx.unlock();
	}

}