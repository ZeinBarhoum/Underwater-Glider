# Simulink Programs

the controller used in the underwater glider is the beaglebone blue which has an intertial measurment unit (IMU) which is the MPU-9250 that includes 
gyroscope,accelerometer and magnetometer. Moreover, an additional IMU which is the MPU-6050 was used. A fusion algorithm between these two IMUs were used to 
calculate the angular position (using Euler angles), in addition, the acceleration were also calculated to test depth calculation using acceleration data. 
The programs that were used to control the underwater glider were constructed using Simulink software with the beaglebone blue plugin. 
