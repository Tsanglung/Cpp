/*
建立一銀行帳戶類別，此類別內有三個私有屬性money (存放目前存款總額)、存戶姓名字串與帳戶號碼，
並有三個公用函數即查詢存款餘額check()、存款deposit(double money) 與提款withdrawal()，
亦請建立一靜態屬性利率ratio 存放銀行一年期固定利率，初始值為1.05%。
帳戶物件建立時應給定存款總額、存戶姓名字串，並亂數給訂一組帳戶
*/
#include <iostream>
#include <random>
#include <string>
#include <set>
#include <ctime>

using namespace std;

const string word = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
random_device rd;
mt19937 generator(rd());
uniform_int_distribution<> distr(0, word.size() - 1);

class Account {
private:
    static double rate; // 靜態屬性利率rate
    static int count;
    double money;
    string ID;
    string account;
    bool Delete;
public:
    Account(double m, string ID, string account);
    ~Account();
    void check(); // 存放目前存款總額
    void deposit(double CashInput); // 存款
    void withdrawal(double Cash); // 提款
    void DeleteAccount(bool D) { Delete = D; }
};

double Account::rate = 1.05; // 初始值為1.05%。
int Account::count = 0; // 帳戶數量

Account::Account(double m, string ID, string account) : money(m), ID(ID), account(account) { Account::count++; }
Account::~Account() {
    if (Delete == true) {
        cout << "撤銷" << ID << "的帳戶" << endl;
        Account::count--;
    }
}
void Account::check() { cout << "目前 " << ID << " 餘額 : " << money << "元" << endl; }
void Account::deposit(double CashInput) {
    money += CashInput;
    cout << "存款 : " << CashInput << "元，帳戶 " << account << " 餘額 : " << money << "元" << endl;
}
void Account::withdrawal(double Cash) {
    if (Cash > money) cout << "帳戶 " << account << " 餘額不足 !" << endl;
    else {
        money -= Cash;
        cout << "提款 : " << Cash << "元，帳戶 " << account << " 餘額 : " << money << "元" << endl;
    }
}

// 生成唯一的?机字符串
string generateAccount(set<string>& Account, int length = 10) {
    string account;
    do {
        account.clear();
        for (int i = 0; i < length; i++) {
            account += word[distr(generator)];
        }
    } while (Account.find(account) != Account.end());
    Account.insert(account);
    return account;
}

int main() {
    set<string> account;
    string account1 = generateAccount(account);
    Account Han(100000, "han", account1);
    Han.check();
    Han.deposit(4000);
    Han.withdrawal(850);
    Han.DeleteAccount(false);

    string account2 = generateAccount(account);
    Account An(5000, "an", account2);
    An.check();
    An.deposit(450);
    An.withdrawal(6000);
    An.DeleteAccount(false);
    return 0;
}
