#include "../include/Character.h"

void Character::Update(int framesCounter)
{
    DrawModel(m_model, {5, 1, 0}, 1.0f, WHITE);
    Animate(framesCounter);
}

void Character::Animate(int framesCounter)
{

    if (framesCounter % animSpeed == 0)
    {
        std::cout << "Updating model animation with frame " << animCounter << std::endl;
        UpdateModelAnimation(m_model, m_animation, animCounter);
        animCounter++;
    }
}