#include "Configs/ConfigProcess.h"
#include "Items/ProcessItem.h"

FString UConfigProcess::MakeString()
{
	FString ret = ClassString("ProcessAction", _ClassTabs);
	for (UProcessItem* item : _ProcessActions)
	{
		item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigProcess::UpdateConfigText()
{
	_ConfigText = MakeString();
}
