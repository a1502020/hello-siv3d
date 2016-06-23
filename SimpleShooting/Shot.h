#pragma once

#include <Siv3D.hpp>

struct Shot {

	/// <summary>
	/// 位置
	/// </summary>
	Vec2 p;

	/// <summary>
	/// 半径
	/// </summary>
	int32 r;

	/// <summary>
	/// 色
	/// </summary>
	Color col;

	/// <summary>
	/// 向き
	/// </summary>
	double angle;

	/// <summary>
	/// 速度[px/frame]
	/// </summary>
	int32 v;

	Shot() = default;

	/// <summary>
	/// 1フレームぶんの処理を行う。
	/// </summary>
	void update();

	/// <summary>
	/// 弾を描画する。
	/// </summary>
	void draw();

};
