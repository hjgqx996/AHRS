/******************************************************************/
//This file is part of The AHRS Project.
//
//Copyright © 2019 By Nicola di Gruttola Giardino. All rights reserved.
//@mail: nicoladgg@protonmail.com
//
//AHRS is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//AHRS is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with The AHRS Project.  If not, see <https://www.gnu.org/licenses/>.
//
//In case of use of this project, I ask you to mention me, to whom it may concern.
/******************************************************************/

#ifndef Kalman_h
#define Kalman_h

#include <stdio.h>
#include <math.h>
#include "matrices.h"

/*====================================*/
/* Kalman Structure                   */
/*====================================*/
typedef struct Kalman {
    float dt;
    Matrix x;        //initial state (then previous estimate)
    Matrix x_p;       //next best estimate
    Matrix y;         //innovation vector
    Matrix P;      //covariance matrix
    Matrix P_p;    //predicted covariance matrix
    Matrix B;         //control matrix
    Matrix K;      //kalman gain
    Matrix H;      //observation matrix
    Matrix R;      //estimated measurement error covariance
    Matrix Q;      //estimated process error covariance
    Matrix A;      //state transition matrix
    Matrix S;      //innovation covariance
}kalman;

//int sat;            //number of satellites
//float sigma(int satellites){if(satellites<3)  return 10000; else return (1+pow(satellites,-0.5));}  //possible error, tbd

/*============================================*/
/* Kalman state functions prototypes          */
/*============================================*/
void predict(kalman *, float);
void innovation(kalman *, Matrix *);
void update(kalman *);


/*============================================*/
/* Kalman main function prototype             */
/*============================================*/
void Kalman_Filter(kalman *, float , Matrix *);
#endif /* Kalman_h */
