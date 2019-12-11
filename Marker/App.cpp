#include "App.h"

App::App()
{
	AssetRegiseter();

	Window::Resize({ 1280,720 });
	// îwåiÇêÖêFÇ…Ç∑ÇÈ
	Scene::SetBackground(Palette::White);
	
}

void App::Update()
{
	if (MouseL.pressed() || MouseL.down())
	{
		effect.add<RingEffect>(Cursor::Pos());

		if (m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
		{
			m_Manager.MoveCaptureMarket(Cursor::PosF().x, Cursor::PosF().y);
		}
		else
		{
			m_Manager.SetMarker(Cursor::PosF().x, Cursor::PosF().y);
		}
	}
	if (MouseL.up())
	{
		m_Manager.ReleaseMarker();
	}

	//if (MouseR.pressed())
	//{
	//	mouseStartPos = Cursor::PosF();
	//	if (MouseR.up())
	//	{
	//		mouseDelta = Cursor::PosF();
	//	}
	//}

	//m_Manager.CameraMarkerSort();

	effect.update();
}

void App::Draw()
{
	FontAsset(U"font1")(U"DrawCount: ", m_Manager.GetDrawCount()).draw(5,5,Palette::Black);

	m_Manager.Draw();

	//m_Manager.DrawCamera();

	//m_Manager.DeleteMarker(mouseStartPos, mouseDelta);
}

void App::AssetRegiseter()
{
	FontAsset::Register(U"font0", 15, Typeface::Heavy);
	FontAsset::Register(U"font1", 15, Typeface::Black);
	FontAsset::Register(U"font2", 15, Typeface::Thin);
	FontAsset::Register(U"font4", 15, Typeface::Light);
}
