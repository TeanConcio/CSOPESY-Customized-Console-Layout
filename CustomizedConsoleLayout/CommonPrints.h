#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>



typedef std::string String;

class CommonPrints
{
public:
	static void printCurrentTime();

    static void printSeparator(
        const int size,
        const char edgeChar = '+',
        const char lineChar = '-',
        const std::vector<int>& middleIndices = std::vector<int>(),
        const char middleChar = '+');

    static void printTableCell(
        const int columnWidth,
        const String& text,
        const char alignment = 'l');

    static String trimLeadingWhitespace(const String& str);

    static void printTableRow(
        const std::vector<String>& headers,
        const std::vector<int>& columnWidths,
        const std::vector<int>& columnSpaces,
        const std::vector<char>& columnAlignments,
        const bool truncate = false,
        const bool truncateLeft = true);
};

