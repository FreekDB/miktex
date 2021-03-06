/* WelcomePage.cpp:

   Copyright (C) 1999-2018 Christian Schenk

   This file is part of the MiKTeX Setup Wizard.

   The MiKTeX Setup Wizard is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2, or
   (at your option) any later version.

   The MiKTeX Setup Wizard is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the MiKTeX Setup Wizard; if not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA. */

#include "StdAfx.h"

#include "Setup.h"

#include "SetupWizard.h"
#include "WelcomePage.h"

BEGIN_MESSAGE_MAP(WelcomePage, CPropertyPage)
END_MESSAGE_MAP();

WelcomePage::WelcomePage() :
  CPropertyPage(IDD)
{
  m_psp.dwFlags |= PSP_HIDEHEADER;
}

BOOL WelcomePage::OnInitDialog()
{
  sheet = reinterpret_cast<SetupWizard *>(GetParent());
  BOOL ret = CPropertyPage::OnInitDialog();
  try
  {
    CWnd* wnd = GetDlgItem(IDC_WELCOME);
    if (wnd == nullptr)
    {
      MIKTEX_UNEXPECTED();
    }
    extern CFont fntWelcome;
    wnd->SetFont(&fntWelcome);
  }
  catch (const MiKTeXException& e)
  {
    sheet->ReportError(e);
  }
  catch (const exception& e)
  {
    sheet->ReportError(e);
  }
  return ret;
}

BOOL WelcomePage::OnSetActive()
{
  sheet->SetWizardButtons(PSWIZB_NEXT);
  return CPropertyPage::OnSetActive();
}

void WelcomePage::DoDataExchange(CDataExchange* dx)
{
  CPropertyPage::DoDataExchange(dx);
}

LRESULT WelcomePage::OnWizardNext()
{
  sheet->PushPage(IDD);
  return reinterpret_cast<LRESULT>(MAKEINTRESOURCE(IDD_LICENSE));
}
