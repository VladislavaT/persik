/*PIANO TUTORIAL*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <clocale>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*--------------SUPPORT FUNCTIONS----------------------*/

/*Object of console for styling*/
HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);

/*Print current key marked*/
void illuminteKey (HANDLE hConsole) {
    SetConsoleTextAttribute (hConsole, (WORD)((13 << 4) | 13));
}

/*Print white key*/
void keyWhite (HANDLE hConsole) {
    SetConsoleTextAttribute (hConsole, (WORD)((15 << 4) | 15));
}

/*Print black key*/
void keyBlack (HANDLE hConsole) {
    SetConsoleTextAttribute (hConsole, (WORD)((0 << 4) | 0));
}

/*Print space between keys*/
void betweenKey(HANDLE hConsole) {
    SetConsoleTextAttribute (hConsole, (WORD)((8 << 4) | 8));
}

/*Change key color*/
void changeKey (int coord, int arr[10][73]) {
    for (int j = coord; j < (4 + coord); j++) {
        int i = 9;
        while (arr[i][j] == 1 && i >= 0) {
            arr[i][j] = 3;
            i--;
        }
    }
}

void print_piano (int key1, int key2) {
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

    if (key1 != -1) changeKey (key1, piano_matrix);
    if (key2 != -1) changeKey (key2, piano_matrix);

    for (int i = 0; i < 10; i++) {

        for (int j = 0; j < 73; j++) {

            switch (piano_matrix[i][j]) {
            case 0:
            {
                keyBlack (hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 1:
            {
                keyWhite (hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 2:
            {
                betweenKey (hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            case 3:
            {
                illuminteKey (hConsole);
                cout << piano_matrix[i][j];
                break;
            }
            }
        }
        cout << endl;
    }
    cout << endl;
    SetConsoleTextAttribute (hConsole, (WORD)((8 << 4) | 0));
}

string readFile() {
    ifstream fin ("quiz.txt", ifstream::binary);
    if (!fin.is_open())
        return NULL;
    else {
        fin.seekg (0, fin.end);
        int length = fin.tellg();
        fin.seekg (0, fin.beg);
        char *buff = new char[length];
        fin.read (buff, length);
        fin.close();
        return buff;
    }
}
/*--------------SUPPORT FUNCTIONS----------------------*/

/*--------------PRINT FUNCTIONS----------------------*/
void print_mainMenu();
void print_menuTutorial();
void print_menuTesting();
void print_menuAbout();
void print_inter_prima();
void print_inter_sec();
void print_inter_ter();
void print_inter_kvarta();
void print_inter_kvinta();
void print_inter_seksta();
void print_inter_septima();
void print_inter_octava();

void print_menuAbout() {
    system ("cls");
    cout << "Программа разработана в рамках конкурса 'Персик'." << endl;
    cout << "Автор программы: Титарекно В.С." << endl;
    cout << "Программа написана в среде разработки Microsoft Visual Studio" << endl;
    cout << "2017 год" << endl;
    system ("pause");
}

void print_mainMenu() {
    cout << "МЕНЮ" << endl;
    cout << "______________" << endl;
    cout << "1. Обучение" << endl;
    cout << "2. Тест" << endl;
    cout << "3. О программе" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите пункт меню...";
}

void print_menuTutorial() {
    cout << "Эта программа поможет в изучении основных интервалов..." << endl;
    cout << "Интервалами называют сочетание двух звуков, взятых одновременно " << endl;
    cout << "или последовательно.Проще говоря - это расстояние между звуками" << endl;
    cout << "в музыке. Простых интервалов всего 8. Названия интервалов - это " << endl;
    cout << "порядковые числители на латинском. Название интервала показывает" << endl;
    cout << "количество ступеней между основанием и вершиной интервала. " << endl;
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
}

void print_menuTesting() {
    cout << "Ваша задача состоит в определении интервалов,\nизображенных на фортепианной клавиатуре." <<endl;
    cout << "Перед прохождением теста, рекомендуется ознакомиться с пунктом 'Обучение'." << endl;
    system ("pause");
}

void print_inter_prima() {
    system ("cls");
    print_piano (35, -1);
    cout << "Прима" << endl;
    cout << "Прима – обозначается числом 1, " << endl;
    cout << "что говорит нам: два звука находятся" << endl;
    cout << "на одной и той же ступени." << endl;
    cout << "Значит, прима – это обыкновенное" << endl;
    cout << "повторение звука, шаг на месте: " << endl;
    cout << "до и еще раз до, или ре и ре, ми-ми и т.д." << endl;
    system ("pause");
}

void print_inter_sec() {
    system ("cls");
    print_piano (5, 15);
    cout << "Секунда" << endl;
    cout << "Секунда – обозначается двойкой," << endl;
    cout << "потому что этот интервал охватывает" << endl;
    cout << "уже две ступени: один звук находится" << endl;
    cout << "на какой-либо ноте, а второй на соседней," << endl;
    cout << "то есть второй по счету ступени. " << endl;
    cout << "Например: до и ре, ре и ми, ми и фа и т.д." << endl;
    system ("pause");
}

void print_inter_ter() {
    system ("cls");
    print_piano (55, 65);
    cout << "Терция" << endl;
    cout << "Терция – охватывает три ступени." << endl;
    cout << "Второй звук находится по отношению " << endl;
    cout << "к первому на расстоянии трех ступеней, " << endl;
    cout << "если идти подряд по музыкальной лестнице." << endl;
    cout << "Примеры терций: до и ми, ре и фа, ми и соль и т.д. " << endl;
    system ("pause");
}

void print_inter_kvarta () {
    system ("cls");
    print_piano (35, 50);
    cout << "Кварта" << endl;
    cout << "Кварта – теперь интервал расширяется" << endl;
    cout << "до четырех ступеней, то есть первый звук" << endl;
    cout << "находится на первой ступени, а второй звук –" << endl;
    cout << "на четвертной. Например: до и фа, ре и соль и т.д." << endl;
    cout << "Поясним еще раз, что считать ступеньки можно" << endl;
    cout << "начинать от любой ноты: хоть от до, хоть от ре – " << endl;
    cout << "выбираем то, что нам нужно." << endl;
    system ("pause");
}

void print_inter_kvinta() {
    system ("cls");
    print_piano (0, 20);
    cout << "Квинта" << endl;
    cout << "Квинта – обозначение числом 5 говорит о том," << endl;
    cout << "что ширина интервала – 5 ступеней. " << endl;
    cout << "Например: до и соль, ре и ля, ми и си и т.д." << endl;
    system ("pause");
}

void print_inter_seksta() {
    system ("cls");
    print_piano (10, 35);
    cout << "Секста" << endl;
    cout << "Секста– число 6, которым он обозначается, " << endl;
    cout << "указывают на то, что нужно отсчитать шесть" << endl;
    cout << "ступеней, чтобы получить сексту. Примеры" << endl;
    cout << "секст: до и ля, ре и си, ми и до." << endl;
    system ("pause");
}

void print_inter_septima() {
    system ("cls");
    print_piano (15, 45);
    cout << "Септима" << endl;
    cout << "Септима – число 7, которыми он обозначается," << endl;
    cout << "указывает на то, что нужно отсчитать семь" << endl;
    cout << "ступеней, чтобы получить септиму. Примеры " << endl;
    cout << "септим (все вверх по лестнице): до и си, ре и до, ми и ре." << endl;
    system ("pause");
}

void print_inter_octava() {
    system ("cls");
    print_piano (0, 35);
    cout << "Октава" << endl;
    cout << "Октава – последний интервал, такой же легкий," << endl;
    cout << "как и прима. Это тоже повторение звука," << endl;
    cout << "только на другой высоте. Например: до первой" << endl;
    cout << "октавы и до второй октавы, ре и ре, ми и ми и т.д." << endl;
    system ("pause");
}

/*--------------PRINT FUNCTIONS----------------------*/

/*--------------MENU FUNCTIONS----------------------*/

void menuTutorial();
void menuTesting();

/*--------------MENU FUNCTIONS----------------------*/

/*--------------QUESTIONS----------------------*/
int question (int answer, string variants, int key1, int key2) {
    system ("cls");
    print_piano (key1, key2);
    cout << variants << endl;
    cout << "Введите номер правильного варианта: ";
    int choice;
    cin >> choice;
    if (choice != answer ) {
        cout << "Неверный ответ" <<endl;
        cout << "Правильный ответ: " << answer <<endl;
        system ("pause");
        return 0;
    }
    cout << "Правильный ответ" << endl;
    system ("pause");
    return 1;
}
/*--------------QUESTIONS----------------------*/

void menuTesting() {
    int result = 0;
    while (true) {
        system ("cls");
        print_piano (-1, -1);
        print_menuTesting();
        string quiz = readFile();
        for (int i = 0; i < int (quiz.length()); i++) {
            if (quiz[i] == '#') {
                int answer = quiz[i-1] - '0';
                string variants = "";
                int key1 = 0;
                int key2 = 0;
                i++;
                while (quiz[i] != '#') {
                    variants += quiz[i];
                    i++;
                }
                i++;
                key1 = atoi((string()+quiz[i]+quiz[i+1]).c_str());
                i+=2;
                key2 = atoi((string()+quiz[i]+quiz[i+1]).c_str());
                result += question(answer, variants, key1, key2);
            }
        }
        system ("cls");
        print_piano (-1, -1);
        cout << "Ваш результат: " << result << endl;
        system ("pause");
        break;
    }
}

void menuTutorial() {
    while (true) {
        system ("cls");
        print_piano (-1, -1);
        int choice;
        print_menuTutorial();
        cin >> choice;
        switch (choice) {
        case 0:
            return;
        case 1:
            print_inter_prima();
            break;
        case 2:
            print_inter_sec();
            break;
        case 3:
            print_inter_ter();
            break;
        case 4:
            print_inter_kvarta();
            break;
        case 5:
            print_inter_kvinta();
            break;
        case 6:
            print_inter_seksta();
            break;
        case 7:
            print_inter_septima();
            break;
        case 8:
            print_inter_octava();
            break;
        default:
            cout << "Данного пункта нет в меню" << endl;
            system ("pause");
            break;
        }
    }
}

int main() {
    SetConsoleTextAttribute (hConsole, (WORD)((8 << 4) | 0));
    setlocale (LC_ALL, "Rus");
    while (true) {
        system ("cls");
        print_piano (-1, -1);
        int choice;
        print_mainMenu();
        cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1:
            menuTutorial();
            continue;
        case 2:
            menuTesting();
            continue;
        case 3:
            print_menuAbout();
            continue;
        default:
            cout << "Данного пункта нет в меню..." << endl;
            system ("pause");
            continue;
        }
    }
    return 0;
}
