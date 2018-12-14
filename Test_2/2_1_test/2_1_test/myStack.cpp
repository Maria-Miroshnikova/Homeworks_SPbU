#include "myStack.h"
#include <vector>
#include <limits>

struct StackElement
{
	int value;
	StackElement* next;
};

struct Stack
{
	StackElement* head;
};

Stack* createStack()
{
	Stack* stack = new Stack { nullptr };
	return stack;
}

bool isEmptyStack(Stack* stack)
{
	return (stack->head == nullptr);
}

void push(Stack* stack, int newValue)
{
	if (isEmptyStack(stack))
	{
		StackElement* newElement = new StackElement{ newValue, nullptr };
		stack->head = newElement;
		return;
	}
	StackElement* nexElement = stack->head;
	StackElement* newElement = new StackElement{ newValue, nexElement };
	stack->head = newElement;
}

int pop(Stack* stack)
{
	if (isEmptyStack(stack))
	{
		return INT_MIN;
	}

	StackElement* deleteElement = stack->head;
	int deleteNumber = deleteElement->value;
	stack->head = deleteElement->next;
	delete deleteElement;
	return deleteNumber;
}

void deleteStack(Stack* stack)
{
	while (!isEmptyStack(stack))
	{
		pop(stack);
	}
	delete stack;
}