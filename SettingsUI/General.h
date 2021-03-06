#pragma once
#include "afxwin.h"

#include <list>

class General : public CPropertyPage
{
	DECLARE_DYNAMIC(General)

public:
    General();
	virtual ~General();

	enum { IDD = IDD_GENERAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnApply();
    virtual BOOL OnInitDialog();
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()

private:
    std::wstring _url;

    void LoadSettings();
    std::list<CString> FindSkins(CString dir);
    std::list<CString> FindLanguages(CString dir);
    void LoadSkinInfo();
    bool RunOnStartup();
    void RunOnStartup(bool enable);

/* Auto-generated members follow*/
public:
    afx_msg void OnBnClickedWebsite();
private:
    CButton _startup;
    CButton _notify;
    CButton _sounds;
    CComboBox _lang;
    CStatic _skinGrp;
    CStatic _behaviorGrp;
    CStatic _languageGrp;
    CStatic _author;
    CButton _website;
    CComboBox _skins;
public:
    afx_msg void OnCbnSelchangeSkin();
};
