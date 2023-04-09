#pragma once
#include "raylib.h"

class Item {

	unsigned char exp;

	Vector2 currentPos;

	//Rectangle rect;

public:
	Item();
	Item(int pName) {
		exp = 10;
		currentPos = startCharacterPosition(false);
	};

	char getExp() { return exp; }

	Vector2 getCurrentPos() { return currentPos; }
	//Texture2D getImg() { return img; }

	void drawItem() {
		DrawRectangleV(getCurrentPos(), { 40, 40 }, RED);
	}
};