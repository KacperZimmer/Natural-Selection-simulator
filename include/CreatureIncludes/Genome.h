#include "raylib.h"


#ifndef EXAMPLE_GENOME_H
#define EXAMPLE_GENOME_H


class Genome {

    float velocity{};
    float size{};
    float seeingRadius{};
    double energy{};


    void generateGenome(const Genome& genome);
    bool shouldGeneMutate() const;

public:
    Genome(float velocity, float radius, double energy, float sizeRadius);

    Genome();

    float getSize() const;
    double getEnergy() const;
    float getVelocity() const;
    float getSeeingRadius() const;

    void setSize(float size);
    void setEnergy(double energy);
    void setVelocity(float velocity);
    void setSeeingRadius(float seeingRadius);
};


#endif //EXAMPLE_GENOME_H
