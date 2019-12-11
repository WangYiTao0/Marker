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
���N���b�N���ā@
Marker�@
���
delete
//marker �ԍ���t���ā@�@�폜�����@
�J��������߂����@�Ƀ}�[�J�[���\�[�g����
�J�����}�[�J�[�@drap drop
�͈͑I���@�����Ȃ�
*/
