#pragma once

#include <Siv3D.hpp>

class Marker
{
public:
	class MarkerEvent
	{
	public:
		enum class Type
		{
			OndragStart,
			Ondrag,
			OndragEnd,

			Ondrop,

			Draw
			//OndragExit,
			//OndragLeave,
			//dragOver,
			//dragStart,
			//drop
		};
	private:
		Type type;
		bool IsDrag;
		bool IsDrop;
	public:
		MarkerEvent(Type type, const Marker& parent)
			:
			type(type),
			IsDrag(parent.IsDrag),
			IsDrop(parent.IsDrop)
		{
		}
		Type GetType() { return type; }
		bool GetIsDrag() { return IsDrag; }
		bool GetIsDrop() { return IsDrop; }
	};
public:
	Marker(float x, float y, int num = 0);

	void SetPosition(const Vec2& position) { m_position = position; }
	void SetPosition(const float x, float y) { SetPosition({ x,y }); }
	const Vec2& GetPosition(void) const { return m_position; }
	void SetNum(int num);
	bool IsInRange(const Vec2& position) const;
	void Draw(void) const;
private:
	static const float MARKER_RADIUS;
	Vec2  m_position;
	int num;
	bool IsDrag = false;
	bool IsDrop = true;
	const Circle m_Marker = Circle(m_position.x, m_position.y, 20);
};