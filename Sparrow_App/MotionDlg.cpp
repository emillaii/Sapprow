// MotionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MotionDlg.h"
#include "afxdialogex.h"
#include "Log.h"
#include "Math.h"

// MotionDlg dialog

IMPLEMENT_DYNAMIC(MotionDlg, CDialog)

MotionDlg* MotionDlg::GetInstance()
{
	static MotionDlg *pDlg = new MotionDlg();
	return pDlg;
}


MotionDlg::MotionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_MOTION, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

MotionDlg::~MotionDlg()
{
}

void MotionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_X_MaxVel, m_cMaxVel_X);
	DDX_Control(pDX, IDC_EDIT_Y_MaxVel, m_cMaxVel_Y);
	DDX_Control(pDX, IDC_EDIT_Z_MaxVel, m_cMaxVel_Z);
	DDX_Control(pDX, IDC_STATIC_X_Pos, m_cCurPos_X);
	DDX_Control(pDX, IDC_STATIC_Y_Pos, m_cCurPos_Y);
	DDX_Control(pDX, IDC_STATIC_Z_Pos, m_cCurPos_Z);
	DDX_Control(pDX, IDC_CHECK_X, m_cMove_X);
	DDX_Control(pDX, IDC_CHECK_Y, m_cMove_Y);
	DDX_Control(pDX, IDC_CHECK_Z, m_cMove_Z);
	DDX_Control(pDX, IDC_STATIC_X_Vel, m_cCurVel_X);
	DDX_Control(pDX, IDC_STATIC_Y_Vel, m_cCurVel_Y);
	DDX_Control(pDX, IDC_STATIC_Z_Vel, m_cCurVel_Z);
	DDX_Control(pDX, IDC_STATIC_X_Acc, m_cCurAcc_X);
	DDX_Control(pDX, IDC_STATIC_Y_Acc, m_cCurAcc_Y);
	DDX_Control(pDX, IDC_STATIC_Z_Acc, m_cCurAcc_Z);
	DDX_Control(pDX, IDC_EDIT_X_MaxAcc, m_cMaxAcc_X);
	DDX_Control(pDX, IDC_EDIT_Y_MaxAcc, m_cMaxAcc_Y);
	DDX_Control(pDX, IDC_EDIT_Z_MaxAcc, m_cMaxAcc_Z);
	DDX_Control(pDX, IDC_EDIT_X_MaxJerk, m_cMaxJerk_X);
	DDX_Control(pDX, IDC_EDIT_Y_MaxJerk, m_cMaxJerk_Y);
	DDX_Control(pDX, IDC_EDIT_Z_MaxJerk, m_cMaxJerk_Z);
	DDX_Control(pDX, IDC_EDIT_X_Pulse, m_cPulseRatio_X);
	DDX_Control(pDX, IDC_EDIT_Y_Pulse, m_cPulseRatio_Y);
	DDX_Control(pDX, IDC_EDIT_Z_Pulse, m_cPulseRatio_Z);
	DDX_Control(pDX, IDC_CHECK_X_Origin, m_cOrigin_X);
	DDX_Control(pDX, IDC_CHECK_Y_Origin, m_cOrigin_Y);
	DDX_Control(pDX, IDC_CHECK_Z_Origin, m_cOrigin_Z);
	DDX_Control(pDX, IDC_CHECK_Output, m_cOutput);
	DDX_Control(pDX, IDC_EDIT_Step, m_cStep);


	DDX_Control(pDX, IDC_STATIC_A_Pos, m_cCurPos_A);
	DDX_Control(pDX, IDC_STATIC_B_Pos, m_cCurPos_B);
	DDX_Control(pDX, IDC_STATIC_C_Pos, m_cCurPos_C);
	DDX_Control(pDX, IDC_STATIC_A_Vel, m_cCurVel_A);
	DDX_Control(pDX, IDC_STATIC_B_Vel, m_cCurVel_B);
	DDX_Control(pDX, IDC_STATIC_C_Vel, m_cCurVel_C);
	DDX_Control(pDX, IDC_STATIC_A_Acc, m_cCurAcc_A);
	DDX_Control(pDX, IDC_STATIC_B_Acc, m_cCurAcc_B);
	DDX_Control(pDX, IDC_STATIC_C_Acc, m_cCurAcc_C);
	DDX_Control(pDX, IDC_EDIT_A_MaxVel, m_cMaxVel_A);
	DDX_Control(pDX, IDC_EDIT_B_MaxVel, m_cMaxVel_B);
	DDX_Control(pDX, IDC_EDIT_C_MaxVel, m_cMaxVel_C);
	DDX_Control(pDX, IDC_EDIT_A_MaxAcc, m_cMaxAcc_A);
	DDX_Control(pDX, IDC_EDIT_B_MaxAcc, m_cMaxAcc_B);
	DDX_Control(pDX, IDC_EDIT_C_MaxAcc, m_cMaxAcc_C);
	DDX_Control(pDX, IDC_EDIT_A_MaxJerk, m_cMaxJerk_A);
	DDX_Control(pDX, IDC_EDIT_B_MaxJerk, m_cMaxJerk_B);
	DDX_Control(pDX, IDC_EDIT_C_MaxJerk, m_cMaxJerk_C);
	DDX_Control(pDX, IDC_EDIT_A_Pulse, m_cPulseRatio_A);
	DDX_Control(pDX, IDC_EDIT_B_Pulse, m_cPulseRatio_B);
	DDX_Control(pDX, IDC_EDIT_C_Pulse, m_cPulseRatio_C);
	DDX_Control(pDX, IDC_CHECK_A, m_cMove_A);
	DDX_Control(pDX, IDC_CHECK_B, m_cMove_B);
	DDX_Control(pDX, IDC_CHECK_C, m_cMove_C);
	DDX_Control(pDX, IDC_CHECK_A_Origin, m_cOrigin_A);
	DDX_Control(pDX, IDC_CHECK_B_Origin, m_cOrigin_B);
	DDX_Control(pDX, IDC_CHECK_C_Origin, m_cOrigin_C);
	DDX_Control(pDX, IDC_CHECK_M, m_cMove_M);
	DDX_Control(pDX, IDC_CHECK_N, m_cMove_N);
	DDX_Control(pDX, IDC_CHECK_L, m_cMove_L);
	DDX_Control(pDX, IDC_STATIC_M_Pos, m_cCurPos_M);
	DDX_Control(pDX, IDC_STATIC_N_Pos, m_cCurPos_N);
	DDX_Control(pDX, IDC_STATIC_L_Pos, m_cCurPos_L);
	DDX_Control(pDX, IDC_STATIC_M_Vel, m_cCurVel_M);
	DDX_Control(pDX, IDC_STATIC_N_Vel, m_cCurVel_N);
	DDX_Control(pDX, IDC_STATIC_L_Vel, m_cCurVel_L);
	DDX_Control(pDX, IDC_STATIC_M_Acc, m_cCurAcc_M);
	DDX_Control(pDX, IDC_STATIC_N_Acc, m_cCurAcc_N);
	DDX_Control(pDX, IDC_STATIC_L_Acc, m_cCurAcc_L);
	DDX_Control(pDX, IDC_EDIT_M_MaxVel, m_cMaxVel_M);
	DDX_Control(pDX, IDC_EDIT_N_MaxVel, m_cMaxVel_N);
	DDX_Control(pDX, IDC_EDIT_L_MaxVel, m_cMaxVel_L);
	DDX_Control(pDX, IDC_EDIT_M_MaxAcc, m_cMaxAcc_M);
	DDX_Control(pDX, IDC_EDIT_N_MaxAcc, m_cMaxAcc_N);
	DDX_Control(pDX, IDC_EDIT_L_MaxAcc, m_cMaxAcc_L);
	DDX_Control(pDX, IDC_EDIT_M_MaxJerk, m_cMaxJerk_M);
	DDX_Control(pDX, IDC_EDIT_N_MaxJerk, m_cMaxJerk_N);
	DDX_Control(pDX, IDC_EDIT_L_MaxJerk, m_cMaxJerk_L);
	DDX_Control(pDX, IDC_EDIT_M_Pulse, m_cPulseRatio_M);
	DDX_Control(pDX, IDC_EDIT_N_Pulse, m_cPulseRatio_N);
	DDX_Control(pDX, IDC_EDIT_L_Pulse, m_cPulseRatio_L);
	DDX_Control(pDX, IDC_CHECK_M_Origin, m_cOrigin_M);
	DDX_Control(pDX, IDC_CHECK_N_Origin, m_cOrigin_N);
	DDX_Control(pDX, IDC_CHECK_L_Origin, m_cOrigin_L);
}

