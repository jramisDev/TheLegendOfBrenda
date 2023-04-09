class LevelData {

	Screens screenActual;

	bool gameOver = false;

public:

	LevelData() {
		screenActual = GAME;
		gameOver = false;
	}

	Screens getScreenActual() { return screenActual; }
	void setScreenActual(Screens pScreen) { screenActual = pScreen; }

	bool isGameOver() { return gameOver; }
	void setGameOver(bool pGameOver) { gameOver = pGameOver; }

};