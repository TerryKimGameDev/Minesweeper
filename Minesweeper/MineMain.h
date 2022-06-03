#pragma once

#include "wx/wx.h"
class MineMain : public wxFrame
{
public:
	MineMain();
	~MineMain();

public:
	/*wxButton *mbttn1 = nullptr;
	wxTextCtrl *mtxtCnt = nullptr;
	wxListBox *mLst = nullptr;

	void onbttnclicked(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();*/

	int m_width = 10;
	int m_height = 10;

	wxButton** mbttn;

	int* nField = nullptr;
	bool bFclick = true;

	void onbttnclicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

