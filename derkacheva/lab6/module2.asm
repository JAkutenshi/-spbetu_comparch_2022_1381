.586
.MODEL FLAT, C
.CODE
PUBLIC C module2
module2 PROC C distr: dword, interv: dword, min: dword, max: dword, res: dword, med: dword

push esi
push edi
push eax
push ebx
push ecx 

mov esi, res
mov edi, interv
mov eax, min
mov ebx, 0
mov ecx, 0


Start:
cmp eax, [edi+4*ebx] ;���������� ��� � �������� ���������
jl Act				 ;��� ������ ������� ��������� � ���
add ebx, 1			 ; ���� ��������� 
jmp Start

Act:
	push eax
	push edi

	mov edi, distr
	sub ebx, 1
	mov eax, [esi+4*ebx] ;����� ������(�����)
	mov edx, [edi+4*ecx] ;��������� ������(���������)
	add eax, edx 
	mov [esi+4*ebx], eax ;� ����� �������� ����� �������� � ����������� �����
	pop edi

	push edi
	push edx
	mov edi, med

	test eax, 1
	jnz ad
	jz cont
ad:
	add eax, 1
cont:
	mov [edi+4*ebx], eax
	pop edx
	pop edi

	pop eax


		push ecx
		mov ecx, max
		cmp eax, ecx ; ���������� ��� � ���
		pop ecx
		je final

	add ecx, 1 ; � ���������� ������.
	add eax, 1 ; �������
	jmp Start

final:
	pop eax
	pop ebx
	pop ecx
	pop edi
	pop esi	
	ret
module2 ENDP
END