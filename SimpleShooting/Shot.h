#pragma once

#include <Siv3D.hpp>

struct Shot {

	/// <summary>
	/// �ʒu
	/// </summary>
	Vec2 p;

	/// <summary>
	/// ���a
	/// </summary>
	int32 r;

	/// <summary>
	/// �F
	/// </summary>
	Color col;

	/// <summary>
	/// ����
	/// </summary>
	double angle;

	/// <summary>
	/// ���x[px/frame]
	/// </summary>
	int32 v;

	Shot() = default;

	/// <summary>
	/// 1�t���[���Ԃ�̏������s���B
	/// </summary>
	void update();

	/// <summary>
	/// �e��`�悷��B
	/// </summary>
	void draw();

};
