#include <iostream>
#include "classes.h"
#include <string>


int showSelection(dispencerType candy, dispencerType soda, dispencerType snack);
void sellProduct(int user_choice, dispencerType &candy, dispencerType &soda, dispencerType &snack, cashRegister &cash_reg);
void error_message(); 
void success_message(); // Две функции для печати частых сообщений


dispencerType disp_candy(1, 10); // Объявляем объекты классов
dispencerType disp_soda(100, 5);
dispencerType disp_snack(200, 15);
cashRegister cash_reg(0);


int main()
{
    while (true) {
        int user_choice = showSelection(disp_candy, disp_soda, disp_snack);
        sellProduct(user_choice, disp_candy, disp_soda, disp_snack, cash_reg);
    }
    return 0;
}

int showSelection(dispencerType candy, dispencerType soda, dispencerType snack) {

    std::cout << "======= Hi! =======" << std::endl;
    std::cout << "1 ---- " << candy.getNoOfItems() << " candies " << std::endl;
    std::cout << "2 ---- " << soda.getNoOfItems() << " cans of soda " << std::endl;
    std::cout << "3 ---- " << snack.getNoOfItems() << " snacks \n" << std::endl;
    std::cout << "Your balance is " << cash_reg.getCurrentBalance() << std::endl;
    std::cout << "Your choice: ";

    int user_choice = 0;
    std::cin >> user_choice;

    if (!std::cin) { // Проверка на тип данных
        std::cout << "Wrong data! Please, enter the number" << std::endl;
    }
    return user_choice;
}

void sellProduct(int user_choice, dispencerType &candy, dispencerType &soda, dispencerType &snack, cashRegister &cash_reg) {
    int user_money;
    switch (user_choice) {
    case 1:

        if (candy.getNoOfItems() < 1) { // Проверка на наличие товара в автомате
            std::cout << "Sorry.. We are out of candies" << std::endl;
            break;
        }

        else {
            std::cout << "Candy costs " << candy.getCost() << ", please deposit the amount \n"; std::cin >> user_money;

            if (!std::cin || (user_money + cash_reg.getCurrentBalance()) < candy.getCost()) { // Если в денег в автомате + внесенных не хватит, то не продаем
                error_message();
                break;
            }

            else {
                cash_reg.acceptAmount(user_money); // Добавляем деньги
                candy.makeSale(); // Убираем товар из автомата
                cash_reg.makeSale(candy.getCost()); // Снимаем деньги за него
                success_message();
                break;
            }
     
        }
       
    case 2:

        if (soda.getNoOfItems() < 1) {
            std::cout << "Sorry... We are out of soda" << std::endl;
            break;
        }

        else {
            std::cout << "Soda costs " << soda.getCost() << ", please deposit the amount \n"; std::cin >> user_money;

            if (!std::cin || (user_money + cash_reg.getCurrentBalance()) < soda.getCost()) {
                error_message();
                break;
            }

            else {
                cash_reg.acceptAmount(user_money);
                soda.makeSale();
                cash_reg.makeSale(soda.getCost());
                success_message();
                break;
            }
            
        }
        
    case 3:

        if (snack.getNoOfItems() < 1) {
            std::cout << "Sorry... We are out of snacks" << std::endl;
        }

        else {
            std::cout << "Snacks cost " << snack.getCost() << ", please deposit the amount \n"; std::cin >> user_money;

            if (!std::cin || (user_money + cash_reg.getCurrentBalance()) < snack.getCost()) {
                error_message();
                break;
            }

            else {
                cash_reg.acceptAmount(user_money);
                snack.makeSale();
                cash_reg.makeSale(snack.getCost());
                success_message();
                break;
            }
        }
        
    default:
        throw std::runtime_error("Wrong data! Use numbers 1-3");
    }
}

void error_message() {
    std::cout << "Oops.. Use numbers or deposit more money" << std::endl;
}
void success_message() {
    std::cout << "Payment accepted, enjoy!" << std::endl;
}