#pragma once
#include <vector>

struct Stack;

/// ������� ���� � ���������� ��������� �� ����.
Stack* createStack();

/// ��������� ������� � ������ �����.
void push(Stack* stack, int newValue);

/// ���������� �������� �������� �������� �����, ������ ��� �� �����,
/// ���� ���� �� ��� ����, ����� ���������� INT_MIN
int pop(Stack* stack);

/// ������� ����
void deleteStack(Stack* stack);