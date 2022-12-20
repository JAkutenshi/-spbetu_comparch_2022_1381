#include <math.h>
#include <iostream>

long double x,result;
long double two = 2;
long double e = exp(1);

long double cosH(long double result1) {
	__asm {

		; ���������� e^x
		fld x				//�������� ���������� � ���� st
		fld e
		fyl2x				//ST(1) = ST(1) * log2(ST(0))
		fld st				//��������� ST(0) � ����������� ����
		frndint				//��������� ST(0) � ������
		fsub st(1), st		//ST(1) = ST(1) - ST(0)
		fxch st(1)			//����� �������� ST(0) � ST(1)
		f2xm1				//ST(0) = 2^ST(0) - 1
		fld1				//��������� +1.0 � ����������� ����
		faddp st(1), st		//ST(1) = ST(0) + ST(1)
		fscale				//ST(0) = ST(0) * 2^ST(1)
		fstp st(1)			//��������� ST(0) � ST(1)
		fst result1

		; ������� 1 / e^x
		fld1				//��������� +1.0 � ����������� ����
		fdiv result1

		fadd st, st(1)		//��������� e^x + 1 / (e^x)
		fdiv two			//��������� cosh(x)
		fstp result1			//�����
	}

	return result1;
}

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_CTYPE, "rus");

	std::cout << "���������� cosh(x). ������� �������� �:\n";
	std::cin >> x;

	result = cosH(result);

	printf("����������� �������� cosh(x): %lf\n", result);
	return 0;
}