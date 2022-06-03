#include "MineApp.h"
wxIMPLEMENT_APP(MineApp);

MineApp::MineApp() {}

MineApp::~MineApp() {}


bool MineApp::OnInit() { 

	MineFrame = new MineMain();
	MineFrame->Show();
	return true; 
}
