#include "ProgramStates/ProgramState_MPMenu.h"

ProgramState_MPMenu::ProgramState_MPMenu(Program& _program)
            : ProgramState_Menu(_program) {
	addMenuItem("Host", &Program::pushState_MPHostMenu);

	addMenuItem("Join", &Program::pushState_MPJoinMenu);

	addGap();
	addMenuItem("Back", &Program::popState);
}
