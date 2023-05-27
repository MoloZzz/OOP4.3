#include <iostream>
#include"comlexInt.h"
#include "B-treeClass.h"



#include <ctime>

#include <random> //random

#include <stdio.h>
#include <time.h>


#include <thread> //potoki

using namespace std;








int randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());

    return mersenne()%max;
}


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

void createRandomTreeAndCheck(){
    BTree t(3);

    int max = 99;
    int length = 1000;

    for(int i = length; i > 0 ; i--) {
        t.insert(Complex(randomInt(1,max), randomInt(1,max)));
    }

    //t.traverse();

    Complex k = Complex(randomInt(1,max), randomInt(1,max));

    (t.search(k) != NULL)
    ? cout << endl << k.getString() << " find"
    : cout << endl << k.getString() << " not find\n";

    Complex m = Complex(randomInt(1,max), randomInt(1,max));

    (t.search(m) != NULL)
    ? cout << endl << m.getString() << " find"
    : cout << endl << m.getString() << " not find\n";
}



int main() {

    setlocale(LC_ALL, "Ukrainian");

    clock_t start = clock();

     thread newThread(createRandomTreeAndCheck);

    createRandomTreeAndCheck();

    newThread.join();

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);




}