BOOL MotionDlg::OnInitDialog() {
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	return TRUE;
}

BOOL MotionDlg::PreTranslateMessage(MSG * pMsg)
{
	int res = 0;

	if (WM_LBUTTONDOWN == pMsg->message)
	{
		if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_X)->m_hWnd)
		{
			UpdateParam_X();
			XT_Controler_Extend::JOG_GO(Thread_X, Axis_X, m_fStep, Axis_X_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_X)->m_hWnd)
		{
			UpdateParam_X();
			XT_Controler_Extend::JOG_GO(Thread_X, Axis_X, -m_fStep, 0);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_Y)->m_hWnd)
		{
			UpdateParam_Y();
			XT_Controler_Extend::JOG_GO(Thread_Y, Axis_Y, m_fStep, Axis_Y_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_Y)->m_hWnd)
		{
			UpdateParam_Y();
			XT_Controler_Extend::JOG_GO(Thread_Y, Axis_Y, -m_fStep, 0);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_Z)->m_hWnd)
		{
			UpdateParam_Z();
			XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, m_fStep, Axis_Z_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_Z)->m_hWnd)
		{
			UpdateParam_Z();
			XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, -m_fStep, 0);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_A)->m_hWnd)
		{
			UpdateParam_A();
			XT_Controler_Extend::JOG_GO(Thread_A, Axis_A, m_fStep, Axis_A_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_A)->m_hWnd)
		{
			UpdateParam_A();
			XT_Controler_Extend::JOG_GO(Thread_A, Axis_A, -m_fStep, -Axis_A_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_B)->m_hWnd)
		{
			UpdateParam_B();
			XT_Controler_Extend::JOG_GO(Thread_B, Axis_B, m_fStep, Axis_B_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_B)->m_hWnd)
		{
			UpdateParam_B();
			XT_Controler_Extend::JOG_GO(Thread_B, Axis_B, -m_fStep, -Axis_B_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_C)->m_hWnd)
		{
			UpdateParam_C();
			XT_Controler_Extend::JOG_GO(Thread_C, Axis_C, m_fStep, Axis_C_Range-10);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_C)->m_hWnd)
		{
			UpdateParam_C();
			XT_Controler_Extend::JOG_GO(Thread_C, Axis_C, -m_fStep, -Axis_C_Range-10);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_M)->m_hWnd)
		{
			UpdateParam_M();
			XT_Controler_Extend::JOG_GO(Thread_M, Axis_M, m_fStep, Axis_M_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_M)->m_hWnd)
		{
			UpdateParam_M();
			XT_Controler_Extend::JOG_GO(Thread_M, Axis_M, -m_fStep, -Axis_M_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_N)->m_hWnd)
		{
			UpdateParam_N();
			XT_Controler_Extend::JOG_GO(Thread_N, Axis_N, m_fStep, Axis_N_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_N)->m_hWnd)
		{
			UpdateParam_N();
			XT_Controler_Extend::JOG_GO(Thread_N, Axis_N, -m_fStep, -Axis_N_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_L)->m_hWnd)
		{
			UpdateParam_L();
			XT_Controler_Extend::JOG_GO(Thread_L, Axis_L, m_fStep, Axis_L_Range);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_L)->m_hWnd)
		{
			UpdateParam_L();
			XT_Controler_Extend::JOG_GO(Thread_L, Axis_L, -m_fStep, -Axis_L_Range);
		}
	}
	else if (WM_LBUTTONUP == pMsg->message)
	{
		if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_X)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_X, Axis_X);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_X)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_X, Axis_X);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_Y)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_Y, Axis_Y);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_Y)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_Y, Axis_Y);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_Z)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_Z, Axis_Z);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_Z)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_Z, Axis_Z);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_A)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_A, Axis_A);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_A)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_A, Axis_A);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_B)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_B, Axis_B);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_B)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_B, Axis_B);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_C)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_C, Axis_C);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_C)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_C, Axis_C);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_L)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_M, Axis_M);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_M)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_M, Axis_M);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_N)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_N, Axis_N);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_N)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_N, Axis_N);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Incre_L)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_L, Axis_L);
		}
		else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_Decre_L)->m_hWnd)
		{
			XT_Controler_Extend::JOG_STOP(Thread_L, Axis_L);
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void MotionDlg::UpdateParam_X()
{
	CString Text;

	m_cMaxVel_X.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_X.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_X.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_X, Axis_X, fVel);
	XT_Controler::SET_MAX_ACC(Thread_X, Axis_X, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_X, Axis_X, fJerk);
}

void MotionDlg::UpdateParam_Y()
{
	CString Text;

	m_cMaxVel_Y.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_Y.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_Y.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_Y, Axis_Y, fVel);
	XT_Controler::SET_MAX_ACC(Thread_Y, Axis_Y, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_Y, Axis_Y, fJerk);
}

void MotionDlg::UpdateParam_Z()
{
	CString Text;

	m_cMaxVel_Z.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_Z.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_Z.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_Z, Axis_Z, fVel);
	XT_Controler::SET_MAX_ACC(Thread_Z, Axis_Z, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_Z, Axis_Z, fJerk);
}

void MotionDlg::UpdateParam_A()
{
	CString Text;

	m_cMaxVel_A.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_A.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_A.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_A, Axis_A, fVel);
	XT_Controler::SET_MAX_ACC(Thread_A, Axis_A, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_A, Axis_A, fJerk);
}

