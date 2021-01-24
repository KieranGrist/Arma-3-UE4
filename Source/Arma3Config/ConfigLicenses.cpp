#include "ConfigLicenses.h"
#include "LicenseItem.h"


FString UConfigLicenses::MakeString()
{
	FString ret = ClassString("Housing", _ClassTabs);
	ret += ClassString(MapName(), _ClassTabs);
	for (ULicenseItem* item : _Licenses)
	{
		ret += item->MakeString();
	}
	ret += ClosedBracketSemiColon();
	return ret;
}

void UConfigLicenses::UpdateConfigText()
{
	_ConfigText = MakeString();
}
