#include <Loop.h>
#include <ExempleGame.h>

int main()
{
	Loop myLoop = Loop("ExempleGame");
	myLoop.SetGame(new ExempleGame());
	myLoop.Run();
	return 0;
}