#pragma once

// из трех элементов массива выбирает средний по значению и возвращает его индекс

int middle(int first, int firstIndex, int second, int secondIndex, int third, int thirdIndex);

// ищет в массиве три различных по значению элемента, если находит - возвращает индекс среднего по значению,
// иначе возвращает -1 (если все элементы массива одинаковые) или -2 (если в массиве всего два различных значения)

int medianElement(int sortArray[], int left, int right);

// сортировка вставками

void insertionSort(int sortArray[], int left, int rigth);

// быстрая сортировка

void myQuickSort(int length, int sortArray[], int left, int right);