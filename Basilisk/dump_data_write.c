#include "navier-stokes/centered.h" //library to be used from http://basilisk.fr/src/navier-stokes/centered.h.

//for unit decimal time interval, we write pressure field, velocity field, vorticity field and curvature in basilisk-specific dump state files.

event snapshot (t = 1; t <= MAXTIME; t += 1)
{
  scalar l2[], kappa[];
  vector omega[];
  curvature(f, kappa);
  lambda2 (u, l2);

  foreach(){
    omega.x[] = (u.z[0,1,0] - u.z[0,-1,0] - u.y[0,0,1] + u.y[0,0,-1])/(2.*Delta);
    omega.y[] = (u.x[0,0,1] - u.x[0,0,-1] - u.z[1,0,0] + u.z[-1,0,0])/(2.*Delta);
    omega.z[] = (u.y[1,0,0] - u.y[-1,0,0] - u.x[0,1,0] + u.x[0,-1,0])/(2.*Delta);
  }
  
  boundary ((scalar*){omega});
  
  char name[80];
  sprintf (name, "dump-%03d", (int) t);
  p.nodump = false;
  dump (file = name);
}
