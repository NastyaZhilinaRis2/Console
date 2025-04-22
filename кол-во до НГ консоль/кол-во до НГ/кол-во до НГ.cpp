#include <iostream>

using namespace std;

int main()
{
    int month, day, ostalos, ostalos_v_mes, ostalos_posle = 0, colvo_dney, fev, ostalos1 = 0;

    setlocale(LC_ALL, "RUSSIAN");
    cout << "Введите номер месяца: ";
    cin >> month;

    cout << "Введите день: ";
    cin >> day;

        if (month > 12 || month == 0 || day > 31 || day == 0 || month == 4 && day > 30 || month == 6 && day > 30 || month == 9 && day > 30 || month == 11 && day > 30 || month == 2 && day > 29) cout << "Такой даты не существует.\n";
        else
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) colvo_dney = 31;
            if (month == 1 || month == 2)
            {
                cout << "Сколько дней в феврале? ";
                cin >> fev;
                if (month == 2) colvo_dney = fev;
            }
            else colvo_dney = 30;
            if ((month == 2 && fev > 29) || (month == 2 && fev < 28) || (month == 2 && day > fev)) cout << "Такой даты не существует.\n";
            else 
            {
                ostalos_v_mes = colvo_dney - day + 1;

                if (month == 1) ostalos_posle = fev + 6 * 31 + 30 * 4;
                if (month == 2) ostalos_posle = 6 * 31 + 30 * 4;
                if (month == 3) ostalos_posle = 5 * 31 + 30 * 4;
                if (month == 4) ostalos_posle = 5 * 31 + 30 * 3;
                if (month == 5) ostalos_posle = 4 * 31 + 30 * 3;
                if (month == 6) ostalos_posle = 4 * 31 + 30 * 2;
                if (month == 7) ostalos_posle = 3 * 31 + 30 * 2;
                if (month == 8) ostalos_posle = 2 * 31 + 30 * 2;
                if (month == 9) ostalos_posle = 2 * 31 + 30;
                if (month == 10) ostalos_posle = 31 + 30;
                if (month == 11) ostalos_posle = 31;

                ostalos = ostalos_v_mes + ostalos_posle;

                ostalos1 = ostalos % 10;

                    if (ostalos1 == 1 && ostalos != 11)
                        cout << "До Нового года осталось: " << ostalos << " день.\n";
                    else
                        if ((ostalos1 == 2 || ostalos1 == 3 || ostalos1 == 4 ) && ostalos != 12 && ostalos != 13 && ostalos != 14)
                            cout << "До Нового года осталось: " << ostalos << " дня.\n";
                        else cout << "До Нового года осталось: " << ostalos << " дней.\n";       
            }
        }
    system("pause");
}
