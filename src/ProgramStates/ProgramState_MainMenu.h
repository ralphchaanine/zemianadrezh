#ifndef PROGRAMSTATE_MAINMENU_H_INCLUDED
#define PROGRAMSTATE_MAINMENU_H_INCLUDED

#include "ProgramState_Menu.h"

class ProgramState_MainMenu : public ProgramState_Menu {
	public:
		ProgramState_MainMenu(Program& _program);
		void onStateSwitch();
};

#endif // PROGRAMSTATE_MAINMENU_H_INCLUDED