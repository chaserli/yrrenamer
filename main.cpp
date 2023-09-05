#include "minisyr.h"

void ApplyRename(uintptr_t offset, const char *str)
{
    auto pAddress = reinterpret_cast<void *>(offset);
    DWORD protect_flag;
    size_t Len = strlen(str) + 1;
    VirtualProtect(pAddress, Len, PAGE_EXECUTE_READWRITE, &protect_flag);
    memcpy(pAddress, str, Len);
    VirtualProtect(pAddress, Len, protect_flag, NULL);
}

DEFINE_HOOK(0x7CD810, ExeRun, 9)
{
    ApplyRename(0x00849F48, "Yuri's Revenge");
    ApplyRename(0x0082668C, "EXPANDMD%02d.MIX");
    ApplyRename(0x0082621C, "AIMD.INI");
    ApplyRename(0x00826254, "ARTMD.INI");
    ApplyRename(0x00826198, "BATTLEMD.INI");
    ApplyRename(0x008261A8, "BATTLEMD*.INI");
    ApplyRename(0x008295E8, "%sMD.INI");
    ApplyRename(0x00825DF0, "EVAMD.INI");
    ApplyRename(0x00830370, "MAPSELMD.INI");
    ApplyRename(0x00839724, "MISSIONMD.INI");
    ApplyRename(0x00826260, "RULESMD.INI");
    ApplyRename(0x0082626C, "RULEMD*.INI");
    ApplyRename(0x00825E50, "SOUNDMD.INI");
    ApplyRename(0x0081C24C, "THEMEMD.MIX");
    ApplyRename(0x00825D94, "THEMEMD.INI");
    ApplyRename(0x00826444, "RA2MD.INI");
    ApplyRename(0x00826614, "ELOCAL*.MIX");
    ApplyRename(0x00826620, "ECACHE*.MIX");
    ApplyRename(0x0081C284, "MULTIMD.MIX");
    ApplyRename(0x00826780, "MULTIMD.MIX");
    ApplyRename(0x0081C2EC, "MAPSMD%02d.MIX");
    ApplyRename(0x0082679C, "MAPSMD*.MIX");
    ApplyRename(0x0081C210, "MOVMD%02d.MIX");
    ApplyRename(0x008266A0, "MIXFILES\\MOVMD03.MIX");
    ApplyRename(0x008266B8, "MOVMD03.MIX");
    ApplyRename(0x008266C4, "MIXFILES\\MOVMD*.MIX");
    ApplyRename(0x008266D8, "MIXFILES\\MOVMD01.MIX");
    ApplyRename(0x008266F0, "MOVMD01.MIX");
    ApplyRename(0x00826748, "MOVMD*.MIX");

    return 0;
}
