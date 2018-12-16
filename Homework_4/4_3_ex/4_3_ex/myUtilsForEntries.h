#pragma once
#include "myStructures.h"

/// для строки вида "<name>: <phone>" возвращает индекс двоеточия в ней
int parseStrToPartOfEntry(char str[]);

/// проверяет наличие в строке, которую нужно преобразовать в запись,
/// наличие последовательности "<буква>: <не пробел>"
bool isCorrectEntry(char str[]);

/// разбивает строку на имя и телефон, формирует из них запись и возвращает ее
PhoneBookEntry createEntry(char buffer[], int maxLength);

/// проверяет запись на пустоту
bool isEmptyEntry(PhoneBookEntry entry);

/// меняет местами две записи в массиве-справочнике
void swapEntries(PhoneBookEntry phonebook[], int index1, int index2);

/// сравнивает части имен до пробелов, если части до пробелов совпали, возвращает индекс пробела
int comparePartsOfNames(char str1[], char str2[], int indexStart);

/// возвращает номер + 1 той строки, которая должна идти первой  алфавитном порядке,
/// и 1, если имена равны
int compareStr(char str1[], char str2[]);

/// находит для новой записи место в телефонной книге в алфавитном порядке, вставляет ее на нужное место
void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry);

/// ищет в массиве-списке элемент, совпадающий с данным, и возвращает его индекс в массиве, если такой нашелся,
/// иначе возвращает -1. Если key == 1, ищет по имени, если key == 0, ищет по телефону.
int searchEntry(PhoneBookEntry phoneBook[], char str[], bool key, int indexLastEntry);