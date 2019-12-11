#pragma once
#include "Marker.h"

class MarkerManager
{
public:
	MarkerManager();

	void Draw();

	/*
	���N���b�N���ā@
	Marker�@
	��ݒu

	delete

	*/

	int GetDrawCount();
	bool IsCaptureMarker();
	void MoveCaptureMarket(float x, float y);
	bool CaptureMarker(float x, float y);
	void ReleaseMarker();
	void SetMarker(float x, float y);
	void DeleteMarker(Vec2 mousePosStart, Vec2 mousePosEnd);

private:
	std::vector<std::unique_ptr<Marker>> m_Marker;
	std::vector<std::unique_ptr<Marker>>::iterator it;
	int drawCount = 0;
};