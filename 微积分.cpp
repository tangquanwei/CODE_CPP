#include <iostream>
#include <cmath>
#include <random>

// --- statistics --- //
template <typename T>
double stats_mean(T data[], int n)
{
    if (n <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double mean = 0.0;
    for (int i = 0; i < n; i++)
        mean += data[i];
    mean /= n;

    return mean;
}

template <typename T>
double stats_gmean(T data[], int n)
{
    if (n <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double gmean = 1.0;
    for (int i = 0; i < n; i++)
        gmean *= data[i];

    if (gmean < 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    gmean = pow(gmean, 1 / double(n));

    return gmean;
}

template <typename T>
double stats_variance(T data[], int n)
{
    if (n <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double mean = 0.0;
    for (int i = 0; i < n; i++)
        mean += data[i];
    mean /= n;

    double variance = 0.0;
    for (int i = 0; i < n; i++)
        variance += pow(data[i] - mean, 2);
    variance /= n;

    return variance;
}

template <typename T>
double stats_skewness(T data[], int n)
{
    if (n <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double mean = 0.0;
    for (int i = 0; i < n; i++)
        mean += data[i];
    mean /= n;

    double variance = 0.0;
    for (int i = 0; i < n; i++)
        variance += pow(data[i] - mean, 2);
    variance /= n;
    double sigma = sqrt(variance);

    double skewness = 0.0;
    for (int i = 0; i < n; i++)
        skewness += pow((data[i] - mean) / sigma, 3);
    skewness /= n;

    return skewness;
}

template <typename T>
double stats_kurtosis(T data[], int n)
{
    if (n <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double mean = 0.0;
    for (int i = 0; i < n; i++)
        mean += data[i];
    mean /= n;

    double variance = 0.0;
    for (int i = 0; i < n; i++)
        variance += pow(data[i] - mean, 2);
    variance /= n;
    double sigma = sqrt(variance);

    double kurtosis = 0.0;
    for (int i = 0; i < n; i++)
        kurtosis += pow((data[i] - mean) / sigma, 4);
    kurtosis /= n;
    kurtosis -= 3;

    return kurtosis;
}

// --- quadrature --- //
template <typename T>
double quadrature_trapezoid(T (*func)(T), T a, T b, int n = 1000)
{
    if (n <= 0 || a >= b)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double res = 0.0;
    double step = double(b - a) / n;
    T x = a;
    for (int i = 1; i < n; i++)
        res += func(x + i * step);
    res += (func(a) + func(b)) / 2.0;

    res *= step;

    return res;
}

template <typename T>
double quadrature_simpson(T (*func)(T), T a, T b, int n = 1000)
{
    if (n <= 0 || a >= b)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double step = double(b - a) / n;
    double res1 = 0.0;
    double x = a;
    for (int i = 1; i < n; i++)
        res1 += func(x + i * step);
    res1 *= 2;

    double res2 = 0.0;
    x = a + step / 2;
    for (int i = 0; i < n; i++)
    {
        res2 += func(x);
        x += step;
    }

    res2 *= 4;

    double res = res1 + res2 + func(a) + func(b);
    res *= step / 6;

    return res;
}

template <typename T>
double quadrature_cotes(T (*func)(T), T a, T b, int n = 1000)
{
    if (n <= 0 || a >= b)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    double step = double(b - a) / n;
    T x;

    double res1 = 0.0;
    x = a;
    for (int i = 1; i < n; i++)
    {
        x += step;
        res1 += func(x);
    }
    res1 *= 14;

    double res2 = 0.0;
    x = a + step / 2;
    double res3 = 0.0;
    double x1 = a + step / 4;
    double x2 = a + step / 4 * 3;

    for (int i = 0; i < n; i++)
    {
        res2 += func(x);
        res3 += func(x1) + func(x2);
        x += step;
        x1 += step;
        x2 += step;
    }
    res2 *= 12;
    res3 *= 32;

    double res4 = (func(a) + func(b)) * 7;

    double res = res1 + res2 + res3 + res4;
    res *= step / 90;

    return res;
}

template <typename T>
T quadrature_romberg(T (*func)(T), T a, T b, int k = 4)
{
    if (k <= 0 || a >= b)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    int size = k + 1;

    double *matrix = new T[size * size];
    for (int i = 0; i < size * size; i++)
        matrix[i] = 0.0;

    double step = b - a;
    matrix[0] = quadrature_trapezoid(func, a, b, 1);

    for (int i = 1; i < size; i++)
    {
        int n = 0x01 << (i - 1);
        for (int j = 0; j < n; j++)
            matrix[i * size + 0] += func(a + (j + 0.5) * step);
        matrix[i * size + 0] *= step;
        matrix[i * size + 0] += matrix[(i - 1) * size];
        matrix[i * size + 0] /= 2.0;
        step /= 2.0;
    }

    double temp = 1.0;
    double factor1, factor2;
    for (int j = 1; j < size; j++)
    {
        temp *= 4.0;
        factor1 = temp / (temp - 1);
        factor2 = 1 / (temp - 1);
        for (int i = j; i < size; i++)
        {
            matrix[i * size + j] = factor1 * matrix[i * size + j - 1] - factor2 * matrix[(i - 1) * size + j - 1];
        }
    }

    double res = matrix[k * size + k];
    delete[] matrix;

    return res;
}

// --- differentiate --- //
template <typename T>
double differentiate(T (*func)(T), T x, double delta = 1e-8)
{
    if (delta <= 0)
    {
        std::cerr << "wrong parameter!" << std::endl;
        return -1;
    }

    T y_pre = func(x - delta);
    T y = func(x);
    T y_post = func(x + delta);

    double diff_backward = (y - y_pre) / delta;
    double diff_forward = (y_post - y) / delta;

    double diff = (diff_backward + diff_forward) / 2.0;

    return diff;
}

// example algebra function
template <typename T>
double func1(T x)
{
    return x + 2 * x * x + 5;
}

// --- monte carlo --- //
double montecarlo_pi(int epochs = 100000)
{
    double r = 1.0;

    std::default_random_engine random_engine;
    std::uniform_real_distribution<double> distribution(0, 1);

    int count = 0;
    for (int i = 0; i < epochs; i++)
    {
        double x = distribution(random_engine);
        double y = distribution(random_engine);
        double distance = sqrt(x * x + y * y);
        if (distance <= r)
            count++;
    }

    double PI = 4 * (double)count / epochs;

    return PI;
}

int main(int argc, char *argv[])
{
    std::cout << "==== statistic test ====" << std::endl;
    double data[] = {3.7, 6.5, 4.3, 2.1, 2.3, 5.8, 5.9, 7.2, 8.6};
    int n = 9;
    std::cout << "data: ";
    for (auto num : data)
        std::cout << num << ' ';
    std::cout << std::endl;

    std::cout << "stats_mean result: " << stats_mean(data, n) << std::endl;
    std::cout << "stats_gmean result: " << stats_gmean(data, n) << std::endl;
    std::cout << "stats_variance result: " << stats_variance(data, n) << std::endl;
    std::cout << "stats_skewness result: " << stats_skewness(data, n) << std::endl;
    std::cout << "stats_kurtosis result: " << stats_kurtosis(data, n) << std::endl;

    std::cout << "==== quadrature test ====" << std::endl;
    std::cout << "f(x) = x + 2x^2 + 5" << std::endl;

    double a = 1;
    double b = 7;
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::cout << "quadrature_manual result: "
              << 1 / 2.0 * b * b + 2 / 3.0 * b * b * b + 5 * b - (1 / 2.0 * a * a + 2 / 3.0 * a * a * a + 5 * a)
              << std::endl;
    std::cout << "quadrature_trapezoid result: " << quadrature_trapezoid(func1, a, b) << std::endl;
    std::cout << "quadrature_simpson result: " << quadrature_simpson(func1, a, b) << std::endl;
    std::cout << "quadrature_cotes result: " << quadrature_cotes(func1, a, b) << std::endl;
    std::cout << "quadrature_romberg result: " << quadrature_romberg(func1, a, b) << std::endl;

    std::cout << "==== differentiate test ====" << std::endl;
    std::cout << "f(x) = x + 2x^2 + 5" << std::endl;
    double x = 3.0;
    std::cout << "x = " << x << std::endl;

    std::cout << "differentiate label result: " << 1 + 4 * x << std::endl;
    std::cout << "differentiate test result: " << differentiate(func1, x) << std::endl;

    std::cout << "==== monte carlo test ====" << std::endl;
    std::cout << "mathmatic accurate PI: " << 3.1415926 << std::endl;
    std::cout << "montecarlo computed PI: " << montecarlo_pi() << std::endl;

    return 0;
}