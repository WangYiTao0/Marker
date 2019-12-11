#include "CameraMarker.h"

CameraMarker::CameraMarker(Vec2 pos, MarkerState me)
	:
	Marker(pos)
{
	CameraMarker(pos.x, pos.y, me);
}

CameraMarker::CameraMarker(float x, float y, MarkerState me)
	:
	Marker(x,y)
{

}

bool CameraMarker::IsInRange(const Vec2& position) const
{
	return m_position.distanceFrom(position) <= CameraMarker_RADIUS;
}

void CameraMarker::Draw(void) const
{
	const Circle m_CamMarker = Circle(m_position, CameraMarker_RADIUS);

	ColorF markerColor = Palette::Chocolate;
	if (m_CamMarker.leftPressed())
	{
		markerColor = Palette::Cadetblue;
		m_CamMarker.draw(markerColor);
	}
	else if (m_CamMarker.mouseOver())
	{
		markerColor = Palette::Chartreuse;
		m_CamMarker.drawShadow(Vec2(3.0f, 0.0f), 10.0f).draw(markerColor);
	}
	m_CamMarker.draw(markerColor);

	FontAsset(U"font4")(U"Camera").draw(m_CamMarker.center - Vec2(25.f, 15), Palette::Black);
}
