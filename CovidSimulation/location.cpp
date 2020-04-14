#include "location.h"
#include <math.h>
#include "simulator.h"
#include <stdlib.h>

Location::Location(){
    x = randomInRange(0, SCENE_WIDTH);
    y = randomInRange(0, SCENE_HEIGHT);
    vx = headOrTail();
    vy = headOrTail();
}

Location::Location(int nx, int ny){
    x = nx;
    y = ny;
    vx = headOrTail();
    vy = headOrTail();
}

bool Location::move_toward(Location destination, double howfar){
    double dx = destination.x - x;
    double dy = destination.y - y;
    double theta = atan2(dy,dx);

    double distance = sqrt((dx*dx)+(dy*dy));

    if(distance < howfar){
        x = destination.x;
        y = destination.y;
        return true;
    }
    else {
        x += howfar*cos(theta);
        y += howfar*sin(theta);
        return false;
    }
}

double Location::get_distance(Location other_location){
    double dx = other_location.x - x;
    double dy = other_location.y - y;
    return sqrt((dx*dx)+(dy*dy));
}

bool Location::at_location(Location destination){
    return (get_distance(destination) < CLOSE_ENOUGH);
}

int Location::getX() {
    return x;
}

int Location::getY() {
    return y;
}

void Location::setX(int a) {
    x = a;
}

void Location::setY(int b) {
    y = b;
}

int Location::getVX() {
    return vx;
}

int Location::getVY() {
    return vy;
}

void Location::setVX(int a) {
    vx = a;
}

void Location::setVY(int b) {
    vy = b;
}

void Location::toggleVX()  {
    vx = -1*vx;
}

void Location::toggleVY()  {
    vy = -1*vy;
}

