//
// Created by tiago on 08/05/2020.
//

#include "Edge.h"
#include "Node.h"

Edge::Edge(Node * origin, Node * destiny, double weight){
    this->origin = origin;
    this->destination = destiny;
    this->weight = weight;
    this->difficulty = 0;
}

Edge::Edge(float weight,Node *destination)
        :weight(weight),destination(destination) {}

Node *Edge::getDestination(){
    return destination;
}
double Edge::getWeight(){
    return weight;
}
Node *Edge::getOrigin() {
    return origin;
}
int Edge::getDifficulty() const {
    return difficulty;
}

void Edge::setDifficulty(int difficulty) {
    Edge::difficulty = difficulty;
}

