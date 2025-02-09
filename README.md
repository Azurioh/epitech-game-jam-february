# Bloons Illusion Tower Defense 7 + Premium Deluxe Definitive Edition Collector Reloaded

This project is a game created during a weekend, for the Epitech Game Jam.

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
