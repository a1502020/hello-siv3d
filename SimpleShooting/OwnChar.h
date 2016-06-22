#pragma once

#include <Siv3D.hpp>

struct OwnChar {

	/// <summary>
	/// 位置
	/// </summary>
	Point p;

	/// <summary>
	/// 半径
	/// </summary>
	int32 r;

	/// <summary>
	/// 色
	/// </summary>
	Color col;

	/// <summary>
	/// 速度[px/frame]
	/// </summary>
	int32 v;

	OwnChar() = default;

	/// <summary>
	/// 右に1フレームぶん移動する。
	/// </summary>
	void moveRight();

	/// <summary>
	/// 上に1フレームぶん移動する。
	/// </summary>
	void moveUp();

	/// <summary>
	/// 左に1フレームぶん移動する。
	/// </summary>
	void moveLeft();

	/// <summary>
	/// 下に1フレームぶん移動する。
	/// </summary>
	void moveDown();

};
