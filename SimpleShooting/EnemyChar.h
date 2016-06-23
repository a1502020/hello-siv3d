#pragma once

#include <Siv3D.hpp>
#include "OwnChar.h"

struct EnemyChar {

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

	EnemyChar() = default;

	/// <summary>
	/// 1フレームぶん移動する。
	/// </summary>
	void move();

	/// <summary>
	/// 敵を描画する。
	/// </summary>
	void draw();

	/// <summary>
	/// 自機と接触しているか判定する。
	/// </summary>
	bool collides(OwnChar &own);

};