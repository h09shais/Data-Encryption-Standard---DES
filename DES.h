#ifndef __DES_h__
#define __DES_h__


	int S1[4][16] = 
{
		{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
		{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
		{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
		{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
	};

	int S2[4][16] = 
{
		{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
		{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
		{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
		{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
	};
	int S3[4][16] = 
{
		{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
		{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
		{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
		{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
	};

	int S4[4][16] = 
{
		{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
		{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
		{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
		{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
	};
	int S5[4][16] = 
{
		{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
		{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
		{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
		{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
	};
	int S6[4][16] = 
{
		{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
		{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
		{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
		{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
	};
	int S7[4][16] = 
{
		{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
		{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
		{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
		{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
	};
	int S8[4][16] = 
{
		{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
		{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
		{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
		{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
	};
	int P[8][4] = 
{
		{16, 7, 20, 21},
		{29, 12, 28, 17},
		{1, 15, 23, 26},
		{5, 18, 31, 10},
		{2, 8, 24, 14},
		{32, 27, 3, 9},
		{19, 13, 30, 6},
		{22, 11, 4, 25}
	};
	
	char convTable[16][5] = 
{
		{'0','0','0','0','0'},
		{'1','0','0','0','1'},
		{'2','0','0','1','0'},
		{'3','0','0','1','1'},
		{'4','0','1','0','0'},
		{'5','0','1','0','1'},
		{'6','0','1','1','0'},
		{'7','0','1','1','1'},
		{'8','1','0','0','0'},
		{'9','1','0','0','1'},
		{'A','1','0','1','0'},
		{'B','1','0','1','1'},
		{'C','1','1','0','0'},
		{'D','1','1','0','1'},
		{'E','1','1','1','0'},
		{'F','1','1','1','1'}
	}; 
	
	int EbitSelectionTable[8][6] = 
{
		{32, 1, 2, 3, 4, 5},
		{4, 5, 6, 7, 8, 9},
		{8, 9, 10, 11, 12, 13},
		{12, 13, 14, 15, 16, 17},
		{16, 17, 18, 19, 20, 21},
		{20, 21, 22, 23, 24, 25},
		{24, 25, 26, 27, 28, 29},
		{28, 29, 30, 31, 32, 1}
	};
char binTohex(char str[])
{
	if(strcmp(str, "0000") == 0)
		return '0';
	else if(strcmp(str, "0001") == 0)
		return '1';
	else if(strcmp(str, "0010") == 0)
		return '2';
	else if(strcmp(str, "0011") == 0)
		return '3';
	else if(strcmp(str, "0100") == 0)
		return '4';
	else if(strcmp(str, "0101") == 0)
		return '5';
	else if(strcmp(str, "0110") == 0)
		return '6';
	else if(strcmp(str, "0111") == 0)
		return '7';
	else if(strcmp(str, "1000") == 0)
		return '8';
	else if(strcmp(str, "1001") == 0)
		return '9';
	else if(strcmp(str, "1010") == 0)
		return 'A';
	else if(strcmp(str, "1011") == 0)
		return 'B';
	else if(strcmp(str, "1100") == 0)
		return 'C';
	else if(strcmp(str, "1101") == 0)
		return 'D';
	else if(strcmp(str, "1110") == 0)
		return 'E';
	else if(strcmp(str, "1111") == 0)
		return 'F';
}
void decTobinForText(int decimal, char binArray[])
{
	char temp[70];
	int remainder, binArrayIndex = 0, tempIndex = 0;
	
	do
	{
		remainder = decimal % 2;
		decimal = decimal / 2;

		temp[tempIndex++] = remainder + '0';
	}while (decimal > 0);

	while (tempIndex >= 0)
		binArray[binArrayIndex++] = temp[--tempIndex];
	binArray[binArrayIndex - 1] = 0;
}

int getPosition(char ch)
{
	int flag;
	for (int i = 0 ; i < 16 ; i++)
	{
		if (ch == convTable[i][0])
			return i;
		else
			flag = 17;
	}
	return flag;
}
void generateAccurateBinFormat(char prvBinArr[], char nextBinArr[])
{
	int i;
	char revPrvBinArr[100] = "";
	int revPrvBinArrIndex = 0;
	int nextBinArrIndex = 0;

	for (i = strlen(prvBinArr) - 1 ; i >= 0 ; i--)
	{
		revPrvBinArr[revPrvBinArrIndex] = prvBinArr[i];
		revPrvBinArrIndex++;
	}
	for (i = revPrvBinArrIndex ; i < 8 ; i++)
		revPrvBinArr[i] = '0';

	for (i = 7 ; i >=0  ; i--)
	{
		nextBinArr[nextBinArrIndex] = revPrvBinArr[i];
		nextBinArrIndex++;
	}
}
void generateHexText(char arr[], char hexArr[])
{
	int decVal;
	char tmpBinArr[100] = "";
	char binArr[100] = "";
	char tmpString[100] = "";
	char firstBinArr[10] = "";
	char lastBinArr[10] = "";
	char hexChar[2] = "";

	for (int i = 0 ; i < strlen(arr) ; i++)
	{
		decVal = arr[i]; 
		decTobinForText(decVal, tmpBinArr);
		generateAccurateBinFormat(tmpBinArr, binArr);

		firstBinArr[0] = binArr[0];
		firstBinArr[1] = binArr[1];
		firstBinArr[2] = binArr[2];
		firstBinArr[3] = binArr[3];

		lastBinArr[0] = binArr[4];
		lastBinArr[1] = binArr[5];
		lastBinArr[2] = binArr[6];
		lastBinArr[3] = binArr[7];
		
		hexChar[0] = binTohex(firstBinArr);
		strcat(hexArr, hexChar);

		hexChar[0] = binTohex(lastBinArr);
		strcat(hexArr, hexChar);
	}
}
void createInitialArr(char arr[], char binArr[])
{
	int i,j,index,len,binIndex = 0;
		
	for (i = 0 ; i < 16 ; i++)
	{
		index = getPosition(arr[i]);
		for (j = 1 ; j < 5 ; j++)
		{
			binArr[binIndex] = convTable[index][j];
			binIndex++;
		}
	}		
}
void generateKplus(char binK[], int rowPCone[56], char Kplus[])
{
	for (int i = 0; i < 56 ; i++)
		Kplus[i] = binK[rowPCone[i] - 1];
}
void generatePofS(char SofB[], int rowP[32], char PofS[])
{
	for (int i = 0; i < 32 ; i++)
		PofS[i] = SofB[rowP[i] - 1];
}
void generateIP(char binIP[], int rowIP[], char IPmsg[])
{
	for (int i = 0; i < 64 ; i++)
		IPmsg[i] = binIP[rowIP[i] - 1];
}
void generateIPinv(char R16L16[], int rowIPinv[], char IPinv[])
{
	for (int i = 0; i < 64 ; i++)
		IPinv[i] = R16L16[rowIPinv[i] - 1];
}
void generateEofR(char Rprv[], int rowE[], char EofR[])
{
	for (int i = 0; i < 48 ; i++)
		EofR[i] = Rprv[rowE[i] - 1];
}
void generateK(char C[], char D[], int rowPC[56], char newK[])
{
	char genCD[56];
	for (int i = 0; i < 28 ; i++)
	{
		genCD[i] = C[i];
		genCD[i + 28] = D[i];
	}
	for (int i = 0; i < 48 ; i++)
		newK[i] = genCD[rowPC[i] - 1];

}
void leftShiftOperation(char beforeLeftShift[], char afterLeftShift[], int no)
{
	int afterLeftShiftIndex = 0;
	for (int i = no; i < 28 ; i++)
	{
		afterLeftShift[afterLeftShiftIndex] = beforeLeftShift[i];
		afterLeftShiftIndex++;
	}
	for (int i = 0; i < no ; i++)
	{
		afterLeftShift[afterLeftShiftIndex] = beforeLeftShift[i];
		afterLeftShiftIndex++;
	}
}
void convRowPCone(int PCone[8][7], int rowPCone[56])
{
	int indexRowPCone = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 7 ; j++)
		{
			rowPCone[indexRowPCone] = PCone[i][j]; 
			indexRowPCone++;
		}
} 
void convRowPCtwo(int PCtwo[8][6], int rowPCtwo[48])
{
	int indexRowPCtwo = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 6 ; j++)
		{
			rowPCtwo[indexRowPCtwo] = PCtwo[i][j]; 
			indexRowPCtwo++;
		}
} 
void convRowIP(int IP[8][8], int rowIP[64])
{
	int indexRowIP = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 8 ; j++)
		{
			rowIP[indexRowIP] = IP[i][j]; 
			indexRowIP++;
		}
} 
void convRowIPinv(int IPinv[8][8], int rowIPinv[64])
{
	int indexRowIPinv = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 8 ; j++)
		{
			rowIPinv[indexRowIPinv] = IPinv[i][j]; 
			indexRowIPinv++;
		}
} 
void convRowP(int P[8][4], int rowP[64])
{
	int indexRowP = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 4 ; j++)
		{
			rowP[indexRowP] = P[i][j]; 
			indexRowP++;
		}
} 
void convRowEbitSelectionTable(int EbitSelectionTable[8][6], int rowE[48])
{
	int indexE = 0;
	for (int i = 0 ; i < 8 ; i++)
		for (int j = 0 ; j < 6 ; j++)
		{
			rowE[indexE] = EbitSelectionTable[i][j]; 
			indexE++;
		}
} 

char exorOperation(char a, char b)
{
	if( a == '0' && b == '0')
		return '0';
	else if( a == '0' && b == '1')
		return '1';
	else if( a == '1' && b == '0')
		return '1';
	else if( a == '1' && b == '1')
		return '0';
}
void generateR(char K[], char newR[], char Rprv[])
{
	int rowE[48];
	char EofR[48];

	convRowEbitSelectionTable(EbitSelectionTable, rowE);
	generateEofR(Rprv , rowE, EofR);

	for (int i = 0 ; i < 48; i++)
		newR[i] = exorOperation(K[i], EofR[i]);
}

int binTodec(char binArr[])
{
	int numericValueOfChar, decValue = 0;
	int i, j, k;
	for(i = 0; i < strlen(binArr) ; i++)
	{
		numericValueOfChar = (binArr[i] - '0');
		for (j = 1, k = strlen(binArr) - 1; k > i; k--)
			j *= 2;
		decValue = decValue + numericValueOfChar * j;
	}
	return decValue; 
}
void decTobin(int decimal, char binary[])
{
	char binArray[5];
	char temp[70];
	int remainder, binArrayIndex = 0, tempIndex = 0;
	
	do
	{
		remainder = decimal % 2;
		decimal = decimal / 2;

		temp[tempIndex++] = remainder + '0';
	}while (decimal > 0);

	while (tempIndex >= 0)
		binArray[binArrayIndex++] = temp[--tempIndex];
	binArray[binArrayIndex - 1] = 0;

	if(strlen(binArray) < 4)
	{
		int len = 4 - strlen(binArray);
		int k = 0;
		
		for (int i = 0 ; i < len ; i++)
			binary[i] = '0';
		for (int j = len ; j < 4 ; j++)
		{
			binary[j] = binArray[k]; 
			k++;
		}
		binary[4] = 0;
	}
	else
	{
		for(int k = 0; k < 4 ; k++)
			binary[k] = binArray[k];
		binary[4] = 0;
	}
}

void generateSofB(int S[4][16], char Bprv[], char Bnext[])
{
	char rowSelectionArray[3];
	char columnSelectionArray[5];

	rowSelectionArray[0] = Bprv[0];
	rowSelectionArray[1] = Bprv[5];
	rowSelectionArray[2] = 0;

	columnSelectionArray[0] = Bprv[1];
	columnSelectionArray[1] = Bprv[2];
	columnSelectionArray[2] = Bprv[3];
	columnSelectionArray[3] = Bprv[4];
	columnSelectionArray[4] = 0;
	
	int rowVal = binTodec(rowSelectionArray);
	int columnVal = binTodec(columnSelectionArray);

	decTobin(S[rowVal][columnVal], Bnext);
}

void generateLR(char Lprv[], char Rprv[], char Lnext[], char Rnext[], char K[])
{
	char tempRnext[48];
	char SofB[33];
	char B1[6], B2[6], B3[6], B4[6], B5[6], B6[6], B7[6], B8[6];
	char B1Next[5], B2Next[5], B3Next[5], B4Next[5], B5Next[5], B6Next[5], B7Next[5], B8Next[5];
	int rowP[32];
	char PofS[32];
	for (int i = 0; i < 32 ; i++)
		Lnext[i] = Rprv[i];
	generateR(K, tempRnext, Rprv);

	for (int j = 0; j < 6; j++)
	{
		B1[j] = tempRnext[j];
		B2[j] = tempRnext[j + 6];
		B3[j] = tempRnext[j + 12];
		B4[j] = tempRnext[j + 18];
		B5[j] = tempRnext[j + 24];
		B6[j] = tempRnext[j + 30];
		B7[j] = tempRnext[j + 36];
		B8[j] = tempRnext[j + 42];
	}
	generateSofB(S1, B1, B1Next); 
	generateSofB(S2, B2, B2Next);
	generateSofB(S3, B3, B3Next);
	generateSofB(S4, B4, B4Next);
	generateSofB(S5, B5, B5Next);
	generateSofB(S6, B6, B6Next);
	generateSofB(S7, B7, B7Next);
	generateSofB(S8, B8, B8Next);

	for (int j = 0; j < 4; j++)
	{
		SofB[j] = B1Next[j];
		SofB[j + 4] = B2Next[j];
		SofB[j + 8] = B3Next[j];
		SofB[j + 12] = B4Next[j];
		SofB[j + 16] = B5Next[j];
		SofB[j + 20] = B6Next[j];
		SofB[j + 24] = B7Next[j];
		SofB[j + 28] = B8Next[j];
	}
	SofB[32] = 0; 
	convRowP(P, rowP); 
	generatePofS(SofB, rowP, PofS);

	for (int k = 0; k < 32 ; k++)
		Rnext[k] = exorOperation(PofS[k], Lprv[k]);  
}
char generateASCIItoText(int ASCIIval)
{
	return char(ASCIIval);
}
void generateFinalDecryptedMsg(char IPinvMsg[], char msgC[])
{
	char tmpIPinvMsg[9];
	int msgCindex = 0;

	for(int i = 0; i < 64 ; i = i + 8 )
	{
		tmpIPinvMsg[0] = IPinvMsg[i];
		tmpIPinvMsg[1] = IPinvMsg[i + 1];
		tmpIPinvMsg[2] = IPinvMsg[i + 2];
		tmpIPinvMsg[3] = IPinvMsg[i + 3];
		tmpIPinvMsg[4] = IPinvMsg[i + 4];
		tmpIPinvMsg[5] = IPinvMsg[i + 5];
		tmpIPinvMsg[6] = IPinvMsg[i + 6];
		tmpIPinvMsg[7] = IPinvMsg[i + 7];
		tmpIPinvMsg[8] = 0;

		msgC[msgCindex] = generateASCIItoText(binTodec(tmpIPinvMsg));
		msgCindex++;
	}
	msgC[msgCindex] = 0;
}
void generateFinalEncryptedMsg(char IPinvMsg[], char msgC[])
{
	char msgCtext[1000] = "";
	char tmpIPinvMsg[5];
	int msgCindex = 0;
	for(int i = 0; i < 64 ; i = i + 4 )
	{
		tmpIPinvMsg[0] = IPinvMsg[i];
		tmpIPinvMsg[1] = IPinvMsg[i + 1];
		tmpIPinvMsg[2] = IPinvMsg[i + 2];
		tmpIPinvMsg[3] = IPinvMsg[i + 3];
		tmpIPinvMsg[4] = 0;

		msgC[msgCindex] = binTohex(tmpIPinvMsg);
		msgCindex++; 
	}
	msgC[msgCindex] = 0; 
}
#endif
