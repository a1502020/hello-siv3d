#pragma once

#include <Siv3D.hpp>

struct OwnChar {

	/// <summary>
	/// �ʒu
	/// </summary>
	Point p;

	/// <summary>
	/// ���a
	/// </summary>
	int32 r;

	/// <summary>
	/// �F
	/// </summary>
	Color col;

	/// <summary>
	/// ���x[px/frame]
	/// </summary>
	int32 v;

	OwnChar() = default;

	/// <summary>
	/// �E��1�t���[���Ԃ�ړ�����B
	/// </summary>
	void moveRight();

	/// <summary>
	/// ���1�t���[���Ԃ�ړ�����B
	/// </summary>
	void moveUp();

	/// <summary>
	/// ����1�t���[���Ԃ�ړ�����B
	/// </summary>
	void moveLeft();

	/// <summary>
	/// ����1�t���[���Ԃ�ړ�����B
	/// </summary>
	void moveDown();

};
