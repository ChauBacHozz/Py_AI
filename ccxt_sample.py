import ccxt

exchange = ccxt.binance()

markets = exchange.load_markets()
print(exchange.parse_ohlcv("BTC/USD"))
# print(exchange.describe()["has"]["fetchOHLCV"])
# for item in (exchange.describe()):
#     print(item)