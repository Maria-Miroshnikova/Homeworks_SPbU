#pragma once
#include <vector>

struct Stack;

/// создает стэк и возвращает указатель на него.
Stack* createStack();

/// добавляет элемент в начало стэка.
void push(Stack* stack, int newValue);

/// возвращает значение верхнего элемента стэка, удалив его из стэка
int pop(Stack* stack);

/// удаляет стэк
void deleteStack(Stack* stack);