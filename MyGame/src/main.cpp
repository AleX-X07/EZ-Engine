#include <Loop.h>
#include <Game.h>

int main()
{
	Loop myLoop = Loop("MyGame");
	myLoop.SetGame(new Game());
	myLoop.Run();
	return 0;
}