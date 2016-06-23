#pragma once

#include <Siv3D.hpp>

struct EnemyChar {

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

	EnemyChar() = default;

	/// <summary>
	/// 1�t���[���Ԃ�ړ�����B
	/// </summary>
	void move();

	/// <summary>
	/// �G��`�悷��B
	/// </summary>
	void draw();

};