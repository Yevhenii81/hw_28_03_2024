#include <iostream>
#include <vector>
using namespace std;

class Herbivore {
protected:
    double weight;
    bool life;
public:

    Herbivore(double weight, bool life) {
        SetWeight(weight);
        SetLife(weight);
    }

    virtual void SetLife(bool life) {
        this->life = life;
    }

    virtual bool GetLife() {
        return life;
    }

    virtual void SetWeight(double weight) {
        this->weight = weight;
    }

    virtual double GetWeight() {
        return weight;
    }

    virtual void EatGrass() {
        cout << "Herbivore eat grass...\n";
        weight += 10;
    }
};

class WildeBeest : public Herbivore {
public:

    WildeBeest(double weight, bool life) : Herbivore(weight, life) {}

    void SetLife(bool life) override {
        this->life = life;
    }

    bool GetLife() {
        return life;
    }

    void SetWeight(double weight) override {
        this->weight = weight;
    }

    double GetWeight() override {
        return weight;
    }

    void EatGrass() override {
        cout << "WildeBeest eat grass...\n";
        weight += 10;
    }
};

class Bison : public Herbivore {
public:

    Bison(double weight, bool life) : Herbivore(weight, life) {}

    void SetLife(bool life) override {
        this->life = life;
    }

    bool GetLife() override {
        return life;
    }

    void SetWeight(double weight) override {
        this->weight = weight;
    }

    double GetWeight() override {
        return weight;
    }

    void EatGrass() override {
        cout << "Bison eat grass...\n";
        weight += 10;
    }
};

class Carnivore {
protected:
    int power;
public:

    Carnivore(int power) {
        SetPower(power);
    }

    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() {
        return power;
    }

    virtual void Eat(Herbivore* herbivore) {
        if (power < herbivore->GetWeight()) {
            cout << "Carnicore eat Herbivor...\n";
            power -= 10;
        }
        else {
            cout << "Carnicore eat Herbivor...\n";
            herbivore->SetLife(false);
        }
    }
};

class Lion : public Carnivore {
public:

    Lion(int power) : Carnivore(power) {}

    void SetPower(int power) override {
        this->power = power;
    }

    int GetPower() override {
        return power;
    }

    void Eat(Herbivore* herbivore) override {
        if (power < herbivore->GetWeight()) {
            cout << "Lion eat Herbivor...\n";
            power -= 10;
        }
        else {
            cout << "Lion eat Herbivor...\n";
            herbivore->SetLife(false);
        }
    }
};

class Wolf : public Carnivore {
public:

    Wolf(int power) : Carnivore(power) {}

    void SetPower(int power) override {
        this->power = power;
    }

    int GetPower() override {
        return power;
    }

    void Eat(Herbivore* herbivore) override {
        if (power < herbivore->GetWeight()) {
            cout << "Wolf eat Herbivor...\n";
            power -= 10;
        }
        else {
            cout << "Wolf eat Herbivor...\n";
            power += 10;
            herbivore->SetLife(false);
        }
    }
};

class Continent {
protected:
    vector<Herbivore*> herbivores;
    vector<Carnivore*> carnivores;

public:
    virtual void AddHerbivore(Herbivore* herbivore) {
        herbivores.push_back(herbivore);
    }

    virtual void AddCarnivore(Carnivore* carnivore) {
        carnivores.push_back(carnivore);
    }

    virtual void MealsHerbivores() {
        for (auto& herbivore : herbivores) {
            herbivore->EatGrass();
        }
    }

    virtual void NutritionCarnivores() {
        for (auto& carnivore : carnivores) {
            for (auto& herbivore : herbivores) {
                carnivore->Eat(herbivore);
            }
        }
    }
};

class Africa : public Continent {
public:
    void AddHerbivore(Herbivore* herbivore) override {
        herbivores.push_back(herbivore);
    }

    void AddCarnivore(Carnivore* carnivore) override {
        carnivores.push_back(carnivore);
    }

    void MealsHerbivores() override {
        for (auto& herbivore : herbivores) {
            herbivore->EatGrass();
        }
    }

    void NutritionCarnivores() override {
        for (auto& carnivore : carnivores) {
            for (auto& herbivore : herbivores) {
                carnivore->Eat(herbivore);
            }
        }
    }
};

class NortAmerica : public Continent {
public:
    void AddHerbivore(Herbivore* herbivore) override {
        herbivores.push_back(herbivore);
    }

    void AddCarnivore(Carnivore* carnivore) override {
        carnivores.push_back(carnivore);
    }

    void MealsHerbivores() override {
        for (auto& herbivore : herbivores) {
            herbivore->EatGrass();
        }
    }

    void NutritionCarnivores() override {
        for (auto& carnivore : carnivores) {
            for (auto& herbivore : herbivores) {
                carnivore->Eat(herbivore);
            }
        }
    }
};

class AnimalWorld {
public:
    void MealsHerbivores(Continent* continent) {
        continent->MealsHerbivores();
    }

    void NutritionCarnivores(Continent* continent) {
        continent->NutritionCarnivores();
    }
};

int main()
{
    WildeBeest wildebeest(500, true);
    Lion lion(200);

    Africa africa;
    africa.AddHerbivore(&wildebeest);
    africa.AddCarnivore(&lion);

    AnimalWorld world;
    world.MealsHerbivores(&africa);
    world.NutritionCarnivores(&africa);
}