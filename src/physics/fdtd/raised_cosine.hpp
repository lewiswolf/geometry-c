#pragma once

// core
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

// src
#include "../../types.hpp"
using namespace kac_core::types;

namespace kac_core::physics {

	Matrix_1D
	raisedCosine1D(const int& size, const int& mu, const double& sigma) {
		/*
		Calculate a two dimensional raised cosine transform. See Bilbao, S.
		- Numerical Sound Synthesis p.121. input: μ = a cartesian point
		representing the maxima of the cosine. size = the size of the
		matrix. σ = variance output:
			{
				(1 + cos(π(x - μ) / σ)) / 2,	|x - μ| ≤ σ
				0,								|x - μ| > σ
			}
		*/

		Matrix_1D raised_cosine(size);
		for (unsigned int x = 0; x < size; x++) {
			double x_diff = x - mu;
			if (x_diff <= sigma) {
				raised_cosine[x] = 0.5 * (1 + cos(M_PI * x_diff / sigma));
			}
		}
		return raised_cosine;
	}

	Matrix_2D raisedCosine2D(
		const int& size_X,
		const int& size_Y,
		const int& mu_x,
		const int& mu_y,
		const double& sigma
	) {
		/*
		Calculate a two dimensional raised cosine transform. See Bilbao, S.
		- Numerical Sound Synthesis p.306. input: μ = a cartesian point
		representing the maxima of the cosine. size = the size of the
		matrix. σ = variance output: l2_norm = ((x - mu_x)^2 + (y -
		mu_y)^2)^0.5
			{
				(1 + cos(π(l2_norm) / σ)) / 2,	|l2_norm| ≤ σ
				0,								|l2_norm| > σ
			}
		*/

		Matrix_2D raised_cosine(size_X, Matrix_1D(size_Y, 0));
		for (unsigned int x = 0; x < size_X; x++) {
			for (unsigned int y = 0; y < size_Y; y++) {
				double l2_norm = sqrt(pow((x - mu_x), 2) + pow((y - mu_y), 2));
				if (l2_norm <= sigma) {
					raised_cosine[x][y] =
						0.5 * (1 + cos(M_PI * l2_norm / sigma));
				}
			}
		}
		return raised_cosine;
	}

}