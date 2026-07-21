# Smart Traffic Light Controller

An Arduino-based intelligent traffic light controller developed as part of my **Electrical and Information Engineering portfolio**. This project demonstrates the implementation of a complete road traffic control system including **vehicle traffic management, pedestrian crossing control, and a night operating mode**.

The controller simulates the behavior of a real traffic intersection while focusing on structured embedded software development, modular programming, and responsive system design using the Arduino platform.

---

## Project Overview

The system controls a realistic traffic light sequence for vehicles while integrating a pedestrian crossing system that can be requested via a push button.

Unlike a basic traffic light controller, pedestrian crossings are **not activated immediately**. Instead, a button press is stored as a request and processed only after the current vehicle traffic cycle has finished safely. This behavior closely resembles real-world traffic light systems.

The project also includes a **Night Mode**, where the normal traffic sequence is suspended and the yellow traffic light flashes continuously to indicate caution.

The complete project was developed and tested using the **Wokwi Arduino Simulator** before deployment on physical hardware.

---

## Features

- Standard vehicle traffic light sequence
- Pedestrian crossing request button
- Stored pedestrian requests
- Safe pedestrian crossing procedure
- Separate pedestrian traffic lights
- Normal operating mode
- Night mode with flashing yellow light
- Continuous monitoring of user inputs
- Modular and well-structured code
- Responsive operating mode switching

---

## Vehicle Traffic Sequence

During normal operation, the controller executes the following sequence:

1. Vehicle Red
2. Vehicle Red + Yellow
3. Vehicle Green
4. Vehicle Yellow
5. Vehicle Red

The sequence repeats continuously while monitoring pedestrian requests and operating mode changes.

---

## Pedestrian Crossing Logic

The pedestrian crossing system follows realistic traffic control principles.

When the pedestrian button is pressed:

- The request is stored in memory.
- The current vehicle traffic phase is completed safely.
- Vehicle traffic changes to red.
- The pedestrian light changes from red to green.
- Pedestrians receive a dedicated crossing period.
- The pedestrian light returns to red.
- The normal traffic light sequence resumes.

This approach prevents unsafe interruptions of vehicle traffic while ensuring safe pedestrian crossings.

---

## Operating Modes

### Normal Mode

- Standard traffic light sequence
- Pedestrian requests accepted
- Automatic pedestrian crossing management

### Night Mode

When the mode switch is activated:

- Normal traffic sequencing stops immediately.
- Vehicle red and green LEDs are turned off.
- The yellow LED flashes continuously.
- Pedestrian traffic remains permanently red.
- Pedestrian crossings are disabled.

The controller continuously checks the operating mode, allowing immediate transitions between Normal Mode and Night Mode.

---

## Hardware Components

- Arduino Uno
- 3 Vehicle LEDs
  - Red
  - Yellow
  - Green
- 2 Pedestrian LEDs
  - Red
  - Green
- Push button for pedestrian requests
- Toggle switch for Night Mode
- 220 Ω resistors
- Breadboard
- Jumper wires

---

## Pin Configuration

| Component | Arduino Pin |
|-----------|------------:|
| Vehicle Red LED | 8 |
| Vehicle Yellow LED | 9 |
| Vehicle Green LED | 10 |
| Pedestrian Red LED | 11 |
| Pedestrian Green LED | 12 |
| Pedestrian Push Button | 2 |
| Night Mode Switch | 3 |

---

## Software Architecture

The program is divided into modular functions to improve readability, maintainability, and future scalability.

Main functions include:

- `setup()` – Initializes hardware and default light states.
- `loop()` – Executes the selected operating mode.
- `updateOperatingMode()` – Detects whether the controller should operate in Normal or Night Mode.
- `runNormalMode()` – Controls the standard traffic light sequence.
- `runNightMode()` – Handles flashing yellow operation.
- `runPedestrianCrossing()` – Executes the pedestrian crossing sequence.
- `waitAndMonitor()` – Monitors button presses and operating mode changes while timing events.
- `nightModeDelay()` – Provides responsive timing during Night Mode.
- `setVehicleLights()` – Controls vehicle LEDs.
- `setPedestrianLights()` – Controls pedestrian LEDs.

---

## Timing Concept

Instead of using long blocking delays, the controller uses the `millis()` function to measure longer time intervals while continuously checking user inputs.

This allows the controller to:

- Detect pedestrian button presses at any time.
- Immediately switch to Night Mode.
- Safely interrupt the current sequence when required.
- Maintain responsive system behavior.

Small `delay(20)` calls are only used to reduce CPU usage during continuous monitoring loops.

---

## Simulation

The project was developed and tested using the **Wokwi Arduino Simulator**.

The simulator was used to verify:

- Traffic light sequencing
- Pedestrian request handling
- Night Mode operation
- Timing behavior
- Overall system functionality

---

## Future Improvements

Planned enhancements include:

- Full Finite State Machine (FSM) implementation
- Completely non-blocking timing
- Emergency vehicle priority mode
- Vehicle detection sensors
- Adaptive traffic control
- OLED or LCD status display
- Audible pedestrian crossing signal
- Configurable timing parameters
- IoT connectivity for remote monitoring
- Physical PCB implementation

---

## Learning Outcomes

This project provided practical experience in:

- Embedded Systems Programming
- Arduino Development
- Digital Input and Output Control
- Event-driven Programming
- Modular Software Design
- Real-Time System Concepts
- Traffic Control Logic
- Responsive timing using `millis()`
- Hardware–Software Integration
- Embedded System Simulation using Wokwi

---

## Technologies Used

- Arduino C/C++
- Arduino Uno
- Wokwi Simulator
- Embedded Systems Programming
- Git & GitHub

---

## Project Status

**Current Version:** Complete

The controller successfully implements:

- Vehicle traffic light control
- Pedestrian crossing requests
- Separate pedestrian traffic lights
- Night Mode
- Responsive input monitoring
- Modular software architecture

Future versions will focus on advanced embedded system concepts such as finite-state machines, adaptive traffic control, and additional safety features.
