// CZXT_keshe.h : main header file for the CZXT_KESHE application
//

#if !defined(AFX_CZXT_KESHE_H__35BF2201_9656_4869_9445_077702098482__INCLUDED_)
#define AFX_CZXT_KESHE_H__35BF2201_9656_4869_9445_077702098482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCZXT_kesheApp:
// See CZXT_keshe.cpp for the implementation of this class
//

class CCZXT_kesheApp : public CWinApp
{
public:
	CCZXT_kesheApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCZXT_kesheApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCZXT_kesheApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CZXT_KESHE_H__35BF2201_9656_4869_9445_077702098482__INCLUDED_)
