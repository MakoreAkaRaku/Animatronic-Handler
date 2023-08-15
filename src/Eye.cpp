#include "../includes/Eye.h"

    Eye::Eye(pair<EYE_ID,uint8_t[2]> eye_info)
    {
        if (eye_info.first == (LEFT|RIGHT))
        {
            mId = NONE;
        }
        else
        {
            mId = eye_info.first;
            for (size_t i = 0; i < NUM_OF_SERVOS_USED; i++)
            {
                usedServos[i] = Servo();
            }
            
        }
    }
    Eye::EYE_ID Eye::GetIdentifier() const
    {
        return mId;
    }
    void Eye::MoveLeft()
    {}
    void Eye::MoveRight()
    {}
    void Eye::MoveDown()
    {}
    void Eye::MoveUp()
    {}
    bool Eye::Attach()
    {}
    bool Eye::Dettach()
    {}