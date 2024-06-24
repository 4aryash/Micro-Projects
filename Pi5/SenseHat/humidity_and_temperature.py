from sense_hat import SenseHat

sense = SenseHat()

humidity = sense.get_humidity()
print("Humidity: %s %%rH" % humidity)
#alternatives
#print(sense.humidity)

temp = sense.get_temperature()
#print("Temperature: %s C" % temp)
print(sense.temp)
print(sense.temperature)
