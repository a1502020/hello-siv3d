
#include "EnemyChar.h"

void EnemyChar::move() {
	p.x += v * cos(angle);
	p.y += v * sin(angle);
}

void EnemyChar::draw() {
	Circle(p, r).draw(col);
}

bool EnemyChar::collides(OwnChar &own) {
	return Circle(p, r).intersects(Circle(own.p, own.r));
}