void MotionDlg::UpdateParam_B()
{
	CString Text;

	m_cMaxVel_B.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_B.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_B.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_B, Axis_B, fVel);
	XT_Controler::SET_MAX_ACC(Thread_B, Axis_B, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_B, Axis_B, fJerk);
}

void MotionDlg::UpdateParam_C()
{
	CString Text;

	m_cMaxVel_C.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_C.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_C.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_C, Axis_C, fVel);
	XT_Controler::SET_MAX_ACC(Thread_C, Axis_C, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_C, Axis_C, fJerk);
}

void MotionDlg::UpdateParam_M()
{
	CString Text;

	m_cMaxVel_M.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_M.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_M.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_M, Axis_M, fVel);
	XT_Controler::SET_MAX_ACC(Thread_M, Axis_M, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_M, Axis_M, fJerk);
}

void MotionDlg::UpdateParam_N()
{
	CString Text;

	m_cMaxVel_N.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_N.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_N.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_N, Axis_N, fVel);
	XT_Controler::SET_MAX_ACC(Thread_N, Axis_N, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_N, Axis_N, fJerk);
}

void MotionDlg::UpdateParam_L()
{
	CString Text;

	m_cMaxVel_L.GetWindowText(Text);
	double fVel = _wtof(Text.GetBuffer());
	if (0 >= fVel)
	{
		AfxMessageBox(_T("Velocity should be positive"));
		return;
	}
	m_cMaxAcc_L.GetWindowText(Text);
	double fVAcc = _wtof(Text.GetBuffer());
	if (0 >= fVAcc)
	{
		AfxMessageBox(_T("Acceleration should be positive"));
		return;
	}
	m_cMaxJerk_L.GetWindowText(Text);
	double fJerk = _wtof(Text.GetBuffer());
	if (0 >= fJerk)
	{
		AfxMessageBox(_T("Jerk should be positive"));
		return;
	}
	m_cStep.GetWindowText(Text);
	m_fStep = _wtof(Text.GetBuffer());

	XT_Controler::SET_MAX_VEL(Thread_L, Axis_L, fVel);
	XT_Controler::SET_MAX_ACC(Thread_L, Axis_L, fVAcc);
	XT_Controler::SET_MAX_JERK(Thread_L, Axis_L, fJerk);
}

void MotionDlg::Axis_SeekOrigin_PN(int iThreadID, unsigned int iAxis, unsigned int iIo_In_Origin, int bIo_In_Origin_Dir, double fPos, double fNeg, double fOffset, double fNew_Pos, double fSpeed_2Seek)
{
	int res = 0;

	if (1 != bIo_In_Origin_Dir)
	{
		bIo_In_Origin_Dir = -1;
	}

	int iThread = iThreadID;

	int	iAxisPosReg = 0;
	int iVelReg = iAxisPosReg + 1;
	int iMulReg = iVelReg + 1;

	XT_Controler::USE_LOCAL_REG(iThread);

	XT_Controler::GET_INPUT_IO(iThread, iIo_In_Origin, iAxisPosReg);
	if (1 == bIo_In_Origin_Dir)
	{
		XT_Controler::CONDITION_NEG_JMP(iThread, iAxisPosReg, 1, 2);
	}
	else
	{
		XT_Controler::CONDITION_NEG_JMP(iThread, iAxisPosReg, 0, 2);
	}
	XT_Controler::SGO(iThread, iAxis, fPos);

	if (1 == bIo_In_Origin_Dir)
	{
		XT_Controler::TILLIO_NEG(iThread, iIo_In_Origin);
	}
	else
	{
		XT_Controler::TILLIO(iThread, iIo_In_Origin);
	}

	XT_Controler::SGO(iThread, iAxis, fNeg);

	if (1 == bIo_In_Origin_Dir)
	{
		XT_Controler::TILLIO(iThread, iIo_In_Origin);
	}
	else
	{
		XT_Controler::TILLIO_NEG(iThread, iIo_In_Origin);
	}

	XT_Controler::GET_OUTPUT_POS(iThread, iAxis, iAxisPosReg);

	XT_Controler::ADD_R_C(iThread, iAxisPosReg, iAxisPosReg, 0);

	XT_Controler::SGO_R(iThread, iAxis, iAxisPosReg);

	XT_Controler::TILLSTOP(iThread, iAxis);

	XT_Controler::GET_MAX_VEL(iThread, iAxis, iVelReg);
	XT_Controler::SET_REG_VAL(iThread, iMulReg, fSpeed_2Seek);
	XT_Controler::MUL_R_R(iThreadID, iVelReg, iMulReg, iMulReg);
	XT_Controler::SET_MAX_VEL_R(iThread, iAxis, iMulReg);

	XT_Controler:: SGO(iThread, iAxis, fPos);

	if (1 == bIo_In_Origin_Dir)
	{
		XT_Controler::TILLIO(iThread, iIo_In_Origin);
		XT_Controler::TILLIO_NEG(iThread, iIo_In_Origin);
	}
	else
	{
		XT_Controler::TILLIO_NEG(iThread, iIo_In_Origin);
		XT_Controler::TILLIO(iThread, iIo_In_Origin);
	}

	XT_Controler::SGO(iThread, iAxis, fNeg);

	if (1 == bIo_In_Origin_Dir)
	{
		XT_Controler::TILLIO(iThread, iIo_In_Origin);
	}
	else
	{
		XT_Controler::TILLIO_NEG(iThread, iIo_In_Origin);
	}

	XT_Controler::GET_OUTPUT_POS(iThread, iAxis, iAxisPosReg);

	XT_Controler::ADD_R_C(iThread, iAxisPosReg, iAxisPosReg, fOffset);

	XT_Controler::SET_MAX_VEL(iThread, iAxis, iVelReg);

	XT_Controler::SGO_R(iThread, iAxis, iAxisPosReg);

	XT_Controler::TILLSTOP(iThread, iAxis);

	XT_Controler::SET_AXIS_ZEROS(iThreadID, iAxis, fNew_Pos);
}

