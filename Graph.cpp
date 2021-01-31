
#include "Graph.h"
#include <iostream>
Graph::Graph(std::vector<Point>& points) : points(points){
	counter = 0;
}

void Graph::addPoint(Point& point) {
	points.push_back(point);
}

void Graph::addWeight(int from, int to, int beginHour, int beginMin, int endHour, int endMin, int valueHour, int valueMin) {
	int beginTime = beginHour * 60 + beginMin;
	int endTime = endHour * 60 + endMin;
	int value = valueHour * 60 + valueMin;
	for (auto it = begin(points); it != end(points); it++) {
		if (it->getName() == from) {
			it->addWeight(to, beginTime, endTime, value);
			break;
		}
	}
}

int Graph::getTime(int timeHour, int timeMin, int total , ...) const {
    int time = timeHour * 60 + timeMin;
    int rezult = 0;
    int way[100]; //total
    int* next = &total;
    next++;
    for (int i = 0; i < total; i++, next++) {
        way[i] = *next;
    }
    total -= 1;
    for (int i = 0; i < total; i++) {
        for (auto p : points) {
            if (p.getName() == way[i]) {
                int Weight = p.getWeight(way[i + 1], time);
                rezult += Weight;
                time += Weight;
            }
        }
    }
    return rezult;
}

void Graph::bestWeight(int timeHour, int timeMin, int start, int stop) {
    int time = timeHour * 60 + timeMin;
    for (auto& p : points) {
        p.setPrev(0);
        p.setBestWeight(0);
    }

    Point& point = getPoint(start);
    std::map<int, std::vector<Weight>> node = point.getNode();
    for (auto& x : node) {
        int  weight = point.getWeight(x.first, time);
        bestWay(point.getName(), x.first, point.getBestWeight() + weight, time + weight, start, stop);
    }

    std::cout << stop << " ; ";
    Point& p = getPoint(stop);
    int line = p.getPrev();
    std::cout << line << ":";
    std::cout << p.getBestWeight() << " ; ";
    while (line != start) {
        Point& prev = getPoint(line);
        line = prev.getPrev();
        std::cout << line << ":";
        std::cout << prev.getBestWeight() << " ; ";
    }
    std::cout << std::endl;
}

void Graph::bestWay(int prev, int target, int weight, int time, int start, int stop) {
    //std::cout << prev << ' ' << target << ' ' << weight << ' ' << time << ' ' << start << ' ' << stop << std::endl;
    if (target == start || counter > 20) return;
    time %= 1440;
    Point& point = getPoint(target);
    if (point.getBestWeight() == 0 || point.getBestWeight() > weight) {
        point.setBestWeight(weight);
        point.setPrev(prev);
        if (target == stop) return;
        std::map<int, std::vector<Weight>> node = point.getNode();
        for (auto& x : node) {
            int  weight = point.getWeight(x.first, time);
            bestWay(point.getName(), x.first, point.getBestWeight() + weight, time + weight, start, stop);
        }
    }
}

Point& Graph::getPoint(int name) const {
    for (auto it = begin(points); it != end(points); it++) {
        if (it->getName() == name) {
            return *it;
        }
    }
}
