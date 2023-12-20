//
// Created by John Greene on 12/20/23.
//
#include "Particle.h"
#include <iostream>

Particle::Particle(float initMass, float initCSArea, float initDragCoefficient)
        : mass(initMass), CSArea(initCSArea), DragCoefficient(initDragCoefficient) {

}


void Particle::setParticleMass(float newMass) {
    mass = newMass;
}

void Particle::setParticleCSArea(float newCSArea) {
    CSArea = newCSArea;
}

void Particle::setParticleDragCoefficient(float newDragCoefficient) {
    DragCoefficient = newDragCoefficient;
}


float Particle::getParticleMass() const {
    return mass;
}

float Particle::getParticleCSArea() const {
    return CSArea;
}

float Particle::getParticleDragCoefficient() const {
    return DragCoefficient;
}

double Particle::getParticleTerminalVelocity() const{
    return sqrt((2 * mass * GRAVITY) / (CSArea * DragCoefficient * AIR_DENSITY));
}

}