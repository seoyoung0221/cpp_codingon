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
		cout << "�ܾ� : " << balance << endl;
	};
	void withdraw(int amount)
	{
		balance.fetch_add(-amount);
		cout << "�ܾ� : " << balance << endl;
	};

private:
	atomic<int> balance =1000;
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