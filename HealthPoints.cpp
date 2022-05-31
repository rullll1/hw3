//
// Created by rulll on 22/05/2022.
//
#include <iostream>
#include "HealthPoints.h"

HealthPoints::HealthPoints() {
    this->m_hp = 100;
    this->m_maxHp = 100;

}

HealthPoints::HealthPoints(int hp) {
    if (hp <= 0){
        throw HealthPoints::InvalidArgument();
    }
    setMaxHP(hp);
    setHP(hp);
}

int HealthPoints::getHP() const {
    return this->m_hp;
}

void HealthPoints::setHP(int hp) {
    this->m_hp = hp;
}

void HealthPoints::setMaxHP(int hp) {
    this->m_maxHp = hp;
}

int HealthPoints::getMaxHP() const {
    return this->m_maxHp;
}

HealthPoints operator+(HealthPoints const& hp1, HealthPoints const& hp2){
    int hp = std::min(hp1.getHP() + hp2.getHP(), hp2.getMaxHP());
    return HealthPoints(hp);
}

HealthPoints& HealthPoints::operator+=(const HealthPoints &hp1) {
    int newHP = std::min(hp1.getHP() + this->getHP(), hp1.getMaxHP());
    this->setHP(newHP);
    return *this;
}

HealthPoints operator-(HealthPoints const& hp1, HealthPoints const& hp2){
    int hp = std::max(hp1.getHP() - hp2.getHP(), 0);
    HealthPoints newHP;
    newHP.setHP(hp);
    newHP.setMaxHP(hp1.getMaxHP());
    return newHP;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints &hp1) {
    int newHP = std::max(this->getHP() - hp1.getHP(), 0);
    this->setHP(newHP);
    return *this;
}

bool operator==(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() == hp2.getHP()){
        return true;
    }
    return false;
}

bool operator!=(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() != hp2.getHP()){
        return true;
    }
    return false;
}

bool operator>=(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() >= hp2.getHP()){
        return true;
    }
    return false;
}

bool operator<=(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() <= hp2.getHP()){
        return true;
    }
    return false;
}

bool operator<(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() < hp2.getHP()){
        return true;
    }
    return false;
}

bool operator>(HealthPoints const& hp1, HealthPoints const& hp2){
    if (hp1.getHP() > hp2.getHP()){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const HealthPoints& hp)
{
    os << hp.getHP() << '(' << hp.getMaxHP() << ')';
    return os;
}

void HealthPoints::printHP() {
    std::cout << this->m_hp << std::endl;
}


