/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MobFactory
*/

#include "MobFactory.hh"

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createRedMob()
{
    return std::unique_ptr<RedMob>(new RedMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createBlueMob()
{
    return std::unique_ptr<BlueMob>(new BlueMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createGreenMob()
{
    return std::unique_ptr<GreenMob>(new GreenMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createYellowMob()
{
    return std::unique_ptr<YellowMob>(new YellowMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createPinkMob()
{
    return std::unique_ptr<PinkMob>(new PinkMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createBlackMob()
{
    return std::unique_ptr<BlackMob>(new BlackMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createWhiteMob()
{
    return std::unique_ptr<WhiteMob>(new WhiteMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createRainbowMob()
{
    return std::unique_ptr<RainbowMob>(new RainbowMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createMoabBlueMob()
{
    return std::unique_ptr<MoabBlueMob>(new MoabBlueMob);
}

std::unique_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createMoabRedMob()
{
    return std::unique_ptr<MoabRedMob>(new MoabRedMob);
}
