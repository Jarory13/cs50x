//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

//curosr y axis 
#define paddleY 450


// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);
void removeGWindow(GWindow gw, GObject gobj);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

   //initialize velocity
   double xvelocity = drand48();
   double yvelocity = drand48(); 
   
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
    
    //start moving ball
    move(ball, xvelocity, yvelocity);
    
    //set scoreboard
    updateScoreboard(window, label, points);
    
    //bounce off left and right edges of window
    if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
          xvelocity = -xvelocity;
        }
    else if (getX(ball) <= 0)
        {
          xvelocity = -xvelocity;
        }
    pause(1);
    
    //stop if touching bottom
    if(getY(ball) + getHeight(ball) >= getHeight(window))
      {
        lives--;
        setLocation(ball, 185, (paddleY/2));
        setLocation(paddle,175, paddleY);
        waitForClick();
      }
    //bounce off top wall   
    else if (getY(ball) <= 0)
      {
        yvelocity = -yvelocity;
      }
    
    
    //detect collision
    GObject object = detectCollision(window, ball);
    
    if(object != NULL)
    {
    //Bounce if rectangle    
      if(strcmp(getType(object), "GRect") == 0)
      {
        yvelocity = -yvelocity;
        
        //if brick, remove it reset add points, lower bricks
        if(object != paddle)
          {
          removeGWindow(window, object);
          bricks--;
          points++;
          }
        else if(object == paddle)
          {
          if(getY(ball) + getHeight(ball) > getY(paddle) + getHeight(paddle))
            {
            lives--;
            setLocation(ball, 185, (paddleY/2));
            setLocation(paddle,175, paddleY);
            waitForClick();
            }
          else if(getY(ball) + getHeight(ball) <= getY(paddle))
            {
            yvelocity = -yvelocity;
            }
            
          }    
      }
       
      //ignore scoreboard   
      else if (strcmp(getType(object), "GLabel") == 0)
      {
      ;
      }
    }
      
        //check for mouse movement
        GEvent event = getNextEvent(MOUSE_EVENT);
        
        //if mouse moves
        if(event != NULL)
          {
           
          //verify event was mouse movement
          if(getEventType(event) == MOUSE_MOVED)           
            {
            //Follow mouse along x-axis
            double x = getX(event) - getWidth(paddle) / 2;
            double y = paddleY;
            setLocation(paddle, x, y);    
            }
            
          }       
     }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // create bricks
    
    //intialize column spacing
    double y = 10;
    
    //set colors
    string color[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};
    
    //create brick table
    for(int n = 0; n < ROWS; n ++)
      {
      double x = 2;
      for(int i = 0; i < COLS; i++)
        {
        GRect brick = newGRect(x, y, 35, 10);
        setFilled(brick, true);
        setColor(brick, color[n]);
        add(window, brick);
        x = x + 40;
        }
        y = y + 20;
      
      }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    //create ball
    GOval ball = newGOval(185, (paddleY/2), 15, 15);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
     // create paddle
     GRect paddle = newGRect(175, paddleY, 50, 10);
     setFilled(paddle, true);
     setColor(paddle,"BLACK");
     add(window, paddle);
     return paddle;
     
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // create scoreboard
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
