#include "App.h"

App::App()
{
	AssetRegiseter();

	// ウィンドウを手動リサイズ可能にする
	Window::SetStyle(WindowStyle::Sizable);

	Window::Resize({ 1280,720 });
	// 背景を水色にする
	Scene::SetBackground(Palette::White);
}

void App::Update()
{

	if (MouseL.pressed())
	{
		if (m_Manager.CaptureCamMarker(Cursor::PosF().x, Cursor::PosF().y))
		{
			m_Manager.MoveCaptureCamMarker(Cursor::PosF().x, Cursor::PosF().y);
		}

		if (m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
		{
			IsCapture = true;
			m_Manager.MoveCapturedMarker(Cursor::PosF().x, Cursor::PosF().y);
		}
		else
		{
			m_Manager.SetMarker(Cursor::PosF().x, Cursor::PosF().y);
		}
	}
	else if (MouseL.up())
	{
		IsCapture = false;
		m_Manager.ReleaseMarker();
	}
	if (MouseL.down())
	{
		effect.add<RingEffect>(Cursor::Pos());
		if (!m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
		{
			m_Manager.SetMarker(Cursor::PosF().x, Cursor::PosF().y);
		}
	}

	Vec2 pos = Cursor::PosF();


	if (MouseR.down())
	{
		startPos = pos;
	}
	else if (MouseR.pressed())
	{
		hw += Cursor::DeltaF();
		const RectF R = RectF(startPos, hw).drawFrame(2, 2, Palette::Red);
	
	}
	else if (MouseR.up())
	{
		endPos = pos;
		m_Manager.DeleteMarker(startPos, endPos);
		hw = Vec2::Zero();
	}

	effect.update();
	m_Manager.CameraMarkerSort();
	m_Manager.ReNum();
}

void App::Draw()
{
	FontAsset(U"font1")(U"DrawCount: ", m_Manager.GetDrawCount()).draw(5,5,Palette::Black);

	m_Manager.Draw();
}

void App::AssetRegiseter()
{
	FontAsset::Register(U"font0", 20, Typeface::Heavy);
	FontAsset::Register(U"font1", 20, Typeface::Black);
	FontAsset::Register(U"font2", 20, Typeface::Regular);
	FontAsset::Register(U"font4", 15, Typeface::Medium);
}
