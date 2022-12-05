.586
.MODEL FLAT, C
.CODE

PUBLIC C second_dist
second_dist PROC C result1:dword, intervals: dword, result2: dword, x_max: dword, x_min: dword, n_int: dword

push esi
push edi

mov esi, intervals
mov edi, result2
mov ecx, n_int

lp:
    mov eax, [esi] ; ����� ������� ���������
    mov ebx, [esi + 4] ; ������ �������

    cmp eax, x_min ; ���� eax >= x_min
    jge l2
    mov eax, 0 ; �����, eax = 0, ������ ������� result1

    sub ebx, x_min ; ���� ����� ��������� = 0
    jle l4
    jmp l5

    l2:
        sub ebx, eax ; ���������� ��������� � ���������
        cmp ebx, 0 ; ���� ����� ��������� = 0
        je l4
        sub eax, x_min ; ������ ������� �������� �� �������� ��������� � ������� result1

    l5:
        push esi 
        push ecx

        mov ecx, ebx ; ���������� ��������� �� result1 �� ������� ����� ������
        mov esi, result1 ; ������
        mov ebx, 0 ; ������� ����� ���������� ���������

    lp2: ; ����, ������� ����� ���������, �������� � ��������
       add ebx, [esi + 4*eax]
       inc eax
       loop lp2

    pop ecx


    cmp ecx, 1 ; ���� ������������ �� ��������� �������, �� ���������� ����� � ������ ���������
    jne l3
    add ebx, [esi + 4*eax] ; �����, ������ ���������� ��������� ���������, ������� ��������� ��� �������

    l3:

        mov [edi], ebx ; ���������� ���������
        pop esi
        jmp l1

    l4:
        mov [edi], ebx ; ���������� 0, ���� �������� ������

    l1:
        add edi, 4 ; ��������� � ����. ��������� ��������
        add esi, 4
    
    loop lp
   

pop edi
pop esi

ret
second_dist ENDP
END
