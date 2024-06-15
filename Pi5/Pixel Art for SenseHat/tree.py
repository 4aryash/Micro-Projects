from sense_hat import SenseHat

sense = SenseHat()

X = [150, 75, 0]  # Brown
O = [66, 105, 47]  # Green
B = [0, 0, 0] # Black

sense.set_rotation(180)

heart = [
B, B, O, O, O, O, B, B,
B, O, O, O, O, O, O, B,
O, O, O, X, X, O, O, O,
O, O, O, X, X, O, O, O,
B, O, O, X, X, O, O, B,
B, B, B, X, X, B, B, B,
B, B, X, X, X, X, B, B,
B, X, X, X, X, X, X, B
]

#sense.low_light = True
sense.set_pixels(heart)
