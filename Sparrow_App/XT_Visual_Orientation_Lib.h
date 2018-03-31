#pragma once
#include "CXTComputerVisionInterface_Data.h"

typedef int(__cdecl*pXT_Visual_Orientation_Callback)(int iIndex, double fDelta_X, double fDelta_Y, double fDelta_C, int bWait_Finish, int bResume);

#ifdef _DLLAPI
#undef _DLLAPI
#endif
#ifdef _DLL_Provider
#define _DLLAPI  _declspec(dllexport)  
#else  
#define _DLLAPI  _declspec(dllimport)  
#endif

extern "C"
{
	// ��ʼ�� .
	int _DLLAPI XT_Visual_Orientation_Init(int iIndex, LPWSTR pServer_IP, LPWSTR pFile_Path, pXT_Visual_Orientation_Callback pCallBack, LPWSTR pFingerPrint, int bSilence);

	// ����ʼ�� , �����©�ڴ� .
	int _DLLAPI XT_Visual_Orientation_DeInit(int iIndex);

	LPWSTR _DLLAPI XT_Visual_Orientation_Get_Last_Error(int iIndex);

	// ֻ��ȡͼ�� .
	int _DLLAPI XT_Visual_Orientation_Get_Image(int iIndex, tImage** pImage);

	// ��ȡ��λλ�� .
	int _DLLAPI XT_Visual_Orientation_Get_Pos(int iIndex, double& fPhy_X, double& fPhy_Y, double& fPhy_C, double& fPix_X, double& fPix_Y, tImage** pImage, int bUse_Proper_Template);

	// ����Ŀ�� .
	int _DLLAPI XT_Visual_Orientation_Track(int iIndex, int nMax_Count, double fDistance, int bUse_Proper_Template);
	int _DLLAPI XT_Visual_Orientation_Wait_Stable(int iIndex);

	// ���ô��� .
	int _DLLAPI XT_Visual_Orientation_DoDlg(int iIndex, LPWSTR strDlg_Caption_Name, LPWSTR strLanguageFile);
	int _DLLAPI XT_Visual_Orientation_CloseDLg(int iIndex, int bOK);

	// ��ȡģ������ .
	int _DLLAPI XT_Visual_Orientation_Get_Template_Amount(int iIndex, int& nAmount);

	// ��ȡ�ͱ༭ģ������ .
	LPWSTR _DLLAPI XT_Visual_Orientation_Get_Template(int iIndex, int iTemplate, tImage** pImage);
	int _DLLAPI XT_Visual_Orientation_Set_Template_Name(int iIndex, int iTemplate, LPWSTR pstrName);


	// ����ģ�� .
	int _DLLAPI XT_Visual_Orientation_Set_Template(int iIndex, LPWSTR pstrName);
	int _DLLAPI XT_Visual_Orientation_Add_Template(int iIndex, const LPWSTR pstrName, const tImage* pImage);

	// �����ع�ʱ�� .
	int _DLLAPI XT_Visual_Orientation_Set_Camera_Manual_Exposure_Time_Abs(int iIndex, double fExposureTimeAbs);
	int _DLLAPI XT_Visual_Orientation_Get_Camera_Manual_Exposure_Time_Abs(int iIndex, double& fExposureTimeAbs);

	// ���� AOI .
	int _DLLAPI XT_Visual_Orientation_Set_Camera_AOI(int iIndex, long long nWidth, long long nHeight, long long OffsetX, long long OffsetY);
	int _DLLAPI XT_Visual_Orientation_Get_Camera_AOI(int iIndex, long long& nWidth, long long& nHeight, long long& OffsetX, long long& OffsetY, long long& nMaxWidth, long long& nMaxHeight);

	//////////////////////////////////////////////////////////////////////////
	// ��ѧ���� .

	// �ڵ㼯���ҳ��������ĵ� , ���ڸ��� .
	// nOutput_Point  2 ��������������� , 3 , 4 ���������� n �� .
	// ��� nInput_Point <= nOutput_Point �����ȫ������ .
	int _DLLAPI XT_Visual_Orientation_Get_Max_Distance_Point(int iIndex, int nDem, int nInput_Point, double* pfPoints, int nOutput_Point, int* pnPoint_Index);

	// ���� pSrc_Points �� pDst_Points ��ӳ�� , ���� pCal_Points ��ӳ���� .
	// nMode ģʽ , ��ʱֻ���� 0 .
	// nDem ά�� , ��ʱֻ���� 2 .
	// nConv_Point ����ת�������� , ��Ӧ pSrc_Points �� pDst_Points �ĳ��� .
	// pSrc_Points ԭʼ�� .
	// pDst_Points Ŀ��� .
	// pCal_Points ��Ҫ�����ӳ��� , ���� nCal_Point , ���������ͬһλ�� .
	int _DLLAPI XT_Visual_Orientation_Conv_Coord(int iIndex, int nMode, int nDem, int nConv_Point, const double* pfSrc_Points, const double* pfDst_Points, int nCal_Point, double* pfCal_Points);

	// TSP .
	int _DLLAPI XT_Visual_Orientation_Get_TSP_Result(int iIndex, int nDem, int nPoint, const double* pfPoints, const double* pfStart_Point, int* piResult_Index);
};