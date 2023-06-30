#include <iostream>
#include <vector>

enum Color
{
    RED,
    YELLOW,
    GREEN,
    BLUE,
    BLACK,
    WHITE,
    DEFAULT
};

std::string colorNames[7] = {"Red", "Yellow", "Green", "Blue", "Black", "White", "Default"};

class Car
{
private:
    std::string make;
    std::string model;
    Color color;
    bool rented;
    static long ID;
    long carId;

public:
    /**
     * @brief Constructs a Car object with the given make, model, color, and rented flag.
     * 
     * @param carMake The make of the car.
     * @param carModel The model of the car.
     * @param carColor The color of the car.
     * @param carRented The rented flag of the car.
     */
    Car(std::string carMake, std::string carModel, Color carColor, bool carRented) : make(carMake), model(carModel), color(carColor), rented(carRented), carId(++ID)
    {
    }

    /**
     * @brief Constructs a Car object with the given make, model, and color.
     * The rented flag is set to false by default.
     * 
     * @param carMake The make of the car.
     * @param carModel The model of the car.
     * @param carColor The color of the car.
     */
    Car(std::string carMake, std::string carModel, Color carColor) : make(carMake), model(carModel), color(carColor), rented(false), carId(++ID) {}

    /**
     * @brief Constructs a Car object with the given make and model.
     * The color is set to the default color, and the rented flag is set to false by default.
     * 
     * @param carMake The make of the car.
     * @param carModel The model of the car.
     */
    Car(std::string carMake, std::string carModel) : make(carMake), model(carModel), color(DEFAULT), rented(false), carId(++ID) {}

    /**
     * @brief Checks if the car is currently rented.
     * 
     * @return True if the car is rented, false otherwise.
     */
    bool isRented() const
    {
        return rented;
    }

    /**
     * @brief Gets the make of the car.
     * 
     * @return The make of the car.
     */
    std::string getMake()
    {
        return make;
    }

    /**
     * @brief Gets the model of the car.
     * 
     * @return The model of the car.
     */
    std::string getModel()
    {
        return model;
    }

    /**
     * @brief Marks the car as rented.
     */
    void carRented()
    {
        rented = true;
    }

    /**
     * @brief Marks the car as returned.
     */
    void carReturned()
    {
        rented = false;
    }

    /**
     * @brief Displays information about the car, including its ID, make, model, and color.
     */
    void displayCar() const
    {
        std::cout << carId << " is a " << make << " " << model << " in " << colorNames[color] << " color.\n";
    }
};

class CarRental
{
private:
    std::vector<Car> cars;

public:
    /**
     * @brief Constructs a CarRental object with an array of cars and its size.
     * 
     * @param carArray An array of Car objects.
     * @param size The size of the carArray.
     */
    CarRental(Car* carArray, size_t size)
    {
        for (size_t i = 0; i < size; i++)
        {
            cars.push_back(carArray[i]);
        }
    }

    /**
     * @brief Default constructor for CarRental.
     */
    CarRental() {}

    /**
     * @brief Displays information about all the cars in the rental.
     */
    void displayAllCars() const
    {
        for (const Car& car : cars)
        {
            car.displayCar();
        }
    }

    /**
     * @brief Displays information about the available cars that can be rented.
     */
    void displayAvailableCars() const
    {
        std::cout << "Available cars to rent:\n";
        for (const Car& car : cars)
        {
            if (!car.isRented())
            {
                car.displayCar();
            }
        }
    }

    /**
     * @brief Retrieves a Car object based on the make and model.
     * 
     * @param carMake The make of the car to retrieve.
     * @param carModel The model of the car to retrieve.
     * @return A reference to the Car object.
     * @throw std::runtime_error if the car is not found.
     */
    Car& getCar(std::string carMake, std::string carModel)
    {
        for (Car& car : cars)
        {
            if (car.getMake() == carMake && car.getModel() == carModel)
            {
                return car;
            }
        }
        throw std::runtime_error("Could not find the car you are looking for.");
    }

    /**
     * @brief Rents a car based on the make and model.
     * 
     * @param carMake The make of the car to rent.
     * @param carModel The model of the car to rent.
     */
    void rentCar(std::string carMake, std::string carModel)
    {
        try
        {
            Car& myCar = getCar(carMake, carModel);
            if (!myCar.isRented())
            {
                myCar.carRented();
                std::cout << "The car " << carMake << " " << carModel << " has now been rented.\n";
            }
            else
            {
                std::cout << "The car has already been rented. Please select another car from the list.\n";
                displayAvailableCars();
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    /**
     * @brief Returns a rented car based on the make and model.
     * 
     * @param carMake The make of the car to return.
     * @param carModel The model of the car to return.
     */
    void returnCar(std::string carMake, std::string carModel)
    {
        try
        {
            Car& myCar = getCar(carMake, carModel);
            if (myCar.isRented())
            {
                myCar.carReturned();
                std::cout << "The car " << carMake << " " << carModel << " has now been returned. Hope you had a good journey!\n";
            }
            else
            {
                std::cout << "The car has already been returned.\n";
            }
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
};

long Car::ID = 100000;

int main()
{
    // Create Car objects
    Car toyotaPrius("Toyota", "Prius");
    Car hondaCityBlue("Honda", "City", BLUE);
    Car marutiSwift("Maruti", "Swift", WHITE, true);
    Car skodaFabia("Skoda", "Fabia", RED);
    Car ferrariLaferrari("Ferrari", "Laferrari", RED, false);

    // Create an array of Car objects
    Car carArray[5] = {toyotaPrius, hondaCityBlue, marutiSwift, skodaFabia, ferrariLaferrari};

    // Create a CarRental object with the carArray
    CarRental karanRental(carArray, sizeof(carArray) / sizeof(carArray[0]));

    // Display all cars in the rental
    karanRental.displayAllCars();
    std::cout << std::endl;

    // Display available cars for rent
    karanRental.displayAvailableCars();
    std::cout << std::endl;

    // Try to get a car that doesn't exist
    try
    {
        karanRental.getCar("Kia", "Sportage");
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Rent a car
    karanRental.rentCar("Ferrari", "Laferrari");
    std::cout << std::endl;

    // Display available cars after renting
    karanRental.displayAvailableCars();
    std::cout << std::endl;

    // Return a car
    karanRental.returnCar("Ferrari", "Laferrari");
    std::cout << std::endl;

    // Try to rent a car that is already rented
    karanRental.rentCar("Ferrari", "Laferrari");
    std::cout << std::endl;

    // Rent another car
    karanRental.rentCar("Maruti", "Swift");
    std::cout << std::endl;

    return 0;
}
