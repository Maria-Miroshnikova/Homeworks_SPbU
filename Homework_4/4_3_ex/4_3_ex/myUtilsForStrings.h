#pragma once

/// проверяет, равно ли содержимое двух строк, предположительно разной длины и
/// частично заполненных '\0' и '\n'
bool isSameStrs(char str1[], char str2[]);

/// считывает из буффера строку от start`индекса до end`индекса (не включительно)
void readStr(char str[], char buffer[], int startIndex, int endIndex);

/// возвращает длину настоящего содержимого строки, частично заполненной '\0' и '\n'
int lengthStr(char str[]);