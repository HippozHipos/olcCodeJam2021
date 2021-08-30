#define OLC_PGE_APPLICATION
#include "application.h"

int main()
{
	Application app{};
	if (app.Construct(600, 600, 1, 1))
	{
		app.Start();
	}
}