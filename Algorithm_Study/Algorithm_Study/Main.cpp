#include "Hash.h"
#include <string>

int main()
{
    Hash* hash = new Hash();
    hash->Insert(1);
    hash->Insert(2);
    hash->Insert(3);
    hash->Insert(4);
    hash->Insert(5);
    hash->Insert(6);

    hash->Show();
}
