/**
 * @file main.cpp
 * @brief Головний файл програми
 */


#include <iostream>
#include"comlexInt.h"
#include "B-treeClass.h"


#include <random> //random

#include <stdio.h>
#include <time.h>


#include <thread> //potoki

using namespace std;







/**
 * @brief Генерує випадкове ціле число у заданому діапазоні
 * @param min Мінімальне значення
 * @param max Максимальне значення
 * @return Випадкове ціле число
 */
int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());

    return mersenne()%max;
}

/**
 * @brief Створює дерево та перевіряє його роботу
 */
void createTreeAndCheck(){
    BTree t(3);

    t.insert(Complex(12,0));
    t.insert(Complex(7, 20));
    t.insert(Complex(10, 2));
    t.insert(Complex(11, 2));
    t.insert(Complex(24, 1));
    t.insert(Complex(5, 22));
    t.insert(Complex(1, 1));
    t.insert(Complex(2, 15));
    t.insert(Complex(9, 22));
    t.insert(Complex(15, 16));
    t.insert(Complex(17, 27));
    t.insert(Complex(55, 22));

    t.traverse();

    Complex k = Complex(10, 2);

    (t.search(k) != NULL)
    ? cout << endl << k.getString() << " find" << endl
    : cout << endl << k.getString() << " not find" << endl;

    Complex m = Complex(55, 22);

    (t.search(m) != NULL)
    ? cout << endl << m.getString() << " find" << endl
    : cout << endl << m.getString() << " not find\n" << endl;
}

/**
 * @brief Створює випадкове дерево
 */
void createRandomTree(){
    BTree t(3);

    int max = 1000;
    int length = 10000;

    for(int i = length; i > 0 ; i--) {
        t.insert(Complex(randomInt(1,max), randomInt(1,max)));
    }
    //t.traverse();

}

/**
 * @brief Функція, яка використовується в потоці
 */
void funcForThread(){
        createRandomTree();
}

/**
 * @brief Виконує створення випадкових дерев у потоках
 */
void threadV(){
    thread newThread1(funcForThread);
    thread newThread2(funcForThread);
    thread newThread3(funcForThread);
    thread newThread4(funcForThread);
    thread newThread5(funcForThread);

    newThread1.join();
    newThread2.join();
    newThread3.join();
    newThread4.join();
    newThread5.join();
}

/**
 * @brief Виконує створення випадкових дерев без використання потоків
 */
void noThreadV(){
    for(int i = 5; i > 0 ; i--)
    createRandomTree();
}

//logs
#include "logs.h"


/**
 * @brief Формує рядок з даними для логу
 * @param seconds Кількість секунд
 * @param mode Режим (з потоками або без)
 * @param count Кількість створених дерев
 * @param action Дія (створення дерева)
 * @param max Максимальне значення
 * @param nodes Кількість вузлів у дереві
 * @param threads Кількість потоків
 * @return Строка з даними для логу
 */
string createStr(double seconds,string mode,int count,string action,int max,int nodes,int threads = 1){

        return "{\"time\":" + to_string(seconds) + ",\"mode\":" + mode + ",\"threads\":" + to_string(threads) + + ",\"count\":"
               + to_string(count) + ",\"action\":" + action + ",\"maxValue\":" + to_string(max) + ",\"nodes\":" +
               to_string(nodes) + ",},";

}


/**
 * @brief Головна функція програми
 * @return Код повернення
 */
int main() {

    string filePath = "C:\\Users\\megao\\Documents\\GitHub\\OOP4.3\\ourLogs.txt";

    setlocale(LC_ALL, "Ukrainian");


    for(int i = 0; i < 100; i++) {
        clock_t start = clock();

        noThreadV();

        clock_t end = clock();

        double seconds = (double) (end - start) / CLOCKS_PER_SEC;

        printf("\nThe time: %f seconds\n", seconds);

        log(createStr(seconds, "\"noThread\"", 5, "\"createTree\"", 1000, 10000, 1), filePath);
    }






}