void MotionDlg::Example_Dispensing()
{
	int res = 0;

	int nPoint_Index = 0;

	int giAxis[3] = { 0, 1, 2 };
	int gbComb[3] = { 1, 1, 1 };
	double gfVel[3] = { 1000, 1000, 1000 };
	double gfAcc[3] = { 5000, 5000, 5000 };
	double gfJerk[3] = { 50000, 50000, 50000 };
	double fWait_Time = 0.05;
	double fON_Time = 0.05;
	double fZ_Pos = 10;
	double fSize = 10;

	res = XT_Controler_Extend::Set_Curve_Param(0, 1, 3, giAxis, gfVel, gfAcc, gfJerk, gbComb);
	if (1 != res)
	{
		AfxMessageBox(_T("Controller do not support this function."));
		return;
	}

	double gfPos0[3] = { 0, 0, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos0, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	double gfPos1[3] = { 0, 0, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos1, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Wait_Time(0, fWait_Time, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 1);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Wait_Time(0, fON_Time, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 0);
	assert(1 == res);

	double gfPos2[3] = { fSize, 0, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos2, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Wait_Time(0, fWait_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 1);
	assert(1 == res);
	res = XT_Controler_Extend::Append_Wait_Time(0, fON_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 0);
	assert(1 == res);

	double gfPos3[3] = { fSize, fSize, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos3, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Wait_Time(0, fWait_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 1);
	assert(1 == res);
	res = XT_Controler_Extend::Append_Wait_Time(0, fON_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 0);
	assert(1 == res);

	double gfPos4[3] = { 0, fSize, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos4, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Wait_Time(0, fWait_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 1);
	assert(1 == res);
	res = XT_Controler_Extend::Append_Wait_Time(0, fON_Time, 0, nPoint_Index);
	assert(1 == res);
	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 0, 0, Output_0, 0);
	assert(1 == res);

	double gfPos5[3] = { 0, fSize, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos5, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Exec_Curve(0, 0, 1, 1);
	assert(1 == res);
}

void MotionDlg::Example_Moving_Dispense()
{
	int res = 0;

	int nPoint_Index = 0;

	int giAxis[3] = { 0, 1, 2 };
	int gbComb[3] = { 1, 1, 1 };
	double gfVel[3] = { 1000, 1000, 1000 };
	double gfAcc[3] = { 50000, 50000, 50000 };
	double gfJerk[3] = { 5000000, 5000000, 5000000 };
	double fWait_Time = 0.05;
	double fON_Time = 0.05;
	double fZ_Pos = 0;
	double fSize = 10;

	res = XT_Controler_Extend::Set_Curve_Param(0, 1, 3, giAxis, gfVel, gfAcc, gfJerk, gbComb);
	if (1 != res)
	{
		AfxMessageBox(_T("Controller do not support this function"));
		return;
	}

	double gfPos0[3] = { 0, 0, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos0, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	double gfPos1[3] = { 0, 0, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos1, 100, 100, 0, nPoint_Index);
	assert(1 == res);


	double gfPos2[3] = { 0, fSize, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos2, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 0, 2, 0, Output_0, 1);
	assert(1 == res);

	double gfPos3[3] = { fSize, fSize, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos3, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	double gfPos4[3] = { fSize, 0, fZ_Pos };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos4, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos1, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos0, 100, 100, 0, nPoint_Index);
	assert(1 == res);

	res = XT_Controler_Extend::Set_Cur_Trig_Output(0, 1, 2, 0, Output_0, 0);
	assert(1 == res);

	res = XT_Controler_Extend::Exec_Curve(0, 0, 1, 1);
	assert(1 == res);
}

void MotionDlg::Example_Flying_Dispense()
{
	int res = 0;

	double fSize = 30;
	double fVel = 100;

	int nPoint_Index = 0;
	double fElapseTime_ms = 2;
	double fPos_Step = 1.5;
	CString Text;
	Text.Format(_T("Curve isometric %fmm output , each point output %fms ."), fPos_Step, fElapseTime_ms);
	AfxMessageBox(Text);

	int giAxis[3] = { 0, 1, 2 };
	int gbComb[3] = { 1, 1, 1 };
	double gfVel[3] = { 1000, 1000, 1000 };
	double gfAcc[3] = { 50000, 50000, 50000 };
	double gfJerk[3] = { 5000000, 5000000, 5000000 };

	res = XT_Controler_Extend::Set_Curve_Param(0, 1, 3, giAxis, gfVel, gfAcc, gfJerk, gbComb);
	if (1 != res)
	{
		AfxMessageBox(_T("Controller do not support this function"));
		return;
	}

	double gfPos0[3] = { 0, 0, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos0, fVel, fVel, 0, nPoint_Index);
	assert(1 == res);

	double gfPos1[3] = { fSize, 0, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos1, fVel, fVel, 0, nPoint_Index);
	assert(1 == res);

	double gfPos2[3] = { fSize, fSize, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos2, fVel, fVel, 0, nPoint_Index);
	assert(1 == res);

	double gfPos3[3] = { 0, fSize, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos3, fVel, fVel, 0, nPoint_Index);
	assert(1 == res);

	double gfPos4[3] = { 0, 0, 0 };
	res = XT_Controler_Extend::Append_Line_Pos(0, 3, giAxis, gfPos4, fVel, fVel, 0, nPoint_Index);
	assert(1 == res);

	double fAllLength = 0;
	for (int i = 0; i < nPoint_Index; i++)
	{
		fAllLength += XT_Controler_Extend::Get_Curve_Length(0, i);
	}
	fAllLength += sqrt(DBL_EPSILON);

	int nExport_Count = (int)(fAllLength / fPos_Step);
	for (int i = 0; i < nExport_Count; i++)
	{
		res = XT_Controler_Extend::Set_Trig_Output(0, 0, fPos_Step * i, 0.008, Output_0, 1);
		assert(1 == res);

		res = XT_Controler_Extend::Set_Trig_Output(0, 0, fPos_Step * i, 0.008 + fElapseTime_ms / 1000, Output_0, 0);
		assert(1 == res);
	}

	res = XT_Controler_Extend::Exec_Curve(0, 0, 1, 1);
	assert(1 == res);
}


BEGIN_MESSAGE_MAP(MotionDlg, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_Init, &MotionDlg::OnBnClickedButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_ZXY_Origin, &MotionDlg::OnBnClickedButtonZxyOrigin)
	ON_BN_CLICKED(IDC_BUTTON_X_Origin, &MotionDlg::OnBnClickedButtonXOrigin)
	ON_BN_CLICKED(IDC_BUTTON_Y_Origin, &MotionDlg::OnBnClickedButtonYOrigin)
	ON_BN_CLICKED(IDC_BUTTON_Z_Origin, &MotionDlg::OnBnClickedButtonZOrigin)
	ON_BN_CLICKED(IDC_BUTTON_Interpolation, &MotionDlg::OnBnClickedButtonInterpolation)
	ON_BN_CLICKED(IDC_BUTTON_Dispensing, &MotionDlg::OnBnClickedButtonDispensing)
	ON_BN_CLICKED(IDC_BUTTON_FlyingDispensing, &MotionDlg::OnBnClickedButtonFlyingdispensing)
	ON_BN_CLICKED(IDC_BUTTON_MovingDispensing, &MotionDlg::OnBnClickedButtonMovingdispensing)
	ON_BN_CLICKED(IDC_CHECK_Output, &MotionDlg::OnBnClickedCheckOutput)
	ON_BN_CLICKED(IDCANCEL, &MotionDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_Update, &MotionDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_A_Origin, &MotionDlg::OnBnClickedButtonAOrigin)
	ON_BN_CLICKED(IDC_BUTTON_B_Origin, &MotionDlg::OnBnClickedButtonBOrigin)
	ON_BN_CLICKED(IDC_BUTTON_C_Origin, &MotionDlg::OnBnClickedButtonCOrigin)
	ON_BN_CLICKED(IDC_BUTTON_Z_Running, &MotionDlg::OnBnClickedButtonZRunning)
	ON_BN_CLICKED(IDC_BUTTON_M_Origin, &MotionDlg::OnBnClickedButtonMOrigin)
	ON_BN_CLICKED(IDC_BUTTON1, &MotionDlg::OnBnClickedHomeAll)
	ON_BN_CLICKED(IDC_BUTTON_L_Origin, &MotionDlg::OnBnClickedButtonLOrigin)
	ON_BN_CLICKED(IDC_BUTTON_N_Origin, &MotionDlg::OnBnClickedButtonNOrigin)
END_MESSAGE_MAP()


// MotionDlg message handlers


void MotionDlg::OnBnClickedButtonInit()
{
	// TODO: Add your control notification handler code here
	if (isInit) return; 
	int res = 0;

	KillTimer(0);
	/*m_cMaxVel_X.SetWindowText(_T("4"));
	m_cMaxVel_Y.SetWindowText(_T("20"));
	m_cMaxVel_Z.SetWindowText(_T("20"));
	m_cMaxVel_A.SetWindowText(_T("23"));
	m_cMaxVel_B.SetWindowText(_T("17"));
	m_cMaxVel_C.SetWindowText(_T("80"));*/

	m_cMaxVel_X.SetWindowText(_T("4"));
	m_cMaxVel_Y.SetWindowText(_T("4"));
	m_cMaxVel_Z.SetWindowText(_T("4"));
	m_cMaxVel_A.SetWindowText(_T("4"));
	m_cMaxVel_B.SetWindowText(_T("4"));
	m_cMaxVel_C.SetWindowText(_T("4"));
	m_cMaxVel_M.SetWindowText(_T("4"));
	m_cMaxVel_N.SetWindowText(_T("4"));
	m_cMaxVel_L.SetWindowText(_T("4"));

	m_cMaxAcc_X.SetWindowText(_T("40"));
	m_cMaxAcc_Y.SetWindowText(_T("40"));
	m_cMaxAcc_Z.SetWindowText(_T("40"));
	m_cMaxAcc_A.SetWindowText(_T("40"));
	m_cMaxAcc_B.SetWindowText(_T("40"));
	m_cMaxAcc_C.SetWindowText(_T("40"));
	m_cMaxAcc_M.SetWindowText(_T("40"));
	m_cMaxAcc_N.SetWindowText(_T("40"));
	m_cMaxAcc_L.SetWindowText(_T("40"));

	m_cMaxJerk_X.SetWindowText(_T("400"));
	m_cMaxJerk_Y.SetWindowText(_T("400"));
	m_cMaxJerk_Z.SetWindowText(_T("400"));
	m_cMaxJerk_A.SetWindowText(_T("400"));
	m_cMaxJerk_B.SetWindowText(_T("400"));
	m_cMaxJerk_C.SetWindowText(_T("400"));
	m_cMaxJerk_M.SetWindowText(_T("400"));
	m_cMaxJerk_N.SetWindowText(_T("400"));
	m_cMaxJerk_L.SetWindowText(_T("400"));

	m_cPulseRatio_X.SetWindowText(_T("1000"));
	m_cPulseRatio_Y.SetWindowText(_T("1000"));
	m_cPulseRatio_Z.SetWindowText(_T("500"));
	m_cPulseRatio_A.SetWindowText(_T("1333.333333333333333333"));
	m_cPulseRatio_B.SetWindowText(_T("1818.181818181818181818"));
	m_cPulseRatio_C.SetWindowText(_T("-500"));
	m_cPulseRatio_M.SetWindowText(_T("10000"));
	m_cPulseRatio_N.SetWindowText(_T("10000"));
	m_cPulseRatio_L.SetWindowText(_T("200"));

	m_cStep.SetWindowText(_T("0.1"));

	LPWSTR pTarget = L"127.0.0.1";

#if 1
	XT_Controler::InitDevice_PC_Local_Controler(1);
#else
	pTarget = L"192.168.1.99";
	XT_Controler::InitDevice_PC_Local_Controler(0);
#endif

	res = XT_Controler::beCurConnectServerAndInterfaceBoard();
	if (1 != res)
	{
		res = XT_Controler::ConnectControlServer(pTarget, 0, 0);
		if (1 != res)
		{
			return;
		}
	}


	XT_Controler::ReBuildSystem();

	Sleep(300);

	res = XT_Controler::ConnectControlServer(pTarget, 0, 0);
	assert(1 == res);


	XT_Controler_Extend::Start_Buffer_Sync(Thread_Buffer_Sync);


	int iThread_Init = 0;

	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 1, Axis_X);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 2, Axis_Y);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 0, Axis_Z); 

	//XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 0, Axis_X);
	//XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 1, Axis_Y);
	//XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 2, Axis_Z);

	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 4, Axis_A);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 5, Axis_B);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 1, 3, Axis_C);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 2, 0, Axis_L);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 2, 1, Axis_M);
	XT_Controler::SET_AXIS_MAP(iThread_Init, 2, 2, Axis_N);

	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 12, 0, Origin_X);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 11, 0, Origin_Y);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 15, 0, Origin_Z);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 6, 0, Origin_A);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 2, 0, Origin_B);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 1, 6, 8, 0, Origin_C);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 2, 4, 0, 0, Origin_L);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 2, 4, 1, 0, Origin_M);
	XT_Controler::SET_IOIN_MAP(iThread_Init, 2, 4, 2, 0, Origin_N);


