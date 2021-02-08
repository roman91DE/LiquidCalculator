#ifndef LIQUID_H
#define LIQUID_H


class Liquid
{
    
private:
    static int mg_per_10ml_shot;
    double vol_total, vol_nicotine, vol_aroma, vol_base;
    double nic_mg_per_ml;
public:
    static void set_nicotine_strength(int mg_per_ml);
    Liquid(double _vol_total, double _vol_aroma, double _nic_mg_per_ml);
    ~Liquid();
    void calculate_amounts();
    double get_nicotine() const;
    double get_base() const;
};

#endif // LIQUID_H


