#include <iostream>
#include "../TinyXML/tinyxml.h"
#include "Verkeerssimulatie.h"


int main() {
    Verkeerssimulatie v("test.xml");
    v.automatischeSimulatie();
    return 0;
}
