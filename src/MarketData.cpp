#include "MarketData.hpp"

void MarketData::loadSampleData() {
    prices = {100.5, 101.0, 100.8, 102.5, 99.8};
}

double MarketData::getLatestPrice() {
    if (!prices.empty()) {
        double price = prices.back();
        prices.pop_back();
        return price;
    }
    return 100.0;  // Default price
}
