/*
 * Solución Tarea 2.1.3
 * Tema 2.1 Construcción de software modular
 * 2º Ingeniería Informática
 * CUNEF Universidad
 * Prof. Dr. Jose L. Salmeron
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

 // Definición de la clase base ExtraterrestrialRobot
class ExtraterrestrialRobot {
public:
    virtual ~ExtraterrestrialRobot() {} // Destructor virtual
    virtual void doMission() = 0; // Método virtual puro
}; 

// Definición de la clase Exploration, que hereda de ExtraterrestrialRobot
class Exploration : public ExtraterrestrialRobot {
public:
    void doMission() override { // Implementación del método doMission()
        std::cout << "Exploring the planet..." << std::endl;
    }
};

// Definición de la clase Mining, que hereda de ExtraterrestrialRobot
class Mining : public ExtraterrestrialRobot {
public:
    void doMission() override { // Implementación del método doMission()
        std::cout << "Mining valuable minerals..." << std::endl;
    }
};

// Definición de la estructura Zone que representa una zona del planeta
struct Zone {
    bool hasMinerals;
    ExtraterrestrialRobot* visitedBy;
    int mineralVolume; // Cantidad de minerales en la zona
};

int main() {
    // Semilla para generar números aleatorios
    std::srand(std::time(nullptr));

    // Creación del array de zonas del planeta
    const int NUM_ZONES = 10;
    Zone planet[NUM_ZONES];
    for (int i = 0; i < NUM_ZONES; i++) {
        planet[i].hasMinerals = std::rand() % 2; // 50% de probabilidad de tener minerales
        planet[i].visitedBy = nullptr; // Inicialmente ningún robot ha visitado la zona
        planet[i].mineralVolume = std::rand() % 1000; // Volumen de minerales aleatorio entre 0 y 999
    }

    // Creación del array de punteros a ExtraterrestrialRobot
    const int NUM_ROBOTS = 3;
    ExtraterrestrialRobot* robots[NUM_ROBOTS];
    robots[0] = new Exploration();
    robots[1] = new Mining();
    robots[2] = new Mining();

    // Cada robot visita una zona aleatoria del planeta
    for (int i = 0; i < NUM_ROBOTS; i++) {
        int zoneIndex = std::rand() % NUM_ZONES;
        planet[zoneIndex].visitedBy = robots[i];
        if (dynamic_cast<Mining*>(robots[i])) { // Si el robot es de la clase Mining
            std::cout << "Robot " << i << " is mining in zone " << zoneIndex << std::endl;
            planet[zoneIndex].mineralVolume -= 100; // Reducir el volumen de minerales en 100
        }
        else {
            robots[i]->doMission();
        }
    }

    // Informe de las zonas del planeta, los robots que las han visitado y su valor minero
    std::cout << "Planet report:" << std::endl;
    for (int i = 0; i < NUM_ZONES; i++) {
        std::cout << "Zone " << "\tVisited by: ";
        if (planet[i].visitedBy == nullptr) {
            std::cout << "No robot has visited this zone" << std::endl;
        }
        else if (dynamic_cast<Exploration*>(planet[i].visitedBy)) {
            std::cout << "Exploration robot" << std::endl;
        }
        else if (dynamic_cast<Mining*>(planet[i].visitedBy)) {
            std::cout << "Mining robot" << std::endl;
        }

        if (planet[i].hasMinerals) {
            std::cout << "\tMineral volume: " << planet[i].mineralVolume << std::endl;
        }
    }

    // Liberación de la memoria
    for (int i = 0; i < NUM_ROBOTS; i++) {
        delete robots[i];
    }

    return 0;
}

