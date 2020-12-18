#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <cmath>
#include <cctype>
#include "../../../!includes/Token/token.h"
#include "../../../!includes/Operator/operator.h"
#include "../../../!includes/Operand/operand.h"
#include "../../../!includes/Queue/queue.h"
#include "../../../!includes/Stack/stack.h"
#include "../../../!includes/Variable/variable.h"
#include "../../../!includes/Eval/eval.h"
#include "../../../!includes/Graph/graph.h"
#include "../../../!includes/Function/function.h"

using namespace std;

const int STRING_SIZE = 200;

vector<sf::Vector2f> plot(Queue<Token*> postfix, double lo, double hi, int numberOfPoints);
void draw(Graph g, vector<sf::Vector2f> listOfPoints, Queue<Token*> postfix, sf::CircleShape circleArray[NUM_OF_POINTS]);
Queue<Token*>stringToQueue(char inputStr[]);
void test_strtok();
Token* getTokenPtr(char *s);
Queue<Token*> f1(); // y = x^2
Queue<Token*> f2(); // y = 3 sin(x)
Queue<Token*> f3(); // y = 0.5x
Queue<Token*> f4(); // y = sin(1/x)
Queue<Token*> f5(); // y = (max(2, 3)) * sin(x)
Queue<Token*> f6(); // y = sin(tan(1/x^2))

int main()
{   

    Queue<Token*> qq;

//    test_strtok();
//    char testString[STRING_SIZE] = "sin ( cos ( 1 / x ) )";
//    char testString[STRING_SIZE] = "sin ( tan ( 1 / ( x * x ) ) )";
//    char testString[STRING_SIZE] = "1 / ( 1 + ( x * x ) )";
    char testString[STRING_SIZE] = "x * x";
//    char testString2[STRING_SIZE] = "( max ( 2 , 3 ) ) * x";
    cout << "------------------------------------------------" << endl;
    Queue<Token*> testQueue = stringToQueue(testString);
//    Queue<Token*> testQueue2 = stringToQueue(testString2);
    cout << "Here's your string as a queue of tokens: " << testQueue << endl;
//    cout << "Here's your string as a queue of tokens: " << testQueue2 << endl;
    cout << "------------------------------------------------" << endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator"); // declare a window object

    window.setFramerateLimit(30);
    sf::CircleShape circleArray[NUM_OF_POINTS]; // points are stored as circles, which are then stored in this array

    window.setVerticalSyncEnabled(true);

    Queue<Token*> infix = testQueue;
    Queue<Token*> postfix = infixToPostfix(infix); // convert
    cout << "------------------------after Shunting yard------------------------" << endl;
    cout << "main: postfix = " << postfix << endl;

    Graph g; // declare a graph object

    sf::CircleShape point(CELL_SIZE);
    point.setFillColor(sf::Color::Red);
    vector<sf::Vector2f> listOfPoints; // declare a vector of coordinates ("vector2f")

    draw(g, listOfPoints, postfix, circleArray); // give coordinates to each circle in your array

    // run the program as long as the window is open
    while (window.isOpen()){

        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;

        //go through all the pending events: keyboard, mouse, close, resize, etc.
        //pollEvent and waitEvent are the only two functions that can fill event
        while (window.pollEvent(event))//or waitEvent
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                cout<<"close event was encountered!"<<endl;
                window.close();
                break;
                // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    std::cout << "Zooming in" << std::endl;
                    g.zoom(0.85);
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    std::cout << "Zooming out" << std::endl;
                    g.zoom(1.15);
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    std::cout << "Pan left" << std::endl;
                    g.pan('a');
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    std::cout << "Pan right" << std::endl;
                    g.pan('d');
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    std::cout << "Pan up" << std::endl;
                    g.pan('w');
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    std::cout << "Pan down" << std::endl;
                    g.pan('s');
                    draw(g, listOfPoints, postfix, circleArray);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                    // let the user enter a new expression
                    cout << "Enter a new expression" << endl
                         << "(Put spaces between each item):" << endl;
                    cin.getline(testString, 200);
                    testQueue = stringToQueue(testString);
                    cout<<"main(): after stringToQueue()"<<endl;
                    cout << "main::process events: queue: " <<endl;
                    cout<<"      "<< testQueue << endl;
                    infix = testQueue;
                    postfix = infixToPostfix(infix);
                    draw(g, listOfPoints, postfix, circleArray);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "Right mouse button: "
                              << "(" << event.mouseButton.x
                              << ", " << event.mouseButton.y
                              << ")" << std::endl;
                }
                else
                    std::cout<<"Left mouse button"<<std::endl;
                break;
            default:
                break;
            }
        }

        window.clear();

        g.drawAxes(window);

        for(int i = 0; i < NUM_OF_POINTS; i++){
            // go through circle array and
            // draw the circle and its points
            // for each element
            window.draw(circleArray[i]);
        }

        window.display();
    }
    return 0;
}

