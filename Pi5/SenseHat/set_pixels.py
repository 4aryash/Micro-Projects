from sense_hat import SenseHat

sense = SenseHat()

X = [255, 0, 0]  # Red
O = [0, 0, 0]  # Black

heart = [
O, O, O, X, X, O, O, O,
O, O, X, X, X, X, O, O,
O, X, X, X, X, X, O, O,
X, X, X, X, X, O, O, O,
X, X, X, X, X, O, O, O,
O, X, X, X, X, X, O, O,
O, O, X, X, X, X, O, O,
O, O, O, X, X, O, O, O
]

#sense.low_light = True
sense.set_pixels(heart)
