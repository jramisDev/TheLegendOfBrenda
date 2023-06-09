class Item {

	unsigned char exp;

	Vector2 currentPos;

	Texture2D img;

	Rectangle rect;

	Items item;

public:
	Item() {
		exp = 10;
		currentPos = startCharacterPosition();
		img = aidKitImg;
		rect = { currentPos.x,currentPos.y, 40, 40 };
		item = {AIDKIT};
	};
	Item(Texture2D pImg, Items pItem) {
		exp = 10;
		currentPos = startCharacterPosition();
		rect = { currentPos.x,currentPos.y, 40, 40 };
		img = pImg;
		item = pItem;

	};


	char getExp() { return exp; }

	Vector2 getCurrentPos() { return currentPos; }
	void setCurrentPos(Vector2 pPosition) { currentPos = pPosition; }

	Rectangle getRectangle() { return rect; }

	Texture2D getImg() { return img; }

	Items getItem() { return item; }

	void drawItem() {
		//DrawRectangle(getCurrentPos().x, getCurrentPos().y, 40, 40, BLACK);//SoloDebugColisiones
		DrawTexture(getImg(), getCurrentPos().x, getCurrentPos().y, WHITE);
	}

	void removeItem() {
		currentPos = { -500,-500 };
		rect = { currentPos.x,currentPos.y, 40, 40 };
	}
};