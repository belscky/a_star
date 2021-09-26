//
// Created by mementomori on 26.09.2021.
//
#include <string>
#include <vector>
#ifndef A_STAR_OBJECTS_H
#define A_STAR_OBJECTS_H
using namespace std;

struct Vertex {
    //Vertex structure, includes name of Vertex
    string name;
    Vertex(string _name) {
        name = _name;
    }
};

struct Link {
    //Link structure, includes weight and linked vertexes
    int weight;
    Vertex *x, *y;
    Link(Vertex *_x, Vertex *_y, int _weight) {
        weight = _weight;
        x = _x;
        y = _y;
    }
};

struct Graph {
    //Graph structure, includes list of vertexes, links, methods to manipulate them
    vector<Vertex> vertexes;
    vector<Link> links;

    void addVertex(string v_name) {
        //Adds a vertex to graph
        vertexes.push_back(Vertex(v_name));
    }

    Vertex *getVertex(string name) {
        //Get a pointer of Vertex by its name
        // Fix bug with finding no vertex
        for (int i=0; i<vertexes.size(); i++) {
            if (vertexes[i].name == name) {
                return &vertexes[i];
            }
        }
    }

    void addLink(string x, string y, int w) {
        //Adds a links between to vertexes
        links.push_back(Link(getVertex(x), getVertex(y), w));
    }

    string getVertexesList() {
        //Beautiful out of vertexes
        string result = "";
        for (int i=0; i<vertexes.size(); i++) {
            result += vertexes[i].name;
            result += "\n";
        }
        return result;
    }

    string getLinksList() {
        //Beautiful out of links
        string result = "";
        for (int i=0; i<links.size(); i++) {
            result += links[i].x->name + " ";
            result += links[i].y->name + " ";
            result += to_string(links[i].weight);
            result += "\n";
        }
        return result;
    }
};

#endif //A_STAR_OBJECTS_H
