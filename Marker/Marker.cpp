#include "Marker.h"

const float Marker::MARKER_RADIUS = 20.0f;

Marker::Marker(float x, float y, int num)
	:
	m_position(x,y)
{
}

bool Marker::IsInRange(const Vec2& position) const
{
	//return m_Marker.leftPressed();

	float xlen = m_position.x - position.x;
	float ylen = m_position.y - position.y;
	float sqlen = xlen * xlen + ylen * ylen;

	return sqlen <= MARKER_RADIUS * MARKER_RADIUS;
}

void Marker::Draw(void) const
{
	ColorF markerColor = Palette::Gray;
	if (m_Marker.leftPressed())
	{
		markerColor = Palette::Darkblue;
	}
	else if(m_Marker.mouseOver())
	{
		markerColor = Palette::Skyblue;
	}
	m_Marker.draw(markerColor);
}
