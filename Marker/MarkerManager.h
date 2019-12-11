#pragma once
#include "CameraMarker.h"

class MarkerManager
{
public:
	MarkerManager();

	void Draw();

	/*
	左クリックして　
	Marker　
	を設置

	delete

	*/

	int GetDrawCount();

	bool IsCaptureMarker();
	void MoveCapturedMarker(float x, float y);
	
	bool CaptureCamMarker(float x, float y);
	void MoveCaptureCamMarker(float x, float y);

	
	bool CaptureMarker(float x, float y);
	void ReleaseMarker();
	void SetMarker(float x, float y);
	void DeleteMarker(Vec2 mousePosStart, Vec2 mousePosEnd);

	void ReNum();
	void CameraMarkerSort();
	

private:
	std::vector<std::unique_ptr<Marker>> m_Marker;
	std::vector<std::unique_ptr<Marker>>::iterator it;

	std::unique_ptr<CameraMarker> m_CamMarker;

	int drawCount = 0;
};