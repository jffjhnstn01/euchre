#include "SimplePlayer.h"
#include "HumanPlayer.h"
#include "Player.h"

Player::~Player(){}

Player *Player_factory(const std::string &name, const std::string &strategy)
{
  // We need to check the value of strategy and return 
  // the corresponding player type.
  if (strategy == "Simple") {
    // The "new" keyword dynamically allocates an object.
    return new SimplePlayer(name);
  }
  // Repeat for each other type of Player
  else if (strategy == "Human")
  {
    return new HumanPlayer(name);
  }
  
  // Invalid strategy if we get here
  else
  {
    assert(false);
    return nullptr;
  }
}

std::ostream & operator<<(std::ostream &os, const Player &p)
{
  os << p.get_name();
  return os;
}

bool smaller_card (const Card lhs, const Card rhs)
{
    return lhs < rhs;
}

