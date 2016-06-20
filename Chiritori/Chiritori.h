#pragma once

#include <Siv3D.hpp>

/// <summary>
/// �`���g���[
/// </summary>
struct Chiritori {

	/// <summary>
	/// ���S�̈ʒu
	/// </summary>
	Vec2 pos;

	/// <summary>
	/// ���a
	/// </summary>
	double r;

	/// <summary>
	/// �F
	/// </summary>
	Color color;

	/// <summary>
	/// ����[rad]
	/// </summary>
	double angle;

	/// <summary>
	/// ���x[px/frame]
	/// </summary>
	double v;

	/// <summary>
	/// �p���x[rad/frame]
	/// </summary>
	double angleV;

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Chiritori();

};