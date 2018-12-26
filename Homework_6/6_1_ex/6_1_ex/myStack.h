#pragma once
#include <vector>

struct Stack;

/// ������� ���� � ���������� ��������� �� ����.
Stack* createStack();

/// ��������� ������� � ������ �����.
void push(Stack* stack, int newValue);

/// ���������� �������� �������� �������� �����, ������ ��� �� �����
int pop(Stack* stack);

/// ������� ����
void deleteStack(Stack* stack);