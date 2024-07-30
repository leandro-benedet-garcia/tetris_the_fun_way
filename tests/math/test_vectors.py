from funenginepy import math


def test_vectors_magnitude():
    aprox = math.approximately
    Vec3 = math.Vector3

    assert aprox(Vec3(10, 10, 10).magnitude(), 17.320508075688775)
    assert aprox(Vec3(1, 1, 1).magnitude(), 1.7320508075688772)
    assert aprox(Vec3(-1, 1, 1).magnitude(), 1.7320508075688772)
    assert aprox(Vec3(1, -1, 1).magnitude(), 1.7320508075688772)
