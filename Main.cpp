#include "Point.h"
#include "Graph.h"
#include <fstream>
#include <string>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;
using std::cout;
using std::string;

int main() {
    std::vector<Point> points;
    std::ifstream file("input.json");
    string line;
    string input = "";
    while (std::getline(file, line)) {
        input += line;
    }
    json j;
    try {
        j = json::parse(input);
    }
    catch (json::parse_error& ex) {
        std::cerr << "parse error at byte " << ex.byte << std::endl;
    }
    for (auto item : j) {
        int name = item["name"].get<int>();
        int total = item["total"].get<int>();
        std::vector<int> next = item["next"].get<std::vector<int>>();
        points.push_back(Point(name, total, next));
    }
    
    Graph graph(points);
    graph.addWeight(3, 17, 8, 0, 10, 0, 0, 30);
    graph.addWeight(3, 17, 10, 0, 11, 0, 0, 15);
    graph.addWeight(17, 4, 8, 10, 9, 0, 0, 30);
    graph.addWeight(7, 8, 8, 0, 10, 0, 0, 30);
    graph.addWeight(11, 18, 9, 0, 10, 0, 0, 45);
    
    graph.bestWeight(9, 15, 3, 16);
    graph.bestWeight(9, 15, 1, 9);
    return 0;
}