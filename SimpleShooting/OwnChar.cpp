
#include "OwnChar.h"

void OwnChar::moveRight() {
	p.x += v;
	if (p.x + r > Window::Width()) {
		p.x = Window::Width() - r;
	}
}

void OwnChar::moveUp() {
	p.y -= v;
	if (p.y - r < 0) {
		p.y = r;
	}
}

void OwnChar::moveLeft() {
	p.x -= v;
	if (p.x - r < 0) {
		p.x = r;
	}
}

void OwnChar::moveDown() {
	p.y += v;
	if (p.y + r > Window::Height()) {
		p.y = Window::Height() - r;
	}
}
