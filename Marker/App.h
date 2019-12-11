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
    struct RingEffect : IEffect
    {
        Vec2 m_pos;

        ColorF m_color;

        RingEffect(const Vec2& pos)
            : m_pos(pos)
            , m_color(RandomColor()) 
        {}

        bool update(double t) override
        {
            // イージング
            const double e = EaseOutExpo(t);

            Circle(m_pos, e * 100).drawFrame(20.0 * (1.0 - e), m_color);

            return t < 1.0;
        }
    };
    Effect effect;
    MarkerManager m_Manager;

    Vec2 mouseStartPos = { 100,100 };
    Vec2 mouseDelta = { 200,200 };
};