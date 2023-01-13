/*
Functions for calculating the linear approximation of a 1-Dimensional wave
equation.
*/

#pragma once

// core
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

// src
#include "../../types.hpp"
namespace T = kac_core::types;

namespace kac_core::physics {

	T::Matrix_1D calculateLinearAmplitudes(const double& x, const int& N) {
		/*
		Calculate the amplitudes of the 1D eigenmodes relative to a strike
		location.
		input:
			x = strike location
			N = number of modes
		output:
			A = { abs(sin(nxπ)) | a ∈ ℝ, 0 < n <= N }
		*/

		T::Matrix_1D A(N);
		double x_pi = x * M_PI;
		for (unsigned int n = 0; n < N; n++) { A[n] = abs(sin((n + 1) * x_pi)); };
		return A;
	}

	T::Matrix_1D calculateLinearSeries(const int& N) {
		/*
		Calculate the the harmonic series.
		input:
			N = number of modes
		output:
			S = { n | s ∈ ℕ, 0 < n <= N }
		*/

		T::Matrix_1D S(N);
		for (unsigned int n = 0; n < N; n++) { S[n] = n + 1; };
		return S;
	}

}