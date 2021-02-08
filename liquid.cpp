#include "liquid.h"
#include <memory>
#include <stdio.h>

int Liquid::mg_per_10ml_shot = 20;

Liquid::Liquid(double _vol_total, double _vol_aroma, double _nic_mg_per_ml) :
vol_total(_vol_total), vol_aroma(_vol_aroma), nic_mg_per_ml(_nic_mg_per_ml) {
    calculate_amounts();
}

Liquid::~Liquid() {};

void Liquid::calculate_amounts() {
    float total_nic_mgs = vol_total * nic_mg_per_ml;
    vol_nicotine = total_nic_mgs/mg_per_10ml_shot;
    vol_base = vol_total - (vol_aroma+vol_nicotine);   
}

double Liquid::get_base() const {
    return vol_base;
}

double Liquid::get_nicotine() const {
    return vol_nicotine;
}

void Liquid::set_nicotine_strength(int mg_per_ml) {
    Liquid::mg_per_10ml_shot = mg_per_ml;
}
