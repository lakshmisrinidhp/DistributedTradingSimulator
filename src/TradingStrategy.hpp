#ifndef TRADINGSTRATEGY_HPP
#define TRADINGSTRATEGY_HPP

#include "OrderBook.hpp"
#include "MarketData.hpp"

class TradingStrategy {
public:
    void execute(OrderBook& book, MarketData& market);
};

#endif
