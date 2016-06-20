
# include <Siv3D.hpp>

#include "Chiritori.h"

void Main()
{
	Chiritori me;

	while (System::Update())
	{
		Vec2 angle(cos(me.angle), sin(me.angle));

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

		Circle(me.pos, me.r).draw(me.color);
		Circle({ me.pos.x + me.r * 0.6 * angle.x, me.pos.y + me.r * 0.6 * angle.y }, me.r * 0.2).draw({ 255, 255, 255, 255 });
	}
}
