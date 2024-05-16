#pragma once
class Fraction
{
private:
	int numerator;//分子
	int denominator;//分母
public:
	int getnumerator() const;//获得函数
	int getdenominator() const;
	Fraction();//构造函数
	Fraction(int numerator, int denominator);
	void setnumerator(int numerator);
	void setdenomerator(int denominator);
	Fraction(Fraction& f1);
	Fraction simplify();
	int func(int& a, int& b)const;
	friend Fraction operator + (Fraction& f1, Fraction& f2);//通过友元进行运算符重载
	friend Fraction operator - (Fraction& f1, Fraction& f2);
	friend Fraction operator / (Fraction& f1, Fraction& f2);
	friend Fraction operator * (Fraction& f1, Fraction& f2);
	void show() const;
};




