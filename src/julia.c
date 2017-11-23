#include "fractol.h"
#include <stdlib.h>
#include <math.h>
 
typedef struct
{
	double x,y;
}       complex;
 
complex add(complex a,complex b)
{
	complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
 
complex sqr(complex a)
{
	complex c;
	c.x = a.x*a.x - a.y*a.y;
	c.y = 2*a.x*a.y;
	return c;
}
 
double mod(complex a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}
 
t_cplx mapPoint(int width, int height, double zoom, t_point x)
{
	t_cplx	c;
	// int l = (width<height)?width:height;
 
	// c.x = 2*radius*(x - width/2.0)/l;
	// c.y = 2*radius*(y - height/2.0)/l;
 	c.x = 1.5 * (x[0] - width / 2) / (0.5 * zoom * width);
    c.y = (x[1] - height / 2) / (0.5 * zoom * height);
	return c;
}
 
// void juliaSet(int width,int height,complex c,double radius,int n)
// {
// 	int x,y,i;
// 	complex z0,z1;
 
// 	for(x=0;x<=width;x++)
// 		for(y=0;y<=height;y++)
// 		{
// 			z0 = mapPoint(width,height,radius,x,y);
// 			for(i=1;i<=n;i++)
// 			{
// 				z1 = add(sqr(z0),c);
// 				if(mod(z1)>radius)
// 				{
// 					putpixel(x,y,i%15+1);
// 					break;
// 				}
// 				z0 = z1;
// 			}
// 			if(i>n)
// 				putpixel(x,y,0);
// 		}
// }

int	gen_colorj(int z)
{
	int r;
	int g;
	int b;

	r = sin(1.666 * z + 0) * 200 * 55;
	g = sin(2.666 * z + 2) * 200 * 55;
	b = sin(4.666 * z + 4) * 200 * 55;
	return (pack_color(r, g, b));
}


// for(i = 0; i < maxIterations; i++)
//     {
//       //remember value of previous iteration
//       oldRe = newRe;
//       oldIm = newIm;
//       //the actual iteration, the real and imaginary part are calculated
//       newRe = oldRe * oldRe - oldIm * oldIm + cRe;
//       newIm = 2 * oldRe * oldIm + cIm;
//       //if the point is outside the circle with radius 2: stop
//       if((newRe * newRe + newIm * newIm) > 4) break;
//     }

int		iter_pointj(t_point p, complex c, t_cplx z0, int limit)
{
	t_cplx z1;
	int		i;

	i = -1;
	while (i++ <= limit)
	{
		z1.x = z0.x * z0.x - z0.y * z0.y + c.x;
		z1.y = 2 * z0.x * z0.y + c.y;
		if (z1.x * z1.x + z1.y * z1.y > 4)
			break ;
		z0 = z1;
	}
	if (i < limit)
		return (gen_colorj(i));
	return (pack_color(0,0,0));
}

// void	render_julia_inner(int x, int y, void *data)
// {
// 	t_state	state;
// 	t_cplx	z;
// 	t_point	pos;
	
// 	state = (t_state)data;
// 	z= mapPoint
// }


 
t_cplx compute_z(int width, int height, double zoom, t_point x)
{
	t_cplx	c;
	// int l = (width<height)?width:height;
 
	// c.x = 2*radius*(x - width/2.0)/l;
	// c.y = 2*radius*(y - height/2.0)/l;
 	c.x = 1.5 * (x[0] - width / 2) / (0.5 * zoom * width);
    c.y = (x[1] - height / 2) / (0.5 * zoom * height);
	return c;
}

void    render_julia(t_buffer buffer, void *data)
{
	t_point		pos;
	complex		c;
	t_state		state;
	t_point		offset;
	t_cplx z0;

	state = (t_state)data;
	c.x = 0.624;
	c.y = 0.435;
	// printf("tl: %i, %i - rndros: %i, %i - scale: %f - iter count: %i\n", buffer->tl[0], buffer->tl[1], buffer->rndros[0], buffer->rndros[1], state->scale, mandel_iter_limit(state->scale));
	pos[0] = buffer->tl[0];
	while (pos[0] < buffer->tl[0] + buffer->size[0])
	{
		pos[1] = buffer->tl[1];
		while (pos[1] < buffer->tl[1] + buffer->size[1])
		{
			offset[0] = pos[0] + state->offset[0];
			offset[1] = pos[1] + state->offset[1];
			z0 = mapPoint(buffer->frame->window->width+ state->offset[0], buffer->frame->window->height+ state->offset[1], state->scale, offset);
			buf_set_pixel(buffer, pos[0], pos[1], iter_pointj(offset, c, z0, 300));
			pos[1] += 1;
		}
		pos[0] += 1;
	}
}

t_state	init_julia(void)
{
	t_state	state;

	NULL_GUARD((state = (t_state)memalloc(sizeof(struct s_state))));
	state->scale = 0.25;
	state->offset[0] = 0;
	state->offset[1] = 0;
	state->changed = 1;
	state->mode = &render_julia;
	return (state);
}
 

//  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
//   double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
//   double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
//   double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
//   ColorRGB color; //the RGB color value for the pixel
//   int maxIterations = 300; //after how much iterations the function should stop

//   //pick some values for the constant c, this determines the shape of the Julia Set
//   cRe = -0.7;
//   cIm = 0.27015;

//   //loop through every pixel
//   for(int y = 0; y < h; y++)
//   for(int x = 0; x < w; x++)
//   {
//     //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
//     newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
//     newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
//     //i will represent the number of iterations
//     int i;
//     //start the iteration process
//     for(i = 0; i < maxIterations; i++)
//     {
//       //remember value of previous iteration
//       oldRe = newRe;
//       oldIm = newIm;
//       //the actual iteration, the real and imaginary part are calculated
//       newRe = oldRe * oldRe - oldIm * oldIm + cRe;
//       newIm = 2 * oldRe * oldIm + cIm;
//       //if the point is outside the circle with radius 2: stop
//       if((newRe * newRe + newIm * newIm) > 4) break;
//     }
//     //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
//     color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
//     //draw the pixel
//     pset(x, y, color);
//   }
//   //make the Julia Set visible and wait to exit
//   redraw();
//   sleep();
//   return 0;
// }