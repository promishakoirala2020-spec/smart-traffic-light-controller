
const int VEHICLE_YELLOW = 9;
const int VEHICLE_GREEN = 10;

const int PEDESTRIAN_RED = 11;
const int PEDESTRIAN_GREEN = 12;

const int PEDESTRIAN_BUTTON_PIN = 2;
const int MODE_SWITCH_PIN = 3;

bool pedestrianRequest = false;

enum OperatingMode {
  NORMAL_MODE,
  NIGHT_MODE
};

OperatingMode currentMode = NORMAL_MODE;

void setup() {
  pinMode(VEHICLE_RED, OUTPUT);
  pinMode(VEHICLE_YELLOW, OUTPUT);
  pinMode(VEHICLE_GREEN, OUTPUT);

  pinMode(PEDESTRIAN_RED, OUTPUT);
  pinMode(PEDESTRIAN_GREEN, OUTPUT);

  pinMode(PEDESTRIAN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(MODE_SWITCH_PIN, INPUT_PULLUP);

  setVehicleLights(HIGH, LOW, LOW);
  setPedestrianLights(HIGH, LOW);
}

void loop() {
  updateOperatingMode();

  if (currentMode == NORMAL_MODE) {
    runNormalMode();
  } else {
    runNightMode();
  }
}

void updateOperatingMode() {
  if (digitalRead(MODE_SWITCH_PIN) == LOW) {
    currentMode = NIGHT_MODE;
  } else {
    currentMode = NORMAL_MODE;
  }
}

void runNormalMode() {
  setPedestrianLights(HIGH, LOW);

  setVehicleLights(HIGH, LOW, LOW);

  if (!waitAndMonitor(3000)) {
    return;
  }

  setVehicleLights(HIGH, HIGH, LOW);

  if (!waitAndMonitor(1000)) {
    return;
  }

  setVehicleLights(LOW, LOW, HIGH);

  if (!waitAndMonitor(3000)) {
    return;
  }

  setVehicleLights(LOW, HIGH, LOW);

  if (!waitAndMonitor(1000)) {
    return;
  }

  if (pedestrianRequest) {
    runPedestrianCrossing();
    pedestrianRequest = false;
  }
}

void runNightMode() {
  digitalWrite(VEHICLE_RED, LOW);
  digitalWrite(VEHICLE_GREEN, LOW);

  setPedestrianLights(HIGH, LOW);

  digitalWrite(VEHICLE_YELLOW, HIGH);

  if (!nightModeDelay(500)) {
    return;
  }

  digitalWrite(VEHICLE_YELLOW, LOW);

  nightModeDelay(500);
}

void runPedestrianCrossing() {
  setVehicleLights(HIGH, LOW, LOW);

  if (!waitAndMonitor(1000)) {
    return;
  }

  setPedestrianLights(LOW, HIGH);

  if (!waitAndMonitor(5000)) {
    setPedestrianLights(HIGH, LOW);
    return;
  }

  setPedestrianLights(HIGH, LOW);

  waitAndMonitor(1000);
}

bool waitAndMonitor(unsigned long duration) {
  unsigned long startTime = millis();

  while (millis() - startTime < duration) {
    updateOperatingMode();

    if (currentMode == NIGHT_MODE) {
      setVehicleLights(LOW, LOW, LOW);
      setPedestrianLights(HIGH, LOW);
      return false;
    }

    if (digitalRead(PEDESTRIAN_BUTTON_PIN) == LOW) {
      pedestrianRequest = true;
    }

    delay(20);
  }

  return true;
}

bool nightModeDelay(unsigned long duration) {
  unsigned long startTime = millis();

  while (millis() - startTime < duration) {
    updateOperatingMode();

    if (currentMode == NORMAL_MODE) {
      digitalWrite(VEHICLE_YELLOW, LOW);
      return false;
    }

    delay(20);
  }

  return true;
}

void setVehicleLights(
  int redState,
  int yellowState,
  int greenState
) {
  digitalWrite(VEHICLE_RED, redState);
  digitalWrite(VEHICLE_YELLOW, yellowState);
  digitalWrite(VEHICLE_GREEN, greenState);
}

void setPedestrianLights(
  int redState,
  int greenState
) {
  digitalWrite(PEDESTRIAN_RED, redState);
  digitalWrite(PEDESTRIAN_GREEN, greenState);
}
