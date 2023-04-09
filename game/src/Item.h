#pragma once
#include "raylib.h"

class Item {

	unsigned char exp;

	Vector2 currentPos;

	Texture2D img;

	Rectangle rect;

public:
	Item() {
		exp = 10;
		currentPos = startCharacterPosition(false);
		img = aidKitImg;
		rect = { currentPos.x,currentPos.y, 40, 40 };
	};
	Item(Texture2D pImg) {
		exp = 10;
		currentPos = startCharacterPosition(false);
		rect = { currentPos.x,currentPos.y, 40, 40 };
		img = pImg;
	};


	char getExp() { return exp; }

	Vector2 getCurrentPos() { return currentPos; }

	Rectangle getRectangle() { return rect; }

	Texture2D getImg() { return img; }

	void drawItem() {
		
		DrawRectangleRec(getRectangle(), RED);
		DrawTexture(getImg(), getCurrentPos().x, getCurrentPos().y, WHITE);
	}

	void removeItem() {
		currentPos = { -500,-500 };
		rect = { currentPos.x,currentPos.y, 40, 40 };
	}
};