#include "ErrorManager.h"

void ErrorManager::DisplayMessage(const std::string& message)
{
    std::cout << "L'application à détecté une erreur :" << std::endl << std::endl << message;
}
