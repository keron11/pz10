#include <iostream>

using namespace std;

// Y = (2000 + х) / (8 * x2 + 25)

int main()
{
	int X = 0;

	__asm {
	m1: inc X		; ситавимо мітку, та збільшуемо аргумент
	mov EAX, 8		; EAX = 8
	imul X			; EAX = 8 * x
	imul X			; EAX = 8 * x^2
	add EAX, 25		; EAX = 8 * x^2 + 25
	mov EDI, EAX	; переносимо EAX до EDI
	mov EAX, 2000	; EAX = 2000
	add EAX, X		; EAX = 2000 + x
	cdq				; розширення операнда - ділимого в EAX - EDX
	div EDI			; часне – EAX, залишок – EDX
	cmp EAX, 10		; перевіряемо
	jg m1			; перехід якщо функція Y менша за 10
	}

	cout << "X = " << X << endl;
}