//#pragma once
#ifndef POINT_H
#define POINT_H
#include <vector>
#include <map>
#include "Weight.h"

class Point {
	public:
		Point(int name, int total, ...);
		void addWeight(int name, int begin, int end, int value);
		int getWeight(int name, int time) const;
		std::map<int, std::vector<Weight>> getNode() const;
		int getName() const;
		int getPrev() const;
		int getBestWeight() const;
		void setPrev(int value);
		void setBestWeight(int value);

	private:
		int name;
		int prev;       //for task 2
		int bestWeight; //for task 2
		const int defWeight = 30;
		std::map<int, std::vector<Weight>> node;
};
#endif

