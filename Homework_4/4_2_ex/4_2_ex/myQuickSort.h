#pragma once

// �� ���� ��������� ������� �������� ������� �� �������� � ���������� ��� ������

int middle(int first, int firstIndex, int second, int secondIndex, int third, int thirdIndex);

// ���� � ������� ��� ��������� �� �������� ��������, ���� ������� - ���������� ������ �������� �� ��������,
// ����� ���������� -1 (���� ��� �������� ������� ����������) ��� -2 (���� � ������� ����� ��� ��������� ��������)

int medianElement(int sortArray[], int left, int right);

// ���������� ���������

void insertionSort(int sortArray[], int left, int rigth);

// ������� ����������

void myQuickSort(int length, int sortArray[], int left, int right);