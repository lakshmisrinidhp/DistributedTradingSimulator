#ifndef MARKETDATA_HPP
#define MARKETDATA_HPP

#include <vector>
#include <iostream>

class MarketData {
private:
    std::vector<double> prices;

public:
    void loadSampleData();
    double getLatestPrice();
};

#endif
