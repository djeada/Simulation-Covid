#include "location.h"
#include "simulation.h"

Location::Location() {
  position.setX(randomInRange(0, SCENE_WIDTH));
  position.setY(randomInRange(0, SCENE_HEIGHT));
  velocity.setX(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000.0);
  velocity.setY(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000.0);
}

Location::Location(float a, float b) {
  position.setX(a);
  position.setY(b);
  velocity.setX(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000);
  velocity.setY(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000);
}

QPointF Location::getPosition() { return position; }

QPointF Location::getVelocity() { return velocity; }

float Location::getCorX() { return position.x(); }

float Location::getCorY() { return position.y(); }

void Location::setCorX(float a) {
  QPointF temp(a, getCorY());
  position = temp;
}

void Location::setCorY(float b) {
  QPointF temp(getCorX(), b);
  position = temp;
}

float Location::getCorVX() { return velocity.x(); }

float Location::getCorVY() { return velocity.y(); }

void Location::setCorVX(float a) {
  QPointF temp(a, getCorVY());
  velocity = temp;
}

void Location::setCorVY(float b) {
  QPointF temp(getCorVX(), b);
  velocity = temp;
}

void Location::toggleVX() { velocity.setX(velocity.x() * -1); }

void Location::toggleVY() { velocity.setY(velocity.y() * -1); }

void Location::randomizeVelocity() {
  velocity.setX(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000.0);
  velocity.setY(randomInRange(-VELOCITY_RANGE * 1000, VELOCITY_RANGE * 1000) /
                1000.0);
}
