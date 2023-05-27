#include <iostream>
#include"comlexInt.h"
#include "B-treeClass.h"
using namespace std;











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

    cout << "B-tree: ";

    t.traverse();

    Complex k = Complex(10, 2);

    (t.search(k) != NULL)
    ? cout << endl << k.getString() << " find"
    : cout << endl << k.getString() << " not find";

    Complex m = Complex(55, 22);

    (t.search(m) != NULL)
    ? cout << endl << m.getString() << " find"
    : cout << endl << m.getString() << " not find\n";
}


int main() {

    setlocale(LC_ALL, "Ukrainian");

   createTreeAndCheck();
}