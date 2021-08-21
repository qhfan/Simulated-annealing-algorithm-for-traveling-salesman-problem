#include "alg.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
vector<char> Routine::change_rootine(int i, int j) {
    auto pre_rootine = get_rootine();
    auto temp1 = pre_rootine.begin() + i;
    auto temp2 = pre_rootine.begin() + j;
    if (i <= j) {
        temp2 += 1;
        reverse(temp1, temp2);
    }
    else {
        temp1 += 1;
        reverse(temp2, temp1);
        reverse(pre_rootine.begin(), pre_rootine.end());;
    }
    return pre_rootine;
}

float Routine::target_func(vector<char>& root) {
    float sum = 0;
    float x_dis = 0;
    float y_dis = 0;
    for(int i = 0; i < root.size()-1; i++) {
        x_dis = get_coordinate(root[i+1])[0] - get_coordinate(root[i])[0];
        y_dis = get_coordinate(root[i+1])[1] - get_coordinate(root[i])[1];
        sum += sqrt((x_dis*x_dis)+(y_dis*y_dis));
    }
    x_dis = get_coordinate(root[root.size()-1])[0]-get_coordinate(root[0])[0];
    y_dis = get_coordinate(root[root.size()-1])[1]-get_coordinate(root[0])[1];
    sum += sqrt(x_dis*x_dis+y_dis*y_dis);
    return sum;
}

float Routine::compute_P(float func_i, float func_j, float T) {
    float rt = (func_i-func_j)/T;
    return exp(rt);
}

void Routine::exchange_in_T(float T) {
    int n = get_ncity()*200;
    for (int i = 0; i < n; i++) {
        int u = gen_rondom_pos();
        int v = gen_rondom_pos();
        auto now_ = get_rootine();
        auto new_ = change_rootine(u, v);
        float score_now = target_func(now_);
        float score_new = target_func(new_);
        if (score_new < score_now) {
            set_rootine(new_);
        }
        else {
            float P = compute_P(score_now, score_new, T);
            float temp = float(rand())/float(RAND_MAX);
            if (temp < P) set_rootine(new_);
        }
    }
}

void Routine::decay() {
    auto preroutine = get_rootine();
    float T = get_initial_T();
    float decay = get_decay_rate();
    fstream out;
    out.open("res.txt", ios::app);
    while (T>0.005) {
        exchange_in_T(T);
        auto root = get_rootine();
        string res = "";
        for (char ch: root) {
            res += ch;
        }
        float dis = target_func(root);
        string temp = "\t"+to_string(dis);
        res += temp;
        res += '\n';
        out << res;
        T *= decay;
    }
    out.close();
}