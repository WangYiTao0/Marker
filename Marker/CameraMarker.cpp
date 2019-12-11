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

void CameraMarker::Draw(void) const
{
	Circle(100, 100, CameraMarker_RADIUS).draw(Palette::Chocolate);
}