//
// Created by John Greene on 12/20/23.
//

#ifndef PARTICLEPROJECT_PARTICLE_H
#define PARTICLEPROJECT_PARTICLE_H

float const GRAVITY = 9.8;
// Air density at 6km, for now keeping it like this for testing only
double const AIR_DENSITY = 0.6601;


class Particle {

private:
    // Mass,crossectional area, and drag coeffcient shouldn't change
    float mass;
    float CSArea;
    float DragCoefficient;

    void setParticleMass(float NewMass);
    void setParticleCSArea(float NewCSArea);
    void setParticleDragCoefficient(float NewDragCoefficient);


public:
    // Velocity,time,acceleration will change
    // The constant k changes with each object initalized
    double velocity = 0;
    double time = 0;
    double acceleration = 0;
    double k = 0;
    float getParticleMass() const;
    float getParticleCSArea() const;
    float getParticleDragCoefficient() const;
    double getParticleTerminalVelocity() const;
    double calculateVelocity();
    Particle(float initMass, float initCSArea, float initDragCoefficient);
};





#endif //PARTICLEPROJECT_PARTICLE_H
