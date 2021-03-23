# assignment10.py

def loop_factorial(n):
    """
    n: Positive integer number
    Return: Factorial of n
    """

    result = 1

    for i in range(n):
        result *= (i + 1)

    return result


def factorial(n):
    """
    n: Positive integer number
    Return: Factorial of n
    """
    # print("factorial has been called with n = " + str(n))

    if n == 1:
        return 1

    result = n * factorial(n - 1)
    # print("intermediate result for ", n, " * factorial(" ,n-1, "): ", result)

    return result


def func_to_measure(fun, value):
    """
    fun: Python Function
    value: Integer value
    Evaluates value in fun
    """

    result = fun(value)


def benchmark_test():
    """
    Benchmark Test Function
    """

    from timeit import default_timer as timer

    top = 4000

    print("starting timer - Loop Factorial")
    start = timer()

    for i in range(1, top):
        func_to_measure(loop_factorial, i)

    end = timer()
    elapsed = end - start
    print("elapsed time for Loop Factorial:", elapsed, "secs")

    print("")

    print("starting timer - Recursive Factorial")
    start = timer()

    for i in range(1, top):
        func_to_measure(factorial, i)

    end = timer()
    elapsed = end - start
    print("elapsed time for Recursive Factorial:", elapsed, "secs")


if __name__ == "__main__":
    import sys

    sys.setrecursionlimit(10000)
    benchmark_test()

