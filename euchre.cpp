#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include "SimplePlayer.h"
#include <sstream>

int main()
{
    Card a;
    std::ostringstream oss;
    Player *test1 = Player_factory("jeff", "Simple");
    for (int i = 0; i <5; i++)
        test1->add_card(a);
    test1->show_hand();

    Card b = Card(Card::RANK_THREE, Card::SUIT_SPADES);

    Pack pack;
    pack.shuffle();

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "euchre I barely know her!" << std::endl;

return 0;
}
