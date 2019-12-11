#pragma once

#include <Siv3D.hpp>

class Marker
{
public:
	enum class MarkerState
	{
		isFree,
		isCapture,
	};

public:
	Marker(Vec2 pos, MarkerState me = MarkerState::isFree, int num = 0);
	Marker(float x, float y, MarkerState me = MarkerState::isFree, int num = 0);
	void SetMarkerState(MarkerState me) { this->me = me; }
	void SetPosition(const Vec2& position) { m_position = position; }
	void SetPosition(const float x, float y) { SetPosition({ x,y }); }
	const Vec2& GetPosition(void) const { return m_position; }
	void SetNum(int num);
	bool IsInRange(const Vec2& position) const;


	virtual void Draw(void) const;
protected:
	const float MARKER_RADIUS = 20;
	Vec2  m_position;
	int num;
	MarkerState me;
};