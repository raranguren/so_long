# so_long

A 2D game built in C using MiniLibX as part of the 42 school curriculum.

*42 School Project — 2025*

## Overview

so_long is a simple 2D game where you control a dolphin navigating through underwater mazes. Collect all the fish and reach the exit (a circle of dolphins) to win — but watch out for the patrolling eels!

## Assets

| Element | Sprite |
|---------|--------|
| Player | Dolphin |
| Collectibles | Orange fish |
| Exit | Circle of dolphins |
| Walls | Bricks / Seaweed / Waves (top row) |
| Enemies | Eels *(bonus)* |

<img width="590" height="627" alt="image" src="https://github.com/user-attachments/assets/a5c8dba2-f2ce-4158-a4ad-33206f0177d7" />

## Features

**Mandatory**
- Map parsing from `.ber` files
- Path validation (ensures map is completable)
- Smooth viewport scrolling for large maps
- Movement counter displayed in terminal

**Bonus**
- Animated sprites (player, collectibles, enemies, decorations)
- Patrolling eel enemies that end the game on contact
- Dynamic wall decoration (waves on top row, seaweed columns)
- On-screen move counter
- Win/lose animations and messages

## Building

```bash
make          # Build mandatory version
make bonus    # Build bonus version
make install  # Clone and build MiniLibX
make play     # Play through all maps sequentially
```

## Usage

```bash
./so_long maps/1-tutorial.ber
./so_long_bonus maps/3-fear.ber
```

## Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `Esc` | Exit game |

## Map Format

Maps are `.ber` files composed of:

| Character | Element |
|-----------|---------|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start (exactly 1) |
| `C` | Collectible (at least 1) |
| `E` | Exit (exactly 1) |

Maps must be rectangular and fully enclosed by walls.

## Dependencies

- MiniLibX (cloned automatically with `make install`)
- X11 development libraries

```bash
# Debian/Ubuntu
sudo apt install libx11-dev libxext-dev
```
