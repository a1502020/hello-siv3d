
#include "Chiritori.h"

Chiritori::Chiritori() {
	pos = Window::Size() / 2;
	r = 30.0;
	color = Color{ 255, 0, 0, 255 };
	angle = Pi * 1.5;
	v = 5;
	angleV = Pi / 30;
}
