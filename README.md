# linkIT: Lightweight Signal-Slot Library
LinkIt is a lightweight C++ library designed to provide a simple and efficient signal-slot mechanism, akin to the well-known Qt signal and slot system. With minimal dependencies and easy integration, LinkIt empowers developers to implement flexible event handling within their applications effortlessly.

## Example Usage
``` cpp
#include <iostream>
#include "linkit/signal.hpp"

auto mySlot(int value) -> void {
    std::cout << "Received value: " << value << std::endl;
}

auto main() -> int {
    auto mySignal = linkit::Signal<int>{};

    // Connect slot to signal
    mySignal.connect(mySlot);

    // Emit signal
    mySignal.emit(42);

    return 0;
}
```

## Compiling the Library and Running Tests
To compile the library, follow these steps:
- Ensure CMake is installed on your system.
- Navigate to the root directory of the LinkIt project.
- Create a build directory: `mkdir build && cd build`
- Run CMake to generate build files: `cmake ..`
- Build the library: `cmake --build .`

Running Tests:
- After compiling the library, navigate to the build directory.
- Execute the test suite: `ctest .`
        
## Implementation Details and Advantages
LinkIt leverages modern C++ features to offer a clean and intuitive interface for implementing the signal-slot pattern. Here are some key advantages and implementation details:
- **Template-Based Design**: Utilizing C++ templates, LinkIt enables type-safe connections between signals and slots, ensuring compile-time safety and flexibility.
- **Minimal Dependencies**: LinkIt minimizes external dependencies, making it lightweight and easily integrable into various projects without introducing unnecessary overhead.
- **Efficient Execution**: By employing std::function for slot connections, LinkIt ensures efficient execution of connected slots with minimal runtime overhead.
- **Easy Integration**: With a simple API, LinkIt simplifies the integration of signal-slot functionality into existing codebases, enhancing modularity and maintainability.


``` cpp
#include <iostream>
#include <thread>

#include "linkit/signal.hpp"

class Sensor {
public:
    // Signal for notifying temperature changes
    linkit::Signal<double> temperatureChanged;

    // Simulate reading temperature from sensor
    auto readTemperature() -> void {
        auto newTemperature = double { 20.0 + (rand() % 20 - 10) / 10.0 };
        temperatureChanged.emit(std::move(newTemperature));
    }
};

class Heater {
public:
    // Slot to react to temperature changes
    auto adjustTemperature(const double newTemperature) const -> void {
        if (newTemperature < targetTemperature)
            std::cout << "Heater: Heating room to " << newTemperature << " degrees.\n";
        else
            std::cout << "Heater: Room temperature optimal.\n";
    }

private:
    const double targetTemperature = 22.0;
};

auto main() -> int {
    auto temperatureSensor = Sensor {};
    const auto roomHeater = Heater {};

    // Connect sensor's temperatureChanged signal to heater's adjustTemperature slot
    temperatureSensor.temperatureChanged.connect(
        [&roomHeater](const auto newTemp) {
            roomHeater.adjustTemperature(newTemp);
        });

    for (int i = 0; i < 5; ++i) {
        temperatureSensor.readTemperature();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
```
