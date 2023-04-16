#include <iostream>
#include <string>
#include <vector>

//Класс груза
class ICargo
{
public:
    virtual ~ICargo() {}
    virtual void getCargo() = 0;    
};

class Box : public ICargo
{
public:
    Box() {};
    ~Box() {};
    void getCargo() override
    {
        std::cout << "Cargo for transportation - Box!\n";
    }
};

class Food : public ICargo {
public:
    Food() {};
    ~Food() {};
    void getCargo() override
    {
        std::cout << "Cargo for transportation - Food!\n";
    }    
};

class Petrol : public ICargo {
public:
    Petrol() {};
    ~Petrol() {};
    void getCargo() override
    {
        std::cout << "Cargo for transportation - Petrol!\n";
    }    
};

class CompositeCargo : public ICargo
{
public:
    CompositeCargo() {};
    virtual ~CompositeCargo()
    {
        for (int i = 0; i < vehicle.size(); ++i)
            delete vehicle[i];
    };
    void getCargo()
    {       
       for (int i = 0; i < vehicle.size(); i++)
       {
           vehicle[i]->getCargo();
           std::cout << vehicle[i] << std::endl;
       }	
    };
    void AddVehicle(ICargo* cargo)
    {
        vehicle.push_back(cargo);
    }
    void AddStock(ICargo* cargo)
    {
        stock.push_back(cargo);
    }
private:
    std::vector<ICargo*> vehicle;  
    std::vector<ICargo*> stock;
};

//Класс транспорта
class IVehicle
{
public:
    virtual ~IVehicle() {}
    virtual void getVehicle() = 0;
    virtual void CreateVehicle(std::shared_ptr<CompositeCargo> cargo) = 0;    
protected:
    std::shared_ptr <CompositeCargo> _cargo;   
};

class Truck : public IVehicle
{
public:
    Truck() {};
    ~Truck() {};
    void getVehicle() override
    {
        std::cout << "Transport for cargo transportation - Truck!\n";
    };
    void CreateVehicle(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* vehicle = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            vehicle->AddVehicle(new Box());
            std::cout << (i+1) << " boxe are loaded onto a Truck!\n";
        }
        std::cout << "All boxes are loaded onto a Truck!\n";
    };
};

class TankTruck : public IVehicle
{
public:
    TankTruck() {};
    ~TankTruck() {};
    void getVehicle() override
    {
        std::cout << "Transport for cargo transportation - TankTruck!\n";
    };
    void CreateVehicle(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* vehicle = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            vehicle->AddVehicle(new Petrol());
            std::cout << (i + 1) << " petrol are loaded onto a Tanktruck!\n";
        }
        std::cout << "All petrols are loaded onto a Tanktruck!\n";
    };
};

class Refrigerator : public IVehicle
{
public:
    Refrigerator() {};
    ~Refrigerator() {};
    void getVehicle() override
    {
        std::cout << "Transport for cargo transportation - Refrigerator!\n";
    };
    void CreateVehicle(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* vehicle = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            vehicle->AddVehicle(new Food());
            std::cout << (i + 1) << " food are loaded onto a Refrigerator!\n";
        }
        std::cout << "All foods are loaded onto a Refrigerator!\n";
    };
};

//Класс скада
class IStock
{
public:
    virtual ~IStock() {}
    virtual void getStock() = 0;  
    virtual void CreateStock(std::shared_ptr<CompositeCargo> cargo) = 0;
protected:
    std::shared_ptr <CompositeCargo> cargo;
};

class Hangar : public IStock
{
public:
    Hangar() {};
    ~Hangar() {};
    void getStock() override
    {
        std::cout << "Cargo for unloading - Hangar!\n";
    };
    void CreateStock(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* stock = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            stock->AddStock(new Box());
            std::cout << (i + 1) << " box is unloaded into the Hangar!\n";
        }
        std::cout << "All boxes are unloaded in the Hangar!\n";
    };
};

class Fridge : public IStock
{
public:
    Fridge() {};
    ~Fridge() {};
    void getStock() override
    {
        std::cout << "Cargo for unloading - Fridge!\n";
    };
    void CreateStock(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* stock = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            stock->AddStock(new Food());
            std::cout << (i + 1) << " food is unloaded into the Fridge!\n";
        }
        std::cout << "All foods are unloaded in the Fridge!\n";
    };
};

class StorageTruck : public IStock
{
public:
    StorageTruck() {};
    ~StorageTruck() {};
    void getStock() override
    {
        std::cout << "Cargo for unloading - StorageTruck!\n";
    };
    void CreateStock(std::shared_ptr<CompositeCargo> cargo) override
    {
        CompositeCargo* stock = new CompositeCargo;
        int amount;
        std::cout << "Enter the amount of cargo -> ";
        std::cin >> amount;
        for (int i = 0; i < amount; ++i)
        {
            stock->AddStock(new Petrol());
            std::cout << (i + 1) << " petrol is unloaded into the StorageTruck!\n";
        }
        std::cout << "All petrol are unloaded in the StorageTruck!\n";
    };
};

int main()
{
    ICargo* box = new Box();
    ICargo* food = new Food();
    ICargo* petrol = new Petrol();
    std::shared_ptr<CompositeCargo> cargo;
    IVehicle* truck = new Truck();
    IVehicle* tankTruck = new TankTruck();
    IVehicle* refrigerator = new Refrigerator();
    IStock* hangar = new Hangar();
    IStock* fridge = new Fridge();
    IStock* storageTruck = new StorageTruck();

    int n = 0, m = 0;
    do {
        std::cout << "\nSelect cargo:" << std::endl;
        std::cout << "1 - Box" << std::endl;
        std::cout << "2 - Food" << std::endl;
        std::cout << "3 - Petrol" << std::endl;
        std::cout << "4 - Exit" << std::endl;
        std::cout << "============" << std::endl;
        std::cout << "Enter -> ";
        std::cin >> m;
        switch (m) {
        case 1:
            box->getCargo();
            truck->getVehicle();
            truck->CreateVehicle(cargo);
            hangar->getStock();
            hangar->CreateStock(cargo);
            break;
        case 2:
            food->getCargo();
            refrigerator->getVehicle();
            refrigerator->CreateVehicle(cargo);
            fridge->getStock();
            fridge->CreateStock(cargo);
            break;
        case 3:
            petrol->getCargo();
            tankTruck->getVehicle();
            tankTruck->CreateVehicle(cargo);
            storageTruck->getStock();
            storageTruck->CreateStock(cargo);
            break;
        case 4:
            std::cout << "Exit" << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Please enter a valid value!" << std::endl;
            break;
        }
    } while (n != 5);
    return 0;
}




