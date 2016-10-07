#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solution(istream &in, ostream &out);

int main()
{
    solution(cin, cout); 
}

/************************************ Let's Start ********************************************/

void solution(istream &in, ostream &out) {
    int n;
    in >> n;

    vector<int> maxProduct(n + 1);
    vector<int> result(n + 1);
    maxProduct[1] = 1;
    for (int numberSolving = 2; numberSolving <= n; ++numberSolving) {
        int currentMaxProduct = 0;
        for (int split1 = 1; split1 <= (numberSolving / 2); ++split1) {
            int split2 = numberSolving - split1;
            int split1Product = maxProduct[split1];
            int split2Product = maxProduct[split2];
            int currentProduct = split1Product * split2Product;
            if (currentProduct > currentMaxProduct) {
                currentMaxProduct = currentProduct;
            }
        }
        maxProduct[numberSolving] = ((currentMaxProduct > numberSolving) ? currentMaxProduct : numberSolving);
        result[numberSolving] = currentMaxProduct;
    }

    out << result[n] << endl;
}
