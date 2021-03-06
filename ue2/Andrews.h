#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

#include "Point.h"
#include "Quicksort.h"

class Andrews
{
	public:
		Andrews() {}
		std::vector<Point> returnConvexHull(std::vector<Point> list) const;
		std::vector<Point> returnConvexHull_Multithreaded(std::vector<Point> list) const;

		void InitSteppable(std::vector<Point> list);
		std::vector<Point> Step(void);
		std::vector<Point> State(void) const;
		bool HasNextStep(void) const;
		void Reset(void);

	private:
		float cross(const Point O, const Point A, const Point B) const;

		std::vector<Point> _allPoints;
		std::vector<Point> _hullPoints;

		enum Status {upper, lower, done};
		int _i;
		int _upperHullSize;
		Status _currentStatus;

};

