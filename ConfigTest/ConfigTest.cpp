// ConfigTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
static const string Quote = "\"";
static const string NewLine = "\n";
static const string Comma = ", ";
static const string Tab = "	";

static const string OpenBrakets(const int tabCount)
{
	string tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab;
	}
	return tabs + "{ ";
}

static const string ClosedBraketsComma(const int tabCount)
{
	string tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab;
	}
	return tabs + "},";
}

static const string ClosedBrakets(const int tabCount)
{
	string tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab;
	}
	return tabs + "}";
}

static const string ClosedBraketSemiColon(const int tabCount)
{
	string tabs;
	for (int i = 0; i < tabCount; i++)
	{
		tabs += Tab;
	}
	return NewLine + tabs + "};";
}

static const string ContainerOpen(const int tabCount)
{
	return "[] = " + NewLine + OpenBrakets(tabCount);
}

class WeaponItemBase
{
public:
	WeaponItemBase() {}
	WeaponItemBase(string classname, string nickname, int buyprice, int sellprice, string conditions)
	{
		Classname = classname;
		Nickname = nickname;
		BuyPrice = buyprice;
		SellPrice = sellprice;
		Conditions = conditions;
	}
	string Classname = "Item Classname";
	string Nickname = "Nickname that will appear purely in the shop dialog";
	//Price To buy this at , should always be less then the buy price
	int BuyPrice = 1;
	//To disable selling, this should be - 1
	int SellPrice = 2;
	//Must return boolean
	string Conditions = " ";
	string MakeString(const bool isEndString) const
	{
		const string endString = !isEndString ? ClosedBraketsComma(0) : ClosedBrakets(0);
		return NewLine + OpenBrakets(3) + Quote + Classname + Quote + Comma + Quote + Nickname + Quote + Comma + to_string(BuyPrice) + Comma + to_string(SellPrice) + Comma + Quote + Conditions + Quote + endString;
	}
};

struct ContainerString
{
public:
	ContainerString(string name)
	{
		Name = name;
	}
	vector<WeaponItemBase> ContainerItems;
	string Name = "item";
	void Add(WeaponItemBase weaponItem)
	{
		ContainerItems.push_back(weaponItem);
	}
	string MakeString() const
	{
		string containerString = "";
		for (int i = 0; i < ContainerItems.size(); i++)
		{
			containerString += ContainerItems[i].MakeString(i == ContainerItems.size() - 1);
		}
		return Name + ContainerOpen(2) + containerString + ClosedBraketSemiColon(2);
	}
};

class WeaponShop
{
public:
	WeaponShop(string name)
	{
		_Name = name;
	}
	string _ClassName = "VariableName";
	string _Name = "";
	string _Side = "";
	string _Conditions = "false";
	ContainerString _Items = ContainerString("Items");
	ContainerString _Magazines = ContainerString("Magazines");
	ContainerString _Accesories = ContainerString("Accessories");

	string MakeString() const
	{
		return  NewLine +
			Tab + "class " + _ClassName + Tab + NewLine + OpenBrakets(1) + NewLine +
			Tab + Tab + "name = " + _Name + ";" + NewLine +
			Tab + Tab + "side = " + _Side + ";" + NewLine +
			Tab + Tab + "conditions = " + _Conditions + NewLine +
			Tab + Tab + _Items.MakeString() + NewLine +
			Tab + Tab + _Magazines.MakeString() + NewLine +
			Tab + Tab + _Accesories.MakeString() +
			ClosedBraketSemiColon(1);
	}
};

class WeaponShopConfigs
{
public:
	WeaponShopConfigs(string className)
	{
		_ClassName = className;
	}
	string _ClassName = "VariableName";
	vector<WeaponShop> _Shops;

	string MakeString() const
	{
		string shopsStrings;
		for (int i = 0; i < _Shops.size(); i++)
		{
			shopsStrings += _Shops[i].MakeString();
		}
		return "class " + _ClassName + NewLine + OpenBrakets(0) + shopsStrings + ClosedBraketSemiColon(0);
	}
};

int main()
{
	WeaponShopConfigs _WeaponShopConfig = WeaponShopConfigs("WeaponShops");
	WeaponShop _LegalGunShop = WeaponShop("Billys Gun Shop");
	_LegalGunShop._ClassName = "Shop_GunShop";


	WeaponItemBase rook40 = WeaponItemBase("hgun_Rook40_F", "", 6500, 3250, "");
	WeaponItemBase rook40Magazine = WeaponItemBase("16Rnd_9x21_Mag", "", 6500, 3250, "");
	WeaponItemBase rook40Suppresors = WeaponItemBase("acc_flashlight_pistol", "", 6500, 3250, "");
	WeaponItemBase pistol = WeaponItemBase("hgun_Pistol_01_F", "", 7000, 3500, "");
	_LegalGunShop._Items.Add(rook40);
	_LegalGunShop._Items.Add(pistol);
	_LegalGunShop._Magazines.Add(rook40Magazine);
	_LegalGunShop._Accesories.Add(rook40Suppresors);

	_WeaponShopConfig._Shops.push_back(_LegalGunShop);
	cout << _WeaponShopConfig.MakeString();
}