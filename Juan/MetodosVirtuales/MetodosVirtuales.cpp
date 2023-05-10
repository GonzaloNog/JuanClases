

#include <iostream>
class Animal {
public:
    virtual ~Animal() {} // Destructor virtual
    virtual void hablar(){
        std::cout << "Animal Habla" << std::endl;
    }; // Método virtual puro
};

// Definición de la clase Exploration, que hereda de ExtraterrestrialRobot
class Perro : public Animal {
public:
    void hablar() override { // Implementación del método doMission()
        std::cout << "Guauuu" << std::endl;
    }
};

// Definición de la clase Mining, que hereda de ExtraterrestrialRobot
class Gato : public Animal {
public:
    void hablar() override { // Implementación del método doMission()
        std::cout << "Miau" << std::endl;
    }
};
int main()
{
    const int NUM_ROBOTS = 3;
    Animal* animales[NUM_ROBOTS];

    animales[0] = new Perro();
    animales[1] = new Animal();
    animales[2] = new Gato();
    
    for (int a = 0; a < NUM_ROBOTS; a++) {
        animales[a]->hablar();
    }
}

