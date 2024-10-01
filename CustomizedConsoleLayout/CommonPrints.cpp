#include "CommonPrints.h"



/// <summary>
/// Print current time. Format: Mon Sep 30 22:18:51 2024
/// </summary>
void CommonPrints::printCurrentTime()
{
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    std::cout << std::put_time(&ltm, "%a %b %d %H:%M:%S %Y") << std::endl;
}

void CommonPrints::printSeparator(
    const int size,
    const char edgeChar,
    const char lineChar,
    const std::vector<int>& middleIndices,
	const char middleChar)
{
	std::cout << edgeChar;
    
    for (int i = 0; i < size - 2; i++)
	{
		// If the index is in the middleIndices, print the edgeChar
		if (std::find(middleIndices.begin(), middleIndices.end(), i) != middleIndices.end())
		{
			std::cout << middleChar;
		}
		else
		{
			std::cout << lineChar;
		}
	}

    std::cout << edgeChar << std::endl;
}

// Helper function to trim leading whitespace
String CommonPrints::trimLeadingWhitespace(const String& str) {
    size_t start = str.find_first_not_of(" ");
    return (start == String::npos) ? "" : str.substr(start);
}

void CommonPrints::printTableCell(
    const int columnWidth,
    const String& text,
    const char alignment)
{
    switch (alignment)
    {
    case 'l':
        std::cout << std::setw(columnWidth) << std::left << text;
        break;
    case 'r':
        std::cout << std::setw(columnWidth) << std::right << text;
        break;
    case 'c':
    {
        int padding = (columnWidth - text.size()) / 2;
        int extraPadding = (columnWidth - text.size()) % 2; // This will be 1 if the difference is odd, 0 otherwise
        std::cout << std::setw(padding) << "" << text << std::setw(padding + extraPadding) << "";
        break;
    }
    default:
        std::cout << std::setw(columnWidth) << std::left << text;
        break;
    }
}

void CommonPrints::printTableRow(
    const std::vector<String>& items,
    const std::vector<int>& columnWidths,
    const std::vector<int>& columnSpaces,
    const std::vector<char>& columnAlignments,
    const bool truncate,
    const bool truncateLeft)
{
    if (items.size() != columnWidths.size() ||
        items.size() != columnSpaces.size() ||
        items.size() != columnAlignments.size())
    {
        std::cerr << "Error: Mismatched items, width, space, or alignment sizes." << std::endl;
        return;
    }

    // If truncate is true
    if (truncate)
    {
        std::vector<String> truncatedItems = items;

        std::cout << "| ";

        // For each item
        for (size_t i = 0; i < items.size(); i++)
        {
            // If Item is longer than the column width, truncate it from the left with ...
            if (truncatedItems[i].size() > columnWidths[i])
            {
				if (truncateLeft)
					truncatedItems[i] = "..." + truncatedItems[i].substr(truncatedItems[i].size() - columnWidths[i] + 3);
				else
					truncatedItems[i] = truncatedItems[i].substr(0, columnWidths[i] - 3) + "...";
            }

            printTableCell(columnWidths[i], truncatedItems[i], columnAlignments[i]);
            std::cout << String(columnSpaces[i], ' ');
        }

        std::cout << " |\n";
    }

    else
    {
        // While there are items that need to be printed
        std::vector<String> remainingHeaders = items;
        while (std::any_of(remainingHeaders.begin(), remainingHeaders.end(), [](const String& header) { return !header.empty(); }))
        {
            std::cout << "| ";

            // For each column
            for (size_t i = 0; i < columnWidths.size(); i++)
            {
                // If the header is shorter than the column width, print the header with padding
                if (remainingHeaders[i].size() <= columnWidths[i])
                {
                    // Print the header with padding
                    printTableCell(columnWidths[i], remainingHeaders[i], columnAlignments[i]);

                    // Empty the header string
                    remainingHeaders[i] = "";
                }
                // If the header is longer than the column width, print words that fit until the next space and pad the rest
                else
                {
                    // Get index of whitespace that is closest to the column width
                    size_t index = remainingHeaders[i].find_last_of(" ", columnWidths[i]);

                    // If there is no whitespace, chop the string at the column width
                    if (index == String::npos)
                        index = columnWidths[i];

                    // Print the substring that fits the column width with padding
                    printTableCell(columnWidths[i], remainingHeaders[i].substr(0, index), columnAlignments[i]);

                    // Remove the printed substring and trim leading whitespace
                    remainingHeaders[i] = CommonPrints::trimLeadingWhitespace(remainingHeaders[i].substr(index));
                }

                // Print the space between columns
                std::cout << String(columnSpaces[i], ' ');
            }

            std::cout << " |\n";
        }
    }
}
