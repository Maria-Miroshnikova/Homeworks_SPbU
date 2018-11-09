#pragma once

/// принимает строку чисел из файла, режет на числа, сравнивает их с контрольным числом
/// и записывает в итоговый файл, если число из файта оказывается меньше контрольного
void workingWithData(FILE *inputData, FILE *outputData, int compareNumber);

/// считывает контрольное число из файла, предполагая, что в нем содержится одно число
int readNumberFromFile(FILE *inputData, int maxLength);