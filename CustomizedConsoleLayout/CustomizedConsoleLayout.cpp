#include "NvidiaSmi.h"
#include "Process.h"



int main()
{
	CommonPrints::printCurrentTime();

	// Create a vector of GPUs and put it in the NvidiaSmi object
	std::vector<GPU> gpus;
	gpus.push_back(GPU("0", "NVIDIA GeForce RTX 3060 XXXX", "WDDM", 
		"N/A", "49C", "P8", "15W", "105W", "00000000:01:00.0", 
		"On", "578MiB", "6144MiB", "N/A", "2%", "Default", "N/A"));
	gpus.push_back(GPU("1", "NVIDIA GeForce GTX 1080", "WDDM", 
		"N/A", "49C", "P8", "15W", "105W", "00000000:02:00.0", 
		"On", "578MiB", "6144MiB", "N/A", "2%", "Default", "N/A"));
	NvidiaSmi nvidiaSmi("560.94", "560.94", "12.6", gpus);

	NvidiaSmi::printNvidiaSmiTable(nvidiaSmi);
	
	std::cout << std::endl;

	// Create a vector of processes
	std::vector<Process> processes;
    processes.push_back(Process("0", "N/A", "N/A", "1828", "C+G", 
		"XXXXXXXXXXCBS_cw5n1h2txyewy\\TextInputHost.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "4688", "C+G", 
		"XXXXXXXXXXnt.CBS_cw5n1h2txyewy\\SearchHost.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "4728", "C+G", 
		"XXXXXXXXXX22\\Community\\Common7\\IDE\\devenv.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "5156", "C+G", 
		"XXXXXXXXXX Access Service\\ePowerButton_NB.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "5660", "C+G", 
		"XXXXXXXXXX4\\ServiceHub.ThreadedWaitDialog.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "9860", "C+G", 
		"XXXXXXXXXXpaper_engine\\bin\\webwallpaper32.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "10272", "C+G", 
		"XXXXXXXXXX2txyewy\\StartMenuExperienceHost.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "10712", "C+G", 
		"C:\\Windows\\explorer.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "13304", "C+G", 
		"XXXXXXXXXX5n1h2txyewy\\ShellExperienceHost.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "16280", "C+G", 
		"XXXXXXXXXBrave-Browser\\Application\\brave.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "17116", "C+G", 
		"XXXXXXXXXXogram Files\\Notepad++\\notepad++.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "17464", "C+G", 
		"XXXXXXXXXXsiveControlPanel\\SystemSettings.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "20620", "C+G", 
		"XXXXXXXXXX__8wekyb3d8bbwe\\WindowsTerminal.exe", "N/A"));
	processes.push_back(Process("0", "N/A", "N/A", "20992", "C+G", 
		"XXXXXXXXXXon\\129.0.2792.65\\msedgewebview2.exe", "N/A"));
	
	Process::printProcessTable(processes);
}
