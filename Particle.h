//
// Created by John Greene on 12/20/23.
//

#ifndef PARTICLEPROJECT_PARTICLE_H
#define PARTICLEPROJECT_PARTICLE_H
#include <chrono>
#include <thread>

float const GRAVITY = 9.8;
// Starting altitude
float const INIT_ALTITUDE = 2000.000;
// Time steps
const float TIMESTEP = 0.05;

class Particle {

private:
    // Mass,cross-sectional area, and drag coefficient shouldn't change
    float mass; // In kg
    float CSArea; // In m^2
    double drag_coefficient;

    void setParticleMass(float NewMass);
    void setParticleCSArea(float NewCSArea);
    void setParticleDragCoefficient(float NewDragCoefficient);

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::duration<double> elapsedTime{};

public:
    // Velocity, time, acceleration will change
    // The constant k changes with each object initialized
    double velocity = 0;
    double time = 0;
    double k = 0;
    double altitude = 0;
    double air_density = 1.225;
    // These three aren't used currently, could be used in the future if I want to have them be called by the user
    double getParticleMass() const;
    double getParticleCSArea() const;
    double getParticleDragCoefficient() const;

    double calculateTerminalVelocity();
    double calculateAirDensity(double currentTime);
    double calculateVelocity(double currentTime); // Add currentTime parameter
    double calculateAltitude(double currentTime); // Add currentTime parameter

    void startTimer();
    double getTimeElapsed();
    Particle(float initMass, float initCSArea, float initDragCoefficient);
};




#endif //PARTICLEPROJECT_PARTICLE_H
