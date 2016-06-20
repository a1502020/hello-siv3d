
# include <Siv3D.hpp>
#include <list>
#include "Chiritori.h"

void Main()
{
	Chiritori me;
	std::list<Circle> trash;
	Color trashCol = { 200, 200, 200, 255 };
	int32 score = 0;
	Font font(20);

	while (System::Update())
	{
		Vec2 angle(cos(me.angle), sin(me.angle));

		// ゴミ出現
		if (RandomBool(1.0 / 50)) {
			Point p = RandomPoint({ 15, 15, Window::Width() - 15, Window::Height() - 15 });
			trash.push_back(Circle(p, 15));
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
			if (Circle(me.pos, me.r).intersects(*it)) {
				it = trash.erase(it);
				++score;
			}
			else {
				++it;
			}
		}

		// ゴミ増えすぎどっかーん
		if (trash.size() >= 30) {
			trash.clear();
			score = 0;
			me = Chiritori();
		}

		// 描画
		uint32 bk = 0;
		if (trash.size() > 20) {
			bk = (trash.size() - 20) * 25;
		}
		Graphics::SetBackground({ bk, bk, 0, 255 });
		Circle(me.pos, me.r).draw(me.color);
		Circle({ me.pos.x + me.r * 0.6 * angle.x, me.pos.y + me.r * 0.6 * angle.y }, me.r * 0.2).draw({ 255, 255, 255, 255 });
		for each (Circle c in trash)
		{
			c.draw(trashCol);
		}
		font(ToString(score)).draw();
	}
}
