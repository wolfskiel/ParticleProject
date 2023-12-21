//
// Created by John Greene on 12/20/23.
//
#include "Particle.h"
#include <iostream>

// Time constant for how long to run simulation
const int TOTALTIME = 10;
const double TIMESTEP = 0.5;
const double THRESHOLD = 0.05;
int main() {
    double currentVelocity = 0;
    double currentTime = 0.0;

    // Testing with the values a 5kg steel ball would have
    Particle aParticle(5, .00895,0.47 );

    double terminalVelocity = aParticle.getParticleTerminalVelocity();

    while (currentTime < TOTALTIME) {
        currentVelocity = aParticle.calculateVelocity();
        // Printing out the velocity changes
        std::cout << "At time: " << currentTime << "s, velocity is: " << currentVelocity << "m/s" <<std::endl;

        if (abs(currentVelocity - terminalVelocity) < THRESHOLD ){
          break;
        }

        currentTime += TIMESTEP;
    }
    return 0;
}