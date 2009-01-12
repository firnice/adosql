; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdoSQLDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AdoSQL.h"

ClassCount=3
Class1=CAdoSQLApp
Class2=CAdoSQLDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ADOSQL_DIALOG

[CLS:CAdoSQLApp]
Type=0
HeaderFile=AdoSQL.h
ImplementationFile=AdoSQL.cpp
Filter=N

[CLS:CAdoSQLDlg]
Type=0
HeaderFile=AdoSQLDlg.h
ImplementationFile=AdoSQLDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=AdoSQLDlg.h
ImplementationFile=AdoSQLDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADOSQL_DIALOG]
Type=1
Class=CAdoSQLDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BTN_CON,button,1342242816

