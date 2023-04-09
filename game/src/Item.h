#pragma once
#include "raylib.h"



class Item {

	//Items itemName;

	int name;
	unsigned char exp;

	Vector2 currentPos;

	Rectangle rect;


public:
	Item(int pName) {
		name = pName;
		exp = 10;
		currentPos = startCharacterPosition(false);
	};

	int getName() { return name; }
	Vector2 getCurrentPos() { return currentPos; }
	//Texture2D getImg() { return img; }

	void drawItem() {
		DrawRectangleV(getCurrentPos(), { 100, 100 }, RED);
	}
};