#if 1
	//XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 0, Output_0);

#else
	XT_Controler_Extend::DigitOut_PreciousTrig_Init(1, 4, 0, 100, 101, 102, 0, Output_0);
#endif


#if 1

	XT_Controler::SET_IOOUT_MAP(iThread_Init, 2, 4, 8, EN_L);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 2, 4, 9, EN_M);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 2, 4, 10, EN_N);

	XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_L, 1);
	XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_M, 1);
	XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_N, 1);
/*
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 15, EN_X);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 16, EN_Y);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 17, EN_Z);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 13, En_A);
	XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 14, En_B);*/
	//XT_Controler::SET_IOOUT_MAP(iThread_Init, 1, 4, 2, En_C);

	//XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_X, 1);
	//XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_Y, 1);
	//XT_Controler::SET_OUTPUT_IO(iThread_Init, EN_Z, 1);
	//XT_Controler::SET_OUTPUT_IO(iThread_Init, En_A, 0);
	//XT_Controler::SET_OUTPUT_IO(iThread_Init, En_B, 0);
	////XT_Controler::SET_OUTPUT_IO(iThread_Init, En_C, 1);
#endif

	//Temporary Comment For Connecting Simulator
	//XT_Controler::WaitForAllInsFinish(iThread_Init);

	XT_Controler_Extend::HandWheel_Init(15, 201, 1);
	XT_Controler_Extend::HandWheel_Init(15, 202, 2);
	XT_Controler_Extend::HandWheel_Init(15, 203, 3);
	XT_Controler_Extend::HandWheel_Init(15, 204, 4);
	XT_Controler_Extend::HandWheel_Init(15, 205, 5);
	XT_Controler_Extend::HandWheel_Init(15, 206, 6);

	XT_Controler_Extend::HandWheel_Bind_Axis(1, Axis_X, 0.01);
	XT_Controler_Extend::HandWheel_Bind_Axis(2, Axis_Y, 0.01);
	XT_Controler_Extend::HandWheel_Bind_Axis(3, Axis_A, 0.01);
	XT_Controler_Extend::HandWheel_Bind_Axis(4, Axis_Z, 0.001);
	XT_Controler_Extend::HandWheel_Bind_Axis(5, Axis_B, 0.01);
	XT_Controler_Extend::HandWheel_Bind_Axis(6, Axis_C, 0.01);

	OnBnClickedButtonUpdate();
	UpdateParam_X();
	UpdateParam_Y();
	UpdateParam_Z();
	UpdateParam_A();
	UpdateParam_B();
	UpdateParam_C();
	UpdateParam_L();
	UpdateParam_M();
	UpdateParam_N();

	//AfxMessageBox(_T("Initialization Finished"), MB_SYSTEMMODAL);
	//m_cInit_Button.SetWindowText(_T("Reset Controller"));
	isInit = true;


	SetTimer(0, 10, 0);
}


