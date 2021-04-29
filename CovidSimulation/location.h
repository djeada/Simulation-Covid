#ifndef LOCATION_H
#define LOCATION_H

#include <QPointF>

/* This class is a helper class for Person position.
  Each person has two coordinates in our simulation.
  Since we are constantly checking and setting them,
  it was clearer to make a separate class.
*/

#define SCENE_WIDTH 1200
#define SCENE_HEIGHT 800
#define VELOCITY_RANGE 2.0f

class Location {
private:
  QPointF position;
  QPointF velocity;

public:
  Location();
  Location(float a, float b);

  QPointF getPosition();
  QPointF getVelocity();

  float getCorX();
  float getCorY();
  void setCorX(float a);
  void setCorY(float b);

  float getCorVX();
  float getCorVY();
  void setCorVX(float a);
  void setCorVY(float b);
  void toggleVX();
  void toggleVY();

  void randomizeVelocity();
};

#endif // LOCATION_H
