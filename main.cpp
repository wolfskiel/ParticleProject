//
// Created by John Greene on 12/20/23.
//
#include "Particle.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cmath>



double const THRESHOLD = 0.05;
// Floor is the floor can be changed for different altitudes
int const ALTITUDE_FLOOR = 0;
int main() {
    Particle aParticle(5, 0.0314, 0.47);

    // Start the timer in the main function
    aParticle.startTimer();

    double currentTime = 0.0;
    double terminalVelocity = aParticle.calculateTerminalVelocity();
    double currentAltitude = aParticle.calculateAltitude(currentTime);
    double currentVelocity = 0.0;

    while (currentAltitude > ALTITUDE_FLOOR) {
        // Use the timer to get elapsed time
        currentTime = aParticle.getTimeElapsed();

        // If the current velocity minus the terminal velocity is less than the threshold set then stop calculating velocity
        if (abs(currentVelocity - terminalVelocity) > THRESHOLD) {
            // Calculate the current velocity given the elapsed time
            currentVelocity = aParticle.calculateVelocity(currentTime);
        }
        else {
            break; // Once velocity is close enough to terminal velocity, exit loop
        }

        // Calculate the altitude given the elapsed time
        currentAltitude = aParticle.calculateAltitude(currentTime);

        // Print all values on the same line using '\r' and std::flush
        std::cout << "\r"
                  << "Time: " << std::fixed << std::setprecision(2) << currentTime << "s, "
                  << "Velocity: " << std::fixed << std::setprecision(2) << currentVelocity << "m/s, "
                  << "Altitude: " << std::fixed << std::setprecision(2) << currentAltitude << "m "
                  << std::flush;

        // Sleep to control the time step
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(TIMESTEP * 1000)));
    }
    return 0;
}