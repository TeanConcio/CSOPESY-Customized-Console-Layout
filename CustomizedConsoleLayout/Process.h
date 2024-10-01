#pragma once

#include "CommonPrints.h"



class Process {
public:
    String GPU;
    String GIID;
    String CIID;
    String PID;
    String Type;
    String ProcessName;
    String GPUMemoryUsage;

    Process(String gpu, 
        String gi, 
        String ci, 
        String pid, 
        String type, 
        String processName, 
        String gpuMemoryUsage) : 
        GPU(gpu), 
        GIID(gi), 
        CIID(ci), 
        PID(pid), 
        Type(type), 
        ProcessName(processName), 
        GPUMemoryUsage(gpuMemoryUsage) {}

    static void printProcessTable(const std::vector<Process>& processes);
};