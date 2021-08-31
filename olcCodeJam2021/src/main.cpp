#define OLC_PGE_APPLICATION
#include "application.h"

//REMEMBER FOR TOMORROW:
//enemy attacker is initialised with nullptr
//enemy bulletSpiteSheet is set to nullptr
//refactor the bullet code to seperate it out from character

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}