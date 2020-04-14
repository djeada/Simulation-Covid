#include "location.h"
#include "simulator.h"

#include <math.h>
#include <stdlib.h>

Location::Location(){
    position.setX(randomInRange<int>(0, SCENE_WIDTH));
    position.setY(randomInRange<int>(0, SCENE_HEIGHT));
    velocity.setX(randomInRange<int>(-VELOCITY_RANGE, VELOCITY_RANGE));
    velocity.setY(randomInRange<int>(-VELOCITY_RANGE, VELOCITY_RANGE));
}

Location::Location(float a, float b){
    position.setX(a);
    position.setY(b);
    velocity.setX(randomInRange<int>(-VELOCITY_RANGE, VELOCITY_RANGE));
    velocity.setY(randomInRange<int>(-VELOCITY_RANGE, VELOCITY_RANGE));
}

bool Location::move_toward(Location destination, double howfar){
    /*double dx = destination.x - x;
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
    }*/
    return true;
}

QPointF Location::getPosition(){
    return position;
}

QPointF  Location::getVelocity(){
    return velocity;
}

float Location::getX() {
    return position.x();
}

float Location::getY() {
    return position.y();
}

void Location::setX(float a) {
    position.setX(a);
}

void Location::setY(float b) {
    position.setY(b);
}

float Location::getVX() {
    return velocity.x();
}

float Location::getVY() {
    return velocity.y();
}

void Location::setVX(float a) {
    velocity.setX(a);
}

void Location::setVY(float b) {
    velocity.setY(b);
}

void Location::toggleVX()  {
    velocity.setX(velocity.x()*-1);
}

void Location::toggleVY()  {
    velocity.setY(velocity.y()*-1);
}
