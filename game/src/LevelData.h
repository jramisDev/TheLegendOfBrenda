class LevelData {

	char* nombreMapa;
	Texture2D img;

	Rectangle rect;

public:
	LevelData() {};
	LevelData(Texture2D pImg, char* pNombre) {
		img = pImg;
		nombreMapa = pNombre;
		rect = { 750,100, 50, 200 };
	}

	Texture2D getImg() { return img; }
	void setImg(Texture2D pImg) { img = pImg; }

	char* getNombreMapa() { return nombreMapa; }

	Rectangle getRectangle() { return rect; }
	void setRectangle(Rectangle pRectangle) { rect = pRectangle; }

	void drawLevel() {
		DrawTexture(img, 0, 0, WHITE);	
	}

	void drawNameLevel() {
		DrawText(getNombreMapa(), 10, SCREEN_HEIGHT-25, 25, BLACK);
	}

	void drawExit(){
		DrawRectangleRec(rect, BLUE);
	}
};