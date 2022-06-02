//
// Created by rulll on 22/05/2022.
//

#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H

#include <iostream>
using namespace std;

class HealthPoints {
public:
    HealthPoints(int hp);
    HealthPoints();
    HealthPoints(const HealthPoints&) = default;

    HealthPoints& operator=(HealthPoints const& other);
    friend HealthPoints operator+(HealthPoints const& hp1, HealthPoints const& hp2);
    friend HealthPoints operator+(HealthPoints const& hp1, int hp2);
    friend HealthPoints operator+(int hp1, HealthPoints const& hp2);

    HealthPoints& operator+=(HealthPoints const& hp1);
    HealthPoints& operator+=(int hp1);

    friend HealthPoints operator-(HealthPoints const& hp1, HealthPoints const& hp2);
    friend HealthPoints operator-(HealthPoints const& hp1, int hp2);



    HealthPoints& operator-=(HealthPoints const& hp1);
    HealthPoints& operator-=(int hp1);


    bool friend operator==(HealthPoints const& hp1, HealthPoints const& hp2);
    bool friend operator!=(HealthPoints const& hp1, HealthPoints const& hp2);
    bool friend operator<=(HealthPoints const& hp1, HealthPoints const& hp2);
    bool friend operator<(HealthPoints const& hp1, HealthPoints const& hp2);
    bool friend operator>=(HealthPoints const& hp1, HealthPoints const& hp2);
    bool friend operator>(HealthPoints const& hp1, HealthPoints const& hp2);
    friend ostream& operator<<(ostream& os, const HealthPoints& hp);





    int getHP() const;
    void setHP(int hp);
    int getMaxHP() const;
    void setMaxHP(int hp);
    void printHP();
    class InvalidArgument {};

private:
    int m_hp;
    int m_maxHp;
};


#endif //HW3_HEALTHPOINTS_H
