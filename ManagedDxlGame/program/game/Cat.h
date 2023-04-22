#pragma once
#include "../dxlib_ext/dxlib_ext.h"


class Cat {
public:
	Cat() {};
	~Cat() {};
	int cat_ = 0;
	int speed_ = 10;
	tnl::Vector3 pos_ = { 0, 0, 0 };

	void update(const float dalte_time);
	void graphicupdate(const float dalte_time);
};