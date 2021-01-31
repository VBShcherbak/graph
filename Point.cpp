#include "Point.h"

Point::Point(int name, int total, ...) : name(name) {
    int* next = &total;
    next++;
    for (int i = 0; i < total; i++, next++) {
        node[*next];
    }
    prev = 0;
    bestWeight = 0;
}

void Point::addWeight(int name, int begin, int end, int value) {
	node[name].push_back(Weight(begin, end, value));
}

int Point::getWeight(int name, int time) const {
    time %= 1440;  //minutes a day
    for (auto& x : node.find(name)->second) {
        if (x.begin <= time && time <= x.end) {
            return x.value + defWeight;
        }
    }
    return defWeight;
}

std::map<int, std::vector<Weight>> Point::getNode() const {
    return node;
}

int Point::getName() const {
	return name;
}

int Point::getPrev() const {
  	return prev;
}

int Point::getBestWeight() const {
	return bestWeight;
}

void Point::setPrev(int value) {
    prev = value;
}

void Point::setBestWeight(int value) {
    bestWeight = value;
}
