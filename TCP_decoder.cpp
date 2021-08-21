#include "TCP_decoder.h"
#include <iostream>
#include <vector>
using namespace std;

TSP_Decoder::TSP_Decoder(string filepath) {
    fstream out;
    char res[50] = {0};
    out.open(filepath, ios::in);
    while (!out.eof()){
        out.getline(res, 30, '\n');
        trans.push_back(string(res));
    }
    out.close();
}

vector<string> TSP_Decoder::stringSplit(string target_str, char target_ch) {
    vector<string> res;
    vector<int> pos;
    pos.push_back(-1);
    for (int i = 0; i < target_str.size(); i++){
        if (target_str[i]==target_ch) {
            pos.push_back(i);
        }
    }
    pos.push_back(target_str.size());
    for(int i = 0; i < pos.size()-1; i++){
        if (pos[i+1]-pos[i]-1 == 0) continue;
        res.push_back(target_str.substr(pos[i]+1, pos[i+1]-pos[i]-1));
    }
    return res;
}

void TSP_Decoder::getCoordinate() {
    for (int i = 1; i < trans.size()-1; i++){
        auto temp1 = stringSplit(trans[i]);
        string temp2 = stringSplit(temp1[2], '\r')[0];
        temp1[2] = temp2;
        float x = atof(temp1[1].c_str());
        float y = atof(temp1[2].c_str());
        coordinate[temp1[0].c_str()[0]] = vector<float> {x,y};
    }
}