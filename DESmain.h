#ifndef __mainDES_h__
#define __mainDES_h__

#include "DES.h"
	
int PCone[8][7] = {
						{57, 49, 41, 33, 25, 17, 9},
						{1, 58, 50, 42, 34, 26, 18},
						{10, 2, 59, 51, 43, 35, 27},
						{19, 11, 3, 60, 52, 44, 36},
						{63, 55, 47, 39, 31, 23, 15},
						{7, 62, 54, 46, 38, 30, 22},
						{14, 6, 61, 53, 45, 37, 29},
						{21, 13, 5, 28, 20, 12, 4}
					  };
	int leftShiftTable[16][2] = {
								{1, 1},
								{2, 1},
								{3, 2},
								{4, 2},
								{5, 2},
								{6, 2},
								{7, 2},
								{8, 2},
								{9, 1},
								{10, 2},
								{11, 2},
								{12, 2},
								{13, 2},
								{14, 2},
								{15, 2},
								{16, 1}
							 };
	int PCtwo[8][6] = {
						{14, 17, 11, 24, 1, 5},
						{3, 28, 15, 6, 21, 10},
						{23, 19, 12, 4, 26, 8},
						{16, 7, 27, 20, 13, 2},
						{41, 52, 31, 37, 47, 55},
						{30, 40, 51, 45, 33, 48},
						{44, 49, 39, 56, 34, 53},
						{46, 42, 50, 36, 29, 32}
					  };
	int IP[8][8] = {
						{58, 50, 42, 34, 26, 18, 10, 2},
						{60, 52, 44, 36, 28, 20, 12, 4},
						{62, 54, 46, 38, 30, 22, 14, 6},
						{64, 56, 48, 40, 32, 24, 16, 8},
						{57, 49, 41, 33, 25, 17, 9, 1},
						{59, 51, 43, 35, 27, 19, 11, 3},
						{61, 53, 45, 37, 29, 21, 13, 5},
						{63, 55, 47, 39, 31, 23, 15, 7}
					};
	int IPinv[8][8] = {
					{40, 8, 48, 16, 56, 24, 64, 32},
					{39, 7, 47, 15, 55, 23, 63, 31},
					{38, 6, 46, 14, 54, 22, 62, 30},
					{37, 5, 45, 13, 53, 21, 61, 29},
					{36, 4, 44, 12, 52, 20, 60, 28},
					{35, 3, 43, 11, 51, 19, 59, 27},
					{34, 2, 42, 10, 50, 18, 58, 26},
					{33, 1, 41, 9, 49, 17, 57, 25}
				};
		

	char binM[65];
	
	char binK[65];
	int rowPCone[56];
	int rowPCtwo[48];
	int rowIP[64];
	int rowIPinv[64];
	char Kplus[56];
	char IPmsg[64];
	char IPinvMsg[64];
	
	
	char C0[28], C1[28], C2[28], C3[28], C4[28], C5[28], C6[28], C7[28], C8[28], C9[28], C10[28], C11[28], C12[28], C13[28], C14[28], C15[28], C16[28];
	char D0[28], D1[28], D2[28], D3[28], D4[28], D5[28], D6[28], D7[28], D8[28], D9[28], D10[28], D11[28], D12[28], D13[28], D14[28], D15[28], D16[28];
	char K1[48], K2[48], K3[48], K4[48], K5[48], K6[48], K7[48], K8[48], K9[48], K10[48], K11[48], K12[48], K13[48], K14[48], K15[48], K16[48];
	char L0[32], L1[32], L2[32], L3[32], L4[32], L5[32], L6[32], L7[32], L8[32], L9[32], L10[32], L11[32], L12[32], L13[32], L14[32], L15[32], L16[32];
	char R0[32], R1[32], R2[32], R3[32], R4[32], R5[32], R6[32], R7[32], R8[32], R9[32], R10[32], R11[32], R12[32], R13[32], R14[32], R15[32], R16[32];
	

