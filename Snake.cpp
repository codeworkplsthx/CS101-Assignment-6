/*
 Snake: The Game
 ------------
 
 Pariticipants:
 
 Willingham, H.
 Hurd, L.
 Graham, D.
 
 
 
Acknolwedgements:
 
Dr. Hovenmeyer for his graphics library.
 
 */
 /*
 * Terminal graphics library
 * Copyright (c) 2007-2010 David H. Hovemeyer <daveho@users.sourceforge.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */



 

#include <stdlib.h>
#include <time.h>
#include "Console.h"


// Default frames per second.
#define FPS 10
#define SNAKE_DEFAULT_X 14
#define SNAKE_DEFAULT_Y 7
#define SCREEN_WIDTH 82
#define SCREEN_HEIGHT 23
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1
#define MAX_SEGMENTS 100


// TODO: define other struct types, e.g., struct Point, struct Snake



struct Point {
    int x, y;
    
};

struct Snake {
    
    struct Point segments[MAX_SEGMENTS];
    int n_segments;
    int dir;
};

struct Scene {
    
    struct Snake snake;
   
    
};

// TODO: define functions to operate on your struct types


void point_init(struct Point *p, int x, int y);

void snake_append_segment(struct Snake *snake, int x, int y);
void snake_remove_tail(struct Snake *snake);
struct Point snake_get_head(const struct Snake *snake);
struct Point snake_get_segment(const struct Snake *snake, int index);

void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
int scene_update(struct Scene *s);
void scene_delay(struct Scene *s);



int main(void) {
    // Important: do NOT modify the main function
    struct Scene scene;
    
    scene_init(&scene);
    
    int keep_going = 1;
    while (keep_going == 1) {
        scene_render(&scene);
        cons_update();
        scene_delay(&scene);
        keep_going = scene_update(&scene);
    }
    
    return 0;
}

void scene_init(struct Scene *s) {
    srand(time(0));
    
    
    s->snake.n_segments = 8;
    s->snake.dir = 1;
    
    
    
}
void point_init(struct Point *p, int x, int y) {
    p->x = x;
    p->y = y;
    
}

void scene_render(const struct Scene *s) {
    // TODO: add your code
    
      cons_clear_screen();
    
    for (unsigned i=0;i < s->snake.n_segments;i++)
    {
        if (i == s->snake.n_segments-1)
            cons_printw("<");
       
        else
            cons_printw("*");
        
    }
    
  
    
    
    
    
    //TODO: add movement
    
    //TODO: move cursor to bottom right
    
}

int scene_update(struct Scene *s) {
    
    
    int key = cons_get_keypress();
    
   
    //update direction

    
   
    
    //quit
    if (key == KEY_Q)
    {
        return 0;
    }
    
    return 1;
}

void scene_delay(struct Scene *s) {
    // This function determines how many milliseconds the game is
    // paused between each frame of animation.
    // You can modify this if you want to vary the game speed.
    cons_sleep_ms(1000/FPS);
}