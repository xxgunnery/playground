#define RLIGHTS_IMPLEMENTATION

#include "../include/Game.h"

void Game::Init()
{
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    ResourceManager.LoadBasicResources();

    // Define the camera to look into our 3d world
    camera.position = {10.0f, 10.0f, 10.0f}; // Camera position
    camera.target = {0.0f, 0.0f, 0.0f};      // Camera looking at point
    camera.up = {0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                     // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;  // Camera mode type

    cubePosition = {0.0f, 1.0f, 0.0f};
    cubeSize = {2.0f, 2.0f, 2.0f};

    cube = LoadModelFromMesh(GenMeshCube(cubeSize.x, cubeSize.y, cubeSize.y));
    plane = LoadModelFromMesh(GenMeshPlane(10, 10, 10, 10));

    SetConfigFlags(FLAG_MSAA_4X_HINT); // Enable Multi Sampling Anti Aliasing 4x (if available)

    std::cout << "Using GLSL version to load shaders: " << GLSL_VERSION << std::endl;
    // Load basic lighting shader

    shader = LoadShader(TextFormat("assets/shaders/lighting.vs", GLSL_VERSION),
                        TextFormat("assets/shaders/lighting.fs", GLSL_VERSION));

    // Get some required shader locations
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(shader, "matModel");

    // NOTE: "matModel" location name is automatically assigned on shader loading,
    // no need to get the location again if using that uniform name
    // shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(shader, "matModel");

    // Ambient light level (some basic lighting)
    ambientLoc = GetShaderLocation(shader, "ambient");
    float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};

    SetShaderValue(shader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);

    // Create lights
    // lights[0] = CreateLight(LIGHT_POINT, {-2, 3, -2}, Vector3Zero(), YELLOW, shader);
    // lights[1] = CreateLight(LIGHT_POINT, {2, 3, 2}, Vector3Zero(), RED, shader);
    // lights[2] = CreateLight(LIGHT_POINT, {-2, 3, 2}, Vector3Zero(), GREEN, shader);
    // lights[3] = CreateLight(LIGHT_DIRECTIONAL, {2, 3, -2}, {0, 2, 1}, RAYWHITE, shader);

    SetTargetFPS(60);

    std::cout << "Initted!" << std::endl;
}

void Game::Update()
{

    UpdateCamera(&camera, CAMERA_ORBITAL);

    // Update the shader with the camera view vector (points towards { 0.0f, 0.0f, 0.0f })
    float cameraPos[3] = {camera.position.x, camera.position.y, camera.position.z};
    SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

    if (IsKeyPressed(KEY_Y))
    {
        lights[0].enabled = !lights[0].enabled;
    }
    if (IsKeyPressed(KEY_R))
    {
        lights[1].enabled = !lights[1].enabled;
    }
    if (IsKeyPressed(KEY_G))
    {
        lights[2].enabled = !lights[2].enabled;
    }
    if (IsKeyPressed(KEY_B))
    {
        lights[3].enabled = !lights[3].enabled;
    }

    // Update light values (actually, only enable/disable them)
    for (int i = 0; i < MAX_LIGHTS; i++)
    {
        UpdateLightValues(shader, lights[i]);
    }

    std::cout << "Drawing!" << std::endl;
    Draw();

    framesCounter++;
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode3D(camera);

    BeginShaderMode(shader);

    DrawPlane(Vector3Zero(), {10.0f, 10.0f}, WHITE);
    DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, WHITE);

    DrawModel(ResourceManager.model, {5, 1, 0}, 1.0f, WHITE);

    std::cout << "Updating model animation with frame " << framesCounter << std::endl;
    std::cout << "Name/FrameCount/BoneCount: " << ResourceManager.animations[0].name << " - " << ResourceManager.animations[0].frameCount << " - " << ResourceManager.animations[0].boneCount << std::endl;
    std::cout << "MaterialCount: " << ResourceManager.model.materialCount << std::endl;

    std::cout << "Is Model Anim Valid?: " << IsModelAnimationValid(ResourceManager.model, ResourceManager.animations[0]) << std::endl;
    UpdateModelAnimation(ResourceManager.model, ResourceManager.animations[0], framesCounter);

    EndShaderMode();

    for (int i = 0; i < MAX_LIGHTS; i++)
    {
        if (lights[i].enabled)
            DrawSphereEx(lights[i].position, 0.2f, 8, 8, lights[i].color);
        else
            DrawSphereWires(lights[i].position, 0.2f, 8, 8, ColorAlpha(lights[i].color, 0.3f));
    }

    EndMode3D();

    DrawFPS(10, 10);

    EndDrawing();
}

void Game::Cleanup()
{
    UnloadModelAnimations(ResourceManager.animations, ResourceManager.animsCount);
    UnloadShader(shader);
}