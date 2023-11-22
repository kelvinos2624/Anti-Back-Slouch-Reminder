float get_angle(float z_comp_acc);
float to_degrees(float radians);

/*
Constants for calculations
--------------
*/

//Acceleration due to gravity in m/s^2
float const GRAVITY_ACC{9.81};

//An approximation of the mathematical constant pi with 6 digits
float const PI_6_DIG{3.14159}; 

//The angle threshold for slouching measured in degrees
float const ANGLE_THRESHOLD{15};