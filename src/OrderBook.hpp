#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include "Order.hpp"
#include <vector>
#include <algorithm>

class OrderBook {
private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;

public:
    void addOrder(const Order& order);
    void matchOrders();
    void printOrderBook();
};

#endif
