/*�ڰ��� ����̽�� ����ѧϰ*/
#include "stdafx.h"

template<typename T>
inline T square(const T x) { return x*x; };

void swapr(int &a, int & b);
void swapp(int *p, int * q);
void swapv(int a, int b);
double refcube(const double&);
char* left(const char* , int);
unsigned long left(unsigned long, unsigned);

void chapter8()
{
	//using namespace std;
	////�������� 8.1
	//double a, b;
	//double c = 12.3;
	//a = square<double>(5.0);
	//b = square<double>(4.5+7.5);
	//std::cout << "a = " << a << ",b=" << b << "\n";
	//std::cout << "c=" << c << "c squared =" << square(c++) << std::endl;
	//std::cout << "Now c = " << c << std::endl;
	////���ñ��� 
	//int rats = 100;
	//int & rodents = rats;	//���ñ�������������ʱ�ͳ�ʼ��,�Ҳ����޸�
	////���ñ���ͬ����ָ���Ч	(rodents = *pr1)
	//int const * pr1 = &rats;	//����ָ��
	//int  * const pr2 = &rats;	//ָ�볣��
	//const int * pr3 = &rats;	//����ָ��,ͬpr1
	//pr1 = &rats;
	////pr2 = &rats;		//ָ�볣��,���ܱ��޸�
	//pr3 = &rats;
	//cout << "rats = " << rats << " at " << &rats << endl;
	//cout << "rodents = " << rodents << " at " << &rodents << endl;
	//cout << "pr1 = " << pr1 << " *pr1 = " << *pr1 << endl;
	//cout << "pr2 = " << pr2 << " *pr2 = " << *pr2 << endl;
	//cout << "pr3 = " << pr3 << " *pr3 = " << *pr3 << endl;

	//int a2 = 100;
	//int b2 = 200;
	//cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapr(a2, b2);
	//cout << "After swapr, a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapp(&a2, &b2);
	//cout << "After swapp, a2 = " << a2 << ", b2 = " << b2 << endl;
	//swapv(a2, b2);
	//cout << "After swapv, a2 = " << a2 << ", b2 = " << b2 << endl;
	////��ʱ����
	//double side = 3.0;
	//double* pd = &side;
	//double& rd = side;
	//long edge = 5L;
	//double lens[4] = { 2.0,5.0,10.0,12.0 };
	//double c1 = refcube(side);
	//double c2 = refcube(*pd);		//���ָ������
	//double c3 = refcube(lens[2]);	//����Ԫ��
	//double c4 = refcube(rd);		//���ñ���
	//double c5 = refcube(edge);		//��ʱ����
	//double c6 = refcube(7.0);		//��ʱ����
	//double c7 = refcube(side + 10.0);//��ʱ����
	////��ֵ����
	//double && rref = sqrt(36.00);
	//double j = 15.0;
	//double&& jref = 2.0 * j + 18.5;
	//cout << "rref = " << rref << "\n";
	//cout << "jref = " << jref << "\n";

	//��������
	char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++) {
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}

};

void swapr(int &a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
};
void swapp(int *p, int * q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
};
void swapv(int a, int b) {	//�޷��������ú�����a,b��ֵ
	int temp;
	temp = a;
	a = b;
	b = temp;
};
double refcube(const double& ra) {	//������ʹ��const
	return ra * ra * ra;
}

char* left(const char* trip, int n) {
	if (n < 0)	
		n = 0;
	cout << n;
	char *p = new char [n+1];
	int i;
	for (i = 0; i < n; i++) {
		p[i] = trip[i];
	}
	while (i <= n)
		p[i++] = '\0';
	return p;
};

unsigned long left(unsigned long num, unsigned ct) {
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits > ct) {
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
};