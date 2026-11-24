#include <iostream>
#include "IntStack.h"
#include "LogFile.h"
#include "RecentlyPlayed.h"
#include "Board.h"

int main() {
    // IntStack
    IntStack s1(5);
    s1.push(10);
    s1.push(20);
    IntStack s2 = s1; // deep copy
    s2.push(30);
    std::cout << "s1 top: " << s1.top() << ", s2 top: " << s2.top() << '\n';

    // LogFile
    LogFile log("test.log");
    log.write("Zapisujem poruku...");

    // RecentlyPlayed
    RecentlyPlayed rp(3);
    rp.play("Pjesma A");
    rp.play("Pjesma B");
    rp.play("Pjesma C");
    rp.play("Pjesma D");
    rp.print();

    // Board
    Board b(3, 3, '.');
    b.set(1, 1, 'X');
    b.print();

    return 0;
}