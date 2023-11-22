#include <math.h>
#include "stats.h"

/*
Functions for Welford's Algorithm
-----------------
*/

/*
 * Calculates and updates the old slouch angle average with the new value. 
 * @param average the current slouch angle average, passed by reference
 * @param old_num_values the old number of collected slouch angle values
 * @param new_value the new slouch angle to update the mean with
 * @date 11/07/2023
 * @cite Uses the formula for updating the mean presented in https://changyaochen.github.io/welford/
 * 
*/
void update_average(float &average, unsigned int old_num_values, float const new_value){
    ++old_num_values;
    average = average + ( ( 1.0/((float)old_num_values) ) * (new_value - average));
}
/*
 * Calculates and updates the old variance angle with the new value using Welford's algorithm
 * @param std_deviation the current un-updated standard deviation, passed by reference
 * @param old_mean the old arithmetic mean
 * @param new_mean the new arithmetic mean
 * @param new_value the new data entry to update the std deviation with
 * @cite Uses the formulas presented in https://changyaochen.github.io/welford/
*/
void update_variance(float &variance, unsigned int old_num_values, float const old_mean, float const new_mean, float const new_value){
    ++old_num_values;
    variance = (variance) + (((new_value-old_mean)*(new_value-new_mean) - (variance))/((float) old_num_values));
}

double calculate_std_dev(float const variance){
    return sqrt(variance);
}
