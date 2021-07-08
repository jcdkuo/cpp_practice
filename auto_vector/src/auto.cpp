#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {1,2,3};
    std::vector<int> w {3,2,1};
    std::vector<std::string>s{"abc", "book", "thanks"};

    // C-style
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }

    // Modern C++:
    for(auto& num : w)
    {
        std::cout << num << std::endl;
    }

    // Modern C++:
    for(auto& what : s)
    {
        std::cout << what << std::endl;
    }
}

