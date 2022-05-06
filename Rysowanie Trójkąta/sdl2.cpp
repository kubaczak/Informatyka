#include <iostream>
#include <SDL.h>
#include <fstream>
#include <string>
#include "drawingOOP.h"
using namespace std;

SDL_Renderer* renderer;
void Circle::Draw()
{
    cout << "Drawing " << m_name << endl;
}

void Rectangle::Draw()
{
    cout << "Drawing " << m_name << endl;
    SDL_Rect r;
    r.x = m_x;
    r.y = m_y;
    r.w = m_width;
    r.h = m_height;
    SDL_SetRenderDrawColor(renderer, m_color.red, m_color.green, m_color.blue, m_color.alpha);
    SDL_RenderFillRect(renderer, &r);

}

void Triangle::Draw() {
    cout << "Drawing" << m_name << endl;
    SDL_SetRenderDrawColor(renderer, m_color.red, m_color.green, m_color.blue, m_color.alpha);

    for (int i = 0; i <= m_width/2; i++) {
        SDL_RenderDrawLine(renderer, m_x+i, m_y-i, m_x + m_width - i, m_y - i);
        SDL_RenderDrawLine(renderer, m_x + m_width - i, m_y - i, m_x + (m_width / 2), m_y - m_height + i);
        SDL_RenderDrawLine(renderer, m_x + (m_width / 2), m_y - m_height + i, m_x + i, m_y - i);
    }
}

int main(int argc, char** argv)
{
    bool leftMouseButtonDown = false;
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Pixel Drawing",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    SDL_Texture* texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, 800, 600);
    Uint32* pixels = new Uint32[800 * 600];
    memset(pixels, 0xff000000, 800 * 600 * sizeof(Uint32));
    
    
    
    
    
    while (!quit)
    {
        
        SDL_UpdateTexture(texture, NULL, pixels, 800 * sizeof(Uint32));

        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                leftMouseButtonDown = true;
        case SDL_MOUSEMOTION:
            if (leftMouseButtonDown)
            {
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                //pixels[mouseY * 640 + mouseX] = 0;
            }
            break;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Clear winow
        SDL_RenderClear(renderer);
        Color color = Color{ 1,2,3,4 };
        vector<Shape*> items;
        //Rectangle* rect1 = new Rectangle("First Rectangle", 100, 100, 100, 100, Color{123,123,123,255});
        //Rectangle* rect2 = new Rectangle("Second Rectangle", 230, 100, 100, 100, Color{ 123,123,123,255 });
        //Rectangle* rect3 = new Rectangle("Third Rectangle", 360, 100, 100, 100, Color{ 123,123,123,255 });
        //Rectangle* rect4 = new Rectangle("Fourth Rectangle", 490, 100, 100, 100, Color{ 123,123,123,255 });
        
        //items.push_back(rect1);
        //items.push_back(rect2);
        //items.push_back(rect3);
        //items.push_back(rect4);

        Triangle* tri1 = new Triangle("First Triangle", 100, 200, 200, 100, Color{ 22,252,45,255 });
        Triangle* tri2 = new Triangle("Second Triangle", 500, 200, 100, 100, Color{ 22,240,252,255 });
        Triangle* tri3 = new Triangle("Third Triangle", 100, 500, 150, 100, Color{ 252,22,22,255 });

        items.push_back(tri1);
        items.push_back(tri2);
        items.push_back(tri3);

        for (Shape* it : items)
        {
            it->Draw();
            delete it;
        }

        items.clear();
        //SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}