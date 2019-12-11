#pragma once

#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include <memory>
#include "Marker.h"
#include "MarkerManager.h"
class App
{
public:
	App();

	void Update();
	void Draw();
private:
	void AssetRegiseter();

private:
	
	MarkerManager m_Manager;
};