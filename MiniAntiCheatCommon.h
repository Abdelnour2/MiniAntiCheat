#pragma once

struct MiniAntiCheatOutput {
	bool isSafeToStart;
};

#define CHECK_BLACKLIST_TO_START CTL_CODE(0x8000, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)