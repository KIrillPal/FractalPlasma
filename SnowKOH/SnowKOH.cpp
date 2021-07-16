#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Complex.h"
#include <stack>
#include <queue>
#include <Windows.h>

float SCROLL_OFFSET = 0.9f;

const char* PROGRAM_NAME = "SFML";
uint16_t WINDOW_W = 300, WINDOW_H = 300;
const uint16_t LEFT_W = 265, MAX_PLAYERS = 10, FIELD_W = 500;
const float USS = 2, ProgramFrameTime = 1000 / 240; // 1000ms / 60frames
int windowMode = 1, length = 200, doubleClickTimer = -1;
float mouseX = 0, mouseY = 0;
uint64_t frameTime = 0;
sf::Font bF, tF;
sf::Sprite result_sprite;
sf::Texture graphTexture;
sf::RectangleShape drawline;
sf::RenderWindow* window;


sf::Uint8* graphPixels;

struct color
{
	double r, g, b;
	color(double r = 0, double g = 0, double b = 0) : r(r), g(g), b(b) {}
};

struct vertex
{
	int x, y;
	sf::Color color;
};

sf::Color mid(sf::Color& a, sf::Color& b)
{
	return sf::Color((a.r + b.r) / 2,(a.g + b.g) / 2,(a.b + b.b) / 2);
}

sf::Color rmid(sf::Color& a, sf::Color& b)
{
	int s = 50, s2 = 2 * s;
	sf::Color answer = sf::Color(
		(a.r + b.r) / 2 + rand() % s2 - s,
		(a.g + b.g) / 2 + rand() % s2 - s,
		(a.b + b.b) / 2 + rand() % s2 - s
	);
	if (answer.r < 0) answer.r = 0;
	if (answer.g < 0) answer.g = 0;
	if (answer.b < 0) answer.b = 0;
	if (answer.r > 255) answer.r = 255;
	if (answer.g > 255) answer.g = 255;
	if (answer.b > 255) answer.b = 255;
	return answer;
}

struct vertex_box
{
	vertex a, b, c, d;
};

std::queue<vertex_box> q;

void drawfield(vertex a, vertex b, vertex c, vertex d)
{
	/*sf::Vertex points[] = {
		sf::Vertex(sf::Vector2f(a.x, a.y), a.color),
		sf::Vertex(sf::Vector2f(b.x-1, b.y), b.color)
	};
	if (a.x != c.x && a.y != c.y)
	{
		int mx = (a.x + b.x) / 2, my = (a.y + c.y) / 2;
		vertex c1 = { mx, a.y, mid(a.color, b.color) };
		vertex c2 = { b.x, my, mid(b.color, c.color) };
		vertex c3 = { mx, c.y, mid(c.color, d.color) };
		vertex c4 = { a.x, my, mid(d.color, a.color) };
		vertex cc = { mx, my, mid(c1.color, c3.color) };
		drawfield(a, c1, cc, c4);
		drawfield(c1, b, c2, cc);
		drawfield(c4, cc, c3, d);
		drawfield(cc, c2, c, c3);
	}
	else
	{
		printf("correct");
	}
	window->draw(points, 2, sf::Points);*/
	q.push({ a, b, c, d });
	while (!q.empty())
	{
		vertex a = q.front().a;
		vertex b = q.front().b;
		vertex c = q.front().c;
		vertex d = q.front().d;
		q.pop();
		sf::Vertex points[] = {
		sf::Vertex(sf::Vector2f(a.x, a.y), a.color),
		sf::Vertex(sf::Vector2f(b.x - 1, b.y), b.color)
		};
		window->draw(points, 2, sf::Points);
		if (a.x+1 < c.x || a.y+1 < c.y)
		{
			int mx = (a.x + b.x) / 2, my = (a.y + c.y) / 2;
			vertex c1 = { mx, a.y, mid(a.color, b.color) };
			vertex c2 = { b.x, my, mid(b.color, c.color) };
			vertex c3 = { mx, c.y, mid(c.color, d.color) };
			vertex c4 = { a.x, my, mid(d.color, a.color) };
			vertex cc = { mx, my, rmid(c1.color, c3.color) };
			q.push({ a, c1, cc, c4 });
			q.push({ c1, b, c2, cc });
			q.push({ c4, cc, c3, d });
			q.push({ cc, c2, c, c3 });
		}
		/*else
		{
			printf("correct\n");
		}*/
	}
}

int main()
{
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(WINDOW_W, WINDOW_H), PROGRAM_NAME);
    window->setFramerateLimit(60);
    while (window->isOpen())
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window->close();
				delete graphPixels;
                delete window;
                return 0;
            }
            int X = e.mouseButton.x, Y = e.mouseButton.y;
            if (windowMode == 1)
            {
                if (e.type == sf::Event::MouseMoved) {
                }
                else if (e.type == sf::Event::MouseWheelScrolled) {
                }
                else if (e.type == sf::Event::MouseButtonPressed) {
                }
                else if (e.type == sf::Event::MouseButtonReleased) {
                }
                else if (e.type == sf::Event::KeyPressed) {
                }
            }
        }
		window->clear(sf::Color::Black);
		drawfield({ 0, 1, sf::Color::Red },
			{ WINDOW_W, 1, sf::Color::Blue },
			{ WINDOW_W, WINDOW_H, sf::Color::Green },
			{ 0, WINDOW_H, sf::Color::Yellow }
		);
		window->display();
		Sleep(100);
    }
}