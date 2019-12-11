#pragma once

#include <Siv3D.hpp>

class Marker
{
public:
	enum class MarkerType
	{
		marker,
		cameraMarker,
	};
	//class MarkerEvent
	//{
	//public:
	//	enum class Type
	//	{
	//		OndragStart,
	//		Ondrag,
	//		OndragEnd,

	//		Ondrop,

	//		Draw
	//		//OndragExit,
	//		//OndragLeave,
	//		//dragOver,
	//		//dragStart,
	//		//drop
	//	};
	//private:
	//	Type type;
	//	bool IsDrag;
	//	bool IsDrop;
	//public:
	//	MarkerEvent(Type type, const Marker& parent)
	//		:
	//		type(type),
	//		IsDrag(parent.IsDrag),
	//		IsDrop(parent.IsDrop)
	//	{
	//	}
	//	Type GetType() { return type; }
	//	bool GetIsDrag() { return IsDrag; }
	//	bool GetIsDrop() { return IsDrop; }
	//};
public:
	Marker(float x, float y, int num = 0);

	void SetPosition(const Vec2& position) { m_position = position; }
	void SetPosition(const float x, float y) { SetPosition({ x,y }); }
	Vec2 GetPosition() { return m_position; }
	int GetDistanceToCameraMarker(Vec2& CameraMarkerPos);

	void SetNum(int num);
	bool IsInRange(const Vec2& position) const;
	void Draw() const;

	void DrawCameraMarker()const;

	//Circle GetMarker() { return m_Marker; }
private:
	static const float MARKER_RADIUS;
	Vec2  m_position;
	int num;
	bool IsDrag = false;
	bool IsDrop = true;
	//Circle m_Marker;
};