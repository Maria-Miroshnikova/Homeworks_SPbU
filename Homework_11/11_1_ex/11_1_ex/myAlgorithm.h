#pragma once
#include <string>

/// вычисляет позицию первого вхождения образца в строку
/// и возвращает ее, если образец встретился, иначе возвращает -1
int findFirstMeeting(const std::string& data, const std::string& sample);