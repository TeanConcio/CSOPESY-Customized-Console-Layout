#include "Process.h"



void Process::printProcessTable(const std::vector<Process>& processes)
{
	// Initialize the table layout
    std::vector<String> headers = { "GPU", "GI ID", "CI ID", "PID", "Type", "Process name", "GPU Memory Usage" };
    std::vector<int> columnHeaderWidths = { 4, 4, 3, 8, 5, 38, 10 };
    std::vector<int> columnHeaderSpaces =  { 2, 2, 2, 2, 3,  4,  0 };
    std::vector<char> columnHeaderAlignments = { 'r', 'c', 'l', 'r', 'r', 'l', 'l' };

    std::vector<int> columnItemWidths = { 4, 4, 3, 8, 5, 38, 13 };
    std::vector<int> columnItemSpaces =  { 2, 2, 2, 2, 3,  1,  0 };
    std::vector<char> columnItemAlignments = { 'r', 'r', 'r', 'r', 'r', 'l', 'c' };

    // Print the header
    CommonPrints::printSeparator(91);
    std::cout << "| ";
    CommonPrints::printTableCell(87, "Processes:", 'l');
    std::cout << " |\n";
    CommonPrints::printTableRow(
        headers,
        columnHeaderWidths,
        columnHeaderSpaces,
        columnHeaderAlignments);
    CommonPrints::printSeparator(91, '|', '=');

    // Print the data
    for (const Process& process : processes)
    {
		std::vector<String> items = {
			process.GPU,
			process.GIID,
			process.CIID,
			process.PID,
			process.Type,
			process.ProcessName,
			process.GPUMemoryUsage
		};

		CommonPrints::printTableRow(
			items,
			columnItemWidths,
			columnItemSpaces,
			columnItemAlignments,
			true);
    }

    CommonPrints::printSeparator(91);
}
