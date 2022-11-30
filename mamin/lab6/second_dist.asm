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
    mov eax, [esi] ; левая граница интервала
    mov ebx, [esi + 4] ; правая граница

    cmp eax, x_min ; если eax >= x_min
    jge l2
    mov eax, 0 ; иначе, eax = 0, начало массива result1

    sub ebx, x_min ; если длина интервала = 0
    jle l4
    jmp l5

    l2:
        sub ebx, eax ; количество элементов в интервале
        cmp ebx, 0 ; если длина интервала = 0
        je l4
        sub eax, x_min ; индекс первого элемента из текущего интервала в массиве result1

    l5:
        push esi 
        push ecx

        mov ecx, ebx ; количество элементов из result1 по которым нужно пройти
        mov esi, result1 ; массив
        mov ebx, 0 ; считает сумму подходящих элементов

    lp2: ; цикл, считает сумму элементов, входящих в интервал
       add ebx, [esi + 4*eax]
       inc eax
       loop lp2

    pop ecx


    cmp ecx, 1 ; если обрабатывали не последний элемент, то записываем сумму в массив результат
    jne l3
    add ebx, [esi + 4*eax] ; иначе, скобка последнего интервала вадратная, поэтому добавляем еще элемент

    l3:

        mov [edi], ebx ; записываем результат
        pop esi
        jmp l1

    l4:
        mov [edi], ebx ; записываем 0, если интервал пустой

    l1:
        add edi, 4 ; двигаемся к след. элементам массивов
        add esi, 4
    
    loop lp
   

pop edi
pop esi

ret
second_dist ENDP
END
