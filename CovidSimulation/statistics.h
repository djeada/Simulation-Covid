#ifndef STATISTICS_H
#define STATISTICS_H

/* This class keeps truck of the number
 * of people in each category.
 */

class Statistics {
  int num_infected;
  int num_dead;
  int num_vulnerable;
  bool saturation;

public:
  Statistics();
  Statistics(int infected, int dead, int vulnerable);

  void set_saturation(bool flag);
  void increaseNum_infected();
  void increaseNum_dead();
  void increaseNum_vulnerable();
  void decreaseNum_infected();
  void decreaseNum_dead();
  void decreaseNum_vulnerable();

  bool isTheSystemSaturated();
  int getNum_infected();
  int getNum_dead();
  int getNum_vulnerable();
};

#endif // STATISTICS_H
