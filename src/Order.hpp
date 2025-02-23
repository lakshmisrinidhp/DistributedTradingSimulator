#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <string>

enum class OrderSide { BUY, SELL };

struct Order {
    int orderId;
    OrderSide side;
    double price;
    int quantity;

    Order(int id, OrderSide s, double p, int q)
        : orderId(id), side(s), price(p), quantity(q) {}

    void print() const {
        std::cout << "Order ID: " << orderId << " | " 
                  << (side == OrderSide::BUY ? "BUY" : "SELL") 
                  << " | Price: " << price << " | Qty: " << quantity << std::endl;
    }
};

#endif
