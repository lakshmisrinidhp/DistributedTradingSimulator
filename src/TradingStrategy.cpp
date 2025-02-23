#include "TradingStrategy.hpp"

void TradingStrategy::execute(OrderBook& book, MarketData& market) {
    double marketPrice = market.getLatestPrice();

    // Simple Momentum Strategy: Buy if price is rising, Sell if falling
    static double lastPrice = 0;

    if (lastPrice == 0) { // First-time initialization
        lastPrice = marketPrice;
        return;
    }

    if (marketPrice > lastPrice) {
        std::cout << "Placing BUY order at " << marketPrice << "\n";
        book.addOrder(Order(rand() % 1000, OrderSide::BUY, marketPrice, 10));
    } else {
        std::cout << "Placing SELL order at " << marketPrice << "\n";
        book.addOrder(Order(rand() % 1000, OrderSide::SELL, marketPrice, 10));
    }

    lastPrice = marketPrice;
}

