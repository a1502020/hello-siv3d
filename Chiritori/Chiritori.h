#pragma once

#include <Siv3D.hpp>

/// <summary>
/// チリトリー
/// </summary>
struct Chiritori {

	/// <summary>
	/// 中心の位置
	/// </summary>
	Vec2 pos;

	/// <summary>
	/// 半径
	/// </summary>
	double r;

	/// <summary>
	/// 色
	/// </summary>
	Color color;

	/// <summary>
	/// 向き[rad]
	/// </summary>
	double angle;

	/// <summary>
	/// 速度[px/frame]
	/// </summary>
	double v;

	/// <summary>
	/// 角速度[rad/frame]
	/// </summary>
	double angleV;

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Chiritori();

};