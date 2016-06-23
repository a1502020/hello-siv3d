
#include "EnemyChar.h"

void EnemyChar::update() {
	p.x += v * Cos(angle);
	p.y += v * Sin(angle);
}

void EnemyChar::draw() {
	Circle(p, r).draw(col);
}

bool EnemyChar::collides(const Circle &c) const {
	return Circle(p, r).intersects(c);
}
