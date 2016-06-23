
# include <Siv3D.hpp>
#include "OwnChar.h"
#include "EnemyChar.h"
#include "Shot.h"
#include <list>

using namespace std;

void Main()
{
	// 自機 { 初期位置, 半径, 色, 速度 }
	OwnChar me = { { 320, 400 }, 20,{ 255, 0, 0, 255 }, 6 };

	// 自機の弾
	list<Shot> ownShots;

	// 敵 { 初期位置, 半径, 色, 向き, 速度 }
	list<EnemyChar> enemies;

	// ゲーム終了フラグ
	bool finished = false;

	while (System::Update() && !finished)
	{
		// 自機移動
		if (Input::KeyRight.pressed) me.moveRight();
		if (Input::KeyUp.pressed) me.moveUp();
		if (Input::KeyLeft.pressed) me.moveLeft();
		if (Input::KeyDown.pressed) me.moveDown();

		// 自機の弾発射
		if ((Input::KeyZ | Input::KeySpace).pressed) {
			ownShots.push_back({ me.p, 5, {255, 128, 0, 128}, Pi * 1.5, 8 });
		}

		// 自機の弾移動
		for (Shot &s : ownShots) {
			s.update();
		}
		
		// 画面外の弾を削除
		ownShots.remove_if([&](const Shot &s) {
			return !Window::ClientRect().intersects(Circle(s.p, s.r));
		});

		// 敵移動
		for (EnemyChar &e : enemies)
		{
			e.update();
		}

		// 画面外の敵を削除
		enemies.remove_if([&](const EnemyChar &e) {
			return !Window::ClientRect().intersects(Circle(e.p, e.r));
		});

		// 敵と自機の当たり判定
		for (EnemyChar &e : enemies) {
			if (e.collides(Circle(me.p, me.r))) {
				finished = true;
			}
		}

		// 敵と自機の弾の当たり判定
		for (auto ite = enemies.begin(); ite != enemies.end();) {
			auto its = ownShots.begin();
			while (its != ownShots.end() && !(*ite).collides(Circle((*its).p, (*its).r))) ++its;
			if (its != ownShots.end()) {
				ite = enemies.erase(ite);
				ownShots.erase(its);
			}
			else {
				++ite;
			}
		}

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
		for (Shot &s : ownShots) {
			s.draw();
		}
	}
}
