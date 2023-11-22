void update_variance(float &std_deviation, unsigned int old_num_values, float const old_mean, float const new_mean, float const new_value);
void update_average(float &average, unsigned int old_num_values, float const new_value);
double calculate_std_dev(float const variance);
/*
Constants
-----------------
*/

/*
 * How frequently the mean, std dev should be updated (every UPDATE_RATE milliseconds)
 * Currently is 0.5 seconds (as of 11-7-2023)
*/
unsigned int const UPDATE_RATE{500};