#pragma once

/// ищет первый (наименьший) наиболее часто встречающийся элемент в отсортированном массиве
int findOftenElement(int length, int sortArray[]);

/// меняет местами два элемента массива
void swap(int sortArray[], int index1, int index2);

/// заполняет массив рандомными элементами по заданному модулю с добавочной константой
void inputRandomArray(int length, int block[], int mod, int constant);

/// выводит массив на экран целиком
void outputArray(int length, int block[]);