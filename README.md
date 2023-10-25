# CUB3D
Our  First RayCaster with miniLibX Library, This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.
# cub3D - My First RayCaster with miniLibX

## Overview
**cub3D** is a project that challenges you to create a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using the principles of Ray-Casting. The goal is to render a 3D scene with walls, textures, and navigation controls.

## Table of Contents
- [Mandatory Part](#mandatory-part)
- [How to Use](#how-to-use)
- [The "cub3D" Program](#the-cub3d-program)
- [Project Structure](#project-structure)
- [Parsing the Scene](#parsing-the-scene)
- [Navigation Controls](#navigation-controls)
- [Error Handling](#error-handling)
- [Bonus Features](#bonus-features)

## Mandatory Part

### How to Use
1. Clone the repository.
2. Navigate to the project directory.
3. Run `make` to compile the `cub3D` program.
4. Execute the program with a scene description file as the first argument in the format `.cub`.

### The "cub3D" Program
- The **cub3D** program renders a 3D maze with a first-person perspective using the Ray-Casting technique.
- You can explore the maze, navigate through it, and look around.
- The program supports multiple textures for walls, floor, and ceiling.
- Features smooth window management, navigation, and exit options.

### Project Structure
- The MiniLibX library is used for rendering.

### Parsing the Scene
- The program reads and parses a scene description file with a `.cub` extension.
- The map is defined using specific characters: `0` for an empty space, `1` for a wall, and `N`, `S`, `E`, or `W` for the player's start position and orientation.
- The map must be enclosed by walls.
- Scene elements are defined with an identifier (e.g., `NO`, `SO`, `WE`) followed by specific information, such as the path to texture images, floor color, and ceiling color.

### Navigation Controls
- Use arrow keys to look left and right in the maze.
- Use `W`, `A`, `S`, and `D` keys to move through the maze.
- Press `ESC` to close the window and quit the program.
- Clicking on the red cross on the window's frame also closes the window and quits the program.

### Error Handling
- The program handles various error conditions and provides explicit error messages.
- Misconfigurations or invalid scene files result in a proper exit with an "Error" message.

### Bonus Features
- Wall collisions.
- A minimap system.
- Rotation of the point of view with the mouse.
