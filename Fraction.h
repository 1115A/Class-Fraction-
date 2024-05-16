#pragma once
class Fraction
{
private:
	int numerator;//����
	int denominator;//��ĸ
public:
	int getnumerator() const;//��ú���
	int getdenominator() const;
	Fraction();//���캯��
	Fraction(int numerator, int denominator);
	void setnumerator(int numerator);
	void setdenomerator(int denominator);
	Fraction(Fraction& f1);
	Fraction simplify();
	int func(int& a, int& b)const;
	friend Fraction operator + (Fraction& f1, Fraction& f2);//ͨ����Ԫ�������������
	friend Fraction operator - (Fraction& f1, Fraction& f2);
	friend Fraction operator / (Fraction& f1, Fraction& f2);
	friend Fraction operator * (Fraction& f1, Fraction& f2);
	void show() const;
};




