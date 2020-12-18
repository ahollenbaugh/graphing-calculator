#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "../../!includes/Queue/queue.h"
#include "../../!includes/Token/token.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 5;
const int NUM_OF_POINTS = 10000;
const double PI = 3.14;

class Graph
{
public:
    Graph();
    Graph(double lo, double hi, sf::Vector2f origin, sf::Vector2f screenRange, sf::Vector2f graphRange);
    vector<sf::Vector2f> plot(Queue<Token*> postfix);
    void zoom(double multiple);
    void pan(char direction);
    sf::Vector2f translate(sf::Vector2f graphCoords);
    sf::Vector2f getRange();
    void drawAxes(sf::RenderWindow &window);
private:
    double _lo;
    double _hi;
    sf::Vector2f _origin;
    sf::Vector2f _screenRange;
    sf::Vector2f _graphRange;
    sf::Vertex xAxis[800]; // semi-arbitrary values used here so that it will compile
    sf::Vertex yAxis[600];
};

#endif // GRAPH_H
