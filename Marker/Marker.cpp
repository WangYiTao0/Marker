#include "Marker.h"

Marker::Marker(Vec2 pos, MarkerState me, int num)
{
	Marker(pos.x, pos.y, me, num);
}

Marker::Marker(float x, float y, MarkerState me, int num)
	:
	m_position(x, y),
	num(num),
	me(me)
{

}

void Marker::SetNum(int num)
{
	this->num = num;
}

bool Marker::IsInRange(const Vec2& position) const
{
	//m_position.distanceFrom(position);

	//float xlen = m_position.x - position.x;
	//float ylen = m_position.y - position.y;
	//float sqlen = xlen * xlen + ylen * ylen;

	return m_position.distanceFrom(position) <= MARKER_RADIUS;
}

int Marker::GetDistanceToCameraMarker(Vec2& CameraMarkerPos)
{
	return m_position.distanceFrom(CameraMarkerPos);
}

void Marker::Draw(void) const
{
	const Circle m_Marker = Circle(m_position.x, m_position.y, MARKER_RADIUS);

	ColorF markerColor = Palette::Gray;
	if (m_Marker.leftPressed())
	{
		markerColor = Palette::Darkblue;
		m_Marker.draw(markerColor);
	}
	else if(m_Marker.mouseOver())
	{
		markerColor = Palette::Skyblue;
		m_Marker.drawShadow(Vec2(3.0f,0.0f),10.0f).draw(markerColor);
	}
	m_Marker.draw(markerColor);
	
	FontAsset(U"font2")(num).draw(m_Marker.center - Vec2(8.5f,17), Palette::Red);;
}
