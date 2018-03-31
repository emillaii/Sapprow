#pragma once

// ͼ�� .
typedef struct{
	int nX;
	int nY;
	int nDem;
	BYTE* pGray;
}tImage;

// ģ��ƥ����� .
typedef struct tMatch_Param
{
	tMatch_Param()
	{
		nMaxPyramidLevel = -1;
		fRoiFactor = 0.65;
		fStartAngle = 0;
		fEndAngle = 360;
		nRetTemplate = 1;
		fMatchValueThreshold = 0.87;
	}
	int nMaxPyramidLevel; //
	double fRoiFactor; // ƥ������ 0 -- 1
	double fStartAngle; // ��
	double fEndAngle; // ��
	int nRetTemplate; // nRetTemplate
	double fMatchValueThreshold; // ƥ�䷧ֵ
}tMatch_Param;

// ƥ���� .
typedef struct
{
	double fMatch_Value;
	double fAngle;
	double fPos_X;
	double fPos_Y;
	double fSize_X;
	double fSize_Y;
}tMatch_Result;

typedef struct{
	int nMatch_Num;
	tMatch_Result* pMatch_Result;
}tMatch_All_Result;

// �Ҷ�Բƥ����� .
typedef struct{
	double fGray;// �Ҷ� , ( 0 , 1 ] .
	double fCircularity;// Բ�� , ( 0 , 1 ] .
	double fRound_Dem;// Բֱ�� , > 2 .
	double fRound_Dem_Error;// Բֱ���ݲ� , > 0 .
	int bInvert;// ��ɫ , 0 / 1 .
}tGray_Param;
