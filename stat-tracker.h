/** @file stat-tracker.h
 *    This file contains the headers for a class that adds numbers 
 *    to a database and can compute averages and standard deviations as requested.
 * 
 *  @author Matthew Frost
 *  @date  2021-Nov-03 Original file
 */

/** @brief   Class which is given measurements and computes some statistical parameters.
 *  @details This class will add data to a database and can compute averages or
 *           standard deviations when called. It can also return the number of measurements
 *           in the database or can clear all numbers.
 */
class StatTracker
{
protected:
    /// Number of individual data points added to the class @c StatTracker.
    uint32_t numPoints;               
    /// Total sum of all data types within the class @c StatTracker.
    float sum;                        
    /// Sum of squared added data within the class @c StatTracker.
    float sumSquared;                 
    /// Standard deviation of data within the class @c StatTracker.
    float Sx;                         

public:  
    StatTracker(void);                // Constructor to initialize variables.
    void add_data(float new_float);   // Add one data point to the set being tracked.
    void add_data(int32_t new_int);   // Add a signed integer point to the data set.
    void add_data(uint32_t new_uint); // Add an unsigned integer point to the data set.
    uint32_t num_points(void);	      // Returns the number of data points added.
    float average(void);	          // Returns the average of the data.
    float std_dev(void);	          // Returns the standard deviation of the data.
    void clear(void);                 // Deletes all the data, returning to no points added state.
};