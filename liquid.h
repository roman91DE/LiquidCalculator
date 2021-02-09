#ifndef LIQUID_H
#define LIQUID_H


class Liquid {   
    public:
        static int mg_per_10ml_shot;
        static void set_nicotine_strength(int mg_per_ml);
    private:
        double vol_total, vol_nicotine, percent_aroma, vol_base;
        double nic_mg_per_ml;
    public:
        Liquid(double _vol_total, double _percent_aroma, double _nic_mg_per_ml);
        ~Liquid();
        void calculate_amounts();
        double get_nicotine() const;
        double get_base() const;
        double get_aroma() const;
};

#endif // LIQUID_H


