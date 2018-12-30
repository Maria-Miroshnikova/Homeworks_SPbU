#pragma once
#include <string>

/// считывает из строки ближайший символ-операцию (*/-+) или цифру,
/// и смещает индекс обращения к строке на этот символ
bool getNewChar(const std::string& data, size_t& i);