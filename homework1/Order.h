struct Order {
    enum Type { SELL, BUY } type;
    //unsigned walletId;
    int walletId;
    double fmiCoins;


    Order()
    {
        //type = t;
        walletId = 0;
        fmiCoins = 0.0;
    }
    Order(int id, double fmiC)
    {
        //type = t;
        walletId = id;
        fmiCoins = fmiC;
    }
};
