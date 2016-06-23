
# include <Siv3D.hpp>
#include "OwnChar.h"
#include "EnemyChar.h"
#include <list>

using namespace std;

void Main()
{
	// 自機 { 初期位置, 半径, 色, 速度 }
	OwnChar me = { { 320, 240 }, 20,{ 255, 0, 0, 255 }, 6 };

	// 敵 { 初期位置, 半径, 色, 向き, 速度 }
	list<EnemyChar> enemies;

	while (System::Update())
	{
		// 自機移動
		if (Input::KeyRight.pressed) me.moveRight();
		if (Input::KeyUp.pressed) me.moveUp();
		if (Input::KeyLeft.pressed) me.moveLeft();
		if (Input::KeyDown.pressed) me.moveDown();

		// 敵移動
		for (EnemyChar &e : enemies)
		{
			e.move();
		}

		// 画面外の敵を削除
		enemies.remove_if([&](const EnemyChar &e) {
			return !Window::ClientRect().intersects(Circle(e.p, e.r));
		});

		// 敵出現
		if (RandomBool(1.0 / 40)) {
			int32 r = Random(15, 30);
			Point p = RandomPoint({ r, r, Window::Width() - 2 * r, 1 });
			Color col = { 255, 0, 255, 255 };
			double angle = Random(Pi * 0.25, Pi * 0.75);
			int32 v = Random(2, 5);
			enemies.push_back({ p, r, col, angle, v });
		}

		// 描画
		Circle(me.p, me.r).draw(me.col);
		for (EnemyChar &e : enemies)
		{
			e.draw();
		}
	}
}
