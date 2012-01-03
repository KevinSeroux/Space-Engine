#include "GameEngine/EngineInstance.h"

int main()
{
    std::string title = "Title";
    unsigned int width = 800;
    unsigned int height = 600;
    EngineInstance myInstance(title, width, height);

    return 0;
}
