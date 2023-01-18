#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "vector2d.h"
#include "C:\Users\burbu\source\repos\PracticasIngenieriaSoftware\4_Componentes\swalib-master\swalib_example\swalib_example\Game.h"

int Main(void)
{
	Game* game = new Game();
	game->InitGame();
	game->UpdateGame();
	game->EndGame();
	delete game;
	return 0;
}
