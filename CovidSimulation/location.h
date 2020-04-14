#ifndef LOCATION_H
#define LOCATION_H

#define SCENE_WIDTH 1200
#define SCENE_HEIGHT 800
#define CLOSE_ENOUGH 1 //locations less than this distance are in danger

class Location {
    private:
        int x, y;
        int vx, vy;
    public:
        Location();
        Location(int nx, int ny);

        double get_distance(Location other_location);
        bool move_toward(Location destination, double speed);
        bool at_location(Location destination);

        int getX();
        int getY();
        void setX(int a);
        void setY(int b);

        int getVX();
        int getVY();
        void setVX(int a);
        void setVY(int b);
        void toggleVX();
        void toggleVY();
};

#endif // LOCATION_H
