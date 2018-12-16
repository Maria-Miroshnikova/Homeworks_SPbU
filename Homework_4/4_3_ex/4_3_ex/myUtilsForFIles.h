#pragma once
#include "myStructures.h"

/// записывает одну запись в файл
void saveEntry(PhoneBookEntry entry, FILE *phonebook);

/// считывает телефонный справочник из файла (если он нашелся) в массив-справочник
void readStartPhoneBook(PhoneBookEntry phoneBook[], int *indexLastEntry, FILE *phonebook);

/// выводит содержимое файла
void outputFile(FILE *file);