#include "TCP_decoder.h"
#include "alg.h"

int main(){
    auto decoder = TSP_Decoder("TSP20.txt");
    decoder.getCoordinate();
    auto rootine = Routine(decoder.get_coordnate(), 20, 280, 0.99);
    rootine.decay();
}