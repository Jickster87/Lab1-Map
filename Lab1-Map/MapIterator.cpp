#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
    currentPosition = 0;
}


void MapIterator::first() {
    currentPosition = 0;
}


void MapIterator::next() {
    if (!valid()) {
        throw exception();
    }
    currentPosition++;
}


TElem MapIterator::getCurrent(){
    if (!valid()) {
        throw exception();
    }
	return map.mainArray[currentPosition];
}


bool MapIterator::valid() const {
	//TODO - Implementation
	return currentPosition < map.mapSize;
}



