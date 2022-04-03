/* Author: Jack Henshaw
 * Created on: 03/04/2022
 * Last edited 03/04/2022
 * Header file for the standard (default) ball
 */

#ifndef STANDARDBALL_H_
#define STANDARDBALL_H_

#include "GenericBall.h"

class StandardBall: public GenericBall {
public:
    StandardBall();
    StandardBall(TwoVector position, TwoVector velocity);
    ~StandardBall();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

protected:
    void advance(int phase); // how the ball will move

};


#endif /* STANDARDBALL_H_ */
