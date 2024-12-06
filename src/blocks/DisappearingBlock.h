//
// Created by jlusk on 12/5/2024.
//

#ifndef DISAPPEARINGBLOCK_H
#define DISAPPEARINGBLOCK_H
#include "Block.h"



class DisappearingBlock : public Block{
public:
    explicit DisappearingBlock(sf::Vector2f position);
    DisappearingBlock(int x, int y);
    void onTouch(Player& whoTouched) override;
    bool getCollidable() const;

private: bool isCollidable;
    float transparency;

};



#endif //DISAPPEARINGBLOCK_H
