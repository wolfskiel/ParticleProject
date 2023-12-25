//
// Created by John Greene on 12/20/23.
//
#include "Particle.h"
#include <chrono>
#include <cmath>

Particle::Particle(float initMass, float initCSArea, float initDragCoefficient)
        : mass(initMass), CSArea(initCSArea), drag_coefficient(initDragCoefficient) {

}

// Setters and getters if needed right now not used.
void Particle::setParticleMass(float newMass) {
    mass = newMass;
}

void Particle::setParticleCSArea(float newCSArea) {
    CSArea = newCSArea;
}

void Particle::setParticleDragCoefficient(float newDragCoefficient) {
    drag_coefficient = newDragCoefficient;
}


double Particle::getParticleMass() const {
    return mass;
}

double Particle::getParticleCSArea() const {
    return CSArea;
}

double Particle::getParticleDragCoefficient() const {
    return drag_coefficient;
}
// Terminal velocity needs the air density to be called to have the correct terminal velocity at the current altitude
double Particle::calculateTerminalVelocity() {
    air_density= calculateAirDensity(time); // Calculate air density first
    return sqrt((2 * mass * GRAVITY) / (CSArea * drag_coefficient * air_density));
}

// Using the Runge-Kutta method
double Particle::calculateVelocity(double currentTime) {
    calculateAirDensity(currentTime);
    k = drag_coefficient * air_density * CSArea;

    // Calculate the four Runge-Kutta increments
    double k1 = GRAVITY - (k / mass) * velocity * velocity;
    double k2 = GRAVITY - (k / mass) * (velocity + 0.5 * TIMESTEP * k1) * (velocity + 0.5 * TIMESTEP * k1);
    double k3 = GRAVITY - (k / mass) * (velocity + 0.5 * TIMESTEP * k2) * (velocity + 0.5 * TIMESTEP * k2);
    double k4 = GRAVITY - (k / mass) * (velocity + TIMESTEP * k3) * (velocity + TIMESTEP * k3);

    // Update the velocity using the weighted average of the increments
    velocity = velocity + (TIMESTEP / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

    time = currentTime;

    return velocity;
}

// A poor altitude calculation at this time will need to change this function for better accuracy
double Particle::calculateAltitude(double currentTime) {

    time = currentTime;
    altitude = INIT_ALTITUDE - (velocity * time);
    return altitude;
}
// Air density calculates using the altitude to get the correct air density as it changes with altitude
double Particle::calculateAirDensity(double currentTime) {

    calculateAltitude(currentTime);
    air_density = 1.225 * exp(-(altitude/8000));
    return air_density;
}
// Timer start for time elapsed
void Particle::startTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}
// Time elapsed calculated constantly to update other functions with the correct time for calculations
double Particle::getTimeElapsed() {
    std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
    elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);
    return elapsedTime.count();
}
