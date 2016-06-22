
# include <Siv3D.hpp>
#include "OwnChar.h"

void Main()
{
	// 自機 { 初期位置, 半径, 色, 速度 }
	OwnChar me = { { 320, 240 }, 20,{ 255, 0, 0, 255 }, 6 };

	while (System::Update())
	{
		// 移動
		if (Input::KeyRight.pressed) me.moveRight();
		if (Input::KeyUp.pressed) me.moveUp();
		if (Input::KeyLeft.pressed) me.moveLeft();
		if (Input::KeyDown.pressed) me.moveDown();

		// 描画
		Circle(me.p, me.r).draw(me.col);
	}
}
