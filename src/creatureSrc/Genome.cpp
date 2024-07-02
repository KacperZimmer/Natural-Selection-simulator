
#include "../../include/CreatureIncludes/Genome.h"
#include "random"

void Genome::generateGenome(const Genome &genome) {

    this->velocity = genome.getVelocity();
    this->energy = genome.getEnergy();
    this->seeingRadius = genome.getSeeingRadius();
    this->size = genome.getSize();

}

float Genome::getVelocity() const {
    return velocity;
}

double Genome::getEnergy() const {
    return energy;
}

void Genome::setVelocity(float velocity) {
    Genome::velocity = velocity;
}


void Genome::setEnergy(double energy) {
    Genome::energy = energy;
}

bool Genome::shouldGeneMutate() const {
    std::random_device rd;

    std::mt19937  gen(rd());
    std::normal_distribution<> dis(1, 100);

    float probability = dis(gen);

    if(probability > 5.f) return true;

    return false;
}

Genome::Genome(float velocity, float radius, double energy, float sizeRadius) : velocity(velocity), seeingRadius(radius), energy(energy), size(sizeRadius){}

Genome::Genome() {}

void Genome::setSize(float size) {
    Genome::size = size;
}

void Genome::setSeeingRadius(float seeingRadius) {
    Genome::seeingRadius = seeingRadius;
}

float Genome::getSize() const {
    return size;
}

float Genome::getSeeingRadius() const {
    return seeingRadius;
}
