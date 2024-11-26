#include <string>
#include <iostream>

#include "TextManager.h"
#include "ResourceManager.h"
#include "Character.h"

#include "external/rlights.h"
#include "raymath.h"

class Game
{
public:
    int framesCounter = 0;
    int animCounter = 0;

    float lastFps = 0.0f;

    ResourceManager ResourceManager;
    Character character(Model model, ModelAnimation animation);

    Camera camera;

    Shader shader;
    int ambientLoc;
    Light lights[MAX_LIGHTS];

    Vector3 cubePosition;
    Vector3 cubeSize;
    Model cube;
    Model plane;

    void Init();
    void Update();
    void Draw();
    void Cleanup();

private:
    // int screenWidth = 1920;
    // int screenHeight = 1080;
    int screenWidth = 800;
    int screenHeight = 450;
};