void MotionDlg::OnBnClickedButtonZxyOrigin()
{
	// TODO: Add your control notification handler code here

	UpdateParam_X();
	UpdateParam_Y();
	UpdateParam_Z();

	Axis_SeekOrigin_PN(Thread_Z, Axis_Z, Origin_Z, 0, Axis_Z_Range, -Axis_Z_Range, 0, 0, 0.1);

#if 0

	XT_Controler::WaitForAllInsFinish(Thread_Z);

	Axis_SeekOrigin_PN(Thread_X, Axis_X, Origin_X, 0, Axis_X_Range + 10, -Axis_X_Range - 10, 0, 0, 0.1);
	Axis_SeekOrigin_PN(Thread_Y, Axis_Y, Origin_Y, 0, Axis_Y_Range + 10, -Axis_Y_Range - 10, 0, 0, 0.1);
#else

	XT_Controler::TILL_THREAD_INS_FINISH(Thread_X, Thread_Z);
	Axis_SeekOrigin_PN(Thread_X, Axis_X, Origin_X, 0, Axis_X_Range, -Axis_X_Range, 0, 0, 0.1);

	XT_Controler::TILL_THREAD_INS_FINISH(Thread_Y, Thread_Z);
	Axis_SeekOrigin_PN(Thread_Y, Axis_Y, Origin_Y, 0, Axis_Y_Range, -Axis_Y_Range, 0, 0, 0.1);
#endif
}


void MotionDlg::OnBnClickedButtonXOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_X();

	Axis_SeekOrigin_PN(Thread_X, Axis_X, Origin_X, 0, Axis_X_Range, -Axis_X_Range, 0, 0, 0.1);
	
	XT_Controler::SET_MAX_VEL(Thread_X, Axis_X, 4);
	XT_Controler::SET_MAX_ACC(Thread_X, Axis_X, 40);
	XT_Controler::SET_MAX_JERK(Thread_X, Axis_X, 400);

	XT_Controler::SGO(Thread_X, Axis_X, 4.15);

	XT_Controler::TILLSTOP(Thread_X, Axis_X);

	XT_Controler::SET_AXIS_ZEROS(Thread_X, Axis_X, 0);
}


void MotionDlg::OnBnClickedButtonYOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_Y();

	Axis_SeekOrigin_PN(Thread_Y, Axis_Y, Origin_Y, 0, Axis_Y_Range, -Axis_Y_Range, 0, 0, 0.1);
	
	XT_Controler::SET_MAX_VEL(Thread_Y, Axis_Y, 4);
	XT_Controler::SET_MAX_ACC(Thread_Y, Axis_Y, 40);
	XT_Controler::SET_MAX_JERK(Thread_Y, Axis_Y, 400);

	//XT_Controler::SET_REG_VAL(Thread_Y, 2, 4);
	//XT_Controler::MUL_R_R(Thread_Y, 1, 2, 2);
	//XT_Controler::SET_MAX_VEL_R(Thread_Y, Axis_Y, 2);

	XT_Controler::SGO(Thread_Y, Axis_Y, 15.65);

	XT_Controler::TILLSTOP(Thread_Y, Axis_Y);

	XT_Controler::SET_AXIS_ZEROS(Thread_Y, Axis_Y, 0);

}


void MotionDlg::OnBnClickedButtonZOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_Z();

	Axis_SeekOrigin_PN(Thread_Z, Axis_Z, Origin_Z, 1, Axis_Z_Range, -Axis_Z_Range, 0, 0, 0.1);

	XT_Controler::SET_MAX_VEL(Thread_Z, Axis_Z, 4);
	XT_Controler::SET_MAX_ACC(Thread_Z, Axis_Z, 40);
	XT_Controler::SET_MAX_JERK(Thread_Z, Axis_Z, 400);

	XT_Controler::SGO(Thread_Z, Axis_Z, 35.91);

	XT_Controler::TILLSTOP(Thread_Z, Axis_Z);

	XT_Controler::SET_AXIS_ZEROS(Thread_Z, Axis_Z, 0);

}

void MotionDlg::OnBnClickedButtonAOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_A();

	Axis_SeekOrigin_PN(Thread_A, Axis_A, Origin_A, 1, Axis_A_Range, -Axis_A_Range*2, 0, -5.21, 0.1);

}


void MotionDlg::OnBnClickedButtonBOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_B();

	Axis_SeekOrigin_PN(Thread_B, Axis_B, Origin_B, 1, Axis_B_Range, -Axis_B_Range*2, 0, -3.89, 0.1);

}


void MotionDlg::OnBnClickedButtonCOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_C();

	Axis_SeekOrigin_PN(Thread_C, Axis_C, Origin_C, 1, Axis_C_Range, -Axis_C_Range*2, 0, 0, 0.1);

}

void MotionDlg::OnBnClickedButtonInterpolation()
{
	// TODO: Add your control notification handler code here
	int res = 0;

	int nPoint_Index = 0;

	int giAxis[3] = { Axis_X, Axis_Y, Axis_Z };
	double gfVel[3] = { 1000, 1000, 1000 };
	double gfAcc[3] = { 5000, 5000, 5000 };
	double gfJerk[3] = { 50000, 50000, 50000 };
	int gbComb[3] = { 1, 1, 1 };

	double gfPos0[3] = { 10, 20, 30 };

	XT_Controler::TILL_INTERPOLATION_S(0, gfPos0, giAxis, 3, 1, gfVel, gfAcc, gfJerk, gbComb, gfVel[0], gfAcc[0], gfJerk[0], 0);
}


void MotionDlg::OnBnClickedButtonDispensing()
{
	// TODO: Add your control notification handler code here
	Example_Dispensing();
}


void MotionDlg::OnBnClickedButtonFlyingdispensing()
{
	// TODO: Add your control notification handler code here
	Example_Flying_Dispense();
}


void MotionDlg::OnBnClickedButtonMovingdispensing()
{
	// TODO: Add your control notification handler code here
	Example_Moving_Dispense();
}


