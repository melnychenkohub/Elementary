#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
#include "GlobalStruct.h"
#include "ExceptionFunc.h"
#include "List.BinTree.Creating.h"
#include "PrintDynamicDataStructure.h"
#include "CreateElement.h"
#include "FillElement.h"
#include "PrintElement.h"

void CreateAndAddToListMenu(Bus **const pBegInPark, Bus **const pEndInPark, Bus **const pBegOnRoute, Bus **const pEndOnRoute)
{
	int    choice = 0;
	string strExcptn;

	do
	{
		cout << "Create/add list/new bus:\n";
		cout << "1. In Park;\n";
		cout << "2. On Route;\n";
		cout << "3. Quit from this;\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choice);

		if (3 == choice)
		{
			break;
		}

		if (1 > choice || 3 < choice)
		{
			cout << "Incorrect input. Try again;\n";
			continue;
		}

		Bus *bus = CreateElementBus();
		FillElement(*bus);

		switch (choice)
		{
		case 1:
			ListCreating(pBegInPark, pEndInPark, bus);
			break;

		case 2:
			ListCreating(pBegOnRoute, pEndOnRoute, bus);
			break;
		}

		cout << "-----------------------------------------------------\n";
		cout << "\nIn PARK:\n\n";
		PrintList(*pBegInPark);
		cout << "\nOn ROUTE:\n\n";
		PrintList(*pBegOnRoute);
	} while (true);
}

void CreateAndAddToBinTreeMenu(DictItem **const root)
{
	int    choice = 0;
	string strExcptn;

	do
	{
		cout << "Create binary tree/add to binary tree element:\n";
		cout << "1. OK;\n";
		cout << "2. Quit from this;\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choice);

		if (2 == choice)
		{
			break;
		}

		if (1 != choice)
		{
			cout << "Incorrect input. Try again;\n";
			continue;
		}

		DictItem *dictItem = CreateElementDict();

		switch (choice)
		{
		case 1:
			FillElement(*dictItem);
			BinaryTreeCreating(root, &dictItem);
			PrintElement(*dictItem);
			break;
		}
	} while (true);
}
