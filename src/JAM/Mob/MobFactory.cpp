/*
** EPITECH PROJECT, 2025
** epitech-game-jam-january
** File description:
** MobFactory
*/

#include "MobFactory.hh"

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createRedMob()
{
    return std::shared_ptr<RedMob>(new RedMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createBlueMob()
{
    return std::shared_ptr<BlueMob>(new BlueMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createGreenMob()
{
    return std::shared_ptr<GreenMob>(new GreenMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createYellowMob()
{
    return std::shared_ptr<YellowMob>(new YellowMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createPinkMob()
{
    return std::shared_ptr<PinkMob>(new PinkMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createBlackMob()
{
    return std::shared_ptr<BlackMob>(new BlackMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createWhiteMob()
{
    return std::shared_ptr<WhiteMob>(new WhiteMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createRainbowMob()
{
    return std::shared_ptr<RainbowMob>(new RainbowMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createMoabBlueMob()
{
    return std::shared_ptr<MoabBlueMob>(new MoabBlueMob);
}

std::shared_ptr<Game::Mob::IMob> Game::Mob::MobFactory::createMoabRedMob()
{
    return std::shared_ptr<MoabRedMob>(new MoabRedMob);
}
