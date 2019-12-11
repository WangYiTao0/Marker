#include "MarkerManager.h"

MarkerManager::MarkerManager()
{
	m_CamMarker = std::make_unique<CameraMarker>(200, 200,Marker::MarkerState::isFree);
}

void MarkerManager::Draw()
{
	for (auto& M : m_Marker)
	{
		M->Draw();
	}

	m_CamMarker->Draw();

	Circle(Cursor::PosF().x, Cursor::PosF().y, 10).drawFrame(1.0f,ColorF(0.0, 0.5, 1.0, 0.8));
}

int MarkerManager::GetDrawCount() { return drawCount = m_Marker.size(); }

bool MarkerManager::IsCaptureMarker()
{
	return it != m_Marker.end();
}

void MarkerManager::MoveCapturedMarker(float x, float y)
{
	if (it != m_Marker.end())
	{
		it->get()->SetPosition(x, y);
		it->get()->SetMarkerState(Marker::MarkerState::isCapture);
	}
}

void MarkerManager::MoveCaptureCamMarker(float x, float y)
{
	m_CamMarker->SetPosition({ x,y });
}

bool MarkerManager::CaptureCamMarker(float x, float y)
{
	return m_CamMarker->IsInRange({ x, y });
}

bool MarkerManager::CaptureMarker(float x, float y)
{
	it = std::find_if(m_Marker.begin(), m_Marker.end(),
		[x, y](std::unique_ptr<Marker>& m)
		{
			return m->IsInRange({ x, y });
		});

	return IsCaptureMarker();
}

void MarkerManager::ReleaseMarker()
{
	it = m_Marker.end();
}

void MarkerManager::SetMarker(float x, float y)
{
	m_Marker.push_back(std::make_unique<Marker>(x, y, Marker::MarkerState::isFree, m_Marker.size()));
}

void MarkerManager::DeleteMarker(Vec2 mousePosStart, Vec2 mousePosEnd)
{

	if (mousePosStart.x > mousePosEnd.x)
	{
		std::swap(mousePosStart.x, mousePosEnd.x);
	}
	if (mousePosStart.y > mousePosEnd.y)
	{
		std::swap(mousePosStart.y, mousePosEnd.y);
	}

	const RectF R = RectF(mousePosStart, mousePosStart-mousePosEnd).drawFrame(2, 2, Palette::Red);

	// remove_if 把要不要删除的元素 前移 返回最后一个不移除元素的下一个位置
	// 新的逻辑终点 到 序列最后 就是要删除的元素

	m_Marker.erase(std::remove_if(m_Marker.begin(), m_Marker.end(),
		[mousePosStart, mousePosEnd](std::unique_ptr<Marker>& m)
		{
			return m->GetPosition().x >= mousePosStart.x && m->GetPosition().x <= mousePosEnd.x
				&& m->GetPosition().y >= mousePosStart.y && m->GetPosition().y <= mousePosEnd.y;
		}),m_Marker.end());

	ReNum();
}

void MarkerManager::ReNum()
{
	for (it = m_Marker.begin(); it != m_Marker.end(); it++)
	{
		it->get()->SetNum(std::distance(m_Marker.begin(), it));
	}
}

void MarkerManager::CameraMarkerSort()
{
	std::sort(m_Marker.begin(), m_Marker.end(), 
		[this](const std::unique_ptr<Marker>& A, const std::unique_ptr<Marker>& B)
		{
			Vec2 cameraMarkerPos = m_CamMarker->GetPosition();

			return A->GetDistanceToCameraMarker(cameraMarkerPos) < B->GetDistanceToCameraMarker(cameraMarkerPos);
		});
}
