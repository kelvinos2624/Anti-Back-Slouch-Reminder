#include <math.h>
#include "angle_math.h"
/*
Functions
----------------
*/

/*
 * Computes the angle with the vertical using trigonometry with the gravitational acceleration vector assuming the user is stationary
 * @param z_comp_acc the z component of acceleration
 * @return the angle with the vertical in radians as a float
*/
float get_angle(float z_comp_acc){
    if(abs(z_comp_acc) > GRAVITY_ACC) z_comp_acc = GRAVITY_ACC;
    return asin(abs(z_comp_acc)/GRAVITY_ACC);
}
/*
 * Computes an angle measure in degrees when given the corresponding radian measure
 * @param radians the radian measure of the angle
 * @return the angle in the unit of degrees
*/
float to_degrees(float radians){
    return radians * 180.0/PI_6_DIG;
}