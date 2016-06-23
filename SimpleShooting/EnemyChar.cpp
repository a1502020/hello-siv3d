
#include "EnemyChar.h"

void EnemyChar::move() {
	p.x += v * cos(angle);
	p.y += v * sin(angle);
}

void EnemyChar::draw() {
	Circle(p, r).draw(col);
}
