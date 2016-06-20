
# include <Siv3D.hpp>
#include <list>

#include "Chiritori.h"

void Main()
{
	Chiritori me;
	std::list<Point> trash;
	int32 trashR = 15;
	Color trashCol = { 200, 200, 200, 255 };

	while (System::Update())
	{
		Vec2 angle(cos(me.angle), sin(me.angle));

		// ゴミ出現
		if (RandomBool(1.0 / 60)) {
			trash.push_back(RandomPoint({ trashR, trashR, Window::Width() - trashR, Window::Height() - trashR }));
		}

		// 操作
		if (Input::KeySpace.pressed) {
			me.pos.x += me.v * angle.x;
			me.pos.y += me.v * angle.y;
			if (me.pos.y - me.r < 0 || me.pos.y + me.r >= Window::Height()) {
				me.angle = -me.angle;
			}
			if (me.pos.x - me.r < 0 || me.pos.x + me.r >= Window::Width()) {
				me.angle = Pi - me.angle;
			}
		}
		else {
			me.angle += me.angleV;
		}

		// ゴミ回収
		for (auto it = trash.begin(); it != trash.end(); ) {
			if (Circle(me.pos, me.r).intersects(Circle(*it, trashR))) {
				it = trash.erase(it);
			}
			else {
				++it;
			}
		}

		// 描画
		Circle(me.pos, me.r).draw(me.color);
		Circle({ me.pos.x + me.r * 0.6 * angle.x, me.pos.y + me.r * 0.6 * angle.y }, me.r * 0.2).draw({ 255, 255, 255, 255 });
		for each (Point p in trash)
		{
			Circle(p, trashR).draw(trashCol);
		}
	}
}
