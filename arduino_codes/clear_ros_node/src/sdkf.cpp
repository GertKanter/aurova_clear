/*
 * sdkf.cpp
 *
 *  Created on: 14 Mar 2018
 *      Author: idelpino
 */

#include "../headers/sdkf.h"

sdkf::sdkf(float A, float B, float P0, float Q, float R) {
	// TODO Auto-generated constructor stub
	A_ = A;
	B_ = B;

	covariance_ = P0; //initialize covariance
	process_noise_ = Q;
	sensor_noise_ = R;

	vel_ = 0.0;
	vel_k_minus_one_ = 0.0;

	volts_k_minus_one_ = 0.0;

	dt_ = -1.0;
	t_k_ = 0.0;
	t_k_minus_one_ = 0.0;

	kalman_gain_ = 0.0;
	innovation_ = 0.0;
	innovation_covariance_ = 0.0;
}

sdkf::~sdkf() {
	// TODO Auto-generated destructor stub
}

void sdkf::make_prediction(float volts, float& vel, float& covariance)
{
	float dvolts = (volts - volts_k_minus_one_);

	vel_ = A_ * vel_ + B_ * dvolts; // dt gets cancelled
	covariance_ = covariance_ + process_noise_;

	covariance = covariance_;
	vel = vel_;

	volts_k_minus_one_ = volts;
}

void sdkf::make_correction(float measured_speed, float& vel, float& covariance)
{
	innovation_ = measured_speed - vel_;
	innovation_covariance_ = covariance_ + sensor_noise_;
	kalman_gain_ = covariance_ / innovation_covariance_;

	vel_ = vel_ + kalman_gain_ * innovation_;
	covariance_ = covariance_ - kalman_gain_ * innovation_covariance_ * kalman_gain_;

	vel = vel_;
	covariance = covariance_;
}
