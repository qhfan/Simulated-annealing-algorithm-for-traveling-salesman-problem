#ifndef ALG_H
#define ALG_H
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;
class Routine {
private:
    unordered_map<char, vector<float> > coordinate;
    vector<char> rootine;
    int N_city;
    float initial_T;
    float decay_rate;
public:
    Routine(unordered_map<char, vector<float> >coordinate, int N_city, float initial_T, float decay_rate) {
        this->coordinate = coordinate;
        this->N_city = N_city;
        this->initial_T = initial_T;
        this->decay_rate = decay_rate;
        for (int i = 0; i < N_city; i++) {
            rootine.push_back('A'+i);
        }
        srand(time(NULL));
    }
    float get_initial_T() {
        return initial_T;
    }
    float get_decay_rate() {
        return decay_rate;
    }
    int get_ncity() {
        return N_city;
    } 
    vector<char> get_rootine() {
        return rootine;
    }
    void set_rootine(vector<char> rootine) {
        this->rootine = rootine;
    }
    vector<float> get_coordinate(char a){
        return coordinate[a];
    }
    int gen_rondom_pos() {
        return rand()%N_city;
    }
    vector<char> change_rootine(int i, int j);
    float target_func(vector<char>& rout);
    float compute_P(float a, float b, float T);
    void exchange_in_T(float T);
    void decay();
};
#endif