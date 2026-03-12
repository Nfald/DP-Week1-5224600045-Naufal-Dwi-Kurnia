#include <iostream>
#include "ShopSystem.h"

void ShopSystem::showOffer(int round, int money) {
    std::cout << "[SHOP] Round " << round
              << " shop opened. Current money: " << money << std::endl;

    if (money >= 25) {
        std::cout << "[SHOP] You can afford a small upgrade." << std::endl;
    } else {
        std::cout << "[SHOP] Not enough money for upgrade yet." << std::endl;
    }
}