/*PIANO TUTORIAL*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <clocale>
#include <cstdio>

using namespace std;


/*--------------SUPPORT FUNCTIONS----------------------*/

/*Object of console for styling*/
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/*Code of colors for console*/
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

/*Print current key marked*/
void illuminteKey(HANDLE hConsole) {
    SetConsoleTextAttribute(hConsole, (WORD)((13 << 4) | 13));
}

/*Print white key*/
void keyWhite(HANDLE hConsole){
    SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 15));
}

/*Print black key*/
void keyBlack(HANDLE hConsole){
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 0));
}

/*Print space between keys*/
void betweenKey(HANDLE hConsole){
    SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 8));
}

/*Change key color*/
void changeKey(int coord, int arr[10][73]) {
    for (int j = coord; j < (4 + coord); j++) {
        int i = 9;
        while (arr[i][j] == 1 && i >= 0) {
            arr[i][j] = 3;
            i--;
        }
    }
}

void print_piano(int key1, int key2) {
    //0-black
    //1-white
    //2-grey

    //C0 = 0
    //D0 = 5
    //E0 = 10
    //F0 = 15
    //G0 = 20
    //A0 = 25
    //B0 = 30
    //C1 = 35
    //D1 = 40
    //E1 = 45
    //F1 = 50
    //G1 = 55
    //A1 = 60
    //B1 = 65
    //C2 = 70

    int piano_matrix[10][73] =
    {
        /*0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72*/
        /*0*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*1*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*2*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*3*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*4*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*5*/{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 2, 1, 1, 1 },
        /*6*/{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1 },
        /*7*/{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1 },
        /*8*/{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1 },
        /*9*/{ 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1 }
    };

    if (key1 != -1) changeKey(key1, piano_matrix);
    if (key2 != -1) changeKey(key2, piano_matrix);

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 73; j++) {

            switch (piano_matrix[i][j]) {
            case 0:{
                keyBlack(hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 1:{
                keyWhite(hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 2:{
                betweenKey(hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 3:{
                illuminteKey(hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            }
        }
        cout << endl;
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 0));
}

/*--------------SUPPORT FUNCTIONS----------------------*/

/*--------------PRINT FUNCTIONS----------------------*/

void print_mainMenu();
void print_menuTutorial();
void print_menuTesting();
void print_menuAbout();

/*--------------PRINT FUNCTIONS----------------------*/

/*--------------MENU FUNCTIONS----------------------*/

void menuTutorial();
void menuTesting();
void menuAbout();

/*--------------MENU FUNCTIONS----------------------*/

/*--------------QUESTIONS----------------------*/
int question(int answer, string question, string variants){
    system ("cls");
    print_piano(-1, -1);

    cout << question <<endl;
    cout << variants << endl;

    int choice;
    cin >> choice;
    if(choice != answer){
        cout << "Wrong answer" <<endl;
        cout << "Correct answer is " << answer <<endl;
        system("pause");
        return 0;
    }
    cout << "Correct answer" <<endl;
    system("pause");
    return 1;
}

/*--------------QUESTIONS----------------------*/

void menuTesting() {
    int result = 0;

    while (true) {
        system ("cls");
        print_piano(-1, -1);

        cout << "Some text for test" <<endl;
        system("pause");

        /*Тут цикл будет.
          Он будет обрабатывать текстовый файл с вопросами.
          Текстовый файл будет иметь вид:

          #Вопрос
          #Варианты ответов
          #Правильный ответ

          На каждом проходе цикла будет вызываться функция question
          с параметрами вопроса:
          question(#Правильный ответ, #Вопрос, #Варианты ответов);

Если цифра введенная пользователем совпадает с правильным ответом в файле,
то функция question возвращает 1, иначе  0.
В любом случае в переменную result мы прибавляем то, что вернула функция.
В конце пользователю выводится его количество правильных ответов.
*/
        //for(int i...) {
        result += question(1, "QUESTION", "a, b, c, d");
        result += question(1, "QUESTION", "a, b, c, d");
        result += question(1, "QUESTION", "a, b, c, d");
        //}

        system ("cls");
        print_piano(-1, -1);
        cout << "Your score: "<< result <<endl;

        system("pause");
        break;
    }
}

void menuTutorial() {

    while (true) {
        system ("cls");
        print_piano(-1, -1);
        int choice;

        cout << "Эта программа поможет в изучении основных интервалов..." << endl;
        cout << " Интервалами называют сочетание двух звуков, взятых одновременно " << endl;
        cout << " или последовательно.Проще говоря - это расстояние между звуками" << endl;
        cout << " в музыке. Простых интервалов всего 8. Названия интервалов - это " << endl;
        cout << " порядковые числители на латинском. Название интервала показывает" << endl;
        cout << " количество ступеней между основанием и вершиной интервала. " << endl;


        cout << "1. Прима (один и тот же звук)" << endl;
        cout << "2. Секунда" << endl;
        cout << "3. Терция" << endl;
        cout << "4. Кварта" << endl;
        cout << "5. Квинта" << endl;
        cout << "6. Секста" << endl;
        cout << "7. Септима" << endl;
        cout << "8. Октава" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите номер, что бы посмотреть пример...";

        cin >> choice;

        switch (choice)
        {
        case 0:
            return;
        case 1:
            system("cls");
            print_piano(35, -1);
            cout << "Прима" << endl;

            system("pause");
            break;
        case 2:
            system("cls");
            print_piano(5, 15);
            cout << "Секунда" << endl;

            system("pause");
            break;
        case 3:
            system("cls");
            print_piano(55, 65);
            cout << "Терция" << endl;
            cout << "" << endl;
            cout << " " << endl;
            cout << "  " << endl;
            cout << " " << endl;
            cout << " " << endl;

            system("pause");
            break;
        case 4:
            system("cls");
            print_piano(35, 50);
            cout << "Кварта" << endl;
            cout << "" << endl;

            system("pause");
            break;
        case 5:
            system("cls");
            print_piano(0, 20);
            cout << "Квинта" << endl;

            system("pause");
            break;
        case 6:
            system("cls");
            print_piano(10, 35);
            cout << "Секста" << endl;

            system("pause");
            break;
        case 7:
            system("cls");
            print_piano(15, 45);
            cout << "Септима" << endl;

            system("pause");
            break;
        case 8:
            system("cls");
            print_piano(0, 35);
            cout << "Октава" << endl;

            system("pause");
            break;
        default:
            cout << "Данного пункта нет в меню" << endl;
            system("pause");
            break;
        }
    }
}

int main() {
    SetConsoleTextAttribute(hConsole, (WORD)((8 << 4) | 0));
    setlocale(LC_ALL, "Rus");
    while (true) {
        system("cls");
        print_piano(-1, -1);

        int choice;
        cout << "МЕНЮ" << endl;
        cout << "______________" << endl;
        cout << "1. Обучение" << endl;
        cout << "2. Тест" << endl;
        cout << "3. О программе" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт меню...";
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            menuTutorial();
            continue;
        case 2:
            menuTesting();
            continue;
        case 3:
            cout << "В разработке"<<endl;
            system("pause");
            continue;
        default:
            cout << "Данного пункта нет в меню..." << endl;
            system("pause");
            continue;
        }
        system("pause");
    }

    return 0;
}
