#include "minisyr.h"

struct AddrNamePair
{
	DWORD offset;
	const char* name;

	void ApplyRename() const
	{
		auto pAddress = reinterpret_cast<void*>(offset);
		DWORD protect_flag;
		size_t Len = strlen(name) + 1;
		VirtualProtect(pAddress, Len, PAGE_EXECUTE_READWRITE, &protect_flag);
		memcpy(pAddress, name, Len);
		VirtualProtect(pAddress, Len, protect_flag, NULL);
	}
};

const AddrNamePair Renames[] = {
	{0x00849F48, "Yuri's Revenge"},
	{0x0082668C, "EXPANDMD%02d.MIX"},
	{0x0082621C, "AIMD.INI"},
	{0x00826254, "ARTMD.INI"},
	{0x00826198, "BATTLEMD.INI"},
	{0x008261A8, "BATTLEMD*.INI"},
	{0x008295E8, "%sMD.INI"},
	{0x00825DF0, "EVAMD.INI"},
	{0x00830370, "MAPSELMD.INI"},
	{0x00839724, "MISSIONMD.INI"},
	{0x00826260, "RULESMD.INI"},
	{0x0082626C, "RULEMD*.INI"},
	{0x00825E50, "SOUNDMD.INI"},
	{0x0081C24C, "THEMEMD.MIX"},
	{0x00825D94, "THEMEMD.INI"},
	{0x00826444, "RA2MD.INI"},
	{0x00826614, "ELOCAL*.MIX"},
	{0x00826620, "ECACHE*.MIX"},
	{0x0081C284, "MULTIMD.MIX"},
	{0x00826780, "MULTIMD.MIX"},
	{0x0081C2EC, "MAPSMD%02d.MIX"},
	{0x0082679C, "MAPSMD*.MIX"},
	{0x0081C210, "MOVMD%02d.MIX"},
	{0x008266A0, "MIXFILES\\MOVMD03.MIX"},
	{0x008266B8, "MOVMD03.MIX"},
	{0x008266C4, "MIXFILES\\MOVMD*.MIX"},
	{0x008266D8, "MIXFILES\\MOVMD01.MIX"},
	{0x008266F0, "MOVMD01.MIX"},
	{0x00826748, "MOVMD*.MIX"},
};

DEFINE_HOOK(0x7CD810, ExeRun, 9)
{
	for (const auto& pair : Renames)
		pair.ApplyRename();

	return 0;
}
