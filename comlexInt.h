/**
 * @file complexInt.h
 * @brief Заголовочний файл для класу Complex
 */

#ifndef OOP4_3_COMLEXINT_H
#define OOP4_3_COMLEXINT_H


#include <iostream>
#include <sstream>
#include <string.h>
#include <cmath>

using namespace std;



/**
 * @class Complex
 * @brief Клас для комплексних чисел
 */
class Complex
{
private:
    double re; /**< Дійсна частина комплексного числа */
    double im; /**< Уявна частина комплексного числа */

public:
    /**
     * @brief Конструктор за замовчуванням
     */
    Complex()
    {
    };

    /**
     * @brief Конструктор з одним параметром
     * @param r Дійсна частина комплексного числа
     */
    Complex(double r)
    {
        re = r;
        im = 0;
    }

    /**
     * @brief Конструктор з двома параметрами
     * @param r Дійсна частина комплексного числа
     * @param i Уявна частина комплексного числа
     */
    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    /**
     * @brief Конструктор копіювання
     * @param c Об'єкт класу Complex для копіювання
     */
    Complex(const Complex& c)
    {
        re = c.re;
        im = c.im;
    }

    /**
     * @brief Деструктор
     */
    ~Complex()
    {
    }


    /**
     * @brief Обчислення модуля комплексного числа
     * @return Модуль комплексного числа
     */
    double abs()
    {
        return sqrt(re * re + im * im);
    }

    /**
     * @brief Перегрузка оператора присвоєння
     * @param c Об'єкт класу Complex для присвоєння
     * @return Посилання на об'єкт, на який було здійснено присвоєння
     */
    Complex& operator = (Complex& c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }

    /**
     * @brief Перегрузка оператора додавання з присвоєнням
     * @param c Об'єкт класу Complex для додавання
     * @return Посилання на об'єкт, на який було здійснено додавання
     */
    Complex& operator += (Complex& c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    /**
     * @brief Перегрузка оператора менше
     * @param c Об'єкт класу Complex для порівняння
     * @return Результат порівняння
     */
    bool operator < (Complex c)
    {
        if (re < c.re) {
            return true;
        }
        else if (re == c.re && im < c.im) {
            return true;
        }
        return false;
    }

    /**
     * @brief Перегрузка оператора більше
     * @param c Об'єкт класу Complex для порівняння
     * @return Результат порівняння
     */
    bool operator > (Complex c)
    {
        if (re > c.re) {
            return true;
        }else if (re == c.re && im > c.im) {
            return true;
        }
        return false;

    }

    /**
     * @brief Перегрузка оператора рівності
     * @param c Об'єкт класу Complex для порівняння
     * @return Результат порівняння
     */
    bool operator == (Complex c)
    {
        if (re == c.re && im == c.im) {
            return true;
        }
        return false;

    }


    /**
     * @brief Повертає рядкове представлення комплексного числа
     * @return Рядкове представлення комплексного числа
     */
    string getString() {

        ostringstream s1,s2;
        s1 << this->re;
        s2 << this->im;
        string str;

        if (re == 0 && im != 0) {
            str = s2.str() + "i";
        }
        else if (im == 0 && re != 0) {
            str = s1.str();
        }
        else if (im == 0 && re == 0) {
            str = "0";
        }
        else if (im == 1) {
            str = s1.str() + "+i";
        }
        else {
            str = s1.str() + "+" + s2.str() + "i";
        }


        return str;
    }
};

#endif //OOP4_3_COMLEXINT_H
