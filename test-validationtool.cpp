#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"
#include <stddef.h>

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorreadings(socReadings, numOfSocReadings,SOCthreshold) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorreadings(currentReadings, numOfCurReadings,Currentthreshold) == 1);
}
TEST_CASE("Tests error when current jumps abruptly") {
  double currentReadings[] = {1.0, 2, 3, 4};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorreadings(currentReadings, numOfCurReadings,Currentthreshold) == 0);
}

TEST_CASE("reports no error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.0, 0.0, 0.0};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorreadings(currentReadings, numOfCurReadings,Currentthreshold) == 1);
}

TEST_CASE("reports no error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.0, 0.0, 0.0};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSensorreadings(socReadings, numOfSocReadings,SOCthreshold) == 1);
}

