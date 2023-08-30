#include "tension.h"//library to be used from http://basilisk.fr/src/tension.h

#include "lambda2.h" //library to be used from http://basilisk.fr/src/lambda2.h

#include "view.h" //library to be used from http://basilisk.fr/src/view.h

//for "float" time interval, we output the streamwise vorticity isosurface using lambda2 criterion

event figure_lambda2front (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "front", fov = 3.5, quat = {0,0,0,1}, tx = -0.0, ty = -0.1, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  travelling (18, 82, ty = -0.50);
  clear();
 
  draw_vof ("f", fc = {0.410156,0.410156,0.410156});

  scalar l2[];
  lambda2 (u, l2);
  isosurface ("l2", -0.0002);

  char name[100];
  sprintf(name,"lambda2front-%.1f.png",t);
  save (name);
}

event figure_lambda2right (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "right", fov = 3.5, quat = {0,0,0,1}, tx = -0.0, ty = -0.1, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  //travelling (18, 82, ty = -0.50);
  clear();
 
  draw_vof ("f", fc = {0.410156,0.410156,0.410156});

  scalar l2[];
  lambda2 (u, l2);
  isosurface ("l2", -0.0002);

  char name[100];
  sprintf(name,"lambda2right-%.1f.png",t);
  save (name);
}

//for "float" time interval, we calculate the streamwise vorticity from velocity field components and output the streamwise vorticity isocontour

event figure_omegatop (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "top", fov = 3, quat = {0,0,0,1}, tx = -0.0005, ty = -0.0005, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  clear();

  scalar omegay[];
  foreach()
    omegay[] = -(u.z[1] - u.z[-1] - u.x[0,0,1] + u.x[0,0,-1])/(2.*Delta);
  boundary ({omegay});
  draw_vof ("f", color = "omegay", min = 0.0, max = 1.0, map = jet);
  //isosurface ("omegay", 0.15, fc = {1,0,0.0});
  //isosurface ("omegay", -0.15, fc = {0,1.0,0.0});

  char name[100];
  sprintf(name,"omegaytop-%.1f.png",t);
  save (name);
  }

event figure_omegafront (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "front", fov = 3, quat = {0,0,0,1}, tx = -0.0, ty = -0.1, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  //travelling (18, 82, ty = -0.65);
  clear();
 
  draw_vof ("f", fc = {0.410156,0.410156,0.410156});

  scalar omegay[];
  foreach()
    omegay[] = -(u.z[1] - u.z[-1] - u.x[0,0,1] + u.x[0,0,-1])/(2.*Delta);
  boundary ({omegay});
  isosurface ("omegay", 0.15, fc = {1,0,0.0});
  isosurface ("omegay", -0.15, fc = {0,1.0,0.0});

  char name[100];
  sprintf(name,"omegayfront-%.1f.png",t);
  save (name);
}

event figure_omegaright (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "right", fov = 3, quat = {0,0,0,1}, tx = -0.0, ty = -0.1, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  //travelling (18, 82, ty = -0.65);
  clear();
 
  draw_vof ("f", fc = {0.410156,0.410156,0.410156});

  scalar omegay[];
  foreach()
    omegay[] = -(u.z[1] - u.z[-1] - u.x[0,0,1] + u.x[0,0,-1])/(2.*Delta);
  boundary ({omegay});
  isosurface ("omegay", 0.15, fc = {1,0,0.0});
  isosurface ("omegay", -0.15, fc = {0,1.0,0.0});

  char name[100];
  sprintf(name,"omegayright-%.1f.png",t);
  save (name);
}

event figure_omegaiso (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "iso", fov = 3.5, quat = {0,0,0,1}, tx = -0.001, ty = -0.062, tz = -0.110, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  //travelling (18, 82, ty = -0.65);
  clear();
 
  draw_vof ("f", fc = {0.410156,0.410156,0.410156});

  scalar omegay[];
  foreach()
    omegay[] = -(u.z[1] - u.z[-1] - u.x[0,0,1] + u.x[0,0,-1])/(2.*Delta);
  boundary ({omegay});
  isosurface ("omegay", 0.15, fc = {1,0,0.0});
  isosurface ("omegay", -0.15, fc = {0,1.0,0.0});

  char name[100];
  sprintf(name,"omegayiso-%.1f.png",t);
  save (name);
}

//for "float" time interval, we output the contour of curvature of bubble surface

event curvebottom (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "bottom", fov = 2, quat = {0,0,0,1}, tx = -0.0005, ty = -0.0005, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  clear();

  scalar kappa[];
  curvature (f, kappa);
  draw_vof("f", color = "kappa", min = -10.0, max = 0.0, map = jet);

  char name[100];
  sprintf(name,"curvebottom-%.1f.png",t);
  save (name);
}

event curvetop (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "top", fov = 2, quat = {0,0,0,1}, tx = -0.0005, ty = -0.0005, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  clear();

  scalar kappa[];
  curvature (f, kappa);
  draw_vof("f", color = "kappa", min = -10.0, max = 0.0, map = jet);

  char name[100];
  sprintf(name,"curvetop-%.1f.png",t);
  save (name);
}

event curveiso (t = 0.0; t <= MAXTIME; t += 0.1)
{
  view (camera = "iso", fov = 3.5, quat = {0,0,0,1}, tx = -0.001, ty = -0.062, tz = -0.110, bg = {1,1,1}, width = 1080, height = 1920, samples = 4);
  clear();

  scalar kappa[];
  curvature (f, kappa);
  draw_vof("f", color = "kappa", min = -10.0, max = 0.0, map = jet);

  char name[100];
  sprintf(name,"curveiso-%.1f.png",t);
  save (name);
}
