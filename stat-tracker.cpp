/** @file stat-tracker.cpp
 *    This file contains source code for a class that adds measurements
 *    to a database and computes statistical values like averages and
 *    standard deviations upon request.
 * 
 *  @author Matthew Frost
 *  @date  2020-Nov-03 Original file
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <stat-tracker.h>
#include <cmath>

/** @brief   Initialize variables for future statistical calculations.
 *  @details This constructor initializes any necessary varaibles for 
 *           when the object of the class is instantiated.
 */
StatTracker::StatTracker(void)
{
    numPoints  = 0; // No points have been added when the class starts.
    sum        = 0; // Total sum, set to 0 at the start in case it hasn't been cleared.
    sumSquared = 0; // Sum of squares, set to 0 at the start in case it hasn't been cleared.
    Sx         = 0; // Standard deviation, set to 0 at the start in case it hasn't been cleared.
}

/** @brief   Add a float-type number to the database.
 *  @details This float data will be added to the running sum and sumSquared variables.
 *           as well as increment the counter for the number of data points in total.
 *  @param   new_float The new floating-point number to be added to the class.
 */
void StatTracker::add_data(float new_float)  
{
    sum += new_float;                  // Add to the sum of data.
    numPoints++;                       // Increment the total counter. 
    sumSquared += pow(new_float, 2.0); // Square the new value.       
} 

/** @brief   Add a signed int-type number to the database.
 *  @details This int data will be added to the running sum and sumSquared variables
 *           as well as increment the counter for the number of data points in total.
 *  @param   new_int The new signed integer to be added to the class.
 */
void StatTracker::add_data(int32_t new_int)  
{
    sum += new_int;                  // Add to the sum of data.
    numPoints++;                     // Increment the total counter.  
    sumSquared += pow(new_int, 2.0); // Square the new value.    
} 

/** @brief   Add an unsigned int-type number to the database.
 *  @details This uint data will be added to the running sum and sumSquared variables
 *           as well as increment the counter for the number of data points in total.
 *  @param   new_uint The new unsigned integer to be added to the class.
 */
void StatTracker::add_data(uint32_t new_uint) 
{
    sum += new_uint;                  // Add to the sum of data.
    numPoints++;                      // Increment the total counter.  
    sumSquared += pow(new_uint, 2.0); // Square the new value.      
}

/** @brief   Counts and returns the total number of data points added to the data set.
 *  @returns The number of measurements that have been added to database.  
 */
uint32_t StatTracker::num_points(void)	
{
    return numPoints; // Return the running total of points added.
}

/** @brief   Computes an average of all data.
 *  @returns The average of all measurements that have been added to database.  
 */
float StatTracker::average(void)	
{
    float average = sum/numPoints; // Compute the average.
    return average;                // Return the average as a floating point number.
}

/** @brief   Computes a standard deviation of all data.
 *  @details This standard deviation is given by the formula in the assignment.
 *  @returns The standard deviation of all measurements that have been added to database.  
 */
float StatTracker::std_dev(void)
{
    float secondTerm = pow((sum/numPoints), 2.0);       // This term is only to make the computation easier to read.
    Sx = pow((sumSquared/numPoints) - secondTerm, 0.5); // Compute the Std-Dev based on the given formula in the assignment. 
    return Sx;                                          // Return the standard deviation as a floating point number.
}

/** @brief   Clears all the arrays.
 */
void StatTracker::clear(void)
{
    numPoints  = 0; // Return the counter for number of added data points.
    sum        = 0; // Reset the sum to 0.
    sumSquared = 0; // Reset the sum of squares to 0.
    Sx         = 0; // Reset the standard deviation to 0.
}