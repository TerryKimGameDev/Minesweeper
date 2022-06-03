#include "MineMain.h"

wxBEGIN_EVENT_TABLE(MineMain, wxFrame)
EVT_BUTTON(10001, onbttnclicked)
wxEND_EVENT_TABLE()

using namespace std;
MineMain::MineMain() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(30, 30), wxSize(800, 600)) {
	/*mbttn1 = new wxButton(this, 10001, "Click", wxPoint(10, 10), wxSize(150, 50));
	mtxtCnt = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	mLst = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));*/

	mbttn = new wxButton * [m_width * m_height];
	wxGridSizer* grid = new wxGridSizer(m_width, m_height, 0, 0);

	nField = new int[m_width * m_height];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (size_t x = 0; x < m_width; x++)
	{
		for (size_t y = 0; y < m_height; y++)
		{
			mbttn[y * m_width + x] = new wxButton(this, 10000 + (y* m_width + x));
			mbttn[y * m_width + x]->SetFont(font);
			grid->Add(mbttn[y * m_width + x], 1, wxEXPAND | wxALL);

			mbttn[y * m_width + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MineMain::onbttnclicked, this);

			nField[y * m_width + x] = 0;
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}

MineMain::~MineMain() {
	delete[] mbttn;
}

void MineMain::onbttnclicked(wxCommandEvent& evt)
{
	/*mLst->AppendString(mtxtCnt->GetValue());
	evt.Skip();*/

	//get the coordinate of button
	int x = (evt.GetId() - 10000) % m_width;
	int y = (evt.GetId() - 10000) / m_width;

	if (bFclick)
	{
		int mines = 30;

		while (mines)
		{
			int rx = rand() % m_width;
			int ry = rand() % m_height;

			if (nField[ry * m_width + rx] == 0 && rx != x && ry != y)
			{
				nField[ry * m_width + rx] = -1;
				mines--;
			}
		}
		bFclick = false;
	}
	mbttn[y * m_width + x]->Enable(false);

	if (nField[y * m_width + x] == -1)
	{
		wxMessageBox("YOu LOse LosER!! >: >");

		bFclick = true;
		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				nField[y * m_width + x] = 0;
				mbttn[y * m_width + x]->SetLabel("");
				mbttn[y * m_width + x]->Enable(true);
			}
		}
	}
	else
	{
		int minecount = 0;

		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if ((x + i) >= 0 && (x + i) < m_width && (y + j) >= 0 && (y + j) < m_height)
				{
					if (nField[(y+j)*m_width + (x+i)] == -1)
					{
						minecount++;
					}
				}
			}
		}

		if (minecount > 0)
		{
			mbttn[y * m_width + x]->SetLabel(to_string(minecount));
		}
	}

	evt.Skip();
}

