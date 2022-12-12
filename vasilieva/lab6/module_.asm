.686
.MODEL FLAT, C 
.CODE

PUBLIC C func
func PROC C intervals: dword, N_int: dword, N: dword, numbers: dword, final_answer: dword
	push esi
	push edi
	push eax
	push ebx
	push ecx
	push edx

	mov esi, numbers ;������ ��������������� �����
	mov edi, final_answer ;�������� �������
	mov eax, 0 ;���������� ���������� �������� � ��������������� �������

	start:
		mov ebx, [esi + 4*eax] ;������� ����� �� ������� ��������������� �����
		push esi
		mov ecx, N_int ;����������, ������������� ����������

		mov esi, intervals 
		cmp [esi + 4*ecx], ebx ;���� ����� ��������� ����� ������ �������� � ���� �������� ���������
		jl finish 
		dec ecx 

		border: ;���� �������� ��� ���������� ������� ���������(����������� ���� �� ����� ������ ������)
			cmp ebx, [esi + 4*ecx] ; ���� ������ ����� ������ ��������� ����� �������
			jge print ;������� � ������
			dec ecx ; �������� �� ���������� ���������� ����
			jmp border 

		print: ;������ � �������� ������
			mov esi, final_answer
			mov ebx, [esi + 4*ecx] ;����� ����� �� ��������� �������

			inc ebx ;����������� �� ���� ����� �� ��������� �������
			mov [edi + 4*ecx], ebx ;������ �������

		finish:
			pop esi
			inc eax ;����������� �� ����
			cmp eax, N ;���� ���� ������ ����� ��������� (���������� �����)
			jne start ;���� ��� ���������� ��������� �� ������� �����

	pop edx
	pop ecx
	pop ebx
	pop eax
	pop edi
	pop esi
ret
func ENDP
END
