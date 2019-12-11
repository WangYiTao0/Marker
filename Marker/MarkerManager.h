#pragma once
#include "Marker.h"


class MarkerManager
{
public:
	MarkerManager();

	void Draw();
	void DrawCamera();
	int GetDrawCount();
	bool IsCaptureMarker();
	void MoveCaptureMarket(float x, float y);
	bool CaptureMarker(float x, float y);
	void ReleaseMarker();
	void SetMarker(float x, float y);
	void SetCameraMarker(float x, float y);	
	void DeleteMarker(Vec2 mousePosStart, Vec2 mousePosEnd);
	void CameraMarkerSort();
private:
	bool SortFunc(const std::unique_ptr<Marker>& A, const std::unique_ptr<Marker>& B);

private:
	std::vector<std::unique_ptr<Marker>> m_Marker;
	std::vector<std::unique_ptr<Marker>>::iterator it;

	std::unique_ptr<Marker> m_CameraMarker;

	int drawCount = 0;
}

/*
左クリックして　
Marker　
を設
delete
//marker 番号を付けて　　削除した　
カメラから近い順　にマーカーをソートする
カメラマーカー　drap drop
範囲選択　消さない
*/
