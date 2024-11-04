#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

enum class TetrominoType {
    I, J, L, O, S, T, Z
};

class Tetromino {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual std::unique_ptr<Tetromino> clone() const = 0;
    virtual ~Tetromino() = default;
};

