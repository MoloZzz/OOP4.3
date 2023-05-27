//
// Created by megao on 27.05.2023.
//

#ifndef OOP4_3_COMLEXINT_H
#define OOP4_3_COMLEXINT_H


#include <iostream>
#include <sstream>
#include <string.h>
#include <cmath>

using namespace std;




class Complex
{
private:
    double re, im;

public:

    Complex()
    {
    };

    Complex(double r)
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    Complex(const Complex& c)
    {
        re = c.re;
        im = c.im;
    }

    ~Complex()
    {
    }


    double abs()
    {
        return sqrt(re * re + im * im);
    }

    Complex& operator = (Complex& c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }

    Complex& operator += (Complex& c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

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

    bool operator > (Complex c)
    {
        if (re > c.re) {
            return true;
        }else if (re == c.re && im > c.im) {
            return true;
        }
        return false;

    }

    bool operator == (Complex c)
    {
        if (re == c.re && im == c.im) {
            return true;
        }
        return false;

    }


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
