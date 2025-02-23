all: trading_simulator

trading_simulator: src/main.cpp src/TradingStrategy.cpp src/OrderBook.cpp src/MarketData.cpp
	g++ -std=c++17 -o trading_simulator src/main.cpp src/TradingStrategy.cpp src/OrderBook.cpp src/MarketData.cpp
