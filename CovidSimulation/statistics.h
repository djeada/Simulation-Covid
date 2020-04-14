#ifndef STATISTICS_H
#define STATISTICS_H

class statistics
{
    int num_infected;
    int num_immune;
    int num_dead;
    int num_vulnerable;
public:
    statistics();

    void increaseNum_infected();
    void increaseNum_dead();
    void increaseNum_vulnerable();

    int getNum_infected();
    int getNum_dead();
    int getNum_vulnerable();
};

#endif // STATISTICS_H
