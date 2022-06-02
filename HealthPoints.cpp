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

HealthPoints& HealthPoints::operator=(HealthPoints const& other){
    this->setMaxHP(other.getMaxHP());
    this->setHP(other.getHP());
    return *this;
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
    int hp = std::min(hp1.getHP() + hp2.getHP(), hp1.getMaxHP());
    HealthPoints newHp(hp);
    newHp.setMaxHP(hp1.getMaxHP());
    return newHp;
}

HealthPoints operator+(HealthPoints const& hp1,int hp2){
    int hp = std::min(hp1.getHP() + hp2, hp1.getMaxHP());
    if (hp < 0){
        hp = 0;
    }
    HealthPoints newHp;
    newHp.setHP(hp);
    newHp.setMaxHP(hp1.getMaxHP());
    return newHp;
}

HealthPoints operator+(int hp1, HealthPoints const& hp2){
    int hp = std::min(hp1 + hp2.getHP(), hp2.getMaxHP());
    if (hp < 0){
        hp = 0;
    }
    HealthPoints newHp;
    newHp.setHP(hp);
    newHp.setMaxHP(hp2.getMaxHP());
    return newHp;
}

HealthPoints& HealthPoints::operator+=(const HealthPoints &hp1) {
    int newHP = std::min(hp1.getHP() + this->getHP(), hp1.getMaxHP());
    this->setHP(newHP);
    return *this;
}

HealthPoints& HealthPoints::operator+=(int hp1) {
    int newHP = std::min(hp1 + this->getHP(), this->getMaxHP());
    if (newHP < 0){
        newHP = 0;
    }
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

HealthPoints operator-(HealthPoints const& hp1, int hp2){
    int hp = std::max(hp1.getHP() - hp2, 0);
    if (hp > hp1.getMaxHP()){
        hp = hp1.getMaxHP();
    }
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

HealthPoints& HealthPoints::operator-=(int hp1) {
    int newHP = std::max(this->getHP() - hp1, 0);
    if (newHP > this->getMaxHP()){
        newHP = this->getMaxHP();
    }
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


