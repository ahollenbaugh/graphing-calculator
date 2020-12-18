#include "graph.h"
#include "../../!includes/Eval/eval.h"
#include <iostream>
using namespace std;

Graph::Graph()
{
    _lo = -10; // use these x-values for your graph
    _hi = 10;   // before you translate to screen coords
    sf::Vector2f origin(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    // so since screen width is 800 and height is 600,
    // we want our origin to be the halfway point
    _origin = origin;
    sf::Vector2f graphRange(_lo, _hi); // set graph range
    _graphRange = graphRange;
    sf::Vector2f screenRange(0, 800); // set screen range
    _screenRange = screenRange;
}
Graph::Graph(double lo, double hi, sf::Vector2f origin, sf::Vector2f screenRange, sf::Vector2f graphRange):
_lo(lo), _hi(hi), _origin(origin), _screenRange(screenRange), _graphRange(graphRange){
    // left blank
}
vector<sf::Vector2f> Graph::plot(Queue<Token *> postfix){
    // returns list of screen coordinates
    const bool debug = false;
    double range; // # of ints between hi and lo
    double increment; // determined by # of pts you want to graph
    int pixPerUnit; // pixels per graph unit
    sf::Vector2f p; // some point in your list of points (changes)
    vector<sf::Vector2f> screenCoords; // list of screen coords
    range = _hi - _lo; // distance between hi and lo
    if(debug)cout << "range: " << range << endl;
    if(debug)cout << "NUM_OF_POINTS: " << NUM_OF_POINTS << endl;
    increment = range / NUM_OF_POINTS;
    if(debug)cout << "increment: " << increment << endl;
    pixPerUnit = _screenRange.y / range; // ex: 800 px / 20 units between -10 and +10
    if(debug)cout << "pixPerUnit: " << pixPerUnit << endl;
    int i = 0;
    double num = _lo;
    if(debug)cout<<"----------------------------------"<<endl;
    while(num < _hi){ // go through range
        // push your x and y values to the vector
        p.x = num; // set the x-coordinate of some point p
        p.y = eval(postfix, num); // set the y-coordinate of some point p
        p.x = p.x * pixPerUnit; // convert to pixels
        p.y = p.y * pixPerUnit;
        p.x = _origin.x + p.x; // adjust position relative to the origin
        p.y = _origin.y - p.y;
        screenCoords.push_back(p); // add this set of coordinates to your vector
        num += increment; // go to the next x-value you need to plot
        i++;
        if(debug)cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return screenCoords;
}
void Graph::zoom(double multiple){
    // can zoom in by multiplying graph range
    // by, for example, .85,
    // and can zoom out by multiplying by 1.15.
    _lo *= multiple;
    _hi *= multiple;
}
void Graph::pan(char direction){
    // pan left, right, up, and down
    const bool debug = false;
    double range;
    int pixPerUnit;
    range = _hi - _lo;
    pixPerUnit = _screenRange.y / range;
    // add/subtract pixPerUnit to/from origin when you move
    // one "step" in any direction
    switch(direction){
    case 'w':
        // pan up
        _origin.y += pixPerUnit;
        if(debug){
            cout << "origin: ("
                 << _origin.x
                 << ", "
                 << _origin.y
                 << ")"
                 << endl;
        }
        break;
    case 's':
        // pan down
        _origin.y -= pixPerUnit;
        if(debug){
            cout << "origin: ("
                 << _origin.x
                 << ", "
                 << _origin.y
                 << ")"
                 << endl;
        }
        break;
    case 'a':
        // pan left
        _origin.x += pixPerUnit;
        _lo--;
        _hi--;
        if(debug){
            cout << "origin: ("
                 << _origin.x
                 << ", "
                 << _origin.y
                 << ")"
                 << endl;
            cout << "_lo: " << _lo << endl;
            cout << "_hi: " << _hi << endl;
        }
        break;
    case 'd':
        // pan right
        _origin.x -= pixPerUnit;
        _lo++;
        _hi++;
        if(debug){
            cout << "origin: ("
                 << _origin.x
                 << ", "
                 << _origin.y
                 << ")"
                 << endl;
            cout << "_lo: " << _lo << endl;
            cout << "_hi: " << _hi << endl;
        }
        break;
    default:
        break;
    }
}

sf::Vector2f Graph::translate(sf::Vector2f graphCoords){
    // translate a set of graph coordinates
    // into a set of screen coordinates
    // for every one graph unit we move,
    // we have to move x pixels
    // for example: if the screen is 800 pixels
    // across, and our graph range is from -10 to +10,
    // then for every one graph unit we move,
    // we have to move 40 pixels.

    // start over!



//    const bool debug = true;
//    double unit; // contains some number of pixels
//    unit = _screenRange.y / (_hi - _lo);
//    if(debug){
//        cout << "Coordinates before translation: " << endl;
//        cout << "Graph::translate: x = " << graphCoords.x
//             << endl
//             << "Graph::translate: y = " << graphCoords.y
//             << endl;
//    }
//    graphCoords.x *= unit;
//    graphCoords.y *= unit;
//    if(debug){
//        cout << "Coordinates after translation: " << endl;
//        cout << "Graph::translate: unit = " << unit << endl
//             << "Graph::translate: x = " << graphCoords.x
//             << endl
//             << "Graph::translate: y = " << graphCoords.y
//             << endl;
//    }
//    graphCoords.x = _origin.x + graphCoords.x; // adjust position
//    graphCoords.y = _origin.y - graphCoords.y; // adjust position
//    if(debug){
//        cout << "After adjusting position: " << endl
//             << "(" << graphCoords.x << ", "
//             << graphCoords.y << ")" << endl;
//    }

    // we need to convert these points
    // relative to the screen's origin
    // (in this case it's (400, 300),
    // rather than the graph origin
    // (0, 0)
    // if x moves left: 400 - x
    // if x moves right: 400 + x
    // if y moves up: 300 - y
    // if y moves down: 300 + y

    return graphCoords;
}
sf::Vector2f Graph::getRange(){
    // returns _graphRange
    sf::Vector2f range(_lo, _hi);
    return range;
}
void Graph::drawAxes(sf::RenderWindow& window){
    sf::Vector2f xAxisPtA, xAxisPtB, yAxisPtA, yAxisPtB;
    xAxisPtA = sf::Vector2f(0, _origin.y); // first endpoint of x-axis
    xAxisPtB = sf::Vector2f(SCREEN_WIDTH, _origin.y); // second endpoint of x-axis
    yAxisPtA = sf::Vector2f(_origin.x, 0); // first endpoint of y-axis
    yAxisPtB = sf::Vector2f(_origin.x, SCREEN_HEIGHT); // second endpoint of y-axis
    // define x-axis:
    xAxis[0] = sf::Vertex(sf::Vector2f(xAxisPtA.x, xAxisPtA.y));
    xAxis[1] = sf::Vertex(sf::Vector2f(xAxisPtB.x, xAxisPtB.y));
    // define y-axis:
    yAxis[0] = sf::Vertex(sf::Vector2f(yAxisPtA.x, yAxisPtA.y));
    yAxis[1] = sf::Vertex(sf::Vector2f(yAxisPtB.x, yAxisPtB.y));
    window.draw(xAxis, 2, sf::Lines);
    window.draw(yAxis, 2, sf::Lines);

}