vector<sf::Vector2f> plot(Queue<Token*> postfix, double lo, double hi, int numberOfPoints){
    // generates a certain number of coordinates (numberOfPoints)
    // between lo and hi
    // by plugging each "x" value into the postfix function
    // and storing the x and y values into a vector of coordinates
    // and returning that vector
    const bool debug = false;
    if(debug) cout << "Hi, I'm the plot function" << endl;
    vector<sf::Vector2f> points; // create your vector of points
    int num = 0; // number of points between lo and hi if we're incrementing by 1
    for(int i = lo; i < hi; i++){
        num = num + ((i+1)-i); // figure out the distance between each number and add them up
    }
    if(debug) cout << "this is how many points there are between " << lo << " and " << hi << ": " << num << endl;
    double increment;
    increment = numberOfPoints / num; // there should be this many points between each integer
    increment = 1 / increment; // this is the increment you should add when going from lo to hi
    int i = 0;
    while(lo < hi){
        lo += increment;
        points.push_back(sf::Vector2f(lo, eval(postfix, lo))); // add this set of coordinates to your vector
        if(debug)cout << points[i].x << ", " << points[i].y << endl;
        i++;
    }
    return points;
}
void draw(Graph g, vector<sf::Vector2f> listOfPoints, Queue<Token *> postfix, sf::CircleShape circleArray[NUM_OF_POINTS]){
    // solution to redundant code problem
    listOfPoints = g.plot(postfix);
    for(int i = 0; i < NUM_OF_POINTS; i++){ // go through circle array and define a circle at some (x, y) for each element
        circleArray[i] = sf::CircleShape(2); // declare a circle of radius = 1
        circleArray[i].move(listOfPoints[i].x, listOfPoints[i].y); // circle will be located at (x, y)
    }
}
Queue<Token*>stringToQueue(char inputStr[]){
    // convert a cstring to a queue of tokens
    const bool debug = true;
    Queue<Token*> infix;
    char* p = strtok(inputStr, " ");
    Token* t;
    /*
     * you create a token pointer,
     * then you figure out whether p can be classified
     * as an operand, operator, variable, or function;
     * for example, if p = "sin",
     * then Token* test = new Function(p)
     * and return test.
     */
    while(p != NULL){

        t = getTokenPtr(p);
        if(debug) cout << "main::stringToQueue: pushing " << t << " to queue" << endl;
        infix.push(t);
        if(debug) cout << "main::stringToQueue: infix is currently: " << infix << endl;
        p = strtok(NULL, " "); // points to the next element in the string
    }
    if(debug)cout << "main::stringToQueue: final infix: " << infix << endl;
    return infix;
}
void test_strtok(){
    char s[] = "sin ( cos ( 1 / x ) )";
    char* p = strtok(s, " "); // p points to some character within the string
    while(p != NULL){
        cout << p << " ";
        p = strtok(NULL, " ");
    }
}
Token* getTokenPtr(char* s){
    const bool debug = true;
    Token* t;
    double operand;
    switch(*s){
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case ',':
        // it's an operator
        if(debug) cout << "main::getTokenPtr: " << s << " is an OPERATOR" << endl;
        t = new Operator(*s);
        return t;
        break;
    case 'X':
    case 'x':
        if(debug) cout << "main::getTokenPtr: " << s << " is a VARIABLE" << endl;
        t = new Variable;
        return t;
        break;
    default:
        break;
    }
    // if it's not an operator or variable, it's either
    // an operand or function
    if(isdigit(*s)){
        // it's an operand
        if(debug) cout << "main::getTokenPtr: " << s << " is an OPERAND" << endl;
        // need to convert value before pushing
        // otherwise it pushes the ASCII value
        // number = char - 48
        if(debug) cout << "main::getTokenPtr: operand: " << operand << endl;
        *s -= 48;
        t = new Operand(*s);
        return t;
    }
    else{
        // it's a function
        if(debug) cout << "main::getTokenPtr: " << s << " is a FUNCTION" << endl;
        t = new Function(s);
        return t;
    }
    cout<<"getTokenPtr: oh shit! what am I doing here?"; cin.get();
//    return t;
}
Queue<Token*> f1(){
    // test function
    // y = x^2:
    Queue<Token*> infix;
    infix.push(new Variable);
    infix.push(new Operator('*'));
    infix.push(new Variable);
    return infix;
}
Queue<Token*> f2(){
    // y = 3 sin(x):
    Queue<Token*> infix;
    infix.push(new Operand(3));
    infix.push(new Operator('*'));
    infix.push(new Function("sin"));
    infix.push(new Operator('('));
    infix.push(new Variable);
    infix.push(new Operator(')'));
    return infix;
}
Queue<Token*> f3(){
    // y = 0.5x:
    Queue<Token*> infix;
    infix.push(new Operand(0.5));
    infix.push(new Variable);
    infix.push(new Operator('*'));
    infix.push(new Variable);
    return infix;
}
Queue<Token*> f4(){
    // y = sin(1/x):
    Queue<Token*> infix;
    infix.push(new Function("sin"));
    infix.push(new Operator('('));
    infix.push(new Operand(1));
    infix.push(new Operator('/'));
    infix.push(new Variable);
    infix.push(new Operator(')'));
    return infix;
}
Queue<Token*> f5(){
    // testing max function
    Queue<Token*> infix;
    infix.push(new Operator('('));
    infix.push(new Function("max"));
    infix.push(new Operator('('));
    infix.push(new Operand(2));
    infix.push(new Operator(','));
    infix.push(new Operand(3));
    infix.push(new Operator(')'));
    infix.push(new Operator(')'));
    infix.push(new Operator('*'));
    infix.push(new Function("sin"));
    infix.push(new Operator('('));
    infix.push(new Variable);
    infix.push(new Operator(')'));
    return infix;
}
Queue<Token*> f6(){
    // sin ( tan ( 1 / ( x * x ) ) )
    Queue<Token*> infix;
    infix.push(new Function("sin"));
    infix.push(new Operator('('));
    infix.push(new Function("tan"));
    infix.push(new Operator('('));
    infix.push(new Operand(1));
    infix.push(new Operator('/'));
    infix.push(new Operator('('));
    infix.push(new Variable);
    infix.push(new Operator('*'));
    infix.push(new Variable);
    infix.push(new Operator(')'));
    infix.push(new Operator(')'));
    infix.push(new Operator(')'));
    return infix;
}

