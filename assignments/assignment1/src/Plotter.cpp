#include "Plotter.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream &input)
{
    PenStyle style = {1, "black"};
    bool toDraw = false;
    double currx = 0, curry = 0;
    string line;
    for (string line; getline(input, line);)
    {
        // Split line
        line = toLowerCase(line);
        Vector<string> command = stringSplit(line, " ");

        if (command[0] == "penwidth")
        {
            style.width = stringToDouble(command[1]);
            continue;
        }

        if (command[0] == "pencolor")
        {
            style.color = command[1];
            continue;
        }

        if (command[0] == "penup")
        {
            toDraw = false;
            continue;
        }

        if (command[0] == "pendown")
        {
            toDraw = true;
            continue;
        }

        // Get x, y
        double x = stringToDouble(command[1]), y = stringToDouble(command[2]);
        double destx, desty;
        if (command[0] == "moveabs")
        {
            destx = x;
            desty = y;
        }
        if (command[0] == "moverel")
        {
            destx = currx + x;
            desty = curry + y;
        }

        if (toDraw)
            drawLine(currx, curry, x, y, style);
        currx = destx;
        curry = desty;
    }
}
