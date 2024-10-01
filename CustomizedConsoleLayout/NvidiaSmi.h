#pragma once

#include "CommonPrints.h"



class GPU
{
public:
	String Number;
	String Name;
	String DriverModel;
	String Fan;
	String Temp;
	String Perf;
	String PwrUsage;
	String PwrCap;

	String BusId;
	String DispA;
	String MemoryUsage;
	String MemoryTotal;

	String VolatileUncorrECC;
	String GPUUtil;
	String ComputeM;
	String MIGM;

	GPU(String number,
		String name,
		String driverModel,
		String fan,
		String temp,
		String perf,
		String pwrUsage,
		String pwrCap,
		String busId,
		String dispA,
		String memoryUsage,
		String memoryTotal,
		String volatileUncorrECC,
		String gpuUtil,
		String computeM,
		String migM) :
		Number(number),
		Name(name),
		DriverModel(driverModel),
		Fan(fan),
		Temp(temp),
		Perf(perf),
		PwrUsage(pwrUsage),
		PwrCap(pwrCap),
		BusId(busId),
		DispA(dispA),
		MemoryUsage(memoryUsage),
		MemoryTotal(memoryTotal),
		VolatileUncorrECC(volatileUncorrECC),
		GPUUtil(gpuUtil),
		ComputeM(computeM),
		MIGM(migM) {}
};

class NvidiaSmi
{
public:
	String Version;
	String DriverVersion;
	String CudaVersion;
	std::vector<GPU> GPUs;

	NvidiaSmi(String version,
		String driverVersion,
		String cudaVersion,
		std::vector<GPU> gpus) :
		Version(version),
		DriverVersion(driverVersion),
		CudaVersion(cudaVersion),
		GPUs(gpus) {}

	static void printNvidiaSmiTable(const NvidiaSmi& nvidiaSmi);
};
