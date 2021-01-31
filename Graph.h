//#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include "Point.h"
class Graph {
	public:
		Graph(std::vector<Point>& points);
		void addPoint(Point& point);
		void addWeight(int from, int to, int beginHour, int beginMin, int endHour, int endMin, int valueHour, int valueMin);
		int getTime(int timeHour, int timeMin, int total, ...) const;
		void bestWeight(int timeHour, int timeMin, int start, int stop);

	private:
		std::vector<Point>& points;
		int counter;
		void bestWay(int prev, int target, int weight, int time, int start, int stop);
		Point& getPoint(int name) const;
};
#endif