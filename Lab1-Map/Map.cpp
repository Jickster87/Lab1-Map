#include "Map.h"
#include "MapIterator.h"

Map::Map() {
    mapCapacity = 32;
    mapSize = 0;
    mainArray = new TElem[mapCapacity]();
    
}

Map::~Map() {
    delete [] mainArray;
}

TValue Map::add(TKey c, TValue v){
	//resize if needed
    if (mapSize == mapCapacity) {
        mapCapacity *= 2;
        TElem* tempArray = new TElem[mapCapacity]();
        for (int i=0; i<mapSize; i++) {
            tempArray[i] = mainArray[i];
        }
        delete [] mainArray;
        mainArray = tempArray;
    }
    
    //search for value, and update
    for (int i=0; i<mapSize; i++) {
        if (mainArray[i].first == c) {
            TValue oldValue = mainArray[i].second;  // Store old value
            mainArray[i].second = v;  // Update value
            return oldValue;  // Return the old value
        }
    }
    //if not found add pair to end of bag
    mainArray[mapSize].first = c;
    mainArray[mapSize].second = v;
    mapSize++;
    return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
    for (int i=0; i<mapSize; i++) {
        if (mainArray[i].first == c) {
            return c;
        }
    }
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
    // If the bag is empty, return false
    if (mapSize == 0) {
        return false;
    }
 
    //find elem
    int elemPos = -1;
    for (int i = mapSize; i >= 0; i--) {
        if (mainArray[i].first == c) {
            elemPos = i;
            break;
        }
    }
  
    // not found get out
    if (elemPos == -1) {
        return NULL_TVALUE;
    }
  
  
    // if freq is now 0 also remove pair
    if (mainArray[elemPos].first == c) {
        for (int i = elemPos; i < mapSize-1; i++) {
            mainArray[i] = mainArray[i+1];
        }
        mapSize--;
    }
     
    return true;

}


int Map::size() const {
	return mapSize;
}

bool Map::isEmpty() const{
	return mapSize==0;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
