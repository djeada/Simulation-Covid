#ifndef LOCATION_H
#define LOCATION_H

#include <QPointF>

#define SCENE_WIDTH 1000
#define SCENE_HEIGHT 1000
#define VELOCITY_RANGE 2

class Location {
    private:
        QPointF position;
        QPointF velocity;
    public:
        Location();
        Location(float a, float b);

        bool move_toward(Location destination, double speed);

        QPointF getPosition();
        QPointF getVelocity();

        float getX();
        float getY();
        void setX(float a);
        void setY(float b);

        float getVX();
        float getVY();
        void setVX(float a);
        void setVY(float b);
        void toggleVX();
        void toggleVY();
};

#endif // LOCATION_H
