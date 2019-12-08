#section [x0, x0 + 1] with the step h = 0.1 for the beginingd and x0 = 0

import sys
import numpy as np
import matplotlib.pyplot as plt
from math import *


def f(x, y) :
    return pow(x, 3) - (2 / x) * y

def runge_kutta_method(f, x0, y0, x1, h):
    n = ceil((x1 - x0) / h)
    y = np.empty(n + 1)
    x = np.empty(n + 1)
    for i in range(n + 1):
        x[i] = x0 + i * h

    y[0] = y0
    for i in range(n):
        f1 = f(x[i], y[i])
        f2 = f(x[i] + h / 2, y[i] + h / 2 * f1)
        f3 = f(x[i] + h / 2, y[i] + h / 2 * f2)
        f4 = f(x[i] + h, y[i] + h * f3)
        y[i + 1] = y[i] + h / 6 * (f1 + 2 * f2 + 2 * f3 + f4)
    return x, y

def adams_bashforth_method(f, x0, y0, x1, h):
    n = ceil((x1 - x0) / h)

    _, y_start = runge_kutta_method(f, x0, y0, x0 + 4 * h, h)
    x = np.empty(n+1)
    y = np.empty(n+1)
    for i in range(4):
        y[i] = y_start[i]
    for i in range(n+1):
        x[i] = x0 + i * h
    for i in range(n - 3):
        y[i + 4] = y[i + 3] + h / 24 * (55 * f(x[i + 3], y[i + 3]) -
                                        59 * f(x[i + 2], y[i + 2]) +
                                        37 * f(x[i + 1], y[i + 1]) - 9 * f(x[i], y[i]))

    return x, y


@np.vectorize
def analytic_solution(x) :
    return pow(x, 4)/6 - 1/pow(x, 2)

def plot_solutions():
    x0 = 1
    x1 = x0 + 1
    y0 = -5/6
    h = 0.1

    x, y_runge = runge_kutta_method(f, x0, y0, x1, h)
    y_exact = analytic_solution(x)
    plt.plot(x, y_runge, label='runge_kutta')
    plt.plot(x, y_exact, label='solution')
    x, y_adams = adams_bashforth_method(f, x0, y0, x1, h)
    plt.plot(x, y_adams, label='adams_bashforth')
    plt.legend()
    plt.title("Solutions for h = {:2}".format(h))
    plt.show()

    plt.plot(x, y_exact - y_runge, label='runge-kutta')
    plt.plot(x, y_exact - y_adams, label='adams')
    plt.title("Errors for h = {:2}".format(h))
    plt.legend()
    plt.show()

    print("h = ", h)
    print()
    for i in range(len(x)):
        print("x = ", x[i])
        print("Exact solution: ", y_exact[i])
        print("Runge-Kutta solution: ", y_runge[i])
        print("Adams-Bashforth solution: ", y_adams[i])
        print("Runge-Kutta error: ", y_exact[i] - y_runge[i])
        print("Adams-Bashforth error: ", y_exact[i] - y_adams[i])


def plot_errors():
    x0 = 1
    x1 = 2
    y0 = -5/6
    H = np.linspace(1e-3, 0.1, 10)
    err_runge = []
    err_adams = []
    for h in H:
        x, y_runge = runge_kutta_method(f, x0, y0, x1, h)
        y_exact = analytic_solution(x)
        err_runge.append(np.max(np.abs(y_exact - y_runge)))
        _, y_adams = adams_bashforth_method(f, x0, y0, x1, h)
        err_adams.append(np.max(np.abs(y_exact - y_adams)))

    plt.plot(H, err_runge, label='runge-kutta')
    plt.plot(H, err_adams, label='adams-bashforth')
    plt.legend()
    plt.title('e(h) using uniform metrics')
    plt.show()


if __name__ == '__main__':
    sys.stdout = open("output.txt", "w")
    plot_solutions()
    plot_errors()