void MotionDlg::OnBnClickedCheckOutput()
{
	// TODO: Add your control notification handler code here
	int res = 0;

	int bState = 0;
	res = XT_Controler_Extend::Get_IoOut_State(Output_0, bState);
	assert(1 == res);

	res = XT_Controler_Extend::DigitOut_PreciousTrig_SetCurIoOutput(Output_0, !bState);
	assert(1 == res);
}


void MotionDlg::OnBnClickedCancel()
{
	//// TODO: Add your control notification handler code here
	int res = 0;

	XT_Controler::InitDevice_PC_Local_Controler(0);

	res = XT_Controler::beCurConnectServerAndInterfaceBoard();
	if (1 == res)
	{
		//XT_Controler::CloseMotionControlerServer(); //someting wrong
	}

	XT_Controler_Extend::Stop_Buffer_Sync();

	XT_Controler::ReleaseDevice();

	OnCancel();
}


void MotionDlg::OnBnClickedButtonUpdate()
{
	// TODO: Add your control notification handler code here

	//update pulse ratio
	CString Text;

	m_cPulseRatio_X.GetWindowText(Text);
	double fPulseRaito_X = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_X)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_Y.GetWindowText(Text);
	double fPulseRaito_Y = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_Y)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_Z.GetWindowText(Text);
	double fPulseRaito_Z = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_Z)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_A.GetWindowText(Text);
	double fPulseRaito_A = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_A)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_B.GetWindowText(Text);
	double fPulseRaito_B = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_B)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_C.GetWindowText(Text);
	double fPulseRaito_C = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_C)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}

	m_cPulseRatio_L.GetWindowText(Text);
	double fPulseRaito_L = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_L)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_M.GetWindowText(Text);
	double fPulseRaito_M = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_M)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}
	m_cPulseRatio_N.GetWindowText(Text);
	double fPulseRaito_N = _wtof(Text.GetBuffer());
	if (0 == fPulseRaito_N)
	{
		AfxMessageBox(_T("pulse ratio should not be 0"));
		return;
	}

	XT_Controler::SET_AXIS_SCALE(Thread_X, Axis_X, fPulseRaito_X * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_Y, Axis_Y, fPulseRaito_Y * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_Z, Axis_Z, fPulseRaito_Z * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_A, Axis_A, fPulseRaito_A * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_B, Axis_B, fPulseRaito_B * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_C, Axis_C, fPulseRaito_C * 65536);

	XT_Controler::SET_AXIS_SCALE(Thread_L, Axis_L, fPulseRaito_L * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_M, Axis_M, fPulseRaito_M * 65536);
	XT_Controler::SET_AXIS_SCALE(Thread_N, Axis_N, fPulseRaito_N * 65536);
}

void MotionDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	int res = 0;
	CString Text;
	double fVal;

	{
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_X, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_X.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Y, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_Y.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_Z.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_A, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_A.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_B, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_B.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_C, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_C.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_L, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_L.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_M, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_M.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_N, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurPos_N.SetWindowText(Text);
	}

	{
		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_X, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_X.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_Y, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_Y.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_Z, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_Z.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_A, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_A.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_B, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_B.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_C, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_C.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_L, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_L.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_M, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_M.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Vel(Axis_N, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurVel_N.SetWindowText(Text);
	}

	{
		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_X, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_X.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_Y, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_Y.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_Z, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_Z.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_A, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_A.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_B, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_B.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_C, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_C.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_L, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_L.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_N, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_N.SetWindowText(Text);

		res = XT_Controler_Extend::Get_Cur_Axis_Acc(Axis_M, fVal);
		assert(1 == res);
		Text.Format(_T("%.3f"), fVal);
		m_cCurAcc_M.SetWindowText(Text);
	}

	{
		int bRun = 0;

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_X, bRun);
		assert(1 == res);
		m_cMove_X.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_Y, bRun);
		assert(1 == res);
		m_cMove_Y.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_Z, bRun);
		assert(1 == res);
		m_cMove_Z.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_A, bRun);
		assert(1 == res);
		m_cMove_A.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_B, bRun);
		assert(1 == res);
		m_cMove_B.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_C, bRun);
		assert(1 == res);
		m_cMove_C.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_L, bRun);
		assert(1 == res);
		m_cMove_L.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_M, bRun);
		assert(1 == res);
		m_cMove_M.SetCheck(bRun);

		res = XT_Controler_Extend::Get_Cur_Axis_State(Axis_N, bRun);
		assert(1 == res);
		m_cMove_N.SetCheck(bRun);
	}

	{

		int bState = 0;

		res = XT_Controler_Extend::Get_IoIn_State(Origin_X, bState);
		assert(1 == res);
		m_cOrigin_X.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_Y, bState);
		assert(1 == res);
		m_cOrigin_Y.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_Z, bState);
		assert(1 == res);
		m_cOrigin_Z.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_A, bState);
		assert(1 == res);
		m_cOrigin_A.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_B, bState);
		assert(1 == res);
		m_cOrigin_B.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_C, bState);
		assert(1 == res);
		m_cOrigin_C.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_L, bState);
		assert(1 == res);
		m_cOrigin_L.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_M, bState);
		assert(1 == res);
		m_cOrigin_M.SetCheck(bState);

		res = XT_Controler_Extend::Get_IoIn_State(Origin_N, bState);
		assert(1 == res);
		m_cOrigin_N.SetCheck(bState);

	}

	{
		int bState = 0;

		res = XT_Controler_Extend::Get_IoOut_State(Output_0, bState);
		assert(1 == res);
		m_cOutput.SetCheck(bState);
	}

	CDialog::OnTimer(nIDEvent);
}

bool MotionDlg::isMotionDriverInit()
{
	return isInit;
}

bool MotionDlg::move_AA_Z(double stepSize, double targetPos)
{
	CString logString;
	logString.Format(_T("[move_AA_Z] stepSize: %f , targetPos: %f"), stepSize, targetPos);
	Log::GetInstance()->WriteString(logString);
	double currPos = 0; 
	double direction = 1;
	int res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, currPos);
	if (targetPos - currPos < 0) {
		direction = -1;
	}
	assert(1 == res);
	XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, direction*stepSize, targetPos);
	while (currPos - targetPos <= 0.01)
	{
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, currPos);
		logString.Format(_T("[move_AA_Z] current pos: %f "), currPos);
		Log::GetInstance()->WriteString(logString);
	}
	return true;
}

