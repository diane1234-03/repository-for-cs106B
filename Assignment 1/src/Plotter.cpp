#include <stdio.h>
#include "Plotter.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    bool down = false;
    double currx = 0;
    double curry = 0;


    PenStyle style = {1, "black"};
    for(string line; getline(input, line);){
        Vector<string> commandList = stringSplit(line, ' ');
        string command = toLowerCase(commandList[0]);
        if(command == "pendown"){
            down = true;
        } else if(command == "penup"){
            down = false;
        } else if(command == "moveabs"){
            double x1 = stringToReal(commandList[1]);
            double y1 = stringToReal(commandList[2]);
            if(down){
                drawLine(currx,curry,x1,y1,style);
            }
            currx = x1;
            curry = y1;
        } else if (command == "moverel"){
            double x1 = currx + stringToReal(commandList[1]);
            double y1 = curry + stringToReal(commandList[2]);
            if(down){
                drawLine(currx,curry,x1,y1,style);
            }

            currx = x1;
            curry = y1;

        } else if(command == "pencolor"){
            style.color = commandList[1];

        }else if(command == "penwidth"){
            style.width = stringToReal(commandList[1]);
        }

    }
}
