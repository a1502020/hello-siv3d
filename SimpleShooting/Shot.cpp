
#include "Shot.h"

void Shot::update() {
	p.x += v * Cos(angle);
	p.y += v * Sin(angle);
}

void Shot::draw() {
	Circle(p, r).draw(col);
}
