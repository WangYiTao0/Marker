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
	
		if (MouseL.pressed())
		{
			const auto mouseStartPos = Cursor::PosF();
			if (m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
			{
				IsCapture = true;
				m_Manager.MoveCaptureMarket(Cursor::PosF().x, Cursor::PosF().y);
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
		Vec2 startPos = Vec2::Zero();
		Vec2 endPos = Vec2::Zero();
		if (MouseR.down())
		{
			startPos = pos;
			if (m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
			{
				m_Manager.DeleteMarker(startPos, endPos);
			}
		}
		if (MouseR.up())
		{
			endPos = pos;
		}

		//Rect(startPos.x, startPos.y, endPos.x, endPos.y).drawFrame(2, 2, Palette::Red);
		//m_Manager.DeleteMarker(startPos, endPos);

	effect.update();

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
	FontAsset::Register(U"font4", 20, Typeface::Light);
}
