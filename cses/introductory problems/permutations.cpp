#include <iostream>

int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  if (n == 2 || n == 3)
  {
    std::cout << "NO SOLUTION\n";
  }
  else 
  {
    for (int i = n - 1; i >= 1; i -= 2)
    {
      std::cout << i << ' ';
    }

    for (int i = n; i >= 1; i -= 2)
    {
      std::cout << i << ' ';
    }
  }

  return 0;
}