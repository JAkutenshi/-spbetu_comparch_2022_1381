.586
.MODEL FLAT, C
.CODE
first PROC C arr:dword, Xmin:dword, result_array:dword, length_:dword

mov eax, arr
mov ebx, result_array
mov ecx, length_
xor edx, edx
xor edi, edi

cycle:
	mov edi, [eax + 4 * edx] ;��������
	sub edi, Xmin
	inc dword ptr [ebx + 4 * edi] ;���������� �������� �����
	inc edx ;��������� ��������
	loop CYCLE
finish:
	ret
	first endp
	end
