#include <string>
#include <iostream>
#include "raylib.h"

class Character
{
public:
    Character(Model model, ModelAnimation animation) : m_model(model), m_animation(animation) {};

    int animCounter = 0;
    int animSpeed = 1;

    void Update(int framesCounter);

private:
    Model m_model;
    ModelAnimation m_animation;

    void Animate(int framesCounter);
};