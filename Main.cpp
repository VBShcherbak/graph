#include "Point.h"
#include "Graph.h"
#include <iostream>
int main() {
    std::vector<Point> points = { {1, 3, 2, 10, 19},
                                {2, 3, 1, 3, 19},
                                {3, 5, 2, 4, 10, 11, 17},
                                {4, 5, 3, 5, 17, 21, 22},
                                {5, 2, 4, 6},
                                {6, 5, 5, 7, 12, 16, 17},
                                {7, 4, 6, 8, 16, 22},
                                {8, 4, 7, 9, 13, 16},
                                {9, 2, 8, 13},
                                {10, 3, 1, 3, 11},
                                {11, 5, 3, 10, 12, 14, 18},
                                {12, 4, 6, 11, 17, 18},
                                {13, 3, 8, 9, 22},
                                {14, 3, 11, 15, 18},
                                {15, 2, 14, 16},
                                {16, 5, 6, 7, 8, 15, 18},
                                {17, 4, 3, 4, 6, 12},
                                {18, 4, 11, 12, 14, 16},
                                {19, 3, 1, 2, 20},
                                {20, 2, 19, 21},
                                {21, 2, 4, 20},
                                {22, 3, 4, 7, 13} };
    Graph graph(points);
    
    graph.addWeight(3, 17, 8, 0, 10, 0, 0, 30);
    graph.addWeight(3, 17, 10, 0, 11, 0, 0, 15);
    graph.addWeight(17, 4, 8, 10, 9, 0, 0, 30);
    graph.addWeight(7, 8, 8, 0, 10, 0, 0, 30);
    graph.addWeight(11, 18, 9, 0, 10, 0, 0, 45);
    
    //task 1
    /*
    int step = 10; //minutes
    for (int i = 0; i < 1440; i += step) {
        int time = graph.getTime(i/60, i%60, 8, 1, 2, 3, 17, 6, 7, 8, 9);
        std::cout << time/60 << ':' << time%60 << "  ";
    }
    std::cout << std::endl << std::endl;

    int last = graph.getTime(0, 0, 8, 1, 2, 3, 17, 6, 7, 8, 9);
    std::cout << 0 << ':' << 0 << " - ";
    for (int i = 0; i < 1440; i++) {
        int time = graph.getTime(i/60, i%60, 8, 1, 2, 3, 17, 6, 7, 8, 9);
        if (time != last) {
            std::cout << i/60 << ':' << i%60 << std::endl;
            std::cout << i/60 << ':' << i%60 << " - ";
            last = time;
        }
    }
    std::cout << 24 << ':' << 0 << std::endl;
    */
    //task 2
    graph.bestWeight(9, 15, 3, 16);
    graph.bestWeight(9, 15, 1, 9);
    return 0;
}