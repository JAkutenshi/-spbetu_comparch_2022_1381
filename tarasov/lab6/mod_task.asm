.586
.MODEL FLAT, C
.CODE
FUNC PROC C array:dword, array_size:dword, left_borders:dword, interval_amount:dword, result_array:dword, even_array:dword
push ecx
push esi
push edi
push eax
push ebx

mov ecx, array_size
mov esi, array
mov edi, left_borders
mov eax, 0
l1:
	mov ebx, 0; �������� ebx ��� ������ ���-�� ����������
	borders:
 		cmp ebx, interval_amount; ���� ebx ������ ���� ����� ���-�� ����������
		jge borders_exit; �� �������
		push eax
		mov eax, [esi+4*eax]; ����� � eax ������� �� array
		cmp eax, [edi+4*ebx]; ���������� ������� ������� � ���� �� left_borders
		pop eax
		jl borders_exit; ���� ������� ������ ����� �������, �� �������
		inc ebx; ���� ��������� ��������
		jmp borders
	borders_exit:
	dec ebx; ������������ �� ���������� ��������

	cmp ebx, -1; ���� ebx ����� -1, �� ������� �� ����������� �� ������ �� ����������
	je skip; ���� ebx >= 0, �� ������� ����������� ������-���� ��������� 
	mov edi, result_array; ��������������� ������� ��������������� ������� ����������� �� 1
	push eax
	mov eax, [edi+4*ebx]
	inc eax
	mov [edi+4*ebx], eax
	pop eax
	push eax
	mov edi, even_array
	mov eax, [esi + 4 * eax]
	test eax, 1
	jnz not_even
	mov eax, [edi+4*ebx]
	inc eax
	mov [edi+4*ebx], eax
	not_even:
	pop eax
	mov edi, left_borders
	skip:
	inc eax; ��������� ������� �������
loop l1; ���� ecx(������ �������) != 0

pop ebx
pop eax
pop edi
pop esi
pop ecx
ret
FUNC ENDP
END