void generateMessage(char textM[], char keyK[], char msgC[], int choice)
{
	createInitialArr(textM,binM);
	createInitialArr(keyK,binK);

	convRowPCone(PCone, rowPCone);
	generateKplus(binK, rowPCone, Kplus);
	
	for (int i = 0 ; i < 28 ; i++)
	{
		C0[i] = Kplus[i];
		D0[i] = Kplus[i + 28];
	}

	leftShiftOperation(C0, C1, leftShiftTable[0][1]);
	leftShiftOperation(D0, D1, leftShiftTable[0][1]);

	leftShiftOperation(C1, C2, leftShiftTable[1][1]);
	leftShiftOperation(D1, D2, leftShiftTable[1][1]);

	leftShiftOperation(C2, C3, leftShiftTable[2][1]);
	leftShiftOperation(D2, D3, leftShiftTable[2][1]);

	leftShiftOperation(C3, C4, leftShiftTable[3][1]);
	leftShiftOperation(D3, D4, leftShiftTable[3][1]);

	leftShiftOperation(C4, C5, leftShiftTable[4][1]);
	leftShiftOperation(D4, D5, leftShiftTable[4][1]);

	leftShiftOperation(C5, C6, leftShiftTable[5][1]);
	leftShiftOperation(D5, D6, leftShiftTable[5][1]);

	leftShiftOperation(C6, C7, leftShiftTable[6][1]);
	leftShiftOperation(D6, D7, leftShiftTable[6][1]);

	leftShiftOperation(C7, C8, leftShiftTable[7][1]);
	leftShiftOperation(D7, D8, leftShiftTable[7][1]);

	leftShiftOperation(C8, C9, leftShiftTable[8][1]);
	leftShiftOperation(D8, D9, leftShiftTable[8][1]);

	leftShiftOperation(C9, C10, leftShiftTable[9][1]);
	leftShiftOperation(D9, D10, leftShiftTable[9][1]);

	leftShiftOperation(C10, C11, leftShiftTable[10][1]);
	leftShiftOperation(D10, D11, leftShiftTable[10][1]);

	leftShiftOperation(C11, C12, leftShiftTable[11][1]);
	leftShiftOperation(D11, D12, leftShiftTable[11][1]);

	leftShiftOperation(C12, C13, leftShiftTable[12][1]);
	leftShiftOperation(D12, D13, leftShiftTable[12][1]);

	leftShiftOperation(C13, C14, leftShiftTable[13][1]);
	leftShiftOperation(D13, D14, leftShiftTable[13][1]);

	leftShiftOperation(C14, C15, leftShiftTable[14][1]);
	leftShiftOperation(D14, D15, leftShiftTable[14][1]);

	leftShiftOperation(C15, C16, leftShiftTable[15][1]);
	leftShiftOperation(D15, D16, leftShiftTable[15][1]);

	convRowPCtwo(PCtwo, rowPCtwo);

	generateK(C1, D1, rowPCtwo, K1);
	generateK(C2, D2, rowPCtwo, K2); 
	generateK(C3, D3, rowPCtwo, K3); 
	generateK(C4, D4, rowPCtwo, K4); 
	generateK(C5, D5, rowPCtwo, K5); 
	generateK(C6, D6, rowPCtwo, K6); 
	generateK(C7, D7, rowPCtwo, K7); 
	generateK(C8, D8, rowPCtwo, K8);
	generateK(C9, D9, rowPCtwo, K9); 
	generateK(C10, D10, rowPCtwo, K10); 
	generateK(C11, D11, rowPCtwo, K11); 
	generateK(C12, D12, rowPCtwo, K12); 
	generateK(C13, D13, rowPCtwo, K13); 
	generateK(C14, D14, rowPCtwo, K14); 
	generateK(C15, D15, rowPCtwo, K15); 
	generateK(C16, D16, rowPCtwo, K16); 

	convRowIP(IP, rowIP);
	generateIP(binM, rowIP, IPmsg);

	for (int i = 0 ; i < 32 ; i++)
	{
		L0[i] = IPmsg[i];
		R0[i] = IPmsg[i + 32];
	}

	if(choice == 1)
	{
		generateLR(L0, R0, L1, R1, K1);
		generateLR(L1, R1, L2, R2, K2);
		generateLR(L2, R2, L3, R3, K3);
		generateLR(L3, R3, L4, R4, K4);
		generateLR(L4, R4, L5, R5, K5);
		generateLR(L5, R5, L6, R6, K6);
		generateLR(L6, R6, L7, R7, K7);
		generateLR(L7, R7, L8, R8, K8);
		generateLR(L8, R8, L9, R9, K9);
		generateLR(L9, R9, L10, R10, K10);
		generateLR(L10, R10, L11, R11, K11);
		generateLR(L11, R11, L12, R12, K12);
		generateLR(L12, R12, L13, R13, K13);
		generateLR(L13, R13, L14, R14, K14);
		generateLR(L14, R14, L15, R15, K15);
		generateLR(L15, R15, L16, R16, K16);	
	}
	else if(choice == 2)
	{
		generateLR(L0, R0, L1, R1, K16);
		generateLR(L1, R1, L2, R2, K15);
		generateLR(L2, R2, L3, R3, K14);
		generateLR(L3, R3, L4, R4, K13);
		generateLR(L4, R4, L5, R5, K12);
		generateLR(L5, R5, L6, R6, K11);
		generateLR(L6, R6, L7, R7, K10);
		generateLR(L7, R7, L8, R8, K9);
		generateLR(L8, R8, L9, R9, K8);
		generateLR(L9, R9, L10, R10, K7);
		generateLR(L10, R10, L11, R11, K6);
		generateLR(L11, R11, L12, R12, K5);
		generateLR(L12, R12, L13, R13, K4);
		generateLR(L13, R13, L14, R14, K3);
		generateLR(L14, R14, L15, R15, K2);
		generateLR(L15, R15, L16, R16, K1);
	}

	char R16L16[64];

	for(int i = 0 ; i < 32 ; i++)
	{
		R16L16[i] = R16[i];
		R16L16[i + 32] = L16[i];
	}

	convRowIPinv(IPinv, rowIPinv);
	generateIPinv(R16L16, rowIPinv, IPinvMsg);

	if (choice == 1)
		generateFinalEncryptedMsg(IPinvMsg, msgC);
	else if (choice == 2)
		generateFinalDecryptedMsg(IPinvMsg, msgC);

}
#endif
