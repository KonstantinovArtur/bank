#include <iostream>
using namespace std;

class BancAcount
{
    private:
        int accnum;
        double balacne;
        int numberschet;
        double interest;
        double balacne2 = 0;
    public:
        BancAcount(double numberschet, int balacne) {

            this->numberschet = numberschet;
            this->balacne = balacne;

            interest = 0;
        }
    public:
        double deposit(double dip) {
            balacne += dip;
            cout << "Ваш баланс: " << balacne << " На счете: " << numberschet << endl;
            return balacne;
        }
        double withdraw(double dip) {
            balacne -= dip;
            cout << "Ваш баланс: " << balacne << " На счете: " << numberschet << endl;
            return balacne;
        }
        double getBalance() {
            double new_balacne = balacne;
            balacne = new_balacne;
            return balacne;
        }
        BancAcount& setInteresRate(double interest1) {
            this->interest = interest1;
            cout << "Ваша новая процетная ставка = " << interest1 << endl;
            return *this;
        }
        double getInterest() {
            double balacne1 = (balacne * interest / 100);
            balacne = balacne + balacne1;
            return balacne1;

        }
        int getNum() {
            return numberschet;
        }
        double transfer(int perchet, int schet2, int bal) {
            if (bal <= balacne) {
                balacne -= bal;
                cout << "Перевод успешно проведен:  " << " \nВаш баланс: " << balacne << endl;
                cout << "Баланс на счете: " << schet2 << " Равен: " << bal << endl;
            }
            else {
                cout << "Перевод не выполнен " << " Ваш баланс: " << balacne << endl;
            }
            return balacne;
        }

        double balance() {
            return balacne;
        }

};










int main()
{
    setlocale(LC_ALL, "Russian");
    int menu;
    BancAcount bank(80085, 0);
    do
    {
        cout << "Выберите действие";
        cout << "\n1. Внести средства";
        cout << "\n2. Снять средства";
        cout << "\n3. Баланс";
        cout << "\n4. Полученные проценты";
        cout << "\n5. Новая процентная ставка";
        cout << "\n6. Номер банковского счета";
        cout << "\n7. Перевод";
        cout << "\n";
        cin >> menu;
        if (menu == 1) {

            double groshi;

            cout << "Введите сумму пополнения " << endl;
            cin >> groshi;
            if (groshi < 0) {
                cout << "Нельзя внести отрицательный баланс " << endl;
                continue;
            }
            else if (groshi == 0) {
                cout << "Некорректная сумма " << endl;
                continue;
            }
            bank.deposit(groshi);
        }
        if (menu == 2) {
            double groshi;
            cout << "Введите сумму для вывода " << endl;
            cin >> groshi;
            if (groshi < 0) {
                cout << "Нельзя внести отрицательный баланс " << endl;
                continue;
            }
            else if (groshi == 0) {
                cout << "Некорректная сумма " << endl;
                continue;
            }
            else if (groshi > bank.balance()) {
                cout << "Недостаточно средств " << endl;
                continue;
            }
      
            bank.withdraw(groshi);
        }
        if (menu == 3) {
     
            bank.getBalance();
            cout << "Ваш баланс = " << bank.balance() << endl;
        }
        if (menu == 4) {
        
            cout << "Сумма процентов" << bank.getInterest() << endl;

        }
        if (menu == 5) {
            double proc;
            cout << "Введите новую процентную ставку" << endl;
            cin >> proc;
    
  
            bank.setInteresRate(proc);

        }
        if (menu == 6) {
            
            cout << "Ваш счет " << bank.getNum() << endl;
        }
        if (menu == 7) {
            cout << "Введите ваш счет" << endl;
            int chet;
            cin >> chet;
            if (chet != 80085) {
                cout << "Такого счета нет" << endl;
                continue;
            }
            int vtot_chet;
            cout << "Введите второй счет" << endl;
            cin >> vtot_chet;
            int sum;
            cout << "Введите сумму" << endl;
            cin >> sum;
            if (sum > bank.balance()) {
                cout << "Недостаточно средств " << endl;
                continue;

            }
            bank.transfer(chet, vtot_chet, sum);
        }
        if (menu > 8) {
            cout << "Такой команды нет";
        }
    
    } while (menu != 8);
}
