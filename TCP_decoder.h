#ifndef TCP_DECODER_H
#define TCP_DECODER_H
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class TSP_Decoder{
private:
    unordered_map<char, vector<float> > coordinate;
    vector<string> trans;
public:
    TSP_Decoder(string file_path);

    vector<string> stringSplit(string target_str, char target_ch='\t');
    void getCoordinate() ;
    unordered_map<char, vector<float> > get_coordnate() {
        return coordinate;
    }
};
#endif