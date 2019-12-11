#include "App.h"

App::App()
{
	AssetRegiseter();
	// 背景を水色にする
	Scene::SetBackground(Palette::White);
	// 大きさ 60 のフォントを用意
	const Font font(60);
}

void App::Update()
{
	if (MouseL.pressed())
	{
		const auto mouseStartPos = Cursor::PosF();
		if (m_Manager.CaptureMarker(Cursor::PosF().x, Cursor::PosF().y))
		{
			m_Manager.MoveCaptureMarket(Cursor::PosF().x, Cursor::PosF().y);
		}
	
		if (MouseL.up()) 
		{
			const auto mouseEndPos = Cursor::PosF();
			m_Manager.DeleteMarker(mouseEndPos, mouseStartPos);
		}

		
	
	}
	else if (MouseL.up())
	{
		m_Manager.ReleaseMarker();
	}
	if (MouseL.down())
	{
		m_Manager.SetMarker(Cursor::PosF().x, Cursor::PosF().y);
	}


}

void App::Draw()
{
	FontAsset(U"font1")(U"DrawCount: ", m_Manager.GetDrawCount()).draw(5,5,Palette::Black);

	m_Manager.Draw();
}

void App::AssetRegiseter()
{
	FontAsset::Register(U"font0", 15, Typeface::Heavy);
	FontAsset::Register(U"font1", 15, Typeface::Black);
	FontAsset::Register(U"font2", 15, Typeface::Thin);
	FontAsset::Register(U"font4", 15, Typeface::Light);
}
