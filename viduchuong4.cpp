#include <iostream>
#include <string>
using namespace std;

// Lớp trừu tượng Vehicle
class Vehicle {
protected:
    int speed;
    int power;
public:
    Vehicle(int s = 0, int p = 0) : speed(s), power(p) {}
    virtual ~Vehicle() {}

    virtual void go() = 0;   // hàm thuần ảo
    virtual void stop() = 0; // hàm thuần ảo
};

// Lớp dẫn xuất PassengerTransport
class PassengerTransport : public Vehicle {
protected:
    int numberOfPassengers;
public:
    PassengerTransport(int s, int p, int n)
        : Vehicle(s, p), numberOfPassengers(n) {}

    void go() override {
        cout << "Passenger transport is moving with speed " << speed << endl;
    }

    void stop() override {
        cout << "Passenger transport stopped." << endl;
    }
};

// Lớp dẫn xuất GoodsTransport
class GoodsTransport : public Vehicle {
protected:
    int loadCapacityKg;
public:
    GoodsTransport(int s, int p, int load)
        : Vehicle(s, p), loadCapacityKg(load) {}

    void go() override {
        cout << "Goods transport is moving with load capacity " << loadCapacityKg << " kg." << endl;
    }

    void stop() override {
        cout << "Goods transport stopped." << endl;
    }
};

// Lớp PassengerTrain
class PassengerTrain : public PassengerTransport {
private:
    int numberOfCars;
public:
    PassengerTrain(int s, int p, int n, int cars)
        : PassengerTransport(s, p, n), numberOfCars(cars) {}

    void go() override {
        cout << "Passenger train with " << numberOfCars << " cars is running at speed " << speed << endl;
    }

    void stop() override {
        cout << "Passenger transport stopped." << endl;
    }

    void doorsOpen() { cout << "Train door opened." << endl; }
    void doorsClose() { cout << "Train door closed." << endl; }
    void airConditioning() { cout << "Train air conditioning activated." << endl; }
};

// Lớp GoodsTrain
class GoodsTrain : public GoodsTransport {
private:
    int numberOfBoxcars;
    int numberOfTankCars;
    int numberOfOpenCars;
public:
    GoodsTrain(int s, int p, int load, int box, int tank, int open)
        : GoodsTransport(s, p, load),
          numberOfBoxcars(box), numberOfTankCars(tank), numberOfOpenCars(open) {}

    void go() override {
        cout << "Goods train running with boxcars: " << numberOfBoxcars
             << ", tank cars: " << numberOfTankCars
             << ", open cars: " << numberOfOpenCars << endl;
    }

    void stop() override {
        cout << "Goods train stopped." << endl;
    }
};

// Lớp Motorcar
class Motorcar : public PassengerTransport {
protected:
    int engineCapacity;
    string bodyColour;
    string trimColour;
    int numberOfCylinders;
    int wheelSize;
    int numberOfDoors;
public:
    Motorcar(int s, int p, int n,
             int engineCap, string bodyCol, string trimCol,
             int cyl, int wheel, int doors)
        : PassengerTransport(s, p, n),
          engineCapacity(engineCap), bodyColour(bodyCol), trimColour(trimCol),
          numberOfCylinders(cyl), wheelSize(wheel), numberOfDoors(doors) {}

    void go() override {
        cout << "Motocar is driving with engine " << engineCapacity << " cc." << endl;
    }

    void stop() override {
        cout << "Motocar stopped." << endl;
    }

    void steer() { cout << "Motocar steering..." << endl; }
    void brake() { cout << "Motocar braking..." << endl; }
};

// Lớp LuxuryCar
class LuxuryCar : public Motorcar {
private:
    double insideAirTemperature;
    string globalPosition;
public:
    LuxuryCar(int s, int p, int n,
              int engineCap, string bodyCol, string trimCol,
              int cyl, int wheel, int doors,
              double temp, string gps)
        : Motorcar(s, p, n, engineCap, bodyCol, trimCol, cyl, wheel, doors),
          insideAirTemperature(temp), globalPosition(gps) {}

    void airConditioningControl() { cout << "Luxury car air conditioning set to " << insideAirTemperature << "°C" << endl; }
    void powerMirrorControl() { cout << "Luxury car mirrors adjusted." << endl; }
    void powerWindowControl() { cout << "Luxyry car windows controlled." << endl; }
    void cruiseControl() { cout << "Luxury car cruise control activated." << endl; }
    void antennaControl() { cout << "Luxury car antenna extended." << endl; }
    void cdControl() { cout << "Luxury car CD player running." << endl; }
};

// Hàm main minh họa
int main() {
    PassengerTrain pt(120, 5000, 600, 12);
    pt.go();
    pt.doorsOpen();
    pt.airConditioning();
    pt.stop();

    cout << "-------------------" << endl;

    GoodsTrain gt(90, 6000, 20000, 20, 10, 15);
    gt.go();
    gt.stop();

    cout << "-------------------" << endl;

    LuxuryCar lc(180, 300, 5, 2000, "Black", "Beige", 4, 18, 4, 22.5, "21.0285N, 105.8542E");
    lc.go();
    lc.airConditioningControl();
    lc.cruiseControl();
    lc.brake();
    lc.stop();

    return 0;
}
