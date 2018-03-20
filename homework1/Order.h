struct Order {
    enum Type { SELL, BUY } type;
    unsigned walletId;
    double fmiCoins;
};
