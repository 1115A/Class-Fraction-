#include "Fraction.h"
#include<iostream>
int Fraction::getnumerator() const//��÷��ӣ��ӿڣ�
{
    return this->numerator;
}

int Fraction::getdenominator() const//��÷�ĸ���ӿڣ�
{
    return this->denominator;
}

Fraction::Fraction():numerator(1),denominator(1)//����Ĭ�ϲ����Ĺ��캯��
{
}

Fraction::Fraction(int numerator, int denominator):numerator(numerator),denominator(denominator)
{//���캯��
}

void Fraction::setnumerator(int numerator)//���÷���
{
    this->numerator = numerator;
}

void Fraction::setdenomerator(int denominator)//���÷�ĸ
{
    this->denominator = denominator;
}

Fraction::Fraction(Fraction& f1)//�������캯��
{
    this->denominator = f1.denominator;
    this->numerator = f1.numerator;
}

Fraction Fraction::simplify()//�������
{
    if (this->numerator == this->denominator)
    {
        this->numerator = 1, this->denominator = 1;
    }
    else
    {
    int n1{ 0 }, d1{ 0 };
    int need{ 1 };
    n1 = this->getnumerator();
    d1 = this->getdenominator();
    need = this->func(n1, d1);
    this->setnumerator(n1 / need);
    this->setdenomerator(d1 / need);
    }
    return *this;
}

int Fraction::func(int& a, int& b)const//�����������
{
    if (a == 0 || b == 0)
        return 0;
    else
    {
            int c = 0, d = 1;
            d = std::max(a, b);
            c = std::min(a, b);
            while (d % c != 0)
            {
                int temp = 0;
                temp = c;
                c = d % c;
                d = temp;
            }
        
        return std::min(c, d);
    }
}

void Fraction::show() const//��ӡ
{
    if (this->denominator == 1)
        std::cout << this->getnumerator() << std::endl;
    else
    std::cout << this->getnumerator() << "/" << this->getdenominator() << std::endl;
}
//������������������������
Fraction operator+(Fraction& f1, Fraction& f2)
{
    Fraction f;
    if (f1.getdenominator() == f2.getdenominator())
    {
        f.setdenomerator(f1.getdenominator());
        f.setnumerator(f1.getnumerator() + f2.getnumerator());
    }
    else
    {
        int n1{ 0 }, d1{0};
        n1 = f1.getnumerator(), d1 = f1.getdenominator();
        f1.setnumerator(f1.getnumerator() * f2.getdenominator());
        f1.setdenomerator(f1.getdenominator() * f2.getdenominator());
        f2.setdenomerator(f2.getdenominator() * n1);
        f2.setnumerator(f2.getnumerator() * d1);
        f.setnumerator(f1.getnumerator() + f2.getnumerator());
        f.setdenomerator(f1.getdenominator());
        f.simplify();
    }
    return f;
}

Fraction operator-(Fraction& f1, Fraction& f2)
{
    Fraction f;
    if (f1.getdenominator() == f2.getdenominator())
    {
        f.setdenomerator(f1.getdenominator());
        f.setnumerator(f1.getnumerator() - f2.getnumerator());
    }
    else
    {
        int n1{ 0 }, d1{ 0 };
        n1 = f1.getnumerator(), d1 = f1.getdenominator();
        f1.setnumerator(f1.getnumerator() * f2.getdenominator());
        f1.setdenomerator(f1.getdenominator() * f2.getdenominator());
        f2.setdenomerator(f2.getdenominator() * d1);
        f2.setnumerator(f2.getnumerator() * n1);
        f.setnumerator(f1.getnumerator() - f2.getnumerator());
        f.setdenomerator(f1.getdenominator());
        f.simplify();
    }
    return f;
}

Fraction operator/(Fraction& f1, Fraction& f2)
{
    Fraction f;
    f.setnumerator(f1.getnumerator() * f2.getdenominator());
    f.setdenomerator(f1.getdenominator() * f2.getnumerator());
    f.simplify();
    return f;
}

Fraction operator*(Fraction& f1, Fraction& f2)
{
    Fraction f;
    f.setnumerator(f1.getnumerator() * f2.getnumerator());
    f.setdenomerator(f1.getdenominator() * f2.getdenominator());
    f.simplify();
    return f;
}
