#include "OrderBook.hpp"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.side == OrderSide::BUY) {
        buyOrders.push_back(order);
        std::sort(buyOrders.begin(), buyOrders.end(), [](Order a, Order b) {
            return a.price > b.price;
        });
    } else {
        sellOrders.push_back(order);
        std::sort(sellOrders.begin(), sellOrders.end(), [](Order a, Order b) {
            return a.price < b.price;
        });
    }
    matchOrders();
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        Order buy = buyOrders.front();
        Order sell = sellOrders.front();

        if (buy.price >= sell.price) {
            int tradeQty = std::min(buy.quantity, sell.quantity);
            std::cout << "Trade Executed: " << tradeQty << " @ " << sell.price << std::endl;

            buy.quantity -= tradeQty;
            sell.quantity -= tradeQty;

            if (buy.quantity == 0) {
                buyOrders.erase(buyOrders.begin());
            } else {
                buyOrders[0] = buy;
            }

            if (sell.quantity == 0) {
                sellOrders.erase(sellOrders.begin());
            } else {
                sellOrders[0] = sell;
            }
        } else {
            break;
        }
    }
}


void OrderBook::printOrderBook() {
    std::cout << "\nOrder Book:\nBUY Orders:\n";
    for (const auto& order : buyOrders) order.print();
    
    std::cout << "SELL Orders:\n";
    for (const auto& order : sellOrders) order.print();
}

