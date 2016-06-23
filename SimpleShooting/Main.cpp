
# include <Siv3D.hpp>
#include "OwnChar.h"
#include "EnemyChar.h"
#include <list>

using namespace std;

void Main()
{
	// 自機 { 初期位置, 半径, 色, 速度 }
	OwnChar me = { { 320, 240 }, 20,{ 255, 0, 0, 255 }, 6 };

	// 敵機 { 初期位置, 半径, 色, 向き, 速度 }
	list<EnemyChar> enemies = {
		{ { 100, 0 }, 20, { 255, 0, 255, 255 }, Pi * 0.5, 2 },
		{ { 540, 0 }, 20, { 255, 0, 255, 255 }, Pi * 0.5, 2 }
	};

	while (System::Update())
	{
		// 自機移動
		if (Input::KeyRight.pressed) me.moveRight();
		if (Input::KeyUp.pressed) me.moveUp();
		if (Input::KeyLeft.pressed) me.moveLeft();
		if (Input::KeyDown.pressed) me.moveDown();

		// 敵機移動
		for (EnemyChar &e : enemies)
		{
			e.move();
		}

		// 画面外の敵を削除
		enemies.remove_if([&](const EnemyChar &e) {
			return !Window::ClientRect().intersects(Circle(e.p, e.r));
		});

		// 描画
		Circle(me.p, me.r).draw(me.col);
		for (EnemyChar &e : enemies)
		{
			e.draw();
		}
	}
}
