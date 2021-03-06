//Cody Ware
//5/19/19

#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "../headers/Scene.h"

class Window
{
private:
    int width_;
    int height_;
    std::string name_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool open_;
    Scene* scene_;

public:
    Window(const int& width, const int& height, const std::string& name);
    ~Window();

    const int& getHeight();
    const int& getWidth();
    const std::string& getName();
    const bool& isOpen();
    void free();
    void runMainLoop();
    SDL_Renderer* getRenderer();
    void setScene(const std::string& fileName);
};