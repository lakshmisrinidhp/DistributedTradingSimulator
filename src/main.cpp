#include "TradingStrategy.hpp"
#include "OrderBook.hpp"
#include "MarketData.hpp"

int main() {
    OrderBook orderBook;
    MarketData marketData;
    TradingStrategy strategy;

    marketData.loadSampleData();

    for (int i = 0; i < 5; i++) {
        strategy.execute(orderBook, marketData);
        orderBook.printOrderBook();
    }

    return 0;
}
