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

// Should use this function with a while statement
// i.e. while t < totalTime: do function
// if velocity is = to terminal velocity calculatation no longer nessecary.
double Particle::calculateVelocity(){
    k = DragCoefficient * AIR_DENSITY * CSArea;
    acceleration = GRAVITY -(k/mass) * velocity * velocity;
    velocity = velocity + acceleration;

    return velocity;
}

