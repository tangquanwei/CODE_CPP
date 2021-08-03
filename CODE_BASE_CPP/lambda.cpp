#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>

void abssort(float *x, unsigned n)
{
  std::sort(x, x + n,
            // Lambda expression begins
            [](float a, float b)
            {
              return (std::abs(a) < std::abs(b));
            } // end of lambda expression
  );
}

struct my_struct
{
  int value;
  std::function<int(int)> function; // wrapped function object
                                    // this can also wrap a closure (the result of evaluating a lambda expression)

  void apply() { value = function(value); } // use the stored function

  // use a function passed as the argument
  template <typename FN>
  void apply_this(FN fn) { value = fn(value); }

  friend std::ostream &operator<<(std::ostream &stm, const my_struct &ms)
  {
    return stm << "my_struct { value == " << ms.value << " }";
  }
};

int main()
{
  // initialise an object with a (wrapped) lambda expression
  my_struct ms{23, [](int v)
               { return v * 2; }};
  std::cout << ms << '\n'; // my_struct { value == 23 }

  ms.apply();              // use the stored function (23*2)S
  std::cout << ms << '\n'; // my_struct { value == 46 }

  ms.function = [](int v)
  { return v * v; };       // change the stored function
  ms.apply();              // use it (46*46)
  std::cout << ms << '\n'; // my_struct { value == 2116 }

  ms.apply_this([](int v)
                { return v * 3; }); // pass the function to be applied (2116*3)
  std::cout << ms << '\n';          // my_struct { value == 6348 }
}