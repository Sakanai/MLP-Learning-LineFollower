const int NUM_SENSORS_TO_READ = 10;
const int sensorPins[NUM_SENSORS_TO_READ] = { 13, 14, 27, 26, 25, 33, 32, 35, 34, 39 };

const int THRESHOLD = 100;

bool areAllSensorsBlack(int sensorArray[], int numSensors) {
  for (int i = 0; i < numSensors; i++) {
    if (sensorArray[i] > THRESHOLD) {
      return false;
    }
  }
  return true;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValues[NUM_SENSORS_TO_READ];
  String arahRobot = "";

  // Baca semua sensor
  for (int i = 0; i < NUM_SENSORS_TO_READ; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Tentukan arah robot
  if (areAllSensorsBlack(sensorValues, NUM_SENSORS_TO_READ)) {
    arahRobot = "Berhenti";
  } 
  else if (sensorValues[1] > THRESHOLD || sensorValues[2] > THRESHOLD ||
  (sensorValues[3] > THRESHOLD && sensorValues[4] > THRESHOLD && sensorValues[5] > THRESHOLD)) {
    arahRobot = "Belok Kiri";
  } 
  else if (sensorValues[8] > THRESHOLD || sensorValues[7] > THRESHOLD ||
  (sensorValues[6] > THRESHOLD && sensorValues[5] > THRESHOLD && sensorValues[4] > THRESHOLD)) {
    arahRobot = "Belok Kanan";
  } 
  else if (sensorValues[4] > THRESHOLD && sensorValues[5] > THRESHOLD) {
    arahRobot = "Maju Lurus";
  } 
  else if (sensorValues[3] < THRESHOLD && sensorValues[4] > THRESHOLD &&
           sensorValues[5] > THRESHOLD && sensorValues[6] < THRESHOLD) {
    arahRobot = "Mundur";
  } 
  else {
    arahRobot = "Tidak Jelas";
  }

  // ============================
  //  KIRIM DATA CSV KE PYTHON
  // ============================

  // Format: IR0,IR1,...,IR9,Arah
  for (int i = 0; i < NUM_SENSORS_TO_READ; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(",");
  }
  Serial.println(arahRobot);

  delay(300);
}
