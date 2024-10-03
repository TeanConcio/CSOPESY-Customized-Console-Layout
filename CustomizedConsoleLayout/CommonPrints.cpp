#include "CommonPrints.h"



/// <summary>
/// Print current time. Format: Mon Sep 30 22:18:51 2024
/// </summary>
void CommonPrints::printCurrentTime()
{
    // Get the current time
    time_t now = time(0);
    tm ltm;
    // Convert to local time structure
    localtime_s(&ltm, &now);

    // Print the time in the specified format
    std::cout << std::put_time(&ltm, "%a %b %d %H:%M:%S %Y") << std::endl;
}


/// <summary>
/// Print a separator line with the specified size, edge character, line character, middle indices, 
///     and middle character
/// </summary>
/// <param name="size">The total length of the separator line</param>
/// <param name="edgeChar">The character to use at the edges of the separator line</param>
/// <param name="lineChar">The character to use for the main part of the separator line</param>
/// <param name="middleIndices">Indices where the middle character should be placed</param>
/// <param name="middleChar">The character to use at the specified middle indices</param>
void CommonPrints::printSeparator(
    const int size,
    const char edgeChar,
    const char lineChar,
    const std::vector<int>& middleIndices,
    const char middleChar)
{
    // Print the edge character at the start
    std::cout << edgeChar;
    
    // Loop through the size minus the two edge characters
    for (int i = 0; i < size - 2; i++)
    {
        // If the index is in the middleIndices, print the middleChar
        if (std::find(middleIndices.begin(), middleIndices.end(), i) != middleIndices.end())
        {
            std::cout << middleChar;
        }
        else
        {
            // Otherwise, print the lineChar
            std::cout << lineChar;
        }
    }

    // Print the edge character at the end
    std::cout << edgeChar << std::endl;
}


/// <summary>
/// Print a table cell with specified width, text, and alignment
/// </summary>
/// <param name="columnWidth">The width of the column</param>
/// <param name="text">The text to print in the cell</param>
/// <param name="alignment">The alignment of the text 
///     ('l' for left, 'r' for right, 'c' for center)</param>
void CommonPrints::printTableCell(
    const int columnWidth,
    const String& text,
    const char alignment)
{
    switch (alignment)
    {
    case 'l':
        // Print text left-aligned
        std::cout << std::setw(columnWidth) << std::left << text;
        break;
    case 'r':
        // Print text right-aligned
        std::cout << std::setw(columnWidth) << std::right << text;
        break;
    case 'c':
    {
        // Calculate padding for center alignment
        int padding = (columnWidth - text.size()) / 2;
        // Extra padding will be 1 if the difference is odd, 0 otherwise
        int extraPadding = (columnWidth - text.size()) % 2; 
        // Print text centered
        std::cout << std::setw(padding) << "" << text 
            << std::setw(padding + extraPadding) << "";
        break;
    }
    default:
        // Default to left alignment
        std::cout << std::setw(columnWidth) << std::left << text;
        break;
    }
}


/// <summary>
/// Trim leading whitespace from a string
/// </summary>
/// <param name="str">The string to trim</param>
/// <returns>The trimmed string</returns>
String CommonPrints::trimLeadingWhitespace(const String& str) {
    // Find the first non-whitespace character
    size_t start = str.find_first_not_of(" ");
    // Return the substring starting from the first non-whitespace character
    return (start == String::npos) ? "" : str.substr(start);
}


/// <summary>
/// Print a table row with specified items, column widths, spaces, 
///     alignments, and truncation options
/// </summary>
/// <param name="items">The items to print in the row</param>
/// <param name="columnWidths">The widths of the columns</param>
/// <param name="columnSpaces">The spaces between columns</param>
/// <param name="columnAlignments">The alignments of the columns</param>
/// <param name="truncate">Whether to truncate the items if 
///     they exceed column width</param>
/// <param name="truncateLeft">Whether to truncate from 
///     the left or right</param>
void CommonPrints::printTableRow(
    const std::vector<String>& items,
    const std::vector<int>& columnWidths,
    const std::vector<int>& columnSpaces,
    const std::vector<char>& columnAlignments,
    const bool truncate,
    const bool truncateLeft)
{
    // Check for mismatched sizes of items, widths, spaces, and alignments
    if (items.size() != columnWidths.size() ||
        items.size() != columnSpaces.size() ||
        items.size() != columnAlignments.size())
    {
        std::cerr << "Error: Mismatched items, width, space, or alignment sizes." 
            << std::endl;
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
            // If Item is longer than the column width, truncate it
            if (truncatedItems[i].size() > columnWidths[i])
            {
                if (truncateLeft)
                    truncatedItems[i] = "..." + truncatedItems[i].substr(
                        truncatedItems[i].size() - columnWidths[i] + 3);
                else
                    truncatedItems[i] = truncatedItems[i].substr(
                        0, columnWidths[i] - 3) + "...";
            }

            // Print the truncated or original item
            printTableCell(columnWidths[i], truncatedItems[i], 
                columnAlignments[i]);
            // Print the space between columns
            std::cout << String(columnSpaces[i], ' ');
        }

        std::cout << " |\n";
    }
    else
    {
        // While there are items that need to be printed
        std::vector<String> remainingHeaders = items;
        while (std::any_of(remainingHeaders.begin(), remainingHeaders.end(), 
            [](const String& header) { return !header.empty(); }))
        {
            std::cout << "| ";

            // For each column
            for (size_t i = 0; i < columnWidths.size(); i++)
            {
                // If the header is shorter than the column width, 
                // print the header with padding
                if (remainingHeaders[i].size() <= columnWidths[i])
                {
                    // Print the header with padding
                    printTableCell(columnWidths[i], remainingHeaders[i], 
                        columnAlignments[i]);

                    // Empty the header string
                    remainingHeaders[i] = "";
                }
                // If the header is longer than the column width, 
                // print words that fit until the next space and pad the rest
                else
                {
                    // Get index of whitespace that is closest to the column width
                    size_t index = remainingHeaders[i].find_last_of(" ", columnWidths[i]);

                    // If there is no whitespace, chop the string at the column width
                    if (index == String::npos)
                        index = columnWidths[i];

                    // Print the substring that fits the column width with padding
                    printTableCell(columnWidths[i], remainingHeaders[i].substr(
                        0, index), columnAlignments[i]);

                    // Remove the printed substring and trim leading whitespace
                    remainingHeaders[i] = CommonPrints::trimLeadingWhitespace(
                        remainingHeaders[i].substr(index));
                }

                // Print the space between columns
                std::cout << String(columnSpaces[i], ' ');
            }

            std::cout << " |\n";
        }
    }
}
