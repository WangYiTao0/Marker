#pragma once
#include "Marker.h"


class CameraMarker : public Marker
{
public:
	CameraMarker(Vec2 pos, MarkerState me);
	CameraMarker(float x, float y, MarkerState me);

	virtual bool IsInRange(const Vec2& position) const override;
	virtual void Draw(void) const override;
protected:
	const float CameraMarker_RADIUS = 30;
};