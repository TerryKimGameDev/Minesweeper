#pragma once

#include "wx/wx.h"
#include "MineMain.h"
class MineApp : public wxApp
{

public:
	MineApp();
	~MineApp();

private:
	MineMain* MineFrame = nullptr;

public:
	virtual bool OnInit();
};

