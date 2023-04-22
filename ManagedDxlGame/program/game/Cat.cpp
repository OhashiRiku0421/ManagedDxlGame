#include "Cat.h"

void Cat::update(const float delta_time) {

	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		pos_.x -= speed_;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		pos_.x += speed_;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		pos_.y -= speed_;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		pos_.y += speed_;
	}
}

void Cat::graphicupdate(const float delte_time)
{
	DrawRotaGraphF(pos_.x, pos_.y, 0.5f, 0, cat_, true);
}