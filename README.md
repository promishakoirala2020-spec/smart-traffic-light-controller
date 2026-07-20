# Smart Traffic Light Controller

This project is an Arduino-based traffic light controller developed as part of my Electrical and Information Engineering portfolio.

## Current Version

The current version controls red, yellow, and green LEDs using a fixed traffic light sequence.

The sequence is:

1. Red
2. Red and yellow
3. Green
4. Yellow
5. Red

The circuit is currently developed and tested using the Wokwi Arduino simulator.

## Hardware

* Arduino Uno
* Three LEDs: red, yellow, and green
* Three 220 Ω resistors
* Jumper wires

## Pin Configuration

| LED    | Arduino Pin |
| ------ | ----------: |
| Red    |           8 |
| Yellow |           9 |
| Green  |          10 |

## Planned Improvements

* Replace blocking `delay()` functions with `millis()`
* Implement a finite-state machine
* Add a pedestrian request button
* Add pedestrian red and green LEDs
* Add an emergency or priority mode
* Improve documentation with circuit diagrams and screenshots

## Simulation

The project is currently simulated in Wokwi.
