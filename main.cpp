/** @file main.cpp
 *    This file contains the test code for the StatTracker class.
 * 
 *  @author Matthew Frost
 *  @date  2021-Nov-04 Original file
 */
#include <Arduino.h>
#include <stat-tracker.h>

// Create an instance of the class.
StatTracker myStat;

void setup() 
{
    // Begin the serial port for printing results.
    Serial.begin(115200);
    delay(2000);
    Serial.println("Serial port has started.");
}

void loop() 
{
    // In order to pass in several variables from arrays, must have the 
    // correct length of the array.
    uint8_t floatLength = 4;  // Length of sample float data array.
    uint8_t intLength   = 6;  // Length of sample signed integer data array.
    uint8_t uintLength  = 5;  // Length of sample unsigned integer data array.

    // Define a few example arrays to pass in data from.
    float floatData[floatLength]  = {0, 4000.01, 3.1415, 23.07};                 // Example float data.
    int32_t intData[intLength]    = {-128, -2147483648, 4000, 2147483647, 0, 1}; // Example signed integer data.
    uint32_t uintData[uintLength] = {1, 3, 1000, 100000, 0};                     // Example unsigned integer data.

    // Define pointers to the sample arrays.
    float* p_float = floatData;  // Pointer to the memory address of the first element in floatData.
    int32_t* p_int = intData;    // Pointer to the memory address of the first element in intData.
    uint32_t* p_uint = uintData; // Pointer to the memory address of the first element in uintData.

    // Pass in the data one element at a time. These for loops go in the order of 
    // float, int, and then uint data (arbitrary).
    for (uint8_t floatIndex = 0; floatIndex < floatLength; floatIndex++)
    {
        myStat.add_data(*p_float++);
    }
    for (uint8_t intIndex = 0; intIndex < intLength; intIndex++)
    {
        myStat.add_data(*p_int++);
    }
    for (uint8_t uintIndex = 0; uintIndex < uintLength; uintIndex++)
    {
        myStat.add_data(*p_uint++);
    }
    
    // Display results of the computation.
    Serial.print("Number of data points added: ");
    Serial.println(myStat.num_points());  // Display the number of data points added to the class.
    Serial.print("Average: ");
    Serial.println(myStat.average());     // Compute and display the average of the dataset.
    Serial.print("Standard deviation: ");
    Serial.println(myStat.std_dev());     // Compute and display the standard deviation of the dataset.
    delay(2000);
    myStat.clear();                       // Clear the data for the next trail run.
}