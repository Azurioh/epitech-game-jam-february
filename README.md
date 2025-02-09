# JAM: A Tower Defense Game Engine

JAM is a comprehensive tower defense game engine implemented in C++. It provides a robust framework for creating and managing various elements of a tower defense game, including maps, mobs, towers, projectiles, and game scenes.

This project offers a flexible and extensible architecture for developing tower defense games. It includes a variety of mob types, different tower types with unique abilities, and a scene management system for handling different game states. The engine is designed to support multiple levels, each with its own map layout and difficulty.

## Authors

- Alan Cunin | [GitHub](https://github.com/Azurioh) - [Linkedin](https://www.linkedin.com/in/alancunin/)
- Enzo Lorenzini | [GitHub](https://github.com/Enzolorenzini)
- Romain Schmitz | [GitHub](https://github.com/r-schmitz11) - [Linkedin](https://www.linkedin.com/in/romain-schmitz-a4a4a7251/)
- Florian Peridy | [GitHub](https://github.com/Florianperidy) - [Linkedin](https://www.linkedin.com/in/florian-peridy/)
- Gabriel Leveque | [GitHub](https://github.com/gabrielleveque) - [Linkedin](https://www.linkedin.com/in/gabriel-leveque2/)
- Thomas Furstenberger | [GitHub](https://github.com/Thomas-furstenberger) - [Linkedin](https://www.linkedin.com/in/thomas-furstenberger/)

## Repository Structure

The repository is organized as follows:

- `build.sh`: Shell script for building the project
- `CMakeLists.txt`: CMake configuration file for project compilation
- `maps/`: Directory containing map files for different levels
- `src/`: Source code directory
  - `main.cpp`: Main entry point of the application
  - `JAM/`: Core game engine components
    - `Level/`: Map and case management
    - `Mob/`: Various mob types and mob factory
    - `Player/`: Player-related functionality
    - `Projectile/`: Projectile types and factory
    - `Scenes/`: Game scene management and UI components
    - `Tower/`: Tower types and tower factory

## Usage Instructions

### Installation

Prerequisites:
- C++ compiler (C++11 or later)
- CMake (version 3.10 or later)

To build the project:

```bash
./build.sh
```

This script will create a `build` directory, generate the necessary build files using CMake, and compile the project.

### Getting Started

After building the project, you can run the executable generated in the `build` directory. The exact name of the executable will depend on your CMake configuration.

### Configuration

The game can be configured by modifying the map files in the `maps/` directory. Each map file (`map_1.txt` to `map_9.txt`) represents a different level layout.

### Common Use Cases

1. Creating a new mob type:
   - Implement a new class inheriting from `AMob` in the `src/JAM/Mob/` directory
   - Add the new mob type to the `MobFactory` for instantiation

2. Adding a new tower:
   - Create a new class inheriting from `ATower` in the `src/JAM/Tower/` directory
   - Update the `TowerFactory` to include the new tower type

3. Implementing a new game scene:
   - Add a new class implementing the `IScene` interface in `src/JAM/Scenes/`
   - Update the `SceneFactory` to handle the new scene type

### Testing & Quality

The project does not include explicit testing instructions. It is recommended to implement unit tests for individual components and integration tests for the game logic.

### Troubleshooting

1. Build failures:
   - Ensure all prerequisites are installed and up to date
   - Check CMake output for specific error messages
   - Verify that all required source files are present in the repository

2. Runtime errors:
   - Enable debug mode in CMake by using `cmake -DCMAKE_BUILD_TYPE=Debug ..`
   - Use a debugger like GDB or LLDB to step through the code and identify the issue

3. Performance issues:
   - Profile the application using tools like Valgrind or gprof
   - Look for bottlenecks in mob movement calculations or collision detection
   - Optimize rendering code in the scene classes

## Data Flow

The JAM engine processes game data in the following sequence:

1. Game initialization
   - Load map data from files in the `maps/` directory
   - Initialize game scenes and UI components

2. Game loop
   - Handle user input in the current scene
   - Update game state (player actions, mob movements, tower actions)
   - Process collisions and projectile impacts
   - Update scene graphics

3. Scene transitions
   - Handle transitions between different game scenes (main menu, levels, settings)

4. Game termination
   - Clean up resources and exit the application

```
[Game Initialization] -> [Main Menu] <-> [Level Selection]
                                          |
                                          v
[Game Loop] <-> [Update Game State] <-> [Game Scene] <-> [Pause/Settings]
    ^                 |
    |                 v
    +--- [Process Collisions/Impacts]
```

Note: The actual implementation may involve more complex interactions between components, especially for handling different mob types, tower behaviors, and projectile calculations.
