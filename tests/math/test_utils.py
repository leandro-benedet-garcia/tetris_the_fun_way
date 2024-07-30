from funenginepy import math


def test_math_approximately():
    aprox = math.approximately

    assert aprox(10, 10)
    assert aprox(10000.001, 10000.001)
    assert aprox(1e-44, 1e-44)
    assert aprox(1.92593e-34, 1.9259302e-34)

    # Those differences are within tolerance, so they return true.
    assert aprox(-1e-44, 1e-44)
    assert aprox(1e-44, 1e-45)
    assert aprox(10000.1, 10000.2, 0.2)
    assert aprox(10000.1, 10000.10000001, 0.1)
    assert aprox(-10000.1, -10000.19, 0.1)

    assert not aprox(10000.1, 10000.21, 0.1)
    assert not aprox(10000.001, 10000.0009765625)
    assert not aprox(10001.001, 10000.001)
    assert not aprox(10000.1, 10000.30000001, 0.2)
    assert not aprox(10000.1, 10000.20000001, 0.1)