bool MotionDlg::move_AA_Y(double stepSize, double targetPos)
{
	XT_Controler::SET_REG_VAL(Thread_Y, 2, 6);
	XT_Controler::MUL_R_R(Thread_Y, 1, 2, 2);
	XT_Controler::SET_MAX_VEL_R(Thread_Y, Axis_Y, 2);
	CString logString;
	logString.Format(_T("[move_AA_Y] stepSize: %f , targetPos: %f"), stepSize, targetPos);
	Log::GetInstance()->WriteString(logString);
	if (targetPos > Axis_Y_Range)
	{
		targetPos = Axis_Y_Range;
		Log::GetInstance()->WriteString(_T("[move_AA_Y] Move targetPos reached to limit."));
	}
	double currPos = 0;
	double direction = 1; 
	int res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Y, currPos);
	assert(1 == res);
	if (targetPos - currPos < 0) {
		direction = -1;
	}
	XT_Controler::SGO(Thread_Y, Axis_Y, targetPos);
	while (fabs(currPos - targetPos) >= 0.01)
	{
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Y, currPos);
		logString.Format(_T("[move_AA_Y...] current pos: %f "), currPos);
		Log::GetInstance()->WriteString(logString);
		Sleep(100);
	}
	return true;
}

bool MotionDlg::move(int iThreadID, int iAxisID, double speed, double targetPos, unsigned int axisRange)
{
	CString logString;
	logString.Format(axis[iAxisID]+_T(" speed: %f , targetPos: %f"), speed, targetPos);
	Log::GetInstance()->WriteString(logString);
	if (targetPos > axisRange)
	{
		targetPos = axisRange;
		Log::GetInstance()->WriteString(axis[iAxisID]+_T(" Move targetPos reached to limit."));
	}

	if (speed > 4)
	{
		speed = 0;
		Log::GetInstance()->WriteString(axis[iAxisID] + _T(" Moving speed(6) is too large."));
	}

	XT_Controler::SET_MAX_VEL(iThreadID, iAxisID, 4);
	XT_Controler::SET_MAX_ACC(iThreadID, iAxisID, 40);
	XT_Controler::SET_MAX_JERK(iThreadID, iAxisID, 400);

	XT_Controler::SET_REG_VAL(iThreadID, 2, speed);
	//XT_Controler::MUL_R_R(iThreadID, 1, 2, 2);
	//XT_Controler::SET_MAX_VEL_R(iThreadID, iAxisID, 2);

	XT_Controler::SGO(iThreadID, iAxisID, targetPos);
	double currPos = 0;
	int res = XT_Controler_Extend::Get_Cur_Axis_Pos(iAxisID, currPos);
	assert(1 == res);
	while (fabs(currPos - targetPos) >= 0.01)
	{
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(iAxisID, currPos);
		assert(1 == res);
		logString.Format(axis[iAxisID]+_T(" current pos: %f "), currPos);
		Log::GetInstance()->WriteString(logString);
		Sleep(100);
	}
	return true;
}

double MotionDlg::get_Z_Pos()
{
	int res;
	double mPos;
	res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, mPos);
	assert(1 == res);
	return mPos;
}

double MotionDlg::get_X_Pos()
{
	int res;
	double mPos;
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_X, mPos);
	assert(1 == res);
	return mPos;
}

double MotionDlg::get_Y_Pos()
{
	int res;
	double mPos;
		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Y, mPos);
	assert(1 == res);
	return mPos;
}

double MotionDlg::get_A_Pos()
{

	int res;
	double mPos;
	res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_A, mPos);
	assert(1 == res);
	return mPos;
}

double MotionDlg::get_B_Pos()
{

	int res;
	double mPos;
	res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_B, mPos);
	assert(1 == res);
	return mPos;
}

double MotionDlg::get_C_Pos()
{

	int res;
	double mPos;
	res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_C, mPos);
	assert(1 == res);
	return mPos;
}

void MotionDlg::OnBnClickedButtonZRunning()
{
	// TODO: Add your control notification handler code here
	double mPos = 0;
	double mStep = 10;
	CString mText;
	int res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, mPos);
	assert(1 == res);

	while (mPos < Axis_Z_Range - 10)
	{
		XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, mStep, Axis_Z_Range);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, mPos);
		assert(1 == res);

		mText.Format(_T("%.3f"), mPos);
		m_cCurPos_Z.SetWindowText(mText);
	}
	XT_Controler_Extend::JOG_STOP(Thread_Z, Axis_Z);

	while (mPos > -Axis_Z_Range + 10)
	{
		XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, -mStep, -Axis_Z_Range);

		res = XT_Controler_Extend::Get_Cur_Axis_Pos(Axis_Z, mPos);
		assert(1 == res);
		mText.Format(_T("%.3f"), mPos);
		m_cCurPos_Z.SetWindowText(mText);
	}
	XT_Controler_Extend::JOG_STOP(Thread_Z, Axis_Z);
}



void MotionDlg::OnBnClickedButtonMOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_M();
	Axis_SeekOrigin_PN(Thread_M, Axis_M, Origin_M, 0, Axis_M_Range, -Axis_M_Range, 0, 0, 0.1);
}


void MotionDlg::OnBnClickedHomeAll()
{
	// TODO: Add your control notification handler code here
	if (!isInit) {
		AfxMessageBox(_T("Motion driver does not init!"));
		return;
	}
	double curr_pos = this->get_X_Pos(); 
	double mStep = 1;
	double direction = 1;
	if (AA_HOME_X - curr_pos < 0) direction = -1;
	XT_Controler_Extend::JOG_GO(Thread_X, Axis_X, direction*mStep, AA_HOME_X);

	curr_pos = this->get_Y_Pos();
	if (AA_HOME_Y - curr_pos < 0) direction = -1;
	mStep = AA_HOME_Y - curr_pos;
	XT_Controler_Extend::JOG_GO(Thread_Y, Axis_Y, direction*mStep, AA_HOME_Y);

	curr_pos = this->get_Z_Pos();
	if (AA_HOME_Z - curr_pos < 0) direction = -1;
	mStep = AA_HOME_Z - curr_pos;
	XT_Controler_Extend::JOG_GO(Thread_Z, Axis_Z, direction*mStep, AA_HOME_Z);

	curr_pos = this->get_A_Pos();
	if (AA_HOME_A - curr_pos < 0) direction = -1;
	mStep = AA_HOME_A - curr_pos;
	XT_Controler_Extend::JOG_GO(Thread_A, Axis_A, direction*mStep, AA_HOME_A);

	curr_pos = this->get_B_Pos();
	if (AA_HOME_B - curr_pos < 0) direction = -1;
	mStep = AA_HOME_B - curr_pos;
	XT_Controler_Extend::JOG_GO(Thread_B, Axis_B, direction*mStep, AA_HOME_B);

	curr_pos = this->get_C_Pos();
	if (AA_HOME_C - curr_pos < 0) direction = -1;
	mStep = AA_HOME_C - curr_pos;
	XT_Controler_Extend::JOG_GO(Thread_C, Axis_C, direction*mStep, AA_HOME_C);
}


void MotionDlg::OnBnClickedButtonLOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_L();

	Axis_SeekOrigin_PN(Thread_L, Axis_L, Origin_L, 0, Axis_L_Range, -Axis_L_Range, 0, 0, 0.1);

}


void MotionDlg::OnBnClickedButtonNOrigin()
{
	// TODO: Add your control notification handler code here
	UpdateParam_N();

	Axis_SeekOrigin_PN(Thread_N, Axis_N, Origin_N, 0, Axis_N_Range, -Axis_N_Range, 0, 0, 0.1);

}
