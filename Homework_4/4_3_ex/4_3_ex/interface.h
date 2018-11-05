#pragma once
#include "myStructures.h"

/// выводит имя из массива-справочника
void outputName(PhoneBookEntry entry);

/// выводит телефон из массива-справочника
void outputPhone(PhoneBookEntry entry);

/// выводит запись из массива-справочника
void outputEntry(PhoneBookEntry entry);

/// принимает строку для преобразования в запись,
/// если строка некорректна - выводит сообщение об ошибке и предлагает ввести строку снова.
PhoneBookEntry getEntry(int maxLength);

/// принимает команды до тех пор, пока команда не нулевая, и распознает их
void getCommand(PhoneBookEntry phoneBook[], int *indexLastEntry);