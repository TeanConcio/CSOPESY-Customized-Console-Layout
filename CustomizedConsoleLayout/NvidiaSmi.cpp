#include "NvidiaSmi.h"



void NvidiaSmi::printNvidiaSmiTable(const NvidiaSmi& nvidiaSmi)
{
	// Initialize the table layout
	std::vector<String> SmiHeaders = { "NVIDIA-SMI " + nvidiaSmi.Version, "Driver Version: " + nvidiaSmi.DriverVersion, "CUDA Version: " + nvidiaSmi.CudaVersion };
	std::vector<int> SmiColumnWidths = { 33, 30, 22 };
	std::vector<int> SmiColumnSpaces =   { 1,  1,  0 };
	std::vector<char> SmiColumnAlignments = { 'l', 'l', 'l' };

	std::vector<String> GpuHeaders1 = { "GPU", "Name", "Driver-Model", "|", "Bus-Id", "Disp.A", "|", "Volatile Uncorr. ECC"};
	std::vector<int> GpuColumnHeaderWidths1 = { 3, 20, 12, 1, 14, 6, 1, 20 };
	std::vector<int> GpuColumnHeaderSpaces1 =        { 2,  2,  1, 1,  2, 1, 1,  0 };
	std::vector<char> GpuColumnHeaderAlignments1 = { 'l', 'l', 'l', 'l', 'l', 'l', 'l', 'l' };

	std::vector<String> GpuHeaders2 = { "Fan", "Temp", "Perf", "Pwr:Usage/Cap", "|", "Memory-Usage", "|", "GPU-Util", "Compute M."};
	std::vector<int> GpuColumnHeaderWidths2 = { 3, 5, 4, 21, 1, 22, 1, 8, 10 };
	std::vector<int> GpuColumnHeaderSpaces2 =  { 2, 2, 2,  1, 1,  1, 1, 2,  0 };
	std::vector<char> GpuColumnHeaderAlignments2 = { 'l', 'l', 'l', 'r', 'l', 'r', 'l', 'l', 'l' };

	std::vector<String> GpuHeaders3 = { "|", "|", "MIG M." };
	std::vector<int> GpuColumnHeaderWidths3 = { 41, 24, 20 };
	std::vector<int> GpuColumnHeaderSpaces3 =   { 1,  1,  0 };
	std::vector<char> GpuColumnHeaderAlignments3 = { 'r', 'r', 'r' };

	std::vector<int> GpuColumnItemWidths1 = { 3, 27, 5, 1, 18, 2, 1, 20 };
	std::vector<char> GpuColumnItemAlignments1 = { 'r', 'l', 'l', 'l', 'r', 'l', 'l', 'r' };

	std::vector<int> GpuColumnItemWidths2 = { 3, 5, 4, 5, 1, 5, 1, 9, 1, 9, 1, 7, 11 };
	std::vector<int> GpuColumnItemSpaces2 =  { 2, 2, 10,1, 1, 1, 2, 1, 1, 1, 1, 2,  0 };
	std::vector<char> GpuColumnItemAlignments2 = { 'r', 'c', 'c', 'r', 'l', 'r', 'l', 'r', 'l', 'r', 'l', 'r', 'r' };

	// Print the headers
	CommonPrints::printSeparator(91);
	CommonPrints::printTableRow(
		SmiHeaders,
		SmiColumnWidths,
		SmiColumnSpaces,
		SmiColumnAlignments);
	CommonPrints::printSeparator(91, '|', '-', { 41, 66 });
	CommonPrints::printTableRow(
		GpuHeaders1,
		GpuColumnHeaderWidths1,
		GpuColumnHeaderSpaces1,
		GpuColumnHeaderAlignments1);
	CommonPrints::printTableRow(
		GpuHeaders2,
		GpuColumnHeaderWidths2,
		GpuColumnHeaderSpaces2,
		GpuColumnHeaderAlignments2);
	CommonPrints::printTableRow(
		GpuHeaders3,
		GpuColumnHeaderWidths3,
		GpuColumnHeaderSpaces3,
		GpuColumnHeaderAlignments3);
	CommonPrints::printSeparator(91, '|', '=', { 41, 66 });

	// Print the data
	for (const GPU& gpu : nvidiaSmi.GPUs)
	{
		std::vector<String> items1 = {
			gpu.Number,
			gpu.Name,
			gpu.DriverModel,
			"|",
			gpu.BusId,
			gpu.DispA,
			"|",
			gpu.VolatileUncorrECC
		};

		std::vector<String> items2 = {
			gpu.Fan,
			gpu.Temp,
			gpu.Perf,
			gpu.PwrUsage,
			"/",
			gpu.PwrCap,
			"|",
			gpu.MemoryUsage,
			"/",
			gpu.MemoryTotal,
			"|",
			gpu.GPUUtil,
			gpu.ComputeM
		};

		std::vector<String> items3 = {
			"|",
			"|",
			gpu.MIGM
		};

		CommonPrints::printTableRow(
			items1,
			GpuColumnItemWidths1,
			GpuColumnHeaderSpaces1,
			GpuColumnItemAlignments1,
			true, false);

		CommonPrints::printTableRow(
			items2,
			GpuColumnItemWidths2,
			GpuColumnItemSpaces2,
			GpuColumnItemAlignments2,
			true, false);

		CommonPrints::printTableRow(
			items3,
			GpuColumnHeaderWidths3,
			GpuColumnHeaderSpaces3,
			GpuColumnHeaderAlignments3,
			true);
	}

	CommonPrints::printSeparator(91, '+', '-', { 41, 66 });
}