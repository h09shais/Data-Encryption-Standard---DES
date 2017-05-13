#include <iostream>
#include "DES.h"
#include "mainDES.h"
using namespace std;

int main()
{
	char hexMArr[1000] = "";
	int choice = 0;
	char textM[1000] = "";
	char keyK[17];
	char msgC[1000] = "";
	char tmpMsgC[17] = "";
	char tmphexMArr[17] = "";
	int hexMArrIndex = 0;
	int len;

	char ch;
	ch = generateASCIItoText(89); 

	cout << "Insert your text:: ";
	cin.getline(textM, 1000, '\n');

	cout << "Insert your key:: ";
	cin >> keyK;

	cout << "Insert 1 for DES encryption or 2 for DES decryption:: ";
	cin >> choice;

	if (choice == 1)
	{
		generateHexText(textM, hexMArr);
		strcat(hexMArr, "0D0A");
	}
	else if (choice == 2)
		strcat(hexMArr, textM); 
	else
	{
		cout << "Wrong input !!!" << endl;
		exit(0); 
	}

	len = strlen(hexMArr);  
	while(len >= 0)
	{
		if (len >= 16)
		{
			for (int i = 0 ; i < 16 ; i++)
			{
				tmphexMArr[i] = hexMArr[hexMArrIndex];
				hexMArrIndex++;
			}
			generateMessage(tmphexMArr, keyK, tmpMsgC, choice);
			strcat(msgC, tmpMsgC); 
		}
		else if (len < 16)
		{
			if (choice == 1)
			{
				for (int i = 0 ; i < len ; i++)
				{
					tmphexMArr[i] = hexMArr[hexMArrIndex];
					hexMArrIndex++;
				}
				for (int j = len ; j < 16 ; j++)
					tmphexMArr[j] = '0';
				generateMessage(tmphexMArr, keyK, tmpMsgC, choice);
				strcat(msgC, tmpMsgC);
			}
		}
		len = len - 16;
	}
	
	if(choice == 1)
	{
		cout << "The encrypted form of the text::";
		puts(msgC); 
	}
	else if(choice == 2)
	{
		cout << "The decrypted form of the text::";
		puts(msgC); 
	}

	return 0;
}
