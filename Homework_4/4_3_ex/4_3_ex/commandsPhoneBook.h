#pragma once
#include "myStructures.h"

/// удаляет массив-справочник
void deletePhoneBook(PhoneBookEntry phoneBook[]);

/// выводит содержимое файла "HELP.txt"
void help();

/// выводит все записи из массива-справочника
void outputAllEntries(PhoneBookEntry phoneBook[]);

/// добавляет запись в массив-справочник, увеличив номер последней занятой записи,
/// если такого номера и имени там нет и есть свободное место в массиве, вернув 0,
/// иначе возвращает: 1 - имя уже есть в массиве, 2 - телефон уже есть в массиве,
/// 3 - переполнение массива.
int addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry);

/// ищет номер по заданному имени в массиве строк и возвращает его индекс, если находит,
/// иначе возвращает -1
int findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry);

/// ищет имя по заданному номеру в массиве строк и возвращает его индекс, если находит,
/// иначе возвращает -1
int findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry);

/// записывает весь массив-список в файл "phonebook.txt"
void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry);

/// создает массив-справочник, считывает в него данные из начального файла справочника
/// и возвращает указатель на него
PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook);
