//
// Created by John Greene on 12/20/23.
//

#ifndef PARTICLEPROJECT_PARTICLE_H
#define PARTICLEPROJECT_PARTICLE_H

float const GRAVITY = 9.8;
double const AIR_DENSITY = 0.6601;

class Particle {

private:
    float mass;
    float CSArea;
    float DragCoefficient;


public:
    void setParticleMass(float NewMass);
    void setParticleCSArea(float NewCSArea);
    void setParticleDragCoefficient(float NewDragCoefficient);
    float getParticleMass() const;
    float getParticleCSArea() const;
    float getParticleDragCoefficient() const;
    double getParticleTerminalVelocity() const;

    Particle(float initMass, float initCSArea, float initDragCoefficient);
};





#endif //PARTICLEPROJECT_PARTICLE_H
