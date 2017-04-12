/*PIANO TUTORIAL*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <clocale>
#include <cstdio>
#include <string>
#include <iostream>

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
void print_inter_prima();
void print_inter_sec();
void print_inter_ter();
void print_inter_kvarta();
void print_inter_kvinta();
void print_inter_seksta();
void print_inter_septima();
void print_inter_octava();

void print_inter_prima(){
	system("cls");
	print_piano(35, -1);
	cout << "Прима" << endl;
	cout << "Прима – обозначается числом 1, " << endl;
	cout << "что говорит нам: два звука находятся" << endl;
	cout << "на одной и той же ступени." << endl;
	cout << "Значит, прима – это обыкновенное" << endl;
	cout << "повторение звука, шаг на месте: " << endl;
	cout << "до и еще раз до, или ре и ре, ми-ми и т.д." << endl;
	system("pause");
};

void print_inter_sec(){
	system("cls");
	print_piano(5, 15);
	cout << "Секунда" << endl;
	cout << "Секунда – обозначается двойкой," << endl;
	cout << "потому что этот интервал охватывает" << endl;
	cout << "уже две ступени: один звук находится" << endl;
	cout << "на какой-либо ноте, а второй на соседней," << endl;
	cout << "то есть второй по счету ступени. " << endl;
	cout << "Например: до и ре, ре и ми, ми и фа и т.д." << endl;
	system("pause");
};

void print_inter_ter(){
	system("cls");
	print_piano(55, 65);
	cout << "Терция" << endl;
	cout << "Терция – охватывает три ступени." << endl;
	cout << "Второй звук находится по отношению " << endl;
	cout << "к первому на расстоянии трех ступеней, " << endl;
	cout << "если идти подряд по музыкальной лестнице." << endl;
	cout << "Примеры терций: до и ми, ре и фа, ми и соль и т.д. " << endl;
	system("pause");
};

void print_inter_kvarta(){
	system("cls");
	print_piano(35, 50);
	cout << "Кварта" << endl;
	cout << "Кварта – теперь интервал расширяется" << endl;
	cout << "до четырех ступеней, то есть первый звук" << endl;
	cout << "находится на первой ступени, а второй звук –" << endl;
	cout << "на четвертной. Например: до и фа, ре и соль и т.д." << endl;
	cout << "Поясним еще раз, что считать ступеньки можно" << endl;
	cout << "начинать от любой ноты: хоть от до, хоть от ре – " << endl;
	cout << "выбираем то, что нам нужно." << endl;
	system("pause");
};

void print_inter_kvinta(){
	system("cls");
	print_piano(0, 20);
	cout << "Квинта" << endl;
	cout << "Квинта – обозначение числом 5 говорит о том," << endl;
	cout << "что ширина интервала – 5 ступеней. " << endl;
	cout << "Например: до и соль, ре и ля, ми и си и т.д." << endl;
	system("pause");
};

void print_inter_seksta(){
	system("cls");
	print_piano(10, 35);
	cout << "Секста" << endl;
	cout << "Секста– число 6, которым он обозначается, " << endl;
	cout << "указывают на то, что нужно отсчитать шесть" << endl;
	cout << "ступеней, чтобы получить сексту. Примеры" << endl;
	cout << "секст: до и ля, ре и си, ми и до." << endl;
	system("pause");
};

void print_inter_septima(){
	system("cls");
	print_piano(15, 45);
	cout << "Септима" << endl;
	cout << "Септима – число 7, которыми он обозначается," << endl;
	cout << "указывает на то, что нужно отсчитать семь" << endl;
	cout << "ступеней, чтобы получить септиму. Примеры " << endl;
	cout << "септим (все вверх по лестнице): до и си, ре и до, ми и ре." << endl;
	system("pause");
};

void print_inter_octava(){
	system("cls");
	print_piano(0, 35);
	cout << "Октава" << endl;
	cout << "Октава – последний интервал, такой же легкий," << endl;
	cout << "как и прима. Это тоже повторение звука," << endl;
	cout << "только на другой высоте. Например: до первой" << endl;
	cout << "октавы и до второй октавы, ре и ре, ми и ми и т.д." << endl;
	system("pause");
};


/*--------------PRINT FUNCTIONS----------------------*/

/*--------------MENU FUNCTIONS----------------------*/

void menuTutorial();
void menuTesting();
void menuAbout();

/*--------------MENU FUNCTIONS----------------------*/

/*--------------QUESTIONS----------------------*/
int question(int answer, string variants, int key1, int key2){
    system ("cls");
    print_piano(key1, key2);

	cout << variants << endl;
    cout << "Введите номер правильного варианта: " <<endl;

    int choice;
    cin >> choice;
    if(choice != answer ){
        cout << "Неверный ответ" <<endl;
        cout << "Правильный ответ: " << answer <<endl;
        system("pause");
        return 0;
    }
    cout << "Правильный ответ" <<endl;
    system("pause");
    return 1;
}

/*--------------QUESTIONS----------------------*/

void menuTesting() {
    int result = 0;

    while (true) {
        system ("cls");
        print_piano(-1, -1);

        cout << "Ваша задача состоит в определении интервалов,\nизображенных на фортепианной клавиатуре." <<endl;
		cout << "Перед прохождением теста, рекомендуется ознакомиться с пунктом 'Обучение'." << endl;
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
        result += question(2, "1. Прима\n2. Терция\n3. Кварта\n4. Секунда", 30, 40);
		result += question(1, "1. Квинта\n2. Кварта\n3. Септима\n4. Октава", 15, 35);
		result += question(4, "1. Прима\n2. Септима\n3. Секунда\n4. Кварта", 15, 30);
		result += question(2, "1. Септима\n2. Секста\n3. Квинта\n4. Терция", 20, 45);
		result += question(3, "1. Кварта\n2. Прима\n3. Секунда\n4. Терция", 55, 60);
		result += question(1, "1. Септима\n2. Терция\n3. Квинта\n4. Кварта", 0, 30);
		result += question(4, "1. Октава\n2. Секста\n3. Кварта\n4. Прима", 45, -1);
		result += question(3, "1. Прима\n2. Терция\n3. Октава\n4. Секунда", 0, 35);
		result += question(1, "1. Терция\n2. Прима\n3. Секунда\n4. Кварта", 55, 65);
		result += question(3, "1. Септима\n2. Прима\n3. Секста\n4. Квинта", 10, 35);
		result += question(2, "1. Секунда\n2. Квинта\n3. Терция\n4. Кварта", 0, 20);

        //}

        system ("cls");
        print_piano(-1, -1);
        cout << "Ваш результат: " << result << endl;

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
