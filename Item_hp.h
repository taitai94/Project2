#pragma once
#include "Item.h"
class Item_hp :
    public Item
{
public:
    Item_hp()
        { 
            m_name = "Heath potion"; 
            m_hp = 200;
            m_price = 500;
        };
    
};

