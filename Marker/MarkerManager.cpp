#include "MarkerManager.h"

MarkerManager::MarkerManager()
{
	
}

void MarkerManager::Draw()
{
	for (auto& M : m_Marker)
	{
		M->Draw();
	}

	Circle(Cursor::PosF().x, Cursor::PosF().y, 10).drawFrame(1.0f,ColorF(0.0, 0.5, 1.0, 0.8));
}

int MarkerManager::GetDrawCount() { return drawCount = m_Marker.size(); }

bool MarkerManager::IsCaptureMarker()
{
	return it != m_Marker.end();
}

void MarkerManager::MoveCaptureMarket(float x, float y)
{
	if (IsCaptureMarker())
	{
		it->get()->SetPosition(x, y);
	}
}

bool MarkerManager::CaptureMarker(float x, float y)
{
	//for (auto& m:m_Marker)
	//{
	//		return it = m->IsMouseOver();
	//};
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
	m_Marker.push_back(std::make_unique<Marker>(x, y));
}

void MarkerManager::DeleteMarker(Vec2 mousePosStart, Vec2 mousePosEnd)
{
	float left, right, top, bottom;
	if (mousePosStart.x > mousePosEnd.x)
	{
		std::swap(mousePosStart.x, mousePosEnd.x);
	}
	if (mousePosStart.y > mousePosEnd.y)
	{
		std::swap(mousePosStart.y, mousePosEnd.y);
	}
	
	Rect(mousePosStart.x, mousePosStart.y, mousePosEnd.x, mousePosEnd.y).drawFrame(2, 2, Palette::Red);

	m_Marker.erase(std::remove_if(m_Marker.begin(), m_Marker.end(),
		[mousePosStart, mousePosEnd](std::unique_ptr<Marker>& m) {
			return m->GetPosition().x >= mousePosStart.x && m->GetPosition().x <= mousePosEnd.x
				&& m->GetPosition().y <= mousePosStart.y && m->GetPosition().y >= mousePosEnd.y;
		